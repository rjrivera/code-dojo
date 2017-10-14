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
//uint64_t height = 0;
//uint64_t width = 0;

//given a cursors raw x,y coord. extrapolate which slot of the board container is associated with the cursors pos. 
uint32_t getBSlot(uint32_t posX_, uint32_t posY_) {
	uint32_t scaledX, scaledY;
	scaledX = posX_/tilesize_const;
	scaledY = posY_/tilesize_const;
	return ((scaledY*width) + scaledX);

}

int32_t getScaledPosX(uint32_t bSlot_) {
	if ( bSlot_ >= width*height || bSlot_ < 0  ) return -1;
	return ( bSlot_ % width ) * tilesize_const;

}

int32_t getScaledPosY(uint32_t bSlot_) {
	if ( bSlot_ >= width*height || bSlot_ < 0  ) return -1;
	return ( (bSlot_ + 1) / width ) * tilesize_const;
}




// must be signed to indicate when outside of bounds
int32_t getAboveBSlot(int32_t sourceBSlot) {
	return sourceBSlot - width;
}

// must be signed to indicate when outside of bounds
int32_t getBelowBSlot(int32_t sourceBSlot) {
	if ((sourceBSlot + width) > (height * width)) return -1; 
	else return (sourceBSlot + width);
}

void battle(uint32_t attackerInd_, uint32_t defenderInd_, std::vector<baseTerrain*>& board_) {
	// init stat calcs
	int32_t DefA, DefD, AtkA, AtkD, DmgA, DmgD;
	DefA = board_[attackerInd_]->defBonus + board_[attackerInd_]->attachedUnit->def;
	DefD = board_[defenderInd_]->defBonus + board_[defenderInd_]->attachedUnit->def;
	AtkA = (board_[attackerInd_]->attachedUnit->atk * board_[attackerInd_]->attachedUnit->hp) / 10;

	// attack phase
	DmgD = AtkA - ( DefD * 2);
	if (DmgD > 0 ) { 
		std::cout << "attacker deals " << DmgD << " to defender\n";
		board_[defenderInd_]->attachedUnit->hp-= DmgD;
		if (board_[defenderInd_]->attachedUnit->hp <= 0)  {
			//kill unit
			delete board_[defenderInd_]->attachedUnit;
			board_[defenderInd_]->attachedUnit = nullptr;
			std::cout << "DEFENDER DESTROYED!!!\n";
			return;
		}
	}
	else std::cout << "attacker deals zero damage\n";
	// recalc stats for defense.
	AtkD = (board_[defenderInd_]->attachedUnit->atk * board_[defenderInd_]->attachedUnit->hp) / 10;
	DmgA = AtkD - (DefA * 2);
	if (DmgA > 0 ) { 
		std::cout << "defender retaliates " << DmgA << " to attacker\n";
		board_[attackerInd_]->attachedUnit->hp-= DmgA;
		if (board_[attackerInd_]->attachedUnit->hp <= 0)  {
			//kill unit
			delete board_[attackerInd_]->attachedUnit;
			board_[attackerInd_]->attachedUnit = nullptr;
			std::cout << "ATTACKER DESTROYED!!!\n";
			return;
		}
	}
	else std::cout << "defender deals zero damage\n";
	// defense phase
}

//foo 
//prototyping function
//provides initial content load of terrain art assetts

enum inputState {terrainSelect, gameMenu, terrainInfo, unitInfo, atkSelect, unitSelected, actionMenu};
enum actionMenuState {move, atk, back};

