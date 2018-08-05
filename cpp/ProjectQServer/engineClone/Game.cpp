#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Project_Constants.h"
#include "baseUnit.cpp"
#include "baseGFX.cpp"
#include "don.cpp"
#include "foot.cpp"
#include "bebop.cpp"
#include "rockSteady.cpp"
#include "bckTerrain.cpp"
#include "hitBox.cpp"
#include "projectile.cpp"
#include "starProj.cpp"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <cstdlib>
#include "Point.h"
#include "Game.h"


// TODO[ ]  backgroung objects need to be revisit, right now tiles need to be preloaded before building world. 

// major todo[ ]  migrate input handling to objects, not client - client just interfaces between input device and objects. 
// enum actionMenuState {move, atk, back}; keeping for reference
// I want this server to receive packets and use said packets as inputs 
// First - I need to prepare a means for listening.
// preconditiohn - all containers must start with a nullpointer
void Game::foo(std::vector<sf::Texture *>& text_container, std::string textType_) {
	uint32_t numTexts = 0;
	std::string texturePath = "textures/";
	texturePath += textType_;
	if (textType_ == "plain" ) numTexts = maxTerrain_const; 
	else if (textType_ == "turtle" ) numTexts = (maxUnit_const); 
	else if (textType_ == "foot" ) numTexts = (maxUnit_const); 
	else if (textType_ == "bebop" ) numTexts = (maxUnit_const); 
	else if (textType_ == "rockSteady" ) numTexts = (maxUnit_const); 
	else if (textType_ == "proj" ) numTexts = (maxProj_const); 
	else return;

	for (int i = 1 ; i <= numTexts; i++) {	
		char stateSprite = 'a';
		for (int j = 0; j < maxUnitState_const; j++) {
			std::string state(1,stateSprite);
			std::string textName = texturePath + std::to_string(i)  + state + ".png";
			sf::Image * tempImg = new sf::Image();
			tempImg->loadFromFile(textName);
			tempImg->createMaskFromColor(sf::Color(255,0,255),0);	
			sf::Texture * tempText = new sf::Texture();
			tempText->loadFromImage(*tempImg);
			std::cout << "pushing texture " << textName << " into container at index " << text_container.size() << std::endl;
			text_container.push_back(tempText);
			stateSprite++;
		}
	}
}

baseUnit * Game::unitBuilder(std::vector<sf::Texture*>& unitTexts_, uint32_t unit_) {
	std::cout << " attempting to build a unit\n";
	std::vector<const sf::Texture *> textures = std::vector<const sf::Texture *>();
	switch(unit_){
		case donUnit_const :

			// rev up those fryers
			for (uint32_t i = 1; i <= maxUnitState_const; i++) textures.push_back(unitTexts_[donUnit_const*i]);

			std::cout << " don textures loaded in vector\n";
			return new don(textures);
			break;
		case footPurpUnit_const :

			// rev up those fryers
			for (uint32_t i = 1; i <= maxUnitState_const; i++) textures.push_back(unitTexts_[i + (footPurpUnit_const-1)*maxUnitState_const]);

			std::cout << "foot textures loaded in vector\n";
			return new foot(textures);
			break;
		case bebopUnit_const :

			// rev up those fryers
			for (uint32_t i = 1; i <= maxUnitState_const; i++) textures.push_back(unitTexts_[i + (bebopUnit_const-1)*maxUnitState_const]);

			std::cout << "bebop textures loaded in vector\n";
			return new bebop(textures);
			break;
		case rockSteadyUnit_const :

			// rev up those fryers
			for (uint32_t i = 1; i <= maxUnitState_const; i++) textures.push_back(unitTexts_[i + (rockSteadyUnit_const-1)*maxUnitState_const]);

			std::cout << "rockSteady textures loaded in vector\n";
			return new rockSteady(textures);
			break;
		default : 
			break;
		}

	return nullptr;
}

