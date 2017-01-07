//immediate TODO[X] GIVE TETSHAPE X Y ACCESSORS. 
//current TODO[X] GENERATE A CLASS HIEARCHEY AND STORE IN A CONTAINER OF SMARTPOINTERS.
//// client.cpp
//// ~~~~~~~~~~
//// lines 25 - 60 
//// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
////
//// Distributed under the Boost Software License, Version 1.0. (See accompanying
//// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//	remaining code
//// Copyright (c) 2016 Robert J Rivera same license as above. 
//	
////

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <random>
#include "tetShape.hpp"
#include "tetSquare.hpp"
#include "tetLine.hpp"
#include "tetL.hpp"
#include <boost/shared_ptr.hpp>
#define WIDTH 400
#define HEIGHT 600
#define SPAWNTIME 1000
#define DROPTIME 500

using boost::asio::ip::tcp;

// OOB TODO[ ] refactor clientv2.cpp functions code to be part of an arena class. 

/* check if the current grid has a valid horizontal line.
 * actual toggle of 'full' rows performed by different function "because best practices ;)" 
 *
 * RETURN vector of row indexes which meet criteria of "full"
 * 	will return a vector of size 0 if no such rows meet the criteria. 
 */

std::vector<double> checkClear(std::vector<std::vector<bool>>& curGrid_, double width_, double height_) {
	std::vector<double> clearRows = std::vector<double>();
	double cInd = 0;
	bool clear;
	for (double i = 0; i <= height_; i++) {
		clear = true;
		for (double j = 0; j <= width_; j++)  {
			//check if square is empty.
			if (!curGrid_.at(j)[i]) {
				clear = false; 
				break; //save computation power.
			}
		}
		if (clear) clearRows.push_back(cInd);
		cInd++; 
	}
	return clearRows;
}


/* clear full rows
 * drop all blocks above row;
 *
 */

void clearDropRows(std::vector<std::vector<bool>>& curGrid_, std::vector<double>& fullRows) {
	double tallRow = *std::min_element(fullRows.begin(), fullRows.end());
	double numRows = fullRows.size();
	std::cout << "num full rows: " << numRows << std::endl;
	//clear the rows. 
	for (double j = 0; j < numRows; j++) {
		for (double i = 0; i < curGrid_.size(); i++) curGrid_.at(i)[fullRows[j]] = false;
		std::cout << "cleared row: " << fullRows[j] << std::endl;
	}

	//"clone" and drop all blocks above the tallest row (remember, the tallest row is the lowest value in this y-coord scheme).
	for (double cRow = tallRow - 1; cRow >= 0; cRow--) {
		for (double i = 0; i < curGrid_.size(); i++) curGrid_.at(i)[cRow+numRows] = curGrid_.at(i)[cRow];
	}
	//empty the top [numRows] 
	for (double cRow = 0; cRow < numRows; cRow++) {
		for (double i = 0; i < curGrid_.size(); i++) curGrid_.at(i)[cRow] = false;
	}
	
	
}

