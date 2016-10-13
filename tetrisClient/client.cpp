//
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
#define WIDTH 400
#define HEIGHT 600
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
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
	// ==================end networking skeleton work. 
	// =============================================================
	// 	PRE GAME-LOOP INITIALIZATIONS
	// =============================================================
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	sf::CircleShape shape(100.f);
	
	// load all sprites	
	std::string textName = " ";
	sf::Texture tempText;
	std::vector<sf::Texture> blocks;
	uint32_t numBlocks = 1;
	std::vector<sf::Sprite> blockSprites; //used in sprite logic section. TODO [ ] create a paradigm for multiple object refering to the same texture. 
	for (int i = 0; i < numBlocks; i++) {
		textName = "textures/block" + std::to_string(i) + ".png";
		tempText.loadFromFile(textName);
		blocks.push_back(tempText);
		std::cout << textName << std::endl;
	}
	bool inGame = true;
	bool loadLevel = true;
	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
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

					}
					std::cout << line << std::endl;
					numLine++;
				}
				arena.close();
			}
			else { std::cout << "Unable to open Arena.txt\n"; }
		}
		// timing for current gamecycle. 
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
		//deltaTime = now - lastCycle;	
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(now-lastCycle).count() << std::endl;
		// end timing capture.
	// ==================INPUT HANDLING====================
		//swap input states to modernize this input cycle. 
		delete prevState; //throw away the garbage. 
		prevState = curState; // swap the input containers
		curState = new std::vector<uint32_t>(); // create a new one. 
		
	// capture all user input. 
		// iterating through sfml keyboard enums - captures entire keyboard state. 
		for (uint32_t curEnum = (uint32_t)sf::Keyboard::A; curEnum != sf::Keyboard::F15; curEnum++) {
			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(curEnum))) {
				curState->push_back(curEnum);
			}
//			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )) { inGame = false; }
		}
	// ====================================================
	// process all user input wrt game state logic. 
	// ====================================================
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Escape) != curState->end()){
			inGame = false;
		}	 

		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Left) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Left) == prevState->end()){
			std::cout << "Left key pressed" << std::endl;
		}

		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Right) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Right) == prevState->end()){
			std::cout << "Right key pressed" << std::endl;
		}
		
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Up) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Up) == prevState->end()){
			std::cout << "Up key pressed" << std::endl;
		}
		if (std::find(curState->begin(), curState->end(), (uint32_t)sf::Keyboard::Down) != curState->end() && // debouncing feature;
			std::find(prevState->begin(), prevState->end(), (uint32_t)sf::Keyboard::Down) == prevState->end()){
			std::cout << "Down key pressed" << std::endl;
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
		//tempSprite.setPosition(sf::Vector2f(400 - 16, 600 - 16)); 
		window.draw(sprite);

	

	}

	window.display();
   }
  return 0;
	
}