//potential repurpose -- create a similar process for the bckTerrain
projectile * Game::projBuilder(std::vector<sf::Texture*>& projTexts_, uint32_t unit_) {
	std::cout << " attempting to build a proj\n";
	std::vector<const sf::Texture *> textures = std::vector<const sf::Texture *>();
	switch(unit_){
		case starProj_const :

			// rev up those fryers
			for (uint32_t i = 1; i <= maxProjState_const; i++) textures.push_back(projTexts_[starProj_const*i]);

			std::cout << " ninja star textures loaded in vector\n";
			return new starProj(textures); //maek this the base...then make new projectiels becaues... there will be others. 
			break;
		default : 
			break;
		}
	return nullptr;
}


bckTerrain * Game::worldBuilder(std::vector<sf::Texture*>& worldTexts_, uint32_t bkg_, Point tL_, Point bR_) {
	std::cout << " attempting to build a Terrain object\n";
	// do we create vis effects for backTerain? no
	bckTerrain * tempT;
	switch(bkg_){
		case pirateBkg_const :
			tempT = new bckTerrain(worldTexts_[pirateBkg_const]);
			
			tempT->setCeiling(tL_.Y());
			tempT->setFloor(bR_.Y());
			tempT->bckSprite.setPosition(tL_.X(), 0);
			return tempT;
		case waterBkg_const :
			tempT = new bckTerrain(worldTexts_[waterBkg_const]);
			tempT->setCeiling(tL_.Y());
			tempT->setFloor(bR_.Y());
			tempT->tL = tL_;
			tempT->bR = bR_;
			return tempT;
		case pirate2Bkg_const :
			tempT = new bckTerrain(worldTexts_[pirate2Bkg_const]);
			tempT->setCeiling(tL_.Y());
			tempT->setFloor(bR_.Y());
			tempT->tL = tL_;
			tempT->bR = bR_;
			return tempT;
		default : 
			break;
		}
	return nullptr;
}

void Game::activateEnemies(std::vector<baseUnit *> * enemies_, bckTerrain * curTerrain_)   {
	// TODO[ ] implement this function
	// usage: the enemies vector will be built bottom up where the active will start at 0, and the first
	// inactive enemy will be at the next background terrain's rectangle
	// THEREFORE, on activation you will...
	
	// detect all enemies withing the curTerrain_'s rectangle using some algrebra
	
	// process those enemies by setting to active, setting ceiling and floor as per curTerrain_'s lines. 
	return;
}

// has access to the entire gamestate out the chute?
// stage management tool for only managing necessary assets - keeping localization minimal while allowing for level scaling to
// NOT impact engine performance. 
//

void Game::updateStage(std::vector<baseUnit *>&  enemies_, std::vector<bckTerrain *>& terrain_, baseUnit * don_) {

	// Activate new foot people needing activation 
	for (uint32_t i = numEnemies; i < enemies_.size(); i++) {
	//	std::cout << enemies_.at(i)->tId << " <- enemies.at(numEnemies) curTerrain-1 -> " << curTerrain-1 <<std::endl;
		if (enemies_.at(i)->tId  == curTerrain-1)  {
			enemies_.at(i)->active = true;
			enemies_.at(i)->alive =true;
			std::cout << "activating a foot from index: " << i << std::endl;
			numEnemies++;
		}
		else {
			break;
		}
		
	}
	// update curTerrain - triggered by movement of player (s).
	if (curTerrain >= terrain_.size()) return;
	if (terrain_.at(curTerrain)->tL.X() < (don_->posX + backX) ) curTerrain++; 
	return;
}



