#include"cursor.h"
#include <iostream>



cursor::cursor() {
	std::cout << "default constructor obsolete, please call cursor(const sf::Texture * image_)\n";

}

cursor::cursor(const sf::Texture * image_){
	tileSprite = sf::Sprite();
	tileSprite.setTexture(*image_);
	posX = posY = 0;
	tileSprite.setPosition(posX, posY);
	movCooldown = true;
}

cursor::~cursor(){
	std::cout << "cursor deletion called\n";
}

void cursor::print() {
	std::cout << "cursor print called\n";

}

bool cursor::getCooldown() {
	return movCooldown;
}

bool cursor::burnCooldown() {
	movCooldown = false;
	cursTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(cursTimer).zero();

}
void cursor::movePosX(uint64_t moveX) {
	uint64_t newX = moveX + posX;
	if (movCooldown && newX >= 0 && newX <= 384-16) {  
		tileSprite.setPosition(newX, posY);
		posX += moveX;
		burnCooldown();
	}

}

void cursor::movePosY(uint64_t moveY) {
	uint64_t newY = moveY + posY;
	if (movCooldown && newY >= 0 && newY <= 384-16) {  
		tileSprite.setPosition(posX, newY);
		posY = newY;
		burnCooldown();
	}

}

void cursor::updateTimer(std::chrono::nanoseconds timer) {
	cursTimer += timer;
	if ( cursTimer >= cursTrigger && !movCooldown)   {
		movCooldown = true;
		cursTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(cursTimer).zero();
	}
}


