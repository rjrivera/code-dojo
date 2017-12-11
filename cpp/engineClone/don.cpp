#include "don.h"
#include "Project_Constants.h"
#include <iostream>
#include <vector>

don::don()  	{
	std::cout << "don instatiated\n";
	
}

don::don(std::vector<const sf::Texture *>& images_) : baseUnit(){
	sprites = new std::vector<sf::Sprite>();
	std::cout << "vector<sf::sprite> built\n";
	for (int32_t i = 0; i < maxUnitState_const; i++) {
		sprites->push_back(sf::Sprite());

		sprites->at(i).setTexture(*(images_[i]));

		sprites->at(i).setPosition(0, 0);
	}
	posX = posY = velX = velY = 0;
	numSprites = 6;
	spriteOffset = 0; 
	spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();

	spriteTrigger = std::chrono::milliseconds(80);
	inputTrigger = std::chrono::milliseconds(35);

	curState = unitState(idle);
	unitSprite = &(sprites->at(curState));
	unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*93,0,93,62));
	movCooldown = true;
	// make and define your hitbox for your basic attack as an alpha. advanced battle will take some time
	hB = new hitBox(new Point((double)posX+93, (double)posY), new Point((double)posX+133, (double)posY+40));
}

don::~don(){
	std::cout << "don object destroyed\n";

}

void don::print() {
	std::cout << "don object printed\n";

}

void don::updateTiming(std::chrono::milliseconds deltaTime){
	spriteTimer += deltaTime;
	inputTimer += deltaTime;
	if (spriteTimer >= spriteTrigger)  {
		spriteTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
		spriteOffset++;
		if (spriteOffset>=numSprites) spriteOffset = 0; 
		unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*93,0,93,62));
//todo [ ] MOVE THIS TO A DIFFERENT TIMER
 		// posX will be local - not global.
 		if (posX + velX <= viewPortRight && velX > 0 ) posX += velX;
		else if (velX > 0) backX += velX;

 		if (posX + velX >= viewPortLeft && velX < 0) posX += velX;
		else if (velX < 0 )  backX += velX;


		posY += velY;
	}
	if (inputTimer >= inputTrigger)  {
		movCooldown = true;
		inputTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
	}

	//update the sprite sheet nao.
	unitSprite->setPosition(posX, posY);
}

/*
 * as is - this combines all buttons under the same cooldown
 */

void don::inputHandling(){
	if (!getCooldown())  return;

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		moveVelX(5);
		curState = unitState(right);
		unitSprite = &(sprites->at(curState));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
		curState = unitState(left);
		moveVelX(-5);
		unitSprite = &(sprites->at(curState));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )  {
		curState = unitState(attack);
		unitSprite = &(sprites->at(curState));
		moveVelX(0);
		moveVelY(0);
		hB->tL->X((double)posX+93+backX);
		hB->tL->Y((double)posY+backY);
		hB->bR->X((double)posX+153+backX);
		hB->bR->Y((double)posY+40+backY);
		std::cout << "tl x y and bR x y: (" << hB->tL->X() << ", " << hB->tL->Y() <<
			") ( " << hB->bR->X() << ", " << hB->bR->Y() << ")";
		atkCheck = true;

	}
	else {
		curState = unitState(idle);
		unitSprite = &(sprites->at(curState));
		moveVelX(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
		moveVelY(5);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
		moveVelY(-5);
	}
	else {
		moveVelY(0);
	}

	// higher priority attacks must be near the bottom to provide defacto override	



	burnCooldown(); 
}

bool don::getCooldown() {
	return movCooldown;
}

bool don::burnCooldown() {
	movCooldown = false;
	inputTimer = std::chrono::duration_cast<std::chrono::milliseconds>(inputTimer).zero();

}
