#include "baseUnit.h";
#include "baseTerrain.h";
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

void baseUnit::initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY, std::vector<baseTerrain*> *board) {
//nop
	if (curX < 0 || curY < 0 || curX > 30*tilesize_const || curY > 30*tilesize_const) return; 
	//mvtRemaining--;
	mvtRemaining -= board->at((getBSlot(curX, curY)))->cost;
	if (mvtRemaining <0 ) return;
	validMoves->push_back((getBSlot(curX, curY)));   
	//up 
	if ( (curY - (1*tilesize_const)) >=0  )  {
		initMoveGrids(mvtRemaining, curX, curY - (1*tilesize_const), board);
		
	}
	//down...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	//for now...magic num ber :S
	if ( (curY + (1*tilesize_const)) <= tilesize_const * 30 )  {
		initMoveGrids(mvtRemaining, curX, curY + (1*tilesize_const), board);
	}
	//right...determine if we need to filter this here or on board...should filter here...make mapsize universally accessible
	//same as above
	if ( (curX + (1*tilesize_const)) <= tilesize_const * 30  )  {
		initMoveGrids(mvtRemaining, curX + (1*tilesize_const), curY, board);
	}
	//left 
	if ( (curX - (1*tilesize_const)) >=0  )  {
		initMoveGrids(mvtRemaining, curX - (1*tilesize_const), curY, board);
	}
}

void baseUnit::findEnemyNeighbors(int32_t posX_, int32_t posY_, std::vector<baseTerrain*> * board) {
	enemyNeighbors->clear();
	int32_t sourceSlot = (int32_t)getBSlot(posX_, posY_);
	int32_t above = getAboveBSlot(sourceSlot);
	int32_t below = getBelowBSlot(sourceSlot);
	if (board->at(sourceSlot + 1)->attachedUnit != nullptr && board->at(sourceSlot + 1)->attachedUnit->player != player) 
		enemyNeighbors->push_back(sourceSlot + 1);  
	if (board->at(sourceSlot - 1)->attachedUnit != nullptr && board->at(sourceSlot - 1)->attachedUnit->player != player) 
		enemyNeighbors->push_back(sourceSlot - 1);
	if (above >= 0 && board->at(above)->attachedUnit != nullptr && board->at(above)->attachedUnit->player != player)
		 enemyNeighbors->push_back(above);   
	if (below >= 0 && board->at(below)->attachedUnit != nullptr && board->at(below)->attachedUnit->player != player)
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

void baseUnit::defineUnitInfoSprite(const sf::Texture * unitInfo_){
	unitInfoSprite = sf::Sprite();
	unitInfoSprite.setTexture(*(unitInfo_));
	unitInfoSprite.setPosition(192, 0);
}
