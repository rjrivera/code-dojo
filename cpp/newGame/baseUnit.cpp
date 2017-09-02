#include "baseUnit.h";
#include <iostream>;
#include "Project_Constants.h";

baseUnit::baseUnit()  	{
	
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

}

bool baseUnit::isValMove(uint32_t destX, uint32_t destY){
//simple linear traversal as it's a cheap operation.
	for (auto mG : *validMoves) {
		if (destX == mG->posX && destY == mG->posY) return true;
		std::cout << mG->posX << std::endl;
	}
	return false;

}
//temporary sprite - redefine with better software architecture. 
void baseUnit::defineGridSprite(const sf::Texture * image) {
	gridSprite = image;
}



