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
#include "rapidjson/include/rapidjson/filereadstream.h"
#include <SFML/Graphics.hpp>
#include "Project_Constants.h"
//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>

#define WIDTH 384
#define HEIGHT 352
//todo - work on an x,y tracking schema - leverag the same back, cur (x,y) scheme, but abstract to a higher layer of client GUI
//	> keep the core game logic data to a minimum
//todo - work on a content pipeline leveraging a json
//	> develop the core functional logic than transition to an appropriate place after some thought. 
//todo - work on statemachine to toggle between user_input options (in game only)
//	>initial PoC accomplished, looking promising
//todo - draft and demo display objects for terrain information 
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

enum inputState {terrainSelect, terrainInfo, unitInfo};

void foo(std::vector<sf::Texture *>& text_container) {
	
	for (int i = 0 ; i < maxTerrain_const; i++) {
		std::string textName = "textures/plain" + std::to_string(i)  + ".png";
		sf::Texture * tempText = new sf::Texture();
		tempText->loadFromFile(textName);
		text_container.push_back(tempText);
	}		

}

//MAPGENERATOR
//PROTOTYPING FUNCTION
void mapGen(std::vector<baseTerrain *>& board_, std::vector<sf::Texture*>& terrainTexts) {
	FILE* fp = fopen("map1.json", "rb");
	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document doc;
	doc.ParseStream(is);

	fclose(fp);

	// Using a reference for consecutive access is handy and faster
	const Value& data = doc["data"];
	const Value& height = doc["height"];
	const Value& width = doc["width"];

	assert(data.IsArray());
	assert(height.IsInt());
	assert(width.IsInt());
	
	std::cout << "data is read\n";
	std::cout << data.Size() << std::endl;
	std::cout << "height is: " << height.GetInt() << std::endl;
	std::cout << "width is: " << width.GetInt() << std::endl;
	int count=0;
	for(int i = 0; i < height.GetInt(); i++) {
		for (int j = 0; j < width.GetInt(); j++) {
			switch(data[count].GetInt()){
				case plainTerrain_const :
					board_.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
					break;
				case mountTerrain_const :
					board_.push_back(new plainTerrain(terrainTexts[mountTerrain_const]));
					break;
				case waterTerrain_const :
					board_.push_back(new plainTerrain(terrainTexts[mountTerrain_const]));
					break;
				case roadTerrain_const :
					board_.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
					break;
				case forestTerrain_const :
					board_.push_back(new plainTerrain(terrainTexts[mountTerrain_const]));
					break;
			}
			board_[count]->tileSprite.setPosition(j*tilesize_const, i*tilesize_const);
			count++;
//			std::cout <<  << std::endl;
		}
	}
}


int main( int argc, char** argv ) {

	// ====================
	// INITIALIZATION 
	// ====================
	std::vector<sf::Texture *> terrainTexts = std::vector<sf::Texture *>();
	foo(terrainTexts);
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Advance Wars Clone");
	
	std::vector<baseTerrain * > board = std::vector<baseTerrain *>();
	//bar(board, terrainTexts);
	mapGen(board, terrainTexts);
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
	inputState curInputState(terrainSelect);

// Terrain info PoC, move to object
	sf::Texture * plainsInfo = new sf::Texture();
	plainsInfo->loadFromFile("textures/plainsInfo.png");
	sf::Sprite * plSprite = new sf::Sprite();
	plSprite->setTexture(*plainsInfo);
	plSprite->setPosition(0,0);

	while(inGame) {
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
//		deltaTime = now - lastCycle;
		myTimer = now - lastCycle;
 //		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime).count() << std::endl;
//		myTime += deltaTime;
		// ===================================================
		// UPDATE TIMING
		// ==================================================		
		
		myC->updateTimer(myTimer);

		// ===================================================
		// INPUT HANDLING
		// ===================================================

		// Escape Key pressed
		switch(curInputState){
			case(terrainSelect):
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) curInputState = terrainInfo;
			break;

			case(terrainInfo):
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
				curInputState = terrainSelect;
			}
			break; 
		}



		// ===================================================
		// sprite draw logic
		// ===================================================
		window.clear();
		// note, blocks is simply a repo of texture. 
		// should iterate through a collection of sprites, not texutres. 
		for(baseTerrain * obj : board) window.draw(obj->tileSprite);	
		window.draw(myC->tileSprite);
		
		if (curInputState == terrainInfo) window.draw(*plSprite); 

		window.display();
		
	}
	return 0;
}