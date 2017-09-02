#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Project_Constants.h"
#include "baseTerrain.cpp"
#include "baseUnit.cpp"
#include "baseGFX.cpp"
#include "infantry.cpp"
#include "tank.cpp"
#include "plane.cpp"
#include "plainTerrain.cpp"
#include "mountTerrain.cpp"
#include "roadTerrain.cpp"
#include "waterTerrain.cpp"
#include "moveGrid.cpp"
#include "cursor.cpp"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filereadstream.h"
#include <SFML/Graphics.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>

#define WIDTH 384
#define HEIGHT 352
//recent update - cleaned up userinput and leveraged cursor attached cooldown mechanism to the uinput handling
//todo - finish PoC on infantry unit 
//	> attache the unit to the board properly and move it on the board.
//	> develop a pathfinding algorithm
//	> implement a [move unit] functionality
//	> transition PoC to a Systematic scheme. to be added to the board
//
//todo - work on an x,y tracking schema - leverag the same back, cur (x,y) scheme, but abstract to a higher layer of client GUI
//	> keep the core game logic data to a minimum
//todo - work on a content pipeline leveraging a json
//	> develop the core functional logic than transition to an appropriate place after some thought. 
//todo - work on statemachine to toggle between user_input options (in game only)
//	>initial PoC accomplished, looking promising
//todo - draft and demo display objects for terrain information 
//personal notes - migrate newGame to an instantiable client object that can sync with a Server.

using namespace rapidjson;

//needs to move somewhere, not allowing classwide vars in this class. 
uint64_t height = 0;
uint64_t width = 0;

//given a cursors raw x,y coord. extrapolate which slot of the board container is associated with the cursors pos. 
uint64_t getBSlot(uint64_t posX_, uint64_t posY_) {
	uint64_t scaledX, scaledY;
	scaledX = posX_/tilesize_const;
	scaledY = posY_/tilesize_const;
	return ((scaledY*width) + scaledX);

}

//foo 
//prototyping function
//provides initial content load of terrain art assetts

enum inputState {terrainSelect, terrainInfo, unitInfo, unitSelected};

