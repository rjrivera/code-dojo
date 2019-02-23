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
	stackInd = 0;
}

cursor::cursor(const cursor& A) {
	tileSprite = A.tileSprite;
	posX = A.posX;
	posY = A.posY;
	movCooldown = A.movCooldown;
	cursTimer = A.cursTimer;
	cursTrigger = A.cursTrigger;
	stackInd = A.stackInd;
}

cursor::~cursor(){
	std::cout << "cursor deletion called\n";
}

cursor * cursor::clone() {
	return new cursor(*this);
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
void cursor::moveX(int64_t moveX) {
	uint64_t newX = moveX + posX;
	if (movCooldown && newX >= 0 && newX <= 384-16) {  
		tileSprite.setPosition(newX, posY);
		posX += moveX;
		burnCooldown();
	}

}

void cursor::moveY(int64_t moveY) {
	uint64_t newY = moveY + posY;
	if (movCooldown && newY >= 0 && newY <= 384-16) {  
		tileSprite.setPosition(posX, newY);
		posY = newY;
		burnCooldown();
	}

}

// an absolute variant to be used by buisness logic, not ui directly as it doesnt use cooldowns.
void cursor::moveXAbs(int64_t moveX) {
	if(moveX >= 0) {
		posX = moveX;
		}
}

//an absolute variant
void cursor::moveYAbs(int64_t moveY) {
	if(moveY >= 0) {
		posY = moveY;
		
	}
}

void cursor::updateTimer(std::chrono::nanoseconds timer) {
	cursTimer += timer;
	if ( cursTimer >= cursTrigger && !movCooldown)   {
		movCooldown = true;
		cursTimer = std::chrono::duration_cast<std::chrono::nanoseconds>(cursTimer).zero();
	}
}


