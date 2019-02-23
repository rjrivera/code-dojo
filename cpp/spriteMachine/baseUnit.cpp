#include "baseUnit.h";
#include <iostream>;
#include "Project_Constants.h";

baseUnit::baseUnit()  	{
	hp = 100;
}

baseUnit::baseUnit(uint32_t player_) {
	player = player_;
	hp = 100;
}

baseUnit::~baseUnit(){
	std::cout << "baseUnit destroyed\n";

}

void baseUnit::moveX(int64_t moveX) {
//nop
	posX += moveX;
}

void baseUnit::moveY(int64_t moveY) {
//nop
	posY += moveY;
}

