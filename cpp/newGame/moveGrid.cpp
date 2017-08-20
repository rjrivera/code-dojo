#include "moveGrid.h"
#include "Project_Constants.h"
#include <iostream>


moveGrid::moveGrid()  	{
	std::cout << "plainTerrain instatiated\n";
	
}

moveGrid::moveGrid(const sf::Texture * image_, uint32_t initX, uint32_t initY) {
	gFXSprite = sf::Sprite();
	gFXSprite.setTexture(*image_);
	gFXSprite.setPosition(initX, initY);

}

moveGrid::~moveGrid(){
}

void moveGrid::print() {
}
