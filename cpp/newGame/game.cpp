#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Project_Constants.h"
#include "Command_Catalogue.h"
#include "baseTerrain.cpp"
#include "baseUnit.cpp"
#include "baseGFX.cpp"
#include "infantry.cpp"
#include "tank.cpp"
#include "plane.cpp"
#include "dash_hby.cpp"
#include "plainTerrain.cpp"
#include "mountTerrain.cpp"
#include "barracksTerrain.cpp"
#include "roadTerrain.cpp"
#include "waterTerrain.cpp"
#include "moveGrid.cpp"
#include "cursor.cpp"
#include "ui_hby.cpp"
#include "gameState.cpp"
#include "clientState.cpp"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <SFML/Graphics.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>
// [ ] manage player turns
// [] NEXT TODO -- finish the attackSelect mode. 
#define WIDTH 768 // formerly 384
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
/*
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
*/

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

//enum inputState {terrainSelect, gameMenu, terrainInfo, unitInfo, atkSelect, unitSelected, actionMenu};


// provide texture container you wish to populate and the texture type you wish to populate it with. 
// project_constants.h contains definitions to constants referenced here. 
// foo is the Proof of concept for a content loader that can be generalized into an object class and instantiated once per client. 
void foo(std::vector<sf::Texture *>& text_container, std::string textType_) {
	uint32_t numTexts = 0;
	std::string texturePath = "textures/";
	texturePath += textType_;
	if (textType_ == "plain" ) numTexts = maxTerrain_const; 
	else if (textType_ == "unit") numTexts = (maxUnit_const * maxPlayers_const); 
	else if (textType_ == "unitInfo") numTexts = (maxUnit_const); 
	else if (textType_ == "terrainInfo") numTexts = maxTerrain_const; 
	else if (textType_ == "ui") numTexts = (maxUI_const); 
	else if (textType_ == "dash") numTexts = (maxDash_const); 
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
void mapGen(gameState * gState_, std::vector<sf::Texture*>& terrainTexts, std::vector<sf::Texture*>& terrainInfoTexts_, const char * mapName) {
//std::vector<baseTerrain *>& board_, std::vector<sf::Texture*>& terrainTexts, const char * mapName) {
	FILE* fp = fopen(mapName, "rb");
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
	gState_->height = h.GetInt();
	gState_->width = w.GetInt();
	height = gState_->height; // TODO[ ] migrate the height and width out of the Project Constants.h
	width  = gState_->width;
	std::vector<baseTerrain *> * board_ = gState_->board;
	int count=0;
	// DESIGN TODO: Until a mechanism is designed to handle and manage all textures (like a content loader) all objects using textures must be passed a pointer at
        // construction
	for(int i = 0; i < h.GetInt(); i++) {
		for (int j = 0; j < w.GetInt(); j++) {
			switch(data[count].GetInt()){
				case (plainTerrain_const -1) :
					gState_->board->push_back(new plainTerrain(terrainTexts[plainTerrain_const], terrainTexts[moveTerrain_const], terrainInfoTexts_[plainTerrain_const]));
					break;
				case (mountTerrain_const - 1) :
					gState_->board->push_back(new mountTerrain(terrainTexts[mountTerrain_const], terrainTexts[moveTerrain_const], terrainInfoTexts_[mountTerrain_const]));
					break;
				case (waterTerrain_const - 1):
					gState_->board->push_back(new waterTerrain(terrainTexts[waterTerrain_const], terrainTexts[moveTerrain_const], terrainInfoTexts_[waterTerrain_const]));
					break;
				case (roadTerrain_const - 1) :
					gState_->board->push_back(new roadTerrain(terrainTexts[roadTerrain_const], terrainTexts[moveTerrain_const], terrainInfoTexts_[roadTerrain_const]));
					break;
				case (forestTerrain_const - 1) :
					gState_->board->push_back(new mountTerrain(terrainTexts[mountTerrain_const], terrainTexts[moveTerrain_const], terrainInfoTexts_[forestTerrain_const]));
					break;
				case (barracksTerrain_const - 1) :
					gState_->board->push_back(new barracksTerrain(terrainTexts[barracksTerrain_const], terrainTexts[barracksTerrain_const], terrainInfoTexts_[barracksTerrain_const]));
					gState_->buildings->at(0)->push_back( gState_->board->back() );
					break;
				case (barracks1Terrain_const - 1) :
					gState_->board->push_back(new barracksTerrain(terrainTexts[barracks1Terrain_const], terrainTexts[barracks1Terrain_const], terrainInfoTexts_[barracksTerrain_const]));
					gState_->board->back()->owner = 1;
					gState_->buildings->at(1)->push_back( gState_->board->back() );
					break;
				case (barracks2Terrain_const - 1) :
					gState_->board->push_back(new barracksTerrain(terrainTexts[barracks2Terrain_const], terrainTexts[barracks2Terrain_const], terrainInfoTexts_[barracksTerrain_const]));
					gState_->board->back()->owner = 2;
					gState_->buildings->at(2)->push_back( gState_->board->back() );
					break;
				default:
					gState_->board->push_back(new mountTerrain(terrainTexts[mountTerrain_const], terrainTexts[moveTerrain_const], terrainInfoTexts_[mountTerrain_const]));
					break;
			}
				//TODO[ ] put this logic in the class...it belongs there. 
			gState_->board->at(count)->tileSprite.setPosition(j*tilesize_const, i*tilesize_const);
			gState_->board->at(count)->highlightSprite.setPosition(j*tilesize_const, i*tilesize_const);
			gState_->board->at(count)->setUnitSize(tilesize_const);
			gState_->board->at(count)->setGridPos(j, i);
			gState_->board->at(count)->setAtkSprite(terrainTexts[atkTerrain_const]);
			gState_->board->at(count)->atkSprite.setPosition(j*tilesize_const, i*tilesize_const);
			std::cout << "built board unit #: " << count << std::endl;
			count++;
		}
	}
}

// leverage the configurations set in config, parse and load engine ui datastructures here. 

void createUIElements( std::vector< std::vector< ui_hby * > * > * stateUIRoot, std::vector< sf::Texture * >& ui_textures ) {
	// define sentinel
	//// sf::Sprite tileSprite;
	// std::vector<ui_hby *> subMenus;
	ui_hby * sentinel = new ui_hby( ui_textures[1] ); // will not leave magic number, migrate to a more valid scheme when ui is a focus
	
	// walk the configuration file (implied) tree. failure to properly  name config files runs risk of 
	// improper configuration
	// ui_actionMenu_0_0.json	
	

	// I'm taking creative control and iterating over enums because I want to :)
	//
//enum inputState {terrainSelect, gameMenu, terrainInfo, unitInfo, atkSelect, unitSelected, actionMenu, lastEnum};
	std::string configFile = "";
	int maxUIDepth = 1; // determin how to encode this in the ui configs.  
	for( uint32_t state = terrainSelect; state != lastEnum; state++ )
	{
		switch( state ) {
			case terrainSelect :
				std::cout << "building ui terrainSelect -- " << terrainSelect << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				break;	
			case gameMenu :
				std::cout << "building ui gameMenu" << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				break;
			case terrainInfo :
				std::cout << "building ui terrainInfo" << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				break;
			case unitInfo :
				std::cout << "building ui unitInfo" << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				break;
			case atkSelect :
				std::cout << "building ui atkSelect" << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				break;
			case unitSelected :
				std::cout << "building ui unitSelected" << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				break;
			case actionMenu :
				std::cout << "building ui actionMenu -- " << actionMenu << std::endl;
				stateUIRoot->push_back( new std::vector< ui_hby * >() );
				for( int depth = 0; depth < maxUIDepth; depth++ )
				{			
					configFile = "config/ui_actionMenu_";// guarenteed to be supplied to engine. 
					configFile += std::to_string(depth) + "_0.json";//root must be present if children specified. 
					// process guarenteed first child
					std::cout << configFile << std::endl;
					const char * curConfig = configFile.c_str();
					FILE* fp = fopen(curConfig, "rb");
					char readBuffer[65536];
					FileReadStream is(fp, readBuffer, sizeof(readBuffer));
					Document doc;
					doc.ParseStream(is);	
					fclose(fp);

					// Using a reference for consecutive access is handy and faster
					const Value& childrenConfigs 	= doc["childrenConfigs"];
					const Value& height		= doc["height"];
					const Value& width		= doc["width"];
					const Value& leaves		= doc["leaves"];
//					int siblings	= childrenConfigs.size();
					

//					assert(rootParams.IsArray());
					assert(width.IsInt());
					assert(height.IsInt());
					assert(childrenConfigs.IsArray());
					assert(leaves.IsArray());
			
					// do work [ fence ]					
					// begin linking the static assets for the ui based off configuration information.
					// generate a single ui_hby as encoded from the .json
//					board_.push_back(new plainTerrain(terrainTexts[plainTerrain_const], terrainTexts[moveTerrain_const]));
					for( int i = 0; i < leaves.Size(); i++) {
						std::cout << "spawning new leaf" << std::endl;
						std::cout << "new leaf png const -- " << leaves[ i ].GetInt() << std::endl;
						stateUIRoot->at(actionMenu)->push_back( new ui_hby( ui_textures[ leaves[ i ].GetInt() ] ) );
						stateUIRoot->at(actionMenu)->back()->setPosition(depth*width.GetInt(), i*height.GetInt());
						stateUIRoot->at(actionMenu)->back()->command = leaves[ i ].GetInt();
						std::cout << "currently made leaf's command enum: " << std::endl;
					}
//					for( uint32_t sibling = 1; sibling < siblings; sibling++ ) {
//						configFile = "config/ui_actionMenu_";
//					}
				}
				break;
			case lastEnum :
				std::cout << "valmorfigation complete" << std::endl;
				break;
			default :
				std::cout << "something broke in ui generation\n";			
		}

	}

}

baseUnit * unitBuilder(std::vector<sf::Texture*>& unitTexts_, std::vector<sf::Texture*>& unitInfoTexts_,
				uint32_t unit_, uint32_t player_) {
	std::cout << "\nbuilding unit for player " << player_ << std::endl;
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
	std::vector< sf::Texture * > terrainTexts 	= std::vector< sf::Texture * >();
	std::vector< sf::Texture * > terrainInfoTexts 	= std::vector< sf::Texture * >();
	std::vector< sf::Texture * > unitTexts 		= std::vector< sf::Texture * >();
	std::vector< sf::Texture * > unitInfoTexts 	= std::vector< sf::Texture * >();
	std::vector< sf::Texture * > uiTexts 		= std::vector< sf::Texture * >();
	std::vector< std::vector< ui_hby * > * > * uiElements 	= new std::vector< std::vector< ui_hby * > * >();
	gameState * gState = new gameState();
	std::cout << "GSTATES CURPLAYER: " << gState->curPlayer << std::endl;


	baseUnit * curUnit;
	bool draw = false;
	//control unit for board manipulation operations TODO[ ] move to cursor class.
	int curUI = 0;
	foo(terrainTexts, "plain");
	foo(terrainInfoTexts, "terrainInfo");
	foo(unitTexts, "unit");
	foo(unitInfoTexts, "unitInfo");
	foo(uiTexts, "ui");
	createUIElements( uiElements, uiTexts );
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Advance Wars Clone");
	//window.setFramerateLimit(35);
	std::chrono::milliseconds frameTrigger{70};
	
	//bar(board, terrainTexts);

	mapGen(gState, terrainTexts, terrainInfoTexts, "map2.json");
	std::cout << "current size of the gState board " << gState->board->size() << std::endl;
	//board = *(gState->board); // testing this is done correctly before further migrating. 
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
	//std::vector<cursor *> cursorStack = std::vector<cursor *>();
	clientState * cState = new clientState();
	cState->cursorStack = new std::vector<cursor *>();
	for (int i = 0; i < maxMenuDepth; i++) {
		cState->cursorStack->push_back(myC->clone());
		cState->cursorStack->at(i)->stackInd = i;
	}
	myC = cState->cursorStack->front();

	bool inGame, menu, prototype, engineLive;
	inGame = menu = prototype = engineLive = false;
	inGame = engineLive = true;

	//GRIDSPRITE Poc -- migrate to appropriate location when finished with factory TODO[ ] 
	//myI->defineGridSprite(movText);
	//now lets attach this unit to a board slot...
	baseUnit * tUnit = unitBuilder(unitTexts, unitInfoTexts, tankUnit_const, 1);
	//tUnit->defineGridSprite(movText);
	//std::cout << "tUnit player num: " << tUnit->player << std::endl;
	gState->board->at(1)->attachUnit(tUnit, gState->board);	
//	gState->board->at(1)->attachedUnit->player = 1;
	tUnit = unitBuilder(unitTexts, unitInfoTexts, infantryUnit_const, 1);
	gState->board->at(9)->attachUnit(tUnit, gState->board);
//	tUnit = unitBuilder(unitTexts, unitInfoTexts, planeUnit_const, 1);
//	gState->board->at(21)->attachUnit(tUnit, gState->board);
//	tUnit = unitBuilder(unitTexts, unitInfoTexts, planeUnit_const, 2);
//	gState->board->at(3)->attachUnit(tUnit, gState->board);	
	tUnit = unitBuilder(unitTexts, unitInfoTexts, tankUnit_const, 2);
	gState->board->at(5)->attachUnit(tUnit, gState->board);
	tUnit = unitBuilder(unitTexts, unitInfoTexts, tankUnit_const, 2);
	gState->board->at(6)->attachUnit(tUnit, gState->board);


//	inputState cState->curInputState(terrainSelect);
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
//	std::vector<int32_t> * enemyNeighbors;	
//	int32_t enemyNeighborIndex = 0;

	cState->myC = myC;
	cState->curInputState = terrainSelect;
	// build out the games representation of the ui. 
	// it will be a state machine. 


	while( inGame)
	{

		// main game ui navigation. 
		// should be viewed as an in-engine data manipulater and configuration. 
/*
		if( menu )
		{
			
			prototype = true;
			menu = false;
		}
		
		if( prototype )
		{

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


			inputState cState->curInputState(terrainSelect);
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



			prototype = false;
			engineLive = true;
		}
*/
		if( engineLive ) 
		{
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
			
			cState->myC->updateTimer(myTimer);

			// ===================================================
			// INPUT HANDLING
			// ===================================================
			//debounce input.
			if (cState->myC->getCooldown() ) {
				switch(cState->curInputState){
					case(terrainSelect):
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
							engineLive 	= false;
							inGame 		= false;
							cState->myC->burnCooldown();
						}	 
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
							cState->myC->movePosX(tilesize_const);
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
							cState->myC->movePosX(-tilesize_const);
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
							cState->myC->movePosY(tilesize_const);
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
							cState->myC->movePosY(-tilesize_const);
							cState->myC->burnCooldown();
						}
	/*					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {

							}
	*/
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) {

							// check if unit occupies that slot...AND if it's the current players unit you can do stuff...
							// BUT if a non-current players unit, can be reviewed for intelligence purposes...
							int bSlot = getBSlot( cState->myC->posX, cState->myC->posY);
							if ( gState->board->at(getBSlot(cState->myC->posX, cState->myC->posY))->attachedUnit != nullptr ) { 
								std::cout << gState->board->at( bSlot )->attachedUnit->player << " board player " << gState->curPlayer << std::endl;
								if( gState->board->at( bSlot )->attachedUnit->player == gState->curPlayer ) {
								cState->myC->burnCooldown();
								cState->sourceBSlot = getBSlot(cState->myC->posX, cState->myC->posY);
								curUnit = gState->board->at(cState->sourceBSlot)->attachedUnit;
								cState->curInputState = unitSelected;
								}
								else{
									cState->curInputState = terrainInfo;
									cState->sourceBSlot = getBSlot(cState->myC->posX, cState->myC->posY);
									cState->myC->burnCooldown();
								}
							//std::cout << board[cState->sourceBSlot]->attachedUnit->posX << std::endl;
							//std::cout << cState->myC->posX << std::endl;
							}
							// only alter the inputState if a unit is stationed on that board slot. 
							//if (curUnit != nullptr) cState->curInputState = unitSelected;
							else { // terrainInfo should be keyed based on the tile information...
								cState->curInputState = terrainInfo;
								cState->sourceBSlot = getBSlot(cState->myC->posX, cState->myC->posY);
								cState->myC->burnCooldown();
							}
							
						}				
						break;

					case(terrainInfo):
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
							cState->curInputState = terrainSelect;
							cState->myC->burnCooldown();
						}
						break;
					case(actionMenu):
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
							switch(curActionMenuState) { 
								case(move) : {
									// pop cursor stack to revert back to the location it was on the menu...	
									cState->myC = cState->cursorStack->at(cState->myC->stackInd - 1);
									// 
									cState->selectedUnit  = curUnit;
									// feed the ui to negotiate the actions...given the gState and cState...
									// introduce a if(...) to react oin bad attempts...or not...uiElements might handle this...
									uiElements->at(actionMenu)->at(curUI)->uiAction( gState, cState );
									
									//cmdMove( gState, cState->myC, cState->curInputState, curUnit, cState->destBSlot, cState->sourceBSlot );
/*
									cState->myC = cursorStack[cState->myC->stackInd - 1];					
									cState->myC->burnCooldown();
									cState->destBSlot = getBSlot(cState->myC->posX, cState->myC->posY);
									bool valMove = gState->board->at(cState->sourceBSlot)->attachedUnit->isValMove(cState->myC->posX, cState->myC->posY);
								if ( cState->destBSlot != cState->sourceBSlot && valMove &&
										gState->board->at(cState->destBSlot)->attachedUnit == nullptr )  {
										gState->board->at(cState->destBSlot)->attachUnit(curUnit, gState->board);
										gState->board->at(cState->sourceBSlot)->detachUnit();	
									 
								}
									cState->curInputState = terrainSelect;
*/

									break;
									}
								case(atkUI) : {
									cState->myC = cState->cursorStack->at(cState->myC->stackInd - 1);
									cState->selectedUnit = curUnit;
									uiElements->at(actionMenu)->at(curUI)->uiAction( gState, cState );
									std::cout << "atkUI selected\n";
									// get the attack menu cursor
									/*
									cState->myC = cursorStack[cState->myC->stackInd + 1];
									cState->myC->burnCooldown();
									cState->curInputState = atkSelect;
									if (enemyNeighbors->size() == 0) {
										enemyNeighborIndex = -1;
										cState->myC->movePosXAbs(0);
										cState->myC->movePosYAbs(0);
									}
									else {
										enemyNeighborIndex = 0;
										uint32_t atkBSlot = enemyNeighbors->at(enemyNeighborIndex);
										int32_t absX = getScaledPosX(atkBSlot);
										int32_t absY = getScaledPosY(atkBSlot);
										if (absX >= 0 && absY >= 0) { 
											cState->myC->movePosXAbs(absX);
											cState->myC->movePosYAbs(absY);
											cState->myC->burnCooldown();
										}
									}*/
									break;
									}
								case(back) : { 
									cState->myC = cState->cursorStack->at(cState->myC->stackInd - 1);
									cState->selectedUnit  = curUnit;
									uiElements->at(actionMenu)->at(curUI)->uiAction( gState, cState );
//									cState->myC->burnCooldown();
//									cState->curInputState = terrainSelect;
									break;
									}

							}
							
						}				
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
							if (curUI < uiElements->at(actionMenu)->size() - 1 ) { // I need to update this to be based off of the ui_hby data structure. 
								curUI++;
								cState->myC->movePosYAbs(uiElements->at(actionMenu)->at(curUI)->getY());
								cState->myC->burnCooldown();
								switch(curActionMenuState) { // for now do this...migrate action to ui_hby class. 
									case(move) :
										curActionMenuState = atkUI;
										break;
									case(atkUI) :
										curActionMenuState = back;
										break;
								}
							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
							if (curUI > 0) {
								curUI--;
								cState->myC->movePosYAbs(uiElements->at(actionMenu)->at(curUI)->getY());
								cState->myC->burnCooldown();
								switch(curActionMenuState) {
									case(back) :
										curActionMenuState = atkUI;
										break;
									case(atkUI) :
										curActionMenuState = move;
										break;
								}
							}
						}
						break;
					case(atkSelect):
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
							if( cState->enemyNeighborsIndex < cState->selectedUnit->enemyNeighbors->size() - 1 ) {
								cState->enemyNeighborsIndex++;
							}
							else cState->enemyNeighborsIndex = 0;
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
							if( cState->enemyNeighborsIndex < cState->selectedUnit->enemyNeighbors->size() - 1 ) {
								cState->enemyNeighborsIndex++;
							}
							else cState->enemyNeighborsIndex = 0;
							cState->myC->burnCooldown();
							
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
							if( cState->enemyNeighborsIndex > 0 ) {//<  ) {
								cState->enemyNeighborsIndex--;
							}
							else cState->enemyNeighborsIndex = cState->selectedUnit->enemyNeighbors->size() - 1;
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
							if( cState->enemyNeighborsIndex > 0 ) {//<  ) {
								cState->enemyNeighborsIndex--;
							}
							else cState->enemyNeighborsIndex = cState->selectedUnit->enemyNeighbors->size() - 1;
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) {
							if( cmdAtk( gState, cState ) ) gState->incrementPlayer();
						}
						cState->myC->movePosXAbs( getScaledPosX((uint32_t)cState->selectedUnit->enemyNeighbors->at( cState->enemyNeighborsIndex )) ); 
						cState->myC->movePosYAbs( getScaledPosY((uint32_t)cState->selectedUnit->enemyNeighbors->at( cState->enemyNeighborsIndex )) ); 