int main(int argc, char* argv[])
{
	
/*	//===================BEGIN NETWORKING TESTS=====================
	auto start = std::chrono::high_resolution_clock::now();
 try{
 if (argc != 2)
    {
      std::cerr << "Usage: client <host>" << std::endl;
      std::cerr << "number of args: " << argc << std::endl;
      return 1;
    }

    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(argv[1], "daytime");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    for (;;)
    {
      boost::array<char, 128> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if ( (error == boost::asio::error::eof))
        break; // Connection closed cleanly by peer.
      else if ( (error))
        throw boost::system::system_error(error); // Some other error.

      std::cout.write(buf.data(), len);
    }
  }
  catch (std::exception& e)
   {
    std::cerr << e.what() << std::endl;
  }
  auto last = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(last-start).count() << std::endl;
*/// ================== COMMENTED OUT THE NETWORKING COMPONENT OF THE CLIENT TO FOCUS ON THE CLIENT GAME LOGIC AD PLUMBING. 
	// ==================end networking skeleton work. 
	// ====== simple texing section =======

	// ====================================
	// =============================================================
	// 	PRE GAME-LOOP INITIALIZATIONS
	// =============================================================
	// uniform RNG for block generation. 
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_int_distribution<uint32_t> distribution (0, 2);
	uint32_t blockType;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tetris Clone!");
	
	// ==================== timeing constants temporarily place here - to be placed in class constants.
	std::chrono::milliseconds spawnTrigger{SPAWNTIME};
	std::chrono::milliseconds dropTrigger{DROPTIME};
	// load all sprites	
	std::string textName = " ";
	sf::Texture tempText;
	std::vector<sf::Texture> blocks;
	std::vector<std::vector<sf::Sprite>> staticSprites;
	uint32_t numBlocks = 2;
	uint32_t numGameBlocks = -1;
	
	std::vector<std::vector<bool>> gamegrid; 
	uint32_t arenaOffset, arenaWidth, arenaHeight;
	std::vector<sf::Sprite> blockSprites; //used in sprite logic section. TODO [x] create a paradigm for multiple object refering to the same texture. 
	//TODO[ ] revisit shared_ptr scheme of tracking the active world beyond the base puzzle grid. 
	////std::vector<std::unique_ptr<tetShape>> tetShapes;
	tetShape * tetShapes;
	//	//initialize an array of size 5 to contain obects of type 'boost::shared_ptr<Shape>'
/*
	Array<boost::shared_ptr<Shape>> shapes  = Array<boost::shared_ptr<Shape>>(5);
	//create a number of different shapes using shared pointers.
	boost::shared_ptr<Circle> c(new Circle());
	boost::shared_ptr<Point> p(new Point());
	boost::shared_ptr<Line> l(new Line());
	// place the new pointers into the array we created 
	shapes[0] = c;
	*/
	//boost::shared_ptr<tetShape> tetShapes;
	//tetSquare * tetShapes = new tetSquare(5, 3, &(blocks[1]));

	// map all textures to their appropriate spot in the vector 
	for (int i = 0; i < numBlocks; i++) {
		textName = "textures/block" + std::to_string(i) + ".png";
		tempText.loadFromFile(textName);
		blocks.push_back(tempText);
		std::cout << textName << std::endl;
	}
	// ==============================TODO [X] transition this functionality to a viable object class such as shape::L shape::M etc
	// used for prototyping.
	std::vector<sf::Sprite> gameBlocks;// TODO[ ] transition global scope constants much like in csharp engine. 

	bool inGame = true;
	bool loadLevel = true;
	bool spawnPiece = true;
	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds spawnTimer; 
	std::chrono::nanoseconds dropTimer;
	//====sanity check -
	//std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime).count() << std::endl;
	//====
	// ==============================================================
	// input paradigm, track previous inputs via a container.
	// ==============================================================
	std::vector<uint32_t> * prevState = new std::vector<uint32_t>();
	std::vector<uint32_t> * curState = new std::vector<uint32_t>(); 
	sf::Keyboard::Key dummy;

	
	//using pointers to swap references in prev/cur state each cycle. no need to manually copy the values in the containers. 
	while (inGame) 
	{
		// initialize the level. NOTE!: THIS IS A PROTOTYPE FOR LEVEL PIPELINEING, TODO [ ] replicate json generation from old engine
		// is unnecessary for tetris (in fact, it's overkill) but is the basis for a rapid level generation in other 2d games. 
		if (loadLevel)  {
			loadLevel = false;
			std::string line;
			std::ifstream arena ("arena.txt");
			uint32_t spriteIndex = 0;
			uint32_t numLine = 0;
			
			arenaWidth = arenaOffset = -1; // default  values used as flags below.
			arenaHeight = 0;
			bool newRow = true;
			if (arena.is_open()  ) {
				while (getline(arena, line)){
					for (uint32_t i = 0; i < WIDTH/16; i++) {
						if (line.at(i) == '1')  {
							 
							blockSprites.push_back(sf::Sprite());
							blockSprites[spriteIndex].setTexture(blocks[0]);		
							blockSprites[spriteIndex].setPosition(sf::Vector2f((float)(16*(i % (WIDTH/16))) , (float)(16*numLine))); 
							//std::cout << "pushing new sprite: " << "1";
							spriteIndex++;
						}
						else if ( line.at(i) == '0' )  {
							if ( arenaOffset == -1 )  {
								arenaOffset = i; //determine left boundary of our game arena.
								std::cout << arenaOffset << std::endl;
							}
							if (newRow) { //tabulate height of arena by presence of '0' in arena.txt line string. 
								arenaHeight++;
								newRow = false;
							}
							if ( numLine == 1  ) {
								arenaWidth++;
								std::cout << "+1 arenaWidth" << std::endl;
							}
						}
						
					}
					newRow = true;//reset row flag. 
					numLine++;
				}
				arena.close();
				// based off information infered from arena.txt - tabulate the floor.
				//
				
				for (uint32_t i = 0; i <= arenaWidth ; i++) {
					gamegrid.push_back(std::vector<bool>());//init the oncoming column.
					staticSprites.push_back(std::vector<sf::Sprite>());
					//gamegrid.at(i).push_back(true);//push the floor. 
					for (uint32_t j = 0; j <=arenaHeight; j++) {
						gamegrid.at(i).push_back(false);		 
						staticSprites.at(i).push_back(sf::Sprite());
						staticSprites.at(i)[j].setTexture(blocks[1]);		
						staticSprites.at(i)[j].setPosition(sf::Vector2f((float)(16*(i)+arenaOffset*16), (float)(16*j))); 

					}
					gamegrid.at(i).push_back(true);
				}
			}
			else { std::cout << "Unable to open Arena.txt\n"; }
		}
		// timing for current gamecycle. 
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
		spawnTimer += now - lastCycle;//std::chrono::duration_cast<std::chrono::nanoseconds>(now-lastCycle).count();
		dropTimer += now - lastCycle; // TODO[ ] place all timers and triggers into containers. reduce LoC and improve readability. 		
		// ============================begin update gamelogic. update all game logic before handling user input. TODO[ ]  move to an update(Timing tObject) method ala desu engine. 
		
		//check if we need to drop a new game piece. 
		if ( spawnTimer > spawnTrigger  && spawnPiece == true) {
			spawnPiece = false;
			numGameBlocks++; //potentially remove
			blockType = distribution(generator);
			if (numGameBlocks> 0) delete tetShapes; //throw away the last piece, we aren't tracking it anymore.  
			if (blockType == 0) tetShapes = new tetSquare(5, 3, &(blocks[1]));
			else if (blockType == 1) tetShapes = new tetL(5, 3, &(blocks[1]));
			else if (blockType == 2)  tetShapes = new tetLine(5, 3, &(blocks[1]));
			// rearchitect TODO[x] to valid game object class hierarchy. 
			// refactor TODO [ ] convert magic numbers to aformentioned constants
			// refactor TODO [ ] create static spawn vector2 to refer to, vice this raw constructor call for a new vector each initialization of a new block.
 			// reset spawn timer. 
			spawnTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).zero();
		}
		if ( dropTimer > dropTrigger ) { 

			// TODO [x] implement tracking mechanism for floor. 
			// TODO [x] simplify to bool call.
			if (tetShapes->floorBoundCheck(gamegrid)) tetShapes->move(0, 1);
			else if (!tetShapes->onFloor() ) { // TODO[X] convert the blocks to a game 2D array of bools for sprites
					// TODO[X] this needs a valid "amendgrid" method for each shape, shouldn't be done here. 
					tetShapes->amendGrid(gamegrid);
					tetShapes->onFloor(true);
					//piece has landed, the spawn control flags are triggered accordingly.
					spawnTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).zero();
					spawnPiece = true;
					std::vector<double> fullRows;					
					fullRows = checkClear(gamegrid, arenaWidth, arenaHeight);
					if (fullRows.size() >0) { 
						try{
							clearDropRows(gamegrid, fullRows);   
						}
						catch(...){
							 std::cout << "bug in clearDropRows\n";
						}
					}
			}
			// reset the drop timer. 
			dropTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(dropTimer).zero();
		}
		// end timing capture and update capture/triggers.
		// ===============================================
	// ==================INPUT HANDLING====================
		//swap input states to modernize this input cycle. 
		delete prevState; //throw away the garbage. 
		prevState = curState; // swap the input containers
		curState = new std::vector<uint32_t>(); // create a new one. 
		
	// capture all user input. TODO[ ] delegate userinput processing to function. 
		// iterating through sfml keyboard enums - captures entire keyboard state. 
		for (uint32_t curEnum = (uint32_t)sf::Keyboard::A; curEnum != sf::Keyboard::F15; curEnum++) {
			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(curEnum))) {
				curState->push_back(curEnum);
			}
		}
	// ====================================================
	// process all user input wrt game state logic. 
	// ====================================================
		// Escape Key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Escape) != curState->end()){
			inGame = false;
		}
