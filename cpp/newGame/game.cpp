#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "baseTerrain.cpp"
#include "plainTerrain.cpp"
#include "cursor.cpp"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include <SFML/Graphics.hpp>
#include "Project_Constants.h"
//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>

#define WIDTH 384
#define HEIGHT 352

//todo - work on an x,y tracking schema
//todo - work on a content pipeline leveraging a json
//personal notes - migrate newGame to an instantiable client object that can sync with a Server.

using namespace rapidjson;


// board construction prototyping function
// used to populate the board container. 
// as-is, does it manually. 

void bar(std::vector<baseTerrain *>& board, std::vector<sf::Texture*>& terrainTexts) {
	//const char * json = "{\"project\":\"json\",\"fucks\":\"none\"}";
	std::cout << map_const << std::endl; 

	Document myD;
	ParseResult myRes = myD.Parse(map_const.c_str());

	std::cerr << myRes.Code() << std::endl;
	Value& copyVal = myD["height"];

	std::cout <<  copyVal.GetDouble() << std::endl;

	//stringify the value objects in Document
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	myD.Accept(writer);
	
	// parsing DOM for necessary information to construct level
	//Value& layOne = myD;
	//int mapWidth = copyVal["layers"]["width"].GetInt();
	//int mapHeight = copyVal["layers"]["height"].GetInt();

	//std::cout << "height " << mapHeight << " Width " << mapWidth << std::endl;
	// constructing level
	board.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
	board.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
	board.push_back(new plainTerrain(terrainTexts[mountTerrain_const]));
	
	board[1]->tileSprite.setPosition(32, 32);
	board[2]->tileSprite.setPosition(64, 32);
	

}

//foo 
//prototyping function
//provides initial content load of terrain art assetts


void foo(std::vector<sf::Texture *>& text_container) {
	for (int i = 0 ; i < maxTerrain_const; i++) {
		std::string textName = "textures/plain" + std::to_string(i)  + ".png";
		sf::Texture * tempText = new sf::Texture();
		tempText->loadFromFile(textName);
		text_container.push_back(tempText);
	}		

}



int main( int argc, char** argv ) {

	std::vector<sf::Texture *> terrainTexts = std::vector<sf::Texture *>();
	foo(terrainTexts);
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Advance Wars Clone");
	
	std::vector<baseTerrain * > board = std::vector<baseTerrain *>();
	bar(board, terrainTexts);
	// testing posix_time libraries

	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds myTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(myTimer).zero();
	
//CURSOR PoC --- migrate code appropriately when done demonstrating TODO [ ]
	sf::Texture * cursText = new sf::Texture();
	cursText->loadFromFile("textures/cursor.png");
	cursor * myC = new cursor(cursText);

	bool inGame = true;
	while(inGame) {
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
//		deltaTime = now - lastCycle;
		myTimer = now - lastCycle;
 //		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime).count() << std::endl;
		std::cout << myC->posX << std::endl;
//		myTime += deltaTime;
		// ===================================================
		// UPDATE TIMING
		// ==================================================		
		
		myC->updateTimer(myTimer);

		// ===================================================
		// INPUT HANDLING
		// ===================================================

		// Escape Key pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			inGame = false;
		}	 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
			myC->movePosX(16);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
			myC->movePosX(-16);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
			myC->movePosY(16);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
			myC->movePosY(-16);
		}




		// ===================================================
		// sprite draw logic
		// ===================================================
		window.clear();
		// note, blocks is simply a repo of texture. 
		// should iterate through a collection of sprites, not texutres. 
		for(baseTerrain * obj : board) window.draw(obj->tileSprite);	
		window.draw(myC->tileSprite);
		
		window.display();
		
	}
	return 0;
}
