#include "baseGFX.h";
#include <iostream>;

baseGFX::baseGFX()  	{	
}

baseGFX::~baseGFX(){
}

void baseGFX::movePosX(uint64_t moveX) {
	posX += moveX;
	gFXSprite.setPosition(posX, posY);
}

void baseGFX::movePosY(uint64_t moveY) {
	posY += moveY;
	gFXSprite.setPosition(posX, posY);
}

void baseGFX::updatePos(){
	posX += velX;
	posY += velY;

}


