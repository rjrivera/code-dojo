#include "infantry.h"
#include "Project_Constants.h"
#include <iostream>


infantry::infantry()  	{
	std::cout << "infantry instatiated\n";
	
}

infantry::infantry(const sf::Texture * image_, uint32_t player_) : baseUnit(player_){
	unitSprite = sf::Sprite();
	unitSprite.setTexture(*(image_));
	unitSprite.setPosition(0, 0);
	//unitSprite.setColor(sf::Color(255,255,255,0));
	numSprites = 2;
	spriteOffset = 0; 
	spriteTimer = 0;
	spriteTrigger = 10;
	mvt = 6;
	std::cout << "constructor sees this player value: " << player_ << std::endl;
	def = 1;
	atk = 10;

}

infantry::~infantry(){
	std::cout << "infantry destroyed\n";

}

void infantry::print() {
	std::cout << "infantry printed\n";

}
