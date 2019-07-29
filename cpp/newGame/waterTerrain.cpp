#include "waterTerrain.h"
#include "Project_Constants.h"
#include <iostream>

waterTerrain::waterTerrain()  	{
	std::cout << "waterTerrain instatiated\n";
	
}

waterTerrain::waterTerrain(const sf::Texture * image_, const sf::Texture * hlImage_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
	cost = 20;
	defBonus = 1;
}

waterTerrain::waterTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);

	infoSprite = sf::Sprite();
	infoSprite.setTexture(*terrainInfo_);
	infoSprite.setPosition(0, 0);
	cost = 20;
	defBonus = 1;
}

waterTerrain::~waterTerrain(){
	std::cout << "waterTerrain destroyed\n";

}

void waterTerrain::print() {
	std::cout << "waterTerrain printed\n";

}



