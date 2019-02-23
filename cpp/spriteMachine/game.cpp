#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Project_Constants.h"
#include "cursor.cpp"
#include "baseUnit.cpp"
#include "infantry.cpp"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <SFML/Graphics.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/date_time/posix_time/posix_time_types.hpp>
// [] NEXT TODO -- finish the attackSelect mode. 
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

void foo(std::vector<sf::Texture *>& text_container, std::string textType_) {
	uint32_t numTexts = 0;
	std::string texturePath = "textures/";
	texturePath += textType_;
	if (textType_ == "plain" ) numTexts = maxTerrain_const; 
	else if (textType_ == "unit") numTexts = (maxUnit_const * maxPlayers_const); 
	else if (textType_ == "unitInfo") numTexts = (maxUnit_const); 
	else if (textType_ == "ui") numTexts = (maxUI_const); 
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

baseUnit * unitBuilder(std::vector<sf::Texture*>& unitTexts_, uint32_t unit_, uint32_t player_) {
	std::cout << "\nbuilding unit for player " << player_ << std::endl;
	baseUnit * unit;
	switch(unit_){
		case infantryUnit_const :
			unit = new infantry(unitTexts_[infantryUnit_const * player_], player_);
			return unit;
		default : 
			break;
		}
}

int main( int argc, char** argv ) {

	// ====================
	// INITIALIZATION 
	// ====================

	std::vector< sf::Texture * > unitTexts 		= std::vector< sf::Texture * >();
	bool draw = false;
	foo(unitTexts, "unit");
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sprite Machine 3000");
	// Create the cursor object as a basic UI for sprite machine tester.
//CURSOR PoC --- migrate code appropriately when done demonstrating TODO [ ]
//sfml::Sprite uses copy constructors - leverage accordingly
	sf::Texture * cursText = new sf::Texture();
	sf::Image * cursImg = new sf::Image();
	cursImg->loadFromFile("textures/cursor.png");
	cursImg->createMaskFromColor(sf::Color(255,0,255), 0);
	cursText->loadFromImage(*cursImg);
	cursor * myC = new cursor(cursText);

	std::chrono::milliseconds frameTrigger{70};
	auto deltaTime = std::chrono::high_resolution_clock::now();
	auto lastCycle = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds myTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(myTimer).zero();
	std::chrono::nanoseconds frameTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(frameTimer).zero();

	bool inGame, menu, prototype, engineLive;
	inGame = menu = prototype = engineLive = false;
	inGame = engineLive = true;

	baseUnit * tUnit = unitBuilder(unitTexts, infantryUnit_const, 1);

	while( inGame)
	{
		if( engineLive ) 
		{
			sf::Event event;	
			while (window.pollEvent(event)) {}//nop == clear the event queue buffer. 
			lastCycle = now;
			now = std::chrono::high_resolution_clock::now();
			frameTimer += myTimer = now - lastCycle;
			// ===================================================
			// UPDATE TIMING
			// ==================================================		
		
			myC->updateTimer(myTimer);

			// ===================================================
			// INPUT HANDLING
			// ===================================================
			//debounce input.
			if (myC->getCooldown() ) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
						engineLive 	= false;
						inGame 		= false;
						myC->burnCooldown();
					}	 
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
						myC->moveX(-1);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
						myC->moveX(1);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
						myC->moveY(1);
						myC->burnCooldown();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
						myC->moveY(-1);
						myC->burnCooldown();
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
				window.draw(tUnit->unitSprite);
				tUnit->spriteTimer++;
				if( tUnit->spriteTimer >= tUnit->spriteTrigger) {
					tUnit->spriteOffset++; 
					tUnit->spriteTimer = 0;
					tUnit->unitSprite.setTextureRect(sf::IntRect(tUnit->spriteOffset*16, 0, 16, 16));
					if (tUnit->spriteOffset == tUnit->numSprites)  {
						tUnit->spriteOffset = 0;
					}
				}

				window.display();
			}
			else draw = true;
		} // < brace is for if( engineLive )		
	//	if( inGame ) std::cout << "inGame\n";
	}
	return 0;
}
