#include "roadTerrain.h"
#include "Project_Constants.h"
#include <iostream>

roadTerrain::roadTerrain()  	{
	std::cout << "roadTerrain instatiated\n";
	
}

roadTerrain::roadTerrain(const sf::Texture * image_, const sf::Texture * hlImage_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
	cost = 1;
	defBonus = 0;
}

roadTerrain::~roadTerrain(){
	std::cout << "plainTerrain destroyed\n";

}

void roadTerrain::print() {
	std::cout << "roadTerrain printed\n";

}



