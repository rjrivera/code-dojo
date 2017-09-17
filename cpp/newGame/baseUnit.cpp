#include "baseUnit.h";
#include <iostream>;
#include "Project_Constants.h";

baseUnit::baseUnit()  	{
	hp = 100;
}

baseUnit::baseUnit(uint32_t player_) {
	player = 1;
	hp = 100;
}

baseUnit::~baseUnit(){
	std::cout << "baseUnit destroyed\n";

}

void baseUnit::movePosX(uint64_t moveX) {
//nop
	posX += moveX;
	unitSprite.setPosition(posX, posY);
}

void baseUnit::movePosY(uint64_t moveY) {
//nop
	posY += moveY;
	unitSprite.setPosition(posX, posY);
}

void baseUnit::initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY) {
//nop
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

//do a simple implementation away from the board's border for PoC, dig deep when refining soon. 
void baseUnit::findEnemyNeighbors() {
	enemyNeighbors->clear();
	int32_t sourceSlot = (int32_t)getBSlot(posX, posY);
	int32_t above = getAboveBSlot(sourceSlot);
	int32_t below = getBelowBSlot(sourceSlot);
	if (board[sourceSlot + 1]->attachedUnit != nullptr && board[sourceSlot + 1]->attachedUnit->player != player) 
		enemyNeighbors->push_back(sourceSlot + 1);  
	else if (board[sourceSlot - 1]->attachedUnit != nullptr && board[sourceSlot - 1]->attachedUnit->player != player) 
		enemyNeighbors->push_back(sourceSlot - 1);
	else if (above >= 0 && board[above]->attachedUnit != nullptr && board[above]->attachedUnit->player != player)
		 enemyNeighbors->push_back(above);   
	else if (below >= 0 && board[below]->attachedUnit != nullptr && board[below]->attachedUnit->player != player)
		 enemyNeighbors->push_back(below); 
	//for debugging - remove when done [ ] TODO
	for (auto& enemy : *enemyNeighbors) std::cout << "enemy neighbor at: " << enemy << std::endl;
	std::cout << "size of enemy neighbor vector: " << enemyNeighbors->size() << std::endl;
	std::cout << "curUnit player number: " << player << std::endl;
}

bool baseUnit::isValMove(uint32_t destX, uint32_t destY){
//simple linear traversal as it's a cheap operation.
	uint32_t destSlot = getBSlot(destX, destY);
	for (uint32_t mG : *validMoves) {
		if (destSlot == mG) return true;
		std::cout << destSlot << std::endl;
	}
	
	return false;

}
/*
//temporary sprite - redefine with better software architecture. 
void baseUnit::defineGridSprite(const sf::Texture * image) {
	gridSprite = image;
}
*/


