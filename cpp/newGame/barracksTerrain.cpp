#include "barracksTerrain.h"
#include "Project_Constants.h"
#include <iostream>

barracksTerrain::barracksTerrain()  	{
	std::cout << "barracksTerrain instatiated\n";
	
}

barracksTerrain::barracksTerrain(const sf::Texture * image_, const sf::Texture * hlImage_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
	cost = 2;
	defBonus = 1;
}

barracksTerrain::barracksTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_) : baseTerrain(hlImage_) {
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);

	infoSprite = sf::Sprite();
	infoSprite.setTexture(*terrainInfo_);
	infoSprite.setPosition(0, 0);
	cost = 2;
	defBonus = 1;
}

barracksTerrain::~barracksTerrain(){
	std::cout << "barracksTerrain destroyed\n";

}

void barracksTerrain::print() {
	std::cout << "barracksTerrain printed\n";

}



