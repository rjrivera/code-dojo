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

void baseUnit::movePosX(int64_t moveX) {
//nop
	posX += moveX;
	if ( moveX >0 ) 
		curState = unitState(right);
		unitSprite = &(sprites->at(curState));
	else {
		curState = unitState(left);
		unitSprite = &(sprites->at(curState));

	}

	//unitSprite.setPosition(posX, posY);
}

void baseUnit::movePosY(int64_t moveY) {
//nop
	posY += moveY;
	//unitSprite.setPosition(posX, posY);
}

bool baseUnit::isValMove(uint32_t destX, uint32_t destY){
	// a potential utility function
	return true;

}


/*
//temporary sprite - redefine with better software architecture. 
void baseUnit::defineGridSprite(const sf::Texture * image) {
	gridSprite = image;
}
*/


