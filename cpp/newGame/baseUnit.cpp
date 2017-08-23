#include "baseUnit.h";
#include <iostream>;

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
