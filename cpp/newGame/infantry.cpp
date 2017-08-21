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
	if ( (curY - (1*tilesize_const)) >=0  )  {
		validMoves->push_back(new moveGrid( gridSprite, curX, curY-(1*tilesize_const)) );
		initMoveGrids(mvtRemaining, curX, curY - (1*tilesize_const));
		
	}
	//down...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	//for now...magic num ber :S
	if ( (curY + (1*tilesize_const)) <= tilesize_const * 30 )  {
		validMoves->push_back(new moveGrid( gridSprite, curX, curY+(1*tilesize_const)) );
		initMoveGrids(mvtRemaining, curX, curY + (1*tilesize_const));
	}
	//right...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	//same as above
	if ( (curX + (1*tilesize_const)) <= tilesize_const * 30  )  {
		validMoves->push_back(new moveGrid( gridSprite, curX+(1*tilesize_const), curY) );
		initMoveGrids(mvtRemaining, curX + (1*tilesize_const), curY);
	}
	//left 
	if ( (curX - (1*tilesize_const)) >=0  )  {
		validMoves->push_back(new moveGrid( gridSprite, curX-(1*tilesize_const), curY) );
		initMoveGrids(mvtRemaining, curX - (1*tilesize_const), curY);
		
	}

}

//temporary sprite - redefine with better software architecture. 
void infantry::defineGridSprite(const sf::Texture * image) {
	gridSprite = image;
}



