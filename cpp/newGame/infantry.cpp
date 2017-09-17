#include "infantry.h"
#include "Project_Constants.h"
#include <iostream>


infantry::infantry()  	{
	std::cout << "plainTerrain instatiated\n";
	
}

infantry::infantry(const sf::Texture * image_, uint32_t player_) : baseUnit(player_){
	unitSprite = sf::Sprite();
	unitSprite.setTexture(*(image_));
	unitSprite.setPosition(0, 0);
	numSprites = 3;
	spriteOffset = 0; 
	spriteTimer = 0;
	spriteTrigger = 10;
	mvt = 6;
	std::cout << "constructor sees this player value: " << player_ << std::endl;
	validMoves = new std::vector<uint32_t>();
	enemyNeighbors = new std::vector<int32_t>();
	def = 1;
	atk = 10;

}

infantry::~infantry(){
	std::cout << "plainTerrain destroyed\n";

}

void infantry::print() {
	std::cout << "plainTerrain printed\n";

}
/*
//simple BFS to generate default move grid objects.
void infantry::initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY)  {
	if (curX < 0 || curY < 0 || curX > 30*tilesize_const || curY > 30*tilesize_const) return; 
	//mvtRemaining--;
	mvtRemaining -= board[(getBSlot(curX, curY))]->cost;
	if (mvtRemaining <0 ) return;
	validMoves->push_back((getBSlot(curX, curY))); 
	//up 
	if ( (curY - (1*tilesize_const)) >=0  )  {
//		validMoves->push_back(new moveGrid( gridSprite, curX, curY-(1*tilesize_const)) );
		initMoveGrids(mvtRemaining, curX, curY - (1*tilesize_const));
		
	}
	//down...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	//for now...magic num ber :S
	if ( (curY + (1*tilesize_const)) <= tilesize_const * 30 )  {
//		validMoves->push_back(new moveGrid( gridSprite, curX, curY+(1*tilesize_const)) );
		initMoveGrids(mvtRemaining, curX, curY + (1*tilesize_const));
	}
	//right...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	//same as above
	if ( (curX + (1*tilesize_const)) <= tilesize_const * 30  )  {
//		validMoves->push_back(new moveGrid( gridSprite, curX+(1*tilesize_const), curY) );
		initMoveGrids(mvtRemaining, curX + (1*tilesize_const), curY);
	}
	//left 
	if ( (curX - (1*tilesize_const)) >=0  )  {
//		validMoves->push_back(new moveGrid( gridSprite, curX-(1*tilesize_const), curY) );
		initMoveGrids(mvtRemaining, curX - (1*tilesize_const), curY);
		
	}

}
*/