void foo(std::vector<sf::Texture *>& text_container, std::string textType_) {
	uint32_t numTexts = 0;
	std::string texturePath = "textures/";
	texturePath += textType_;
	if (textType_ == "plain" ) numTexts = maxTerrain_const; 
	else if (textType_ == "unit" ) numTexts = maxUnit_const; 
	else return;
	for (int i = 0 ; i < numTexts; i++) {
		std::string textName = texturePath + std::to_string(i)  + ".png";
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
	const Value& h = doc["height"];
	const Value& w = doc["width"];

	assert(data.IsArray());
	assert(h.IsInt());
	assert(w.IsInt());
	
	std::cout << "data is read\n";
	std::cout << data.Size() << std::endl;
	std::cout << "height is: " << h.GetInt() << std::endl;
	std::cout << "width is: " << w.GetInt() << std::endl;
	height = h.GetInt();
	width = w.GetInt();
	int count=0;
	for(int i = 0; i < h.GetInt(); i++) {
		for (int j = 0; j < w.GetInt(); j++) {
			switch(data[count].GetInt()){
				case plainTerrain_const :
					board_.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
					break;
				case mountTerrain_const :
					board_.push_back(new mountTerrain(terrainTexts[mountTerrain_const]));
					break;
				case waterTerrain_const :
					board_.push_back(new waterTerrain(terrainTexts[waterTerrain_const]));
					break;
				case roadTerrain_const :
					board_.push_back(new roadTerrain(terrainTexts[roadTerrain_const]));
					break;
				case forestTerrain_const :
					board_.push_back(new mountTerrain(terrainTexts[mountTerrain_const]));
					break;
			}
			board_[count]->tileSprite.setPosition(j*tilesize_const, i*tilesize_const);
			board_[count]->setUnitSize(tilesize_const);
			board_[count]->setGridPos(j, i);

			count++;
		}
	}
}

baseUnit * unitBuilder(std::vector<sf::Texture*>& unitTexts_, uint32_t unit_ ) {
	switch(unit_){
		case infantryUnit_const :
			return new infantry(unitTexts_[infantryUnit_const]);

		case tankUnit_const  :
			return new tank(unitTexts_[tankUnit_const]);
		case planeUnit_const :
			return new plane(unitTexts_[planeUnit_const]);
//		case boatUnit_const :
//			return new boat(unitTexts_[boatUnit_const]);
		default : 
			break;
		}
}

int main( int argc, char** argv ) {

	// ====================
	// INITIALIZATION 
	// ====================
	///*	std::vector<baseTerrain * >*/ board = std::vector<baseTerrain *>();
	std::vector<sf::Texture *> terrainTexts = std::vector<sf::Texture *>();
	std::vector<sf::Texture *> unitTexts = std::vector<sf::Texture *>();
	baseUnit * curUnit;
	//control unit for board manipulation operations TODO[ ] move to cursor class.
	uint32_t sourceBSlot = 0;
	uint32_t destBSlot = 0;
	foo(terrainTexts, "plain");
	foo(unitTexts, "unit");
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Advance Wars Clone");
	//window.setFramerateLimit(35);
	std::chrono::milliseconds frameTrigger{35};

	//bar(board, terrainTexts);
	mapGen(board, terrainTexts);
	// testing posix_time libraries

	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds myTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(myTimer).zero();
	std::chrono::nanoseconds frameTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer).zero();
	
//CURSOR PoC --- migrate code appropriately when done demonstrating TODO [ ]
	sf::Texture * cursText = new sf::Texture();
	cursText->loadFromFile("textures/cursor.png");
	cursor * myC = new cursor(cursText);
//INFANTRY POC -- migrate code appropriately when done demonstrating TODO [X]

//GRIDSPRITE Poc -- migrate to appropriate location when finished with factory TODO[ ] 
	sf::Texture * movText = new sf::Texture();
	movText->loadFromFile("textures/moveGrid.png");
	//myI->defineGridSprite(movText);
	//now lets attach this unit to a board slot...
	baseUnit * tUnit = unitBuilder(unitTexts, infantryUnit_const);
	tUnit->defineGridSprite(movText);
	board[1]->attachUnit(tUnit);// = myI;	
//	board[1]->attachedUnit->defineGridSprite(movText);
	tUnit = unitBuilder(unitTexts, tankUnit_const);
	tUnit->defineGridSprite(movText);
	board[9]->attachUnit(tUnit);// = myI;	
//	board[9]->attachedUnit->defineGridSprite(movText);
	tUnit = unitBuilder(unitTexts, planeUnit_const);
	tUnit->defineGridSprite(movText);
	board[21]->attachUnit(tUnit);// = myI;	
//	board[21]->attachedUnit->defineGridSprite(movText);
//	board[40]->attachUnit(unitBuilder(unitTexts, planeUnit_const));// = myI;	
//	board[40]->attachedUnit->defineGridSprite(movText);
	
//	board[1]->attachedUnit->print();
//

	bool inGame = true;
	inputState curInputState(terrainSelect);

// Terrain info PoC, move to object
	sf::Texture * plainsInfo = new sf::Texture();
	plainsInfo->loadFromFile("textures/plainsInfo.png");
	sf::Sprite * plSprite = new sf::Sprite();
	plSprite->setTexture(*plainsInfo);
	plSprite->setPosition(0,0);

	while(inGame) {
		sf::Event event;	
		while (window.pollEvent(event)) {}//nop == clear the event queue buffer. 
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
//		deltaTime = now - lastCycle;
		frameTimer += myTimer = now - lastCycle;
		
 //		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime).count() << std::endl;
//		myTime += deltaTime;
		// ===================================================
		// UPDATE TIMING
		// ==================================================		
		
		myC->updateTimer(myTimer);

		// ===================================================
		// INPUT HANDLING
		// ===================================================
		//debounce input.
		if (myC->getCooldown() ) {
			switch(curInputState){
				case(terrainSelect):
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
						inGame = false;
						myC->burnCooldown();
					}	 
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
						myC->movePosX(tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
						myC->movePosX(-tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
						myC->movePosY(tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
						myC->movePosY(-tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
						curInputState = terrainInfo;
						myC->burnCooldown();
						}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && board[getBSlot(myC->posX, myC->posY)]->attachedUnit != nullptr) {
						myC->burnCooldown();
						  

						sourceBSlot = getBSlot(myC->posX, myC->posY);
						curUnit = board[sourceBSlot]->attachedUnit;
						std::cout << board[sourceBSlot]->attachedUnit->posX << std::endl;
						std::cout << myC->posX << std::endl;
						// only alter the inputState if a unit is stationed on that board slot. 
						if (curUnit != nullptr) curInputState = unitSelected;
					}				
					break;

				case(terrainInfo):
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
						curInputState = terrainSelect;
						myC->burnCooldown();
					}
					break;
				case(unitSelected):
					//s -- move unit
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {	
						destBSlot = getBSlot(myC->posX, myC->posY);
						bool valMove = board[sourceBSlot]->attachedUnit->isValMove(myC->posX, myC->posY);
						std::cout << "cursor x: " << myC->posX << std::endl;
						if ( destBSlot != sourceBSlot && valMove)  {
							board[destBSlot]->attachUnit(curUnit);
							board[sourceBSlot]->detachUnit();	
						}
						curInputState = terrainSelect; 
						myC->burnCooldown();

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
						myC->movePosX(tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
						myC->movePosX(-tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
						myC->movePosY(tilesize_const);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
						myC->movePosY(-tilesize_const);
						myC->burnCooldown();
					}
	
					//a -- exit unit with no action
					break; 
			}
		}


		// ===================================================
		// sprite draw logic
		// ===================================================
		// needs a framerate

//		if ( frameTimer >= frameTrigger)   {
//			frameTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer).zero();
		
			window.clear();
			// note, blocks is simply a repo of texture. 
			// should iterate through a collection of sprites, not texutres. 
			for(baseTerrain * obj : board) 	{
				window.draw(obj->tileSprite);
				if (obj->attachedUnit != nullptr) window.draw(obj->attachedUnit->unitSprite); 
			}
			if (curInputState == unitSelected)  {
				for(auto mGrid : *(board[sourceBSlot]->attachedUnit->validMoves)) {
					window.draw(mGrid->gFXSprite);
				}
			}

			window.draw(myC->tileSprite);
			
			if (curInputState == terrainInfo) window.draw(*plSprite); 

			window.display();
//		}
		
	}
	return 0;
}