/*// comment block for regression purposes (alteration from tetShapes to single tetShape active on board. 
 *		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Left) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Left) == prevState->end()){
			if (numGameBlocks >= 0) {
				if ( tetShapes[numGameBlocks]->lBoundCheck(arenaOffset-1, gamegrid)){ //delegate specifics to the class.
					tetShapes[numGameBlocks]->move(-1, 0); // TODO [x] begin delegating responsibilities to other aspects of the project. 
				}
			}
		}
	*/
		// Left Key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Left) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Left) == prevState->end()){
			if (numGameBlocks >= 0) {
				if ( tetShapes->lBoundCheck(arenaOffset-1, gamegrid)){ //delegate specifics to the class.
					tetShapes->move(-1, 0); // TODO [x] begin delegating responsibilities to other aspects of the project. 
				}
			}
		}
		//Right key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Right) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Right) == prevState->end()){

			if ( numGameBlocks >= 0 ) {
				if ( tetShapes->rBoundCheck(arenaOffset + arenaWidth + 1, gamegrid)) {
					tetShapes->move(1, 0); 
				}
			}
		}
		// implement debouncing functionality. 
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Up) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Up) == prevState->end()){
		//	NOP
		}
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Down) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Down) == prevState->end()){
			
			if ( numGameBlocks >= 0 ) {
				//tetShapes[numGameBlocks].move(0, 16);
				dropTimer = dropTrigger;
			}
		}

		  
	// ====================================================
	// end processing user input wrt game logic. 
	// ====================================================
	//tutorial polling for closure of the window via 'x'ing out the window. why not. 
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ) {
				window.close();			
			
			}
		
		}
		
		

	

	// ===================================================
	// sprite draw logic
	// ===================================================
	window.clear();
	// note, blocks is simply a repo of texture. 
	// should iterate through a collection of sprites, not texutres. 

	for (auto& sprite : blockSprites) {
	// no rectangle paradigm established. tbc
		
		//sprite.setTexture(text);
	//	tempS = sprites;
		//tempSprite.setPosition(sf::Vector2f(400 - 16, 600 - 16)); 
		window.draw(sprite);
		
	

	}


	//for (auto& sprite : staticSprites.at(5)) window.draw(sprite);
	
	//draw all sprites associated with shapes in the shapes container vector<tetShape> tetShapes

	//for (auto& shape : tetShapes) {
	
		
		if (!tetShapes->onFloor() ) {
			for (auto& sprite : tetShapes->getSprites()) {
		//		std::cout << "x, y: " << (sprite.getPosition()).x << " " << (sprite.getPosition()).y << std::endl;	
				window.draw(sprite);
			}
		}
		
		
	//}
	for (uint32_t i = 0; i <= arenaWidth; i++) 	{
		for (uint32_t j = 0; j <= arenaHeight; j++) {
			if (gamegrid.at(i)[j]) 	window.draw(staticSprites.at(i)[j]);

		}
	}

	window.display();
  
  }
 
  return 0;
	
  

}
