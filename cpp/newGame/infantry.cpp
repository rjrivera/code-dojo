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
	mvt = 4;
	validMoves = new std::vector<moveGrid *>();
}

infantry::~infantry(){
	std::cout << "plainTerrain destroyed\n";

}

void infantry::print() {
	std::cout << "plainTerrain printed\n";

}

//simple BFS to generate default move grid objects.
void infantry::initMoveGrids(uint32_t mvtRemaining, uint32_t curX, uint32_t curY)  {
	if ( mvtRemaining <= 0 ) return; 
	//decrement moves remaining
	mvtRemaining--;
	//initMoveGrids(mvtRemaining);
	//up 
	if ( (posY - (1*tileConstSize)) >=0  )  {
		validMoves->push_back(new moveGrid( gridSprite ), posX, posY-(1*tileConstSize) );
		initMoveGrids(mvtRemaining, posX, posY - (1*tileConstSize));
		
	}
	//down...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	if ( (posY + (1*tileConstSize)) <=0  )  {
		validMoves->push_back(new moveGrid( gridSprite ), posX, posY+(1*tileConstSize) );
		initMoveGrids(mvtRemaining, posX, posY + (1*tileConstSize));
	}
	//right...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	if ( (posX + (1*tileConstSize)) <=0  )  {
		validMoves->push_back(new moveGrid( gridSprite ), posX+(1*tileConstSize), posY );
		initMoveGrids(mvtRemaining, posX + (1*tileConstSize), posY);
	}
	//left 
	if ( (posX - (1*tileConstSize)) >=0  )  {
		validMoves->push_back(new moveGrid( gridSprite ), posX-(1*tileConstSize), posY );
		initMoveGrids(mvtRemaining, posX - (1*tileConstSize), posY);
		
	}

}

//temporary sprite - redefine with better software architecture. 
void defineGridSprite(const sf::Texture image) {
	gridSprite = image;
}