// provide texture container you wish to populate and the texture type you wish to populate it with. 
// project_constants.h contains definitions to constants referenced here. 
void foo(std::vector<sf::Texture *>& text_container, std::string textType_) {
	uint32_t numTexts = 0;
	std::string texturePath = "textures/";
	texturePath += textType_;
	if (textType_ == "plain" ) numTexts = maxTerrain_const; 
	else if (textType_ == "unit") numTexts = (maxUnit_const * maxPlayers_const); 
	else if (textType_ == "unitInfo") numTexts = (maxUnit_const); 
	else return;
	text_container.push_back(nullptr); //needed to reconcile 1-based const nameing scheme with accessing of textures via consts.
	for (int i = 1 ; i <= numTexts; i++) {
		std::string textName = texturePath + std::to_string(i)  + ".png";
		sf::Texture * tempText = new sf::Texture();
		sf::Image * tempImg = new sf::Image();
		// loading sprite sheet to image for alpha handling
		tempImg->loadFromFile(textName);
		tempImg->createMaskFromColor(sf::Color(255,0,255),0);
		tempImg->createMaskFromColor(sf::Color(0,0xff, 0xcd),100);
		tempImg->createMaskFromColor(sf::Color(0xb8,0x00, 0x68),150);
		tempText->loadFromImage(*tempImg);
		std::cout << "pushing texture " << textName << " into container at index " << text_container.size() << std::endl;
		text_container.push_back(tempText);
	}
}

//MAPGENERATOR
//PROTOTYPING FUNCTION TODO[ ] update the json to reflect the new const scheme for terrains and remove the + 1 offset in below funct
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
				case (plainTerrain_const -1) :
					board_.push_back(new plainTerrain(terrainTexts[plainTerrain_const], terrainTexts[moveTerrain_const]));
					break;
				case (mountTerrain_const - 1) :
					board_.push_back(new mountTerrain(terrainTexts[mountTerrain_const], terrainTexts[moveTerrain_const]));
					break;
				case (waterTerrain_const - 1):
					board_.push_back(new waterTerrain(terrainTexts[waterTerrain_const], terrainTexts[moveTerrain_const]));
					break;
				case (roadTerrain_const - 1) :
					board_.push_back(new roadTerrain(terrainTexts[roadTerrain_const], terrainTexts[moveTerrain_const]));
					break;
				case (forestTerrain_const - 1) :
					board_.push_back(new mountTerrain(terrainTexts[mountTerrain_const], terrainTexts[moveTerrain_const]));
					break;
			}
				//TODO[ ] put this logic in the class...it belongs there. 
			board_[count]->tileSprite.setPosition(j*tilesize_const, i*tilesize_const);
			board_[count]->highlightSprite.setPosition(j*tilesize_const, i*tilesize_const);
			board_[count]->setUnitSize(tilesize_const);
			board_[count]->setGridPos(j, i);
			board_[count]->setAtkSprite(terrainTexts[atkTerrain_const]);
			board_[count]->atkSprite.setPosition(j*tilesize_const, i*tilesize_const);
			count++;
		}
	}
}

