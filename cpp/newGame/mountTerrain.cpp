#include "mountTerrain.h"
#include "Project_Constants.h"
#include <iostream>

mountTerrain::mountTerrain()  	{
	std::cout << "plainTerrain instatiated\n";
	
}

mountTerrain::mountTerrain(const sf::Texture * image_, const sf::Texture * hlImage_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
	cost = 4;
	defBonus = 4;
}

mountTerrain::mountTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
	
	infoSprite = sf::Sprite();
 	infoSprite.setTexture(*terrainInfo_);
	infoSprite.setPosition(0, 0);
	cost = 4;
	defBonus = 4;
}

mountTerrain::~mountTerrain(){
	std::cout << "plainTerrain destroyed\n";

}

void mountTerrain::print() {
	std::cout << "plainTerrain printed\n";

}



