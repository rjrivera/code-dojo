#include <SFML/Graphics.hpp>
#include "moveGrid.h"
#include <vector>
#include "hitBox.h"
#include "starProj.h"
#include "Project_Constants.h"
#include <cmath>
#include <iostream>
#include <vector>

starProj::starProj()  	{
	std::cout << "starProj instatiated\n";
	
}

starProj::starProj(std::vector<const sf::Texture *>& images_) {
	
	sprites = new std::vector<sf::Sprite>();
	std::cout << "vector<sf::sprite> built\n";
	for (int32_t i = 0; i < maxProjState_const; i++) {
		sprites->push_back(sf::Sprite());

		sprites->at(i).setTexture(*(images_[i]));

		sprites->at(i).setPosition(0, 0);
	}

	posX = posY = velX = velY = 0;
	posX = 128;
	numSprites = 1;
	spriteOffset = 0; 
	spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();

	spriteTrigger = std::chrono::milliseconds(80);
	// hmmmm - inputTrigger IS an projTrigger	
	
	projTrigger = std::chrono::milliseconds(2000);
	projTimer = std::chrono::duration_cast<std::chrono::milliseconds>(projTimer).zero();
	unitSprite = &sprites->at(0);
	unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*20,0,20,20));
	movCooldown = true;
	active = false;
	defHB = new hitBox(new Point((double)posX+93, (double)posY), new Point((double)posX+133, (double)posY+62));
	velX = 12;
	velY = std::sin((double)posX);
	
}

starProj::~starProj(){
	std::cout << "starProj object destroyed\n";

}

starProj::starProj(const projectile& sauce) {
	sprites = new std::vector<sf::Sprite >();
	sprites = sauce.sprites;
	unitSprite = sauce.unitSprite;
	defHB = new hitBox();
	offHB = new hitBox();
	// look at making a clone constructor for HB's
	defHB = sauce.defHB;
	offHB = sauce.offHB;
	alive = active = false;
	posX = sauce.posX;
	posY = sauce.posY;
	velX = sauce.velX;
	velY = sauce.velY;
	hp = sauce.hp;
	tId = sauce.tId; 
	player = sauce.player;
	spriteOffset = sauce.spriteOffset;
	numSprites = sauce.numSprites;
	spriteTimer = sauce.spriteTimer;
	spriteTrigger = sauce.spriteTrigger;
	projTimer = sauce.projTimer;
	projTrigger = sauce.projTrigger;
}
starProj& starProj::operator= (const starProj& sauce) {
	sprites = new std::vector<sf::Sprite >();
	sprites = sauce.sprites;
	unitSprite = sauce.unitSprite;
	defHB = new hitBox();
	offHB = new hitBox();
	// look at making a clone constructor for HB's
	defHB = sauce.defHB;
	offHB = sauce.offHB;
	alive = active = false;
	posX = sauce.posX;
	posY = sauce.posY;
	velX = sauce.velX;
	velY = sauce.velY;
	hp = sauce.hp;
	tId = sauce.tId; 
	player = sauce.player;
	spriteOffset = sauce.spriteOffset;
	numSprites = sauce.numSprites;
	spriteTimer = sauce.spriteTimer;
	spriteTrigger = sauce.spriteTrigger;
	projTimer = sauce.projTimer;
	projTrigger = sauce.projTrigger;
	return *this;	
}

void starProj::updateTiming(std::chrono::milliseconds deltaTime){
	spriteTimer += deltaTime;
	if (spriteTimer >= spriteTrigger)  {
		spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
		spriteOffset++;
		if (spriteOffset>=numSprites) spriteOffset = 0; 
		unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*20,0,20,20));
//todo [ ] MOVE THIS TO A DIFFERENT TIMER
		posX += velX;
		posY += velY;	
	}
	velY = std::sin((double)posX) * 10;
	std::cout<< "VELY of projectile --- " << velY << std::endl;
	std::cout<< "POSX of projectile --- " << posX << std::endl;
	projTimer += deltaTime;
	if ( projTimer >= projTrigger ) {
		projTimer = std::chrono::duration_cast<std::chrono::milliseconds>(projTimer).zero();
		active = false;
	}
	
	//update the sprite sheet nao.
	unitSprite->setPosition(posX - backX, posY - backY);
}

/*
 * as is - this combines all buttons under the same cooldown
 */

void starProj::updateBehavior() {


	burnCooldown(); 
}

void starProj::updateHitBox() {
	defHB->tL->X((double)posX+93);
	defHB->tL->Y((double)posY);
	defHB->bR->X((double)posX+133);
	defHB->bR->Y((double)posY+62);
		
}


bool starProj::getCooldown() {
	return movCooldown;
}

bool starProj::burnCooldown() {
	movCooldown = false;

}