baseUnit * unitBuilder(std::vector<sf::Texture*>& unitTexts_, std::vector<sf::Texture*>& unitInfoTexts_,
				uint32_t unit_, uint32_t player_) {
	std::cout << "building unit for player " << player_ << std::endl;
	baseUnit * unit;
	switch(unit_){
		case infantryUnit_const :
			unit = new infantry(unitTexts_[infantryUnit_const * player_], player_);
			unit->defineUnitInfoSprite(unitInfoTexts_[infantryUnit_const]);
			return unit;
		case tankUnit_const  :
			unit = new tank(unitTexts_[tankUnit_const * player_], player_);
			unit->defineUnitInfoSprite(unitInfoTexts_[tankUnit_const]);
			return unit;
		case planeUnit_const :
			unit =  new plane(unitTexts_[planeUnit_const * player_], player_);
			unit->defineUnitInfoSprite(unitInfoTexts_[planeUnit_const]);
			return unit;
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
	std::vector<sf::Texture *> unitInfoTexts = std::vector<sf::Texture *>();
	baseUnit * curUnit;
	bool draw = false;
	//control unit for board manipulation operations TODO[ ] move to cursor class.
	uint32_t sourceBSlot = 0;
	uint32_t destBSlot = 0;
	foo(terrainTexts, "plain");
	foo(unitTexts, "unit");
	foo(unitInfoTexts, "unitInfo");
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Advance Wars Clone");
	//window.setFramerateLimit(35);
	std::chrono::milliseconds frameTrigger{70};
	
	//bar(board, terrainTexts);

	mapGen(board, terrainTexts);
	// testing posix_time libraries

	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds myTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(myTimer).zero();
	std::chrono::nanoseconds frameTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer).zero();
	
//CURSOR PoC --- migrate code appropriately when done demonstrating TODO [ ]
//sfml::Sprite uses copy constructors - leverage accordingly
	sf::Texture * cursText = new sf::Texture();
	sf::Image * cursImg = new sf::Image();
	cursImg->loadFromFile("textures/cursor.png");
	cursImg->createMaskFromColor(sf::Color(255,0,255), 0);
	cursText->loadFromImage(*cursImg);
	cursor * myC = new cursor(cursText);
	//cursor * tmpMyC = nullptr; //used to permit multi-state usage of same sprite object while tracking old
	//TODO[ ] consider a stack of tmpMyC's to track multiple layers of state machine cursor usage *like as needed for submenus.
	std::vector<cursor *> cursorStack = std::vector<cursor *>();
	for (int i = 0; i < maxMenuDepth; i++) {
		cursorStack.push_back(myC->clone());
		cursorStack[i]->stackInd = i;
	}
	myC = cursorStack[0];




//INFANTRY POC -- migrate code appropriately when done demonstrating TODO [X]

//GRIDSPRITE Poc -- migrate to appropriate location when finished with factory TODO[ ] 
	//myI->defineGridSprite(movText);
	//now lets attach this unit to a board slot...
	baseUnit * tUnit = unitBuilder(unitTexts, unitInfoTexts, infantryUnit_const, 1);
	//tUnit->defineGridSprite(movText);
	std::cout << "tUnit player num: " << tUnit->player << std::endl;
	board[1]->attachUnit(tUnit);// = myI;	
	std::cout << "unit attached\n";
	std::cout << "attached unit player num is: " << board[1]->attachedUnit->player << std::endl;
	board[1]->attachedUnit->player = 1;
	std::cout << "attached unit player num is: " << board[1]->attachedUnit->player << std::endl;
//	board[1]->attachedUnit->defineGridSprite(movText);
	tUnit = unitBuilder(unitTexts, unitInfoTexts, tankUnit_const, 1);
	//tUnit->defineGridSprite(movText);
	board[9]->attachUnit(tUnit);// = myI;	
//	board[9]->attachedUnit->defineGridSprite(movText);
	tUnit = unitBuilder(unitTexts, unitInfoTexts, planeUnit_const, 1);
	//tUnit->defineGridSprite(movText);
	board[21]->attachUnit(tUnit);// = myI;	
	tUnit = unitBuilder(unitTexts, unitInfoTexts, planeUnit_const, 2);
	board[3]->attachUnit(tUnit);	
	tUnit = unitBuilder(unitTexts, unitInfoTexts, tankUnit_const, 2);
	board[5]->attachUnit(tUnit);

	bool inGame = true;
	inputState curInputState(terrainSelect);
	actionMenuState curActionMenuState(move);
// Terrain info PoC, move to object
	sf::Texture * plainsInfo = new sf::Texture();
	plainsInfo->loadFromFile("textures/plainsInfo.png");
	sf::Sprite * plSprite = new sf::Sprite();
	plSprite->setTexture(*plainsInfo);
	plSprite->setPosition(0,0);
// actionmenu info PoC, move to object
	sf::Texture * menuInfo = new sf::Texture();
	menuInfo->loadFromFile("textures/menuInfo.png");
	sf::Sprite * actionSprite = new sf::Sprite();
	actionSprite->setTexture(*menuInfo);
	actionSprite->setPosition(0,0);
//	simple reusable vector<uint32_t> for navigating through potential enemies...great because NOW simply altering a unit's findEnemyNeighbors function. 
//	No need to declare this explicitly
	std::vector<int32_t> * enemyNeighbors;	
	int32_t enemyNeighborIndex = 0;
	while(inGame) {
		sf::Event event;	
		while (window.pollEvent(event)) {}//nop == clear the event queue buffer. 
		lastCycle = now;
		now = std::chrono::high_resolution_clock::now();
//		deltaTime = now - lastCycle;
		frameTimer += myTimer = now - lastCycle;
		
// 		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer ).count() << std::endl;


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
/*					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {

						}
*/
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) {
						if ( board[getBSlot(myC->posX, myC->posY)]->attachedUnit != nullptr ) { 
							myC->burnCooldown();
							sourceBSlot = getBSlot(myC->posX, myC->posY);
							curUnit = board[sourceBSlot]->attachedUnit;
							curInputState = unitSelected;
						//std::cout << board[sourceBSlot]->attachedUnit->posX << std::endl;
						//std::cout << myC->posX << std::endl;
						}
						// only alter the inputState if a unit is stationed on that board slot. 
						//if (curUnit != nullptr) curInputState = unitSelected;
						else {
							curInputState = terrainInfo;
							myC->burnCooldown();
						}
						
					}				
					break;

				case(terrainInfo):
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						curInputState = terrainSelect;
						myC->burnCooldown();
					}
					break;
				case(actionMenu):
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						switch(curActionMenuState) { 
							case(move) : {
								myC = cursorStack[myC->stackInd - 1];					
								myC->burnCooldown();
								destBSlot = getBSlot(myC->posX, myC->posY);
								bool valMove = board[sourceBSlot]->attachedUnit->isValMove(myC->posX, myC->posY);
							if ( destBSlot != sourceBSlot && valMove &&
									board[destBSlot]->attachedUnit == nullptr )  {
									board[destBSlot]->attachUnit(curUnit);
									board[sourceBSlot]->detachUnit();	
								 
							}
								curInputState = terrainSelect;
								break;
								}
							case(atk) : {
								// get the attack menu cursor
								myC = cursorStack[myC->stackInd + 1];
								myC->burnCooldown();
								curInputState = atkSelect;
								if (enemyNeighbors->size() == 0) {
									enemyNeighborIndex = -1;
									myC->movePosXAbs(0);
									myC->movePosYAbs(0);
								}
								else {
									enemyNeighborIndex = 0;
									uint32_t atkBSlot = enemyNeighbors->at(enemyNeighborIndex);
									int32_t absX = getScaledPosX(atkBSlot);
									int32_t absY = getScaledPosY(atkBSlot);
									if (absX >= 0 && absY >= 0) { 
										myC->movePosXAbs(absX);
										myC->movePosYAbs(absY);
										myC->burnCooldown();
									}
								}
								break;
								}
							case(back) : { 
								myC = cursorStack[myC->stackInd - 1];
								myC->burnCooldown();
								curInputState = terrainSelect;
								break;
								}
						}
						
					}				
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
						if (curActionMenuState != back ) { 
							myC->movePosY(menusize_const);
							myC->burnCooldown();
							switch(curActionMenuState) {
								case(move) :
									curActionMenuState = atk;
									break;
								case(atk) :
									curActionMenuState = back;
									break;

							}
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
						if (curActionMenuState != move ) {
							myC->movePosY(-menusize_const);
							myC->burnCooldown();
							switch(curActionMenuState) {
								case(back) :
									curActionMenuState = atk;
									break;
								case(atk) :
									curActionMenuState = move;
									break;
							}
	
						}
					}
					break;
				case(atkSelect):
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))  {
						//use the cursor's current location to calc potential attacks
						curInputState = terrainSelect;
						std::cout << "Current cursor stack index: " << myC->stackInd << std::endl;
						myC = cursorStack[myC->stackInd - 2];
						std::cout << "Moving to terrain select\n";
						std::cout << "current cursor pos: " << myC->posX << ", " << myC->posY << std::endl;
						myC->burnCooldown();
						//TODO[ ] initiate battle sequence.
	
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || 
						sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && enemyNeighborIndex >= 0) {
						

						if (enemyNeighborIndex == enemyNeighbors->size() - 1 ) enemyNeighborIndex = 0; 
						else 	enemyNeighborIndex++;
						uint32_t atkBSlot = enemyNeighbors->at(enemyNeighborIndex);
						std::cout << "atkBslot from up/right input: " << atkBSlot << std::endl;
						int32_t absX = getScaledPosX(atkBSlot);
						int32_t absY = getScaledPosY(atkBSlot);
						if (absX >= 0 && absY >= 0) { 
							myC->movePosXAbs(absX);
							myC->movePosYAbs(absY);
							myC->burnCooldown();
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
						sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && enemyNeighborIndex >= 0 ) {
						
						if (enemyNeighborIndex == 0 ) enemyNeighborIndex = enemyNeighbors->size() - 1; 
						else	enemyNeighborIndex--;

						uint32_t atkBSlot = enemyNeighbors->at(enemyNeighborIndex);
						std::cout << "atkBslot from down/left input: " << atkBSlot << std::endl;
						int32_t absX = getScaledPosX(atkBSlot);
						int32_t absY = getScaledPosY(atkBSlot);
						
						if (absX >= 0 && absY >= 0) { 
							myC->movePosXAbs(absX);
							myC->movePosYAbs(absY);
							myC->burnCooldown();
						}					
						
					}
					break; 
			case(unitSelected):
					//s -- move unit
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {	
						curUnit->findEnemyNeighbors(myC->posX, myC->posY);
						enemyNeighbors = curUnit->enemyNeighbors;
						curInputState = actionMenu;
						myC = cursorStack[myC->stackInd +1];
						myC->movePosYAbs(64);
						myC->movePosXAbs(96);
						myC->burnCooldown();
						curActionMenuState = move;
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
		// needs a framerate TODO[ ] deal with rendering killing game timing ala space Invaders. 
		// FOR TODO - consider drawing on a clock, not on a gameloop, cycle.
		if (frameTimer > frameTrigger )  {
	// 		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer ).count() << std::endl;
			frameTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer).zero();

			if (draw) draw = false;
			else draw = true;
			window.clear();
			// note, blocks is simply a repo of texture. 
			// should iterate through a collection of sprites, not texutres. 
			for(baseTerrain * obj : board) 	{
				window.draw(obj->tileSprite);
				if (obj->attachedUnit != nullptr) {
					window.draw(obj->attachedUnit->unitSprite);
					std::cout << obj->attachedUnit->spriteTimer << std::endl;
//					if (objj->attachedUnit is  ) everthing below in this else loop needs to be in the unit class. 
					obj->attachedUnit->spriteTimer++;
					if (obj->attachedUnit->spriteTimer >= obj->attachedUnit->spriteTrigger) {
						obj->attachedUnit->spriteOffset++; 
						obj->attachedUnit->spriteTimer = 0;
						obj->attachedUnit->unitSprite.setTextureRect(sf::IntRect(obj->attachedUnit->spriteOffset*16, 0, 16, 16));
						if (obj->attachedUnit->spriteOffset == obj->attachedUnit->numSprites)  {
							obj->attachedUnit->spriteOffset = 0;
						}
					}
				}
			}
			//TODO[ ] this is apparently a resource hog. must develop a way to draw all pixels EXACTLY ONCE or a make foreground draw far less. 
			//use 'draw' for things you want to use even/odd drawing to reduce load. 
			if (curInputState == unitSelected )  {

				for(uint32_t mGrid : *(board[sourceBSlot]->attachedUnit->validMoves)) {
					window.draw(board[mGrid]->highlightSprite);
					if (board[mGrid]->attachedUnit != nullptr) window.draw(board[mGrid]->attachedUnit->unitSprite); 
				}
			}
			window.draw(myC->tileSprite);
			
			if (curInputState == terrainInfo) window.draw(*plSprite); 
			if (curInputState == actionMenu || curInputState == atkSelect) {
				window.draw(cursorStack[myC->stackInd-1]->tileSprite);
				for(uint32_t mGrid : *(board[sourceBSlot]->attachedUnit->validMoves)) {
					window.draw(board[mGrid]->highlightSprite);
					if (board[mGrid]->attachedUnit != nullptr) window.draw(board[mGrid]->attachedUnit->unitSprite); 
				}
				for(uint32_t atkGrid : *(curUnit->enemyNeighbors)) {
					window.draw(board[atkGrid]->atkSprite);
				}
				window.draw(*actionSprite); 
				window.draw(myC->tileSprite);
				if (curInputState == atkSelect && enemyNeighborIndex >= 0) window.draw(board[enemyNeighbors->at(enemyNeighborIndex)]->attachedUnit->unitInfoSprite); 
			}

			window.display();
		}
		else draw = true;
		
	}
	return 0;
}
