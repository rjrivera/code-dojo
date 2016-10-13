//
//// client.cpp
//// ~~~~~~~~~~
////
//// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
////
//// Distributed under the Boost Software License, Version 1.0. (See accompanying
//// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <ctime>
#include <chrono>
#include <SFML/Graphics.hpp>

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
	
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML workds!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	bool inGame = true;
	// input paradigm, track previous inputs via a container.
	std::vector<uint32_t> * prevState = new std::vector<uint32_t>();
	std::vector<uint32_t> * curState = new std::vector<uint32_t>(); 
	//using pointers to swap references in prev/cur state each cycle. no need to manually copy the values in the containers. 
	while (inGame) 
	{
	
	// ==================INPUT HANDLING====================
		//swap input states to modernize this input cycle. 
		delete prevState; //throw away the garbage. 
		prevState = curState; // swap the input containers
		curState = new std::vector<uint32_t>(); // create a new one. 
		
	// capture all user input. 
		// test iterating through sfml keyboard enums
		for (uint32_t curEnum = (uint32_t)sf::Keyboard::A; curEnum != sf::Keyboard::F15; curEnum++) {
			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(curEnum)))  {
				std::cout << "Key pressed enum value: " << curEnum << std::endl;
			}
			if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )) { inGame = false; }
		}
	// ====================================================
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ) {
				window.close();			
			}
		
		}
		
		window.clear();
		window.draw(shape);
		window.display();

	}

	
  return 0;
	
}