/*
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))  {
							//use the cursor's current location to calc potential attacks
							cState->curInputState = terrainSelect;
							std::cout << "Current cursor stack index: " << cState->myC->stackInd << std::endl;
							cState->myC = cursorStack[cState->myC->stackInd - 2];
							std::cout << "Moving to terrain select\n";
							std::cout << "current cursor pos: " << cState->myC->posX << ", " << cState->myC->posY << std::endl;
							cState->myC->burnCooldown();
							//TODO[ ] initiate battle sequence.
		
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || 
							sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) { //&& enemyNeighborIndex >= 0) {
							

							if (enemyNeighborIndex == enemyNeighbors->size() - 1 ) enemyNeighborIndex = 0; 
							else 	enemyNeighborIndex++;
							uint32_t atkBSlot = enemyNeighbors->at(enemyNeighborIndex);
							std::cout << "atkBslot from up/right input: " << atkBSlot << std::endl;
							int32_t absX = getScaledPosX(atkBSlot);
							int32_t absY = getScaledPosY(atkBSlot);
							if (absX >= 0 && absY >= 0) { 
								cState->myC->movePosXAbs(absX);
								cState->myC->movePosYAbs(absY);
								cState->myC->burnCooldown();
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
								cState->myC->movePosXAbs(absX);
								cState->myC->movePosYAbs(absY);
								cState->myC->burnCooldown();
							}					
							
						}
*/
						break; 

					case(unitSelected):
						//s -- move unit
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {	
							curUnit->findEnemyNeighbors(cState->myC->posX, cState->myC->posY, gState->board);
							curUnit->enemyNeighbors;
							cState->curInputState = actionMenu;
							cState->myC = cState->cursorStack->at( cState->myC->stackInd +1 );
							curUI = 0;
							cState->myC->movePosYAbs(uiElements->at(actionMenu)->at(curUI)->getY());
							cState->myC->movePosXAbs(uiElements->at(actionMenu)->at(curUI)->getX());
							cState->myC->burnCooldown();
							curActionMenuState = move;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
							cState->myC->movePosX(tilesize_const);
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
							cState->myC->movePosX(-tilesize_const);
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
							cState->myC->movePosY(tilesize_const);
							cState->myC->burnCooldown();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
							cState->myC->movePosY(-tilesize_const);
							cState->myC->burnCooldown();
						}
		
						//a -- exit unit with no action
						break; 
		
				}
			}
	// 		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer ).count() << std::endl;
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
				for(baseTerrain * obj : *(gState->board)) 	{
					window.draw(obj->tileSprite);
					if (obj->attachedUnit != nullptr) {
						window.draw(obj->attachedUnit->unitSprite);
	//					std::cout << obj->attachedUnit->spriteTimer << std::endl;
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
				if (cState->curInputState == unitSelected )  {
					for(uint32_t mGrid : *(gState->board->at(cState->sourceBSlot)->attachedUnit->validMoves)) {
						window.draw(gState->board->at(mGrid)->highlightSprite);
						if (gState->board->at(mGrid)->attachedUnit != nullptr) window.draw(gState->board->at(mGrid)->attachedUnit->unitSprite); 
					}
				}
				if (cState->curInputState == atkSelect) {
					for(int32_t atkGrid : *(cState->selectedUnit->enemyNeighbors)) {
						window.draw(gState->board->at(atkGrid)->atkSprite);
					}
				}
				window.draw(cState->myC->tileSprite);
				
				if (cState->curInputState == terrainInfo) {
	//				window.draw(*plSprite); 
					window.draw(gState->board->at(cState->sourceBSlot)->infoSprite); 
				}
				if (cState->curInputState == actionMenu ) {//|| cState->curInputState == atkSelect) {
					window.draw(cState->cursorStack->at( cState->myC->stackInd-1 )->tileSprite);
					for(uint32_t mGrid : *(gState->board->at(cState->sourceBSlot)->attachedUnit->validMoves)) {
						window.draw(gState->board->at(mGrid)->highlightSprite);
						if (gState->board->at(mGrid)->attachedUnit != nullptr) window.draw(gState->board->at(mGrid)->attachedUnit->unitSprite); 
					}
//					window.draw(*actionSprite); 
					for(ui_hby * ui : *(uiElements->at(cState->curInputState)) ) {
						window.draw(ui->tileSprite);					
					}
					window.draw(cState->myC->tileSprite);
//					if (cState->curInputState == atkSelect && enemyNeighborIndex >= 0) window.draw(gState->board->at(enemyNeighbors->at(enemyNeighborIndex))->attachedUnit->unitInfoSprite); 
				}

				window.display();
			}
			else draw = true;
		} // < brace is for if( engineLive )		
	//	if( inGame ) std::cout << "inGame\n";
	}
	return 0;
}
