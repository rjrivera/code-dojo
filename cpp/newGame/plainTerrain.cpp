#include "plainTerrain.h"
#include "Project_Constants.h"
#include <iostream>

plainTerrain::plainTerrain()  	{
	std::cout << "plainTerrain instatiated\n";
	
}

plainTerrain::plainTerrain(const sf::Texture * image_, const sf::Texture * hlImage_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
	cost = 2;
	defBonus = 1;
}

plainTerrain::~plainTerrain(){
	std::cout << "plainTerrain destroyed\n";

}

void plainTerrain::print() {
	std::cout << "plainTerrain printed\n";

}



