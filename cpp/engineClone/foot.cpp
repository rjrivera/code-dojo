#include "foot.h"
#include "Project_Constants.h"
#include <iostream>
#include <vector>

foot::foot()  	{
	std::cout << "foot instatiated\n";
	
}

foot::foot(std::vector<const sf::Texture *>& images_) : baseUnit(){
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
// hmmmm - inputTrigger IS an aiTrigger	
	aiTrigger = std::chrono::milliseconds(35);
	aiTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
	curState = unitState(idle);
	unitSprite = &(sprites->at(curState));
	unitSprite->setTextureRect(sf::IntRect(
			spriteOffset*40,0,40,62));
	movCooldown = true;
}

foot::~foot(){
	std::cout << "foot object destroyed\n";

}

void foot::print() {
	std::cout << "foot object printed\n";

}

void foot::updateTiming(std::chrono::milliseconds deltaTime){
	spriteTimer += deltaTime;
	inputTimer += deltaTime;
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
	if (inputTimer >= inputTrigger)  {
		movCooldown = true;
		inputTimer = std::chrono::duration_cast<std::chrono::milliseconds>(spriteTimer).zero();
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

void foot::updateBehavior() {
	if (!getCooldown())  return;
	// iteration one, preprogrammed state pathing - TODO[ ] rng state pick - easy implementation, just rng to pick state, then keep this prototype as the behavior swap logic. 
	switch (distribution(generator)) {
		case 0:
			curState = right;
			break;
		case 1:
			curState = left;
			break; 
		case 2:
			curState = attack;
			break;
		case 3:
			curState = idle;
			break;
		case 4:
			curState = dLeft;
			break;
		case 5:
			curState = uLeft;
			break;
		case 6:
			curState = dRight;
			break;
		case 7:
			curState = uRight;
			break;
		default:
			curState = idle;
			break;
	}
// now do the action of new state
	switch (curState) { 
		case (idle) :
			moveVelX(0);
			unitSprite = &(sprites->at(curState));
			break;
		case (right) :		
			moveVelX(3);
			unitSprite = &(sprites->at(curState));
			break;
		case (left) :
			unitSprite = &(sprites->at(curState));
			moveVelX(-3);
			moveVelY(0);
			break;
		case (attack) :
			unitSprite = &(sprites->at(curState));
			moveVelX(0);
			break;
		case (dLeft) :
			unitSprite = &(sprites->at(left));
			moveVelX(-3);
			moveVelY(3);
			break;
		case (dRight) :
			unitSprite = &(sprites->at(right));
			moveVelX(3);
			moveVelY(3);
			break;
		case (uRight) :
			unitSprite = &(sprites->at(right));
			moveVelX(3);
			moveVelY(-3);
			break;
		case (uLeft) :
			unitSprite = &(sprites->at(left));
			moveVelX(3);
			moveVelY(-3);
			break;
			// higher priority attacks must be near the bottom to provide defacto override	
	
	}

	burnCooldown(); 
}
/*
 * updateBehavoir is a proof-of-concept function to capture ai behavior - 
 * characters will be similar in nature but will still require customization and tuning
 * relies on random number generator. 
 *
 */
void foot::inputHandling(){
	if (!getCooldown())  return;

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		moveVelX(3);
		curState = unitState(right);
		unitSprite = &(sprites->at(curState));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
		curState = unitState(left);
		moveVelX(-3);
		unitSprite = &(sprites->at(curState));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )  {
		curState = unitState(attack);
		unitSprite = &(sprites->at(curState));
		moveVelX(0);
		moveVelY(0);
	}
	else {
		curState = unitState(idle);
		unitSprite = &(sprites->at(curState));
		moveVelX(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
		moveVelY(3);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
		moveVelY(-3);
	}
	else {
		moveVelY(0);
	}

	// higher priority attacks must be near the bottom to provide defacto override	



	burnCooldown(); 

}

bool foot::getCooldown() {
	return movCooldown;
}

bool foot::burnCooldown() {
	movCooldown = false;
	inputTimer = std::chrono::duration_cast<std::chrono::milliseconds>(inputTimer).zero();

}
