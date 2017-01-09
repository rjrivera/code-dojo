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
#include <boost/thread/thread.hpp>
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
#include "arena.hpp"
#include <boost/shared_ptr.hpp>
#define WIDTH 400
#define HEIGHT 600
#define SPAWNTIME 1000
#define DROPTIME 500

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	
/*	//===================BEGIN NETWORKING TESTS=====================
//auto start = std::chrono::high_resolution_clock::now();
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
  //auto last = std::chrono::high_resolution_clock::now();
  //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(last-start).count() << std::endl;
// ================== COMMENTED OUT THE NETWORKING COMPONENT OF THE CLIENT TO FOCUS ON THE CLIENT GAME LOGIC AD PLUMBING. 
*/	// ==================end networking skeleton work. 
	// ====== simple texing section =======

	// ====================================
	// =============================================================
	// 	PRE GAME-LOOP INITIALIZATIONS
	// =============================================================
	// uniform RNG for block generation. 
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_int_distribution<uint32_t> distribution (0, 2);
	uint32_t blockType; //controll signal used in spawnTrigger logic. 
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tetris Clone!");
	
	// ==================== timeing constants temporarily place here - to be placed in class constants.
	std::chrono::milliseconds spawnTrigger{SPAWNTIME};
	std::chrono::milliseconds dropTrigger{DROPTIME};
	// load all sprites	
	std::string textName = " ";
	sf::Texture tempText;
	std::vector<sf::Texture> blocks;
	arena * curArena = new arena();
	uint32_t numBlocks = 2;
	uint32_t numGameBlocks = -1;
	
	std::vector<std::vector<bool>> gamegrid; 
	uint32_t arenaOffset, arenaWidth, arenaHeight;
	std::vector<sf::Sprite> blockSprites; //used in sprite logic section. TODO [x] create a paradigm for multiple object refering to the same texture. 
	//TODO[ ] revisit shared_ptr scheme of tracking the active world beyond the base puzzle grid. 
	////std::vector<std::unique_ptr<tetShape>> tetShapes;

	// map all textures to their appropriate spot in the vector 
	for (int i = 0; i < numBlocks; i++) {
		textName = "textures/block" + std::to_string(i) + ".png";
		tempText.loadFromFile(textName);
		blocks.push_back(tempText);
	}
	// ==============================TODO [X] transition this functionality to a viable object class such as shape::L shape::M etc
	// TODO[ ] transition global scope constants much like in csharp engine. 

	bool inGame = true;
	bool loadLevel = true;
	bool spawnPiece = true;
	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds spawnTimer; 
	std::chrono::nanoseconds dropTimer;

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
			curArena->readLevelFile(("arena.txt"), blocks);
			arenaOffset = 2; //TODO[ ] replace these with accessors from the arena object. 
			arenaWidth = 14;
			arenaHeight = 36;
		}
		// transmit current state to the game server.
		// TODO[ ] IMPLEMENT A NETWORK CLIENT CLASS 
		// guide: boost.org - chatclient.cpp
		////io_service.post(boost::bind
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
			if (numGameBlocks> 0) curArena->clearPiece();////delete tetShapes; //throw away the last piece, we aren't tracking it anymore.  
			if (blockType == 0) curArena->definePiece(new tetSquare(5, 3, &(blocks[1])));
			else if (blockType == 1) curArena->definePiece(new tetL(5, 3, &(blocks[1])));
			else if (blockType == 2)  curArena->definePiece(new tetLine(5, 3, &(blocks[1])));
			// rearchitect TODO[x] to valid game object class hierarchy. 
			// refactor TODO [ ] convert magic numbers to aformentioned constants
			// refactor TODO [ ] create static spawn vector2 to refer to, vice this raw constructor call for a new vector each initialization of a new block.
 			// reset spawn timer. 
			spawnTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).zero();
		}

		if ( dropTimer > dropTrigger ) { 
			
			// TODO [x] implement tracking mechanism for floor. 
			// TODO [x] simplify to bool call.
			// TODO [ ] revisit how the board hands off info to it's constituent pieces. 
			if ((curArena->getPiece())->floorBoundCheck((curArena->getGrid())) ) (curArena->getPiece())->move(0, 1);
			else if (!(curArena->getPiece())->onFloor() ) { // TODO[X] convert the blocks to a game 2D array of bools for sprites
					// TODO[X] this needs a valid "amendgrid" method for each shape, shouldn't be done here. 
					(curArena->getPiece())->amendGrid(curArena->getGrid());
					(curArena->getPiece())->onFloor(true);
					//piece has landed, the spawn control flags are triggered accordingly.
					spawnTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(spawnTimer).zero();
					spawnPiece = true;
					std::vector<double> fullRows;					
					fullRows = curArena->checkClear();
					if (fullRows.size() >0) { 
						try{
							curArena->clearDropRows(fullRows);   
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
		// Left Key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Left) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Left) == prevState->end()){
			if (numGameBlocks >= 0) {
				if ( (curArena->getPiece())->lBoundCheck(arenaOffset-1, curArena->getGrid())){ //delegate specifics to the class.
					(curArena->getPiece())->move(-1, 0); // TODO [x] begin delegating responsibilities to other aspects of the project. 
				}
			}
		}
		//Right key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Right) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Right) == prevState->end()){

			if ( numGameBlocks >= 0 ) {
				if ( (curArena->getPiece())->rBoundCheck(arenaOffset + arenaWidth, curArena->getGrid())) {
					(curArena->getPiece())->move(1, 0); 
				}
			}
		}
		// implement debouncing functionality. 
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Up) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Up) == prevState->end()){
		//	NOP
		}
		// Down key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Down) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Down) == prevState->end()){
			
			if ( numGameBlocks >= 0 ) {
				//tetShapes[numGameBlocks].move(0, 16);
				dropTimer = dropTrigger;
			}
		}

		// Space key pressed
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Space) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Space) == prevState->end()){
			
			if ( numGameBlocks >= 0 ) {
				(curArena->getPiece())->morph(curArena->getGrid());
				std::cout << "Spacebar pressed\n";
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

	for (auto& sprite : curArena->getArenaSprites()) {
	// no rectangle paradigm established. tbc
		
		//sprite.setTexture(text);
	//	tempS = sprites;
		//tempSprite.setPosition(sf::Vector2f(400 - 16, 600 - 16)); 
		window.draw(sprite);
		
	}
	
	//draw all sprites associated with shapes in the shapes container vector<tetShape> tetShapes

		
	if ( !((curArena->getPiece())->onFloor()) ) {
		for (auto& sprite : (curArena->getPiece())->getSprites()) {
			window.draw(sprite);
		}
	}		
	
	for (uint32_t i = 0; i < arenaWidth; i++) 	{
		for (uint32_t j = 0; j < arenaHeight; j++) { // -1 because you don't draw the floor
			if ((curArena->getGrid()).at(i)[j]) 	window.draw((curArena->getGridSprites()).at(i)[j]);
		}
	}

	window.display();
  
  }
 
  return 0;

}
