#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Project_Constants.h"
#include "baseUnit.cpp"
#include "baseGFX.cpp"
#include "don.cpp"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/filereadstream.h"
#include <SFML/Graphics.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#define WIDTH 384
#define HEIGHT 352

// major todo[ ]  migrate input handling to objects, not client - client just interfaces between input device and objects. 
// enum actionMenuState {move, atk, back}; keeping for reference
// I want this server to receive packets and use said packets as inputs 
// First - I need to prepare a means for listening.

void foo(std::vector<sf::Texture *>& text_container, std::string textType_) {
	uint32_t numTexts = 0;
	std::string texturePath = "textures/";
	texturePath += textType_;
	if (textType_ == "plain" ) numTexts = maxTerrain_const; 
	else if (textType_ == "turtle" ) numTexts = (maxUnit_const); 
	else return;

	text_container.push_back(nullptr); //needed to reconcile 1-based const nameing scheme with accessing of textures via consts.

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

/*
//MAPGENERATOR // keeping for junk parts
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
*/
//potential repurpose
baseUnit * unitBuilder(std::vector<sf::Texture*>& unitTexts_, uint32_t unit_) {
	std::cout << " attempting to build a unit\n";
	std::vector<const sf::Texture *> textures = std::vector<const sf::Texture *>();
	switch(unit_){
		case donUnit_const :

			// rev up those fryers
			for (uint32_t i = 1; i <= maxUnitState_const; i++) textures.push_back(unitTexts_[donUnit_const*i]);

			std::cout << " don textures loaded in vector\n";
			return new don(textures);
			break;
		default : 
			break;
		}
	return nullptr;
}

int main( int argc, char** argv ) {


	// ====================
	// INITIALIZATION 
	// ====================
	std::vector<sf::Texture *> terrainTexts = std::vector<sf::Texture *>();
	std::vector<sf::Texture *> unitTexts = std::vector<sf::Texture *>();

	//control unit for board manipulation operations TODO[ ] move to cursor class.
	foo(unitTexts, "turtle");
	std::chrono::milliseconds frameTrigger{35};
	// testing stl time libraries

	auto deltaTime = std::chrono::high_resolution_clock::now();
	std::chrono::system_clock::time_point lastCycle = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::milliseconds myTimer = std::chrono::duration_cast<std::chrono::milliseconds>(myTimer).zero();
	std::chrono::milliseconds frameTimer = std::chrono::duration_cast<std::chrono::milliseconds>(frameTimer).zero();
	
	baseUnit * tUnit = unitBuilder(unitTexts, donUnit_const);

	bool inGame = true;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TMNT Clone");
	sf::Event event;				

	// Networking PoC scratch pad ==================
	// make a socket system call - returns a socket descriptor or -1 error coded reportable to stderr.
	int mySocketfd = socket(AF_INET, SOCK_DGRAM, 0);
	std::cout << "debugging -  mySocketfd ---> " << mySocketfd << std::endl;
	// binding my socket
	struct sockaddr_in mySockAddr;
	mySockAddr.sin_family = AF_INET;
	mySockAddr.sin_port = htons(MYPORT); // automate getting an unused port by using '0'
	mySockAddr.sin_addr.s_addr = htonl(inet_addr("127.0.0.1")); // use my IP addressa.
	struct sockaddr_in theirAddr;
	memset(&(mySockAddr.sin_zero), '\0', 8);// zero out the rest of the struct.

	int myBind = bind(mySocketfd, (struct sockaddr *)&mySockAddr, sizeof(struct sockaddr));
	std::cout << "debugging - myBind ---> " << myBind << std::endl;
	
	// listening
//	int myListen = listen(mySocketfd, 4);
//	std::cout << "debugging - myListen ---> " << myListen << std::endl;

	int myNewFd = -1;
	socklen_t sin_size = sizeof(struct sockaddr_in);

	std::cout << "information on sockaddr * mySockAddr" << mySockAddr.sin_addr.s_addr << std::endl; 
	// ==============================================	
	while(inGame) {

		while (window.pollEvent(event)) {}//nop == clear the event queue buffer. 
		lastCycle = now;
		now = std::chrono::system_clock::now();
		frameTimer += myTimer = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastCycle);
		
		// ===================================================
		// UPDATE TIMING
		// ==================================================		
		//TODO[ ]  MIGRATE COOLDOWN TO CHARACTER 

		tUnit->updateTiming(myTimer);

		// ===================================================
		// INPUT HANDLING
		// ===================================================
		// character control
	//	tUnit->inputHandling();

			
		// client control TODO[ ] abstract away to a client handling layer. 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			inGame = false;
		}	 

		// accept here 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			 //myNewFd = accept(mySocketfd, (struct sockaddr *)&theirAddr, &sin_size);
			 //std::cout << "attempting to connect to a queued request\n";
			//std::cout << "result of accept(): " << myNewFd << std::endl;
			char buf[10];
			int recvlen = recvfrom(mySocketfd, buf, strlen(buf), 0, (struct sockaddr *)&theirAddr, &sin_size);
			if ( recvlen > 0 ) {
				buf[recvlen] = 0;
				printf("received message: \"%s\"\n", buf);
			}					
			else {
				printf("error receiving message\n");
			}
		}
//		std::cout << "current value of file descriptor" << " myNewFd: " << myNewFd << std::endl;
		if (myNewFd != -1)  {
			char* buffer[10];
			recv(myNewFd, buffer, 10, 0);
		 	std::cout << "my Received message: " << buffer << std::endl;
		}

		if ( frameTimer >= frameTrigger ) { 
			std::chrono::milliseconds frameTimer = std::chrono::duration_cast<std::chrono::milliseconds>(frameTimer).zero();
			//std::cout << "draw some shit\n";
			window.clear();
			window.draw(*(tUnit->unitSprite)); // all animation logic MUST be 'under the hood'
			
			window.display();
		}
	}

	return 0;
}
