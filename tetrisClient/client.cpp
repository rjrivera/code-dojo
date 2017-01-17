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
#include <ctime>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <random>
#include "tetShape.hpp"
#include "tetSquare.hpp"
#include "tetLine.hpp"
#include "tetL.hpp"
#define WIDTH 400
#define HEIGHT 600
#define SPAWNTIME 1000
#define DROPTIME 500

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	
/*
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
	uint32_t numBlocks = 2;
	uint32_t numGameBlocks = -1;
	
	std::vector<double> floor; 
	uint32_t arenaOffset, arenaWidth, arenaHeight;
	std::vector<sf::Sprite> blockSprites; //used in sprite logic section. TODO [x] create a paradigm for multiple object refering to the same texture. 
	std::vector<std::unique_ptr<tetShape>> tetShapes;
	// map all textures to their appropriate spot in the vector 
	for (int i = 0; i < numBlocks; i++) {
		textName = "textures/block" + std::to_string(i) + ".png";
		tempText.loadFromFile(textName);
		blocks.push_back(tempText);
		std::cout << textName << std::endl;
	}
	// ==============================TODO [ ] transition this functionality to a viable object class such as shape::L shape::M etc
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
				for (uint32_t i = 0; i <= arenaWidth ; i++) {
					floor.push_back(arenaHeight);
				}
			}
			else { std::cout << "Unable to open Arena.txt\n"; }
		}
		// timing for current gamecycle. 
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
		//deltaTime = now - lastCycle;	
//		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(now-lastCycle).count() << std::endl;
		spawnTimer += now - lastCycle;//std::chrono::duration_cast<std::chrono::nanoseconds>(now-lastCycle).count();
//		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).count()<< std::endl;
		dropTimer += now - lastCycle; // TODO[ ] place all timers and triggers into containers. reduce LoC and improve readability. 		
		// ============================begin update gamelogic. update all game logice before handling user input. TODO[ ]  move to an update(Timing tObject) method ala desu engine. 
		//
		//// std::vector<tetShape> tetShapes; tetSquare : tetShape
		if ( spawnTimer > spawnTrigger  && spawnPiece == true) {
			spawnPiece = false;
			numGameBlocks++;
			blockType = distribution(generator);
			if (blockType == 0) tetShapes.emplace_back(new tetSquare(5, 3, &(blocks[1])));
			else if (blockType == 1)  tetShapes.emplace_back(new tetLine(5, 3, &(blocks[1])));
			else if (blockType == 2)  tetShapes.emplace_back(new tetL(5, 3, &(blocks[1])));
			// rearchitect TODO[x] to valid game object class hierarchy. 
			// refactor TODO [ ] convert magic numbers to aformentioned constants
			// refactor TODO [x] create static spawn vector2 to refer to, vice this raw constructor call for a new vector each initialization of a new block.
 			// reset spawn timer. 
			spawnTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).zero();
			// output status of new instance of tetSquare. 
			std::cout << "spawn new block --- RNG yielded: " << blockType << std::endl;
			std::cout << tetShapes.at(numGameBlocks)->X() << std::endl;

		}
		if ( dropTimer > dropTrigger && tetShapes.size() > 0) {
			std::vector<double> floorSnap;	
			
			// if ( floor encountered ) do drop TODO [x] implement tracking mechanism for floor. 
			for (auto& shape : tetShapes) {
/*
			floorSnap.push_back(floor[shape->X() - arenaOffset]);
			floorSnap.push_back(floor[shape->X() - arenaOffset + 1]);*/
				// TODO [x] simplify to bool call.
				if (shape->floorBoundCheck(floor)) shape->move(0, 1);
				else if (!shape->onFloor()) { //use index for now, but TODO[ ] convert the blocks to a game 2D array of bools for sprites
					// determine a for_each scheme 
					floor[shape->X()] = shape->Y();
					floor[shape->X() + 1] = shape->Y();
					shape->onFloor(true);
					spawnTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).zero();
					spawnPiece = true;
				}
				
			}
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
		// Left Key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Left) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Left) == prevState->end()){
			if (numGameBlocks >= 0) {
				if ( tetShapes[numGameBlocks]->lBoundCheck(arenaOffset-1)){ //delegate specifics to the class.
					tetShapes[numGameBlocks]->move(-1, 0); // TODO [x] begin delegating responsibilities to other aspects of the project. 
				}
			}
		}
		//Right key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Right) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Right) == prevState->end()){

			if ( numGameBlocks >= 0 ) {
				if ( tetShapes[numGameBlocks]->rBoundCheck(arenaOffset + arenaWidth + 1)) {
					tetShapes[numGameBlocks]->move(1, 0); 
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
				////tetShapes[numGameBlocks].move(0, 16);
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

//draw all sprites associated with shapes in the shapes container vector<tetShape> tetShapes
	for (auto& shape : tetShapes) {
	//	std::cout << "in a shape\n";
		

		for (auto& sprite : shape->getSprites()) {
	//		std::cout << "x, y: " << (sprite.getPosition()).x << " " << (sprite.getPosition()).y << std::endl;	
			window.draw(sprite);
		}
		
		
	}
	
	window.display();
   }
  return 0;
	
}
