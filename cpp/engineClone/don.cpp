#include "don.h"
#include "Project_Constants.h"
#include <iostream>
#include <vector>

don::don()  	{
	std::cout << "don instatiated\n";
	
}

don::don(std::vector<const sf::Texture *>& images_) : baseUnit(){
	sprites = new std::vector<sf::Sprite>();
	std::cout << "vector<sf::sprite> built\n";
	for (int32_t i = 0; i < maxUnitState_const; i++) {
		sprites->push_back(sf::Sprite());

		std::cout << "vector<sf::sprite> pushed new sprite\n";
		sprites->at(i).setTexture(*(images_[i]));

		std::cout << "sprites texture set\n";
		sprites->at(i).setPosition(0, 0);
	}
	numSprites = 7;
	spriteOffset = 0; 
	spriteTimer = std::chrono::duration_cast<std::chrono::milliscconds>(spriteTimer).zero();
	spriteTrigger = std::chrono::duration_cast<std::chrono::milliscconds>(spriteTrigger).zero();
	curState = unitState(idle);
	unitSprite = &(sprites->at(curState));
	unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*80,0,80,62));
	std::cout << "cur Don state: " << curState << std::endl;
}

don::~don(){
	std::cout << "don object destroyed\n";

}

void don::print() {
	std::cout << "don object printed\n";

}

void updateTiming(std::chrono::milliseconds deltaTime){
	spriteTimer+= deltaTime;
	if (spriteTimer >= spriteTrigger)  {
		spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
		spriteOffset++;
		if (spriteOffset>=numSprites) spriteOffset = 0; 
		//update the sprite sheet nao.
		unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*80,0,80,62));

	}

}
