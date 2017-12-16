#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
#include "moveGrid.h"
#include <vector>
#include "hitBox.h"
#include "projectile.h"




#include "projectile.h"
#include "Project_Constants.h"
#include <iostream>
#include <vector>

projectile::projectile()  	{
	std::cout << "projectile instatiated\n";
	
}

projectile::projectile(std::vector<const sf::Texture *>& images_) {
	sprites = new std::vector<sf::Sprite>();
	std::cout << "vector<sf::sprite> built\n";
	for (int32_t i = 0; i < maxUnitState_const; i++) {
		sprites->push_back(sf::Sprite());

		sprites->at(i).setTexture(*(images_[i]));

		sprites->at(i).setPosition(0, 0);
	}
	posX = posY = velX = velY = 0;
	posX = 128;
	numSprites = 4;
	spriteOffset = 0; 
	spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();

	spriteTrigger = std::chrono::milliseconds(80);
	inputTrigger = std::chrono::milliseconds(1000);
// hmmmm - inputTrigger IS an projTrigger	
	projTrigger = std::chrono::milliseconds(35);
	projTimer = std::chrono::duration_cast<std::chrono::milliseconds>(projTimer).zero();
	curState = unitState(idle);
	unitSprite = &(sprites->at(curState));
	unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*40,0,40,62));
	movCooldown = true;
	defHB = new hitBox(new Point((double)posX+93, (double)posY), new Point((double)posX+133, (double)posY+62));

}

projectile::~projectile(){
	std::cout << "projectile object destroyed\n";

}

void projectile::print() {
	std::cout << "projectile object printed\n";

}

void projectile::updateTiming(std::chrono::milliseconds deltaTime){
	spriteTimer += deltaTime;
	if (spriteTimer >= spriteTrigger)  {
		spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
		spriteOffset++;
		if (spriteOffset>=numSprites) spriteOffset = 0; 
		unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*40,0,40,62));
//todo [ ] MOVE THIS TO A DIFFERENT TIMER
		posX += velX;
		posY += velY;
	}
	//TODO[ ] remove the hardnumber and query the sprite textRect Vector2u for height
	if (posY  > maxHeight-62 ) posY = height - 62; 
	if (posY  < minHeight) posY = minHeight; 
	
	//update the sprite sheet nao.
	unitSprite->setPosition(posX - backX, posY - backY);
}

/*
 * as is - this combines all buttons under the same cooldown
 */

void projectile::updateBehavior() {


	burnCooldown(); 
}

void projectile::updateHitBox() {
	defHB->tL->X((double)posX+93);
	defHB->tL->Y((double)posY);
	defHB->bR->X((double)posX+133);
	defHB->bR->Y((double)posY+62);
		
}


bool projectile::getCooldown() {
	return movCooldown;
}

bool projectile::burnCooldown() {
	movCooldown = false;
	inputTimer = std::chrono::duration_cast<std::chrono::milliseconds>(inputTimer).zero();

}