Game::Game() {


	// ====================
	// INITIALIZATION 
	// ====================
	
	sf::Music music;
	music.openFromFile("audio/XmenAudio.mp3");
	music.play();
	std::vector<sf::Texture *> terrainTexts = std::vector<sf::Texture *>();
	std::vector<sf::Texture *> unitTexts = std::vector<sf::Texture *>();
	std::vector<baseUnit *> enemies = std::vector<baseUnit *>();
	std::vector<bckTerrain *> terrain = std::vector<bckTerrain *>();
	projTexts = std::vector<sf::Texture *>();
	// the projectile library will assist in determining the projectile indexes. 
	std::vector<projectile *> projLibrary = std::vector<projectile *>();
	// this holds all repurposable projectiles, must be populated, indexes must be tracked.
	std::vector<projectile *> allProjs = std::vector<projectile *>();
	std::vector<uint32_t> projIndices = std::vector<uint32_t>();
	// populate the container appropriately
	projTexts.push_back(nullptr);
	unitTexts.push_back(nullptr);
	terrainTexts.push_back(nullptr);
	// foo should be renamed to loadUnitTexts
	foo(unitTexts, "turtle");
	foo(unitTexts, "foot");
	foo(unitTexts, "bebop");
	foo(unitTexts, "rockSteady");
	foo(projTexts, "proj");
	
	std::chrono::milliseconds frameTrigger{35};
	// testing stl time libraries

	auto deltaTime = std::chrono::high_resolution_clock::now();
	std::chrono::system_clock::time_point lastCycle = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::milliseconds myTimer = std::chrono::duration_cast<std::chrono::milliseconds>(myTimer).zero();
	std::chrono::milliseconds frameTimer = std::chrono::duration_cast<std::chrono::milliseconds>(frameTimer).zero();
	
	// ==== build the projectile library for copying into new enemies
	for (uint32_t i = 1; i <= maxProj_const; i++) {
		projLibrary.push_back(projBuilder(projTexts, i));
		projIndices.push_back( (i - 1) * maxProjPerType );
		for (uint32_t j = 0; j < maxProjPerType; j++ ) {
			allProjs.push_back(projLibrary.at(i-1)->Clone());
		}
	}
	
	// ====
	// PoC scratch Pad ===== all PoC work must be Migrated to a pipeline which can construct from data files 
	// ===== build the enemies_ vector 
	std::vector<baseUnit *> enemies_ = std::vector<baseUnit *>();
	for (uint32_t i = 0; i <= maxEnemies; i++) enemies_.push_back(unitBuilder(unitTexts, footPurpUnit_const));
	numEnemies = 0;
	// ===== define initial enemy locations from activation - external manifest will define in positionally sorted order all enemies. 
	// interleaving spawn locations 

	baseUnit * tUnit = unitBuilder(unitTexts, donUnit_const);
	baseUnit * fUnit = unitBuilder(unitTexts, footPurpUnit_const);
	baseUnit * fUnit2 = unitBuilder(unitTexts, footPurpUnit_const);
	baseUnit * fUnit3 = unitBuilder(unitTexts, footPurpUnit_const);
	baseUnit * fUnit4 = unitBuilder(unitTexts, footPurpUnit_const);
	baseUnit * bUnit = unitBuilder(unitTexts, bebopUnit_const);
	baseUnit * rUnit = unitBuilder(unitTexts, rockSteadyUnit_const);

	// all this right here should be in the activate function ====
	/*
	fUnit->projectiles.push_back(new starProj(*(projLibrary[0]))); //PoC rtb migrate to scalable solution - concentrate on clone-ing for new ones. 
	fUnit2->projectiles.push_back(new starProj(*(projLibrary[0]))); //PoC rtb migrate to scalable solution - concentrate on clone-ing for new ones. 
	fUnit3->projectiles.push_back(new starProj(*(projLibrary[0]))); //PoC rtb migrate to scalable solution - concentrate on clone-ing for new ones. 
	fUnit4->projectiles.push_back(new starProj(*(projLibrary[0]))); //PoC rtb migrate to scalable solution - concentrate on clone-ing for new ones. 
	*/
	fUnit4->posX = 400;
	fUnit4->posY = 300;
	fUnit4->tId = 1;
	fUnit3->posX = 500;
	fUnit3->posY = 300;
	fUnit3->tId = 1;
	fUnit2->posX = 200;
	fUnit2->posY = 300;
	fUnit2->tId = 0;
	fUnit->posX = 300;
	fUnit->posY = 320;
	fUnit->tId = 0;
	bUnit->posX = 300;
	bUnit->posY = 320;
	bUnit->tId = 0;
	rUnit->posX = 200;
	rUnit->posY = 320;
	rUnit->tId = 0;


	// ===============
	// when building units from json file, build just like you would ... in the advanced wars PoC/Engine
	enemies.push_back(fUnit);
	enemies.push_back(fUnit2);
	enemies.push_back(bUnit);
	enemies.push_back(rUnit);// REMEMBER, PUSH IN ORDER OF TUID TO SIMULATE PROCESS OF JSON PARSING
	enemies.push_back(fUnit3);
	enemies.push_back(fUnit4);
	std::cout << "enemies loaded in enemy container\n" << std::endl;

	tUnit->posX = 75;
	tUnit->posY = 325;

	//
	sf::Image * tempImg = new sf::Image();
	tempImg->loadFromFile("textures/pirateShip.png");
	tempImg->createMaskFromColor(sf::Color(255,0,255),0);	
	sf::Texture * tempText = new sf::Texture();
	tempText->loadFromImage(*tempImg);
	terrainTexts.push_back(tempText);
	// todo[ ] Leverage the point PoC with the world building content pipeline and TILED program to json up the world
	// JUST LIKE in the advanced wars demos. 
	bckTerrain * bTerrain = worldBuilder(terrainTexts, pirateBkg_const, Point(0,225), Point(640, 400));
	terrain.push_back(bTerrain);
	// still need to migrate poc to foo like function
	tempImg = new sf::Image();
	tempImg->loadFromFile("textures/water.png");
	tempImg->createMaskFromColor(sf::Color(255,0,255),0);	
	tempText = new sf::Texture();
	tempText->loadFromImage(*tempImg);
	terrainTexts.push_back(tempText);
	bTerrain = worldBuilder(terrainTexts, waterBkg_const, Point(0,0), Point(0, 0));
	terrain.push_back(bTerrain);
	// FYI all this should be in a 'foo' like funciton - just doing a poc
	tempImg = new sf::Image();
	tempImg->loadFromFile("textures/pirateShip2.png");
	tempImg->createMaskFromColor(sf::Color(255,0,255),0);	
	tempText = new sf::Texture();
	tempText->loadFromImage(*tempImg);
	terrainTexts.push_back(tempText);
	bTerrain = worldBuilder(terrainTexts, pirate2Bkg_const, Point(640,225), Point(1280, 400));
	terrain.push_back(bTerrain);

	// this should be in activate unit function =====
	for (baseUnit * enemy : enemies) {
		enemy->setCeiling(bTerrain->minHeight);
		enemy->setFloor(bTerrain->maxHeight);
	}
	tUnit->setCeiling(bTerrain->minHeight);
	tUnit->setFloor(bTerrain->maxHeight);
	
	curTerrain = 0;
	// =====
	bool inGame = true;

	sf::RenderWindow window(sf::VideoMode(width, height), "TMNT Clone");
	sf::Event event;				

	// Networking PoC scratch pad ==================
	/* DELAY NETWORKING PATCH TO ACCOMODATE A RAPID VERTICAL SLICE DEVELOPMENT 
	// make a socket system call - returns a socket descriptor or -1 error coded reportable to stderr.
	int mySocketfd = socket(AF_INET, SOCK_DGRAM, 0);
	std::cout << "debug output: mySocketfd ---> " << mySocketfd << std::endl;
	int mySendSocket = socket(AF_INET, SOCK_DGRAM, 0);
	std::cout << "debug output: mySendSocket ---> " << mySendSocket << std::endl;
	
	// binding my socket
	struct sockaddr_in mySockAddr;
	mySockAddr.sin_family = AF_INET;
	mySockAddr.sin_port = htons(CLIENTPORT); // automate getting an unused port by using '0'
	mySockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // use my IP address.

	struct sockaddr_in localServerAddr;
	localServerAddr.sin_family = AF_INET;
 	localServerAddr.sin_port = htons(MYPORT);
	localServerAddr.sin_addr.s_addr = htonl(inet_addr("127.0.0.1")); // I know my server ip will be local. 
	memset(&(localServerAddr.sin_zero), '\0', 8); //zero the rest of the struct.	
	// mySocketfd is for listening
	int myBind = bind(mySocketfd, (struct sockaddr *)&mySockAddr, sizeof(struct sockaddr));

	std::cout << "checking my destination and source ip from inet_addr:\n";
	std::cout << "destination ip ---> " << localServerAddr.sin_addr.s_addr << std::endl;
	std::cout << "source ip ---> " << mySockAddr.sin_addr.s_addr << std::endl;
	

 	int myConnect = 0;
	*/
	// ==============================================	
}

void Game::iterateGameLoop() {

	std::cout << "iterating gameloop\n";

}


