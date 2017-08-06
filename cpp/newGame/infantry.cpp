#include "infantry.h"
#include "Project_Constants.h"
#include <iostream>

infantry::infantry()  	{
	std::cout << "plainTerrain instatiated\n";
	
}

infantry::infantry(const sf::Texture * image_) {
	unitSprite = sf::Sprite();
	unitSprite.setTexture(*image_);
	unitSprite.setPosition(0, 0);

}

infantry::~infantry(){
	std::cout << "plainTerrain destroyed\n";

}

void infantry::print() {
	std::cout << "plainTerrain printed\n";

}





