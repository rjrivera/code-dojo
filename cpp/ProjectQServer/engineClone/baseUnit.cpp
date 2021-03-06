#include "baseUnit.h";
#include <iostream>;
#include "Project_Constants.h";

baseUnit::baseUnit()  	{
	hp = 100;
	alive = true;
	active = false;
	tId = 1;
	atkCheck = false;
}

baseUnit::baseUnit(uint32_t player_) {
	player = 1;
	hp = 100;
}

baseUnit::~baseUnit(){
	std::cout << "baseUnit destroyed\n";

}

void baseUnit::movePosX(int32_t moveX) {
//nop
	posX += moveX;
	if ( moveX >0 ) {
		curState = unitState(right);
		unitSprite = &(sprites->at(curState));
	}
	else {
		curState = unitState(left);
		unitSprite = &(sprites->at(curState));

	}

	//unitSprite.setPosition(posX, posY);
}

void baseUnit::movePosY(int32_t moveY) {
//nop
	posY += moveY;
	//unitSprite.setPosition(posX, posY);
}

void baseUnit::moveVelX(int32_t moveX) {

	velX = moveX;
}

void baseUnit::moveVelY(int32_t moveY) {
	velY = moveY;
}

bool baseUnit::isValMove(uint32_t destX, uint32_t destY){
	// a potential utility function
	return true;

}

void baseUnit::updateTiming(std::chrono::milliseconds deltaTime) {

	//NOP
}
void baseUnit::updateBehavior(){


	//NOP
}

void baseUnit::updateDefHitBox(){
	//NOP
}

void baseUnit::updateOffHitBox(){
	//NOP
}

void baseUnit::setCeiling(double ceiling_) {
	minHeight = ceiling_; 
}

void baseUnit::setFloor(double floor_) {
	maxHeight = floor_; 
}
/*
//temporary sprite - redefine with better software architecture. 
void baseUnit::defineGridSprite(const sf::Texture * image) {
	gridSprite = image;
}
*/


