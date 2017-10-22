#ifndef BASEUNIT_H
#define BASEUNIT_H
#include <SFML/Graphics.hpp>
#include "moveGrid.h"
#include <vector>
//#include "baseTerrain.h"



class baseUnit {

	public:
		baseUnit(); 	
		baseUnit(uint32_t player_); 	
		~baseUnit();
		virtual void print() = 0;
		std::vector<sf::Sprite> * sprites;
		sf::Sprite * unitSprite;
		int32_t posX, posY, velX, velY,  hp; 
		uint32_t player, spriteOffset, numSprites;
		std::chrono::milliseconds spriteTimer, spriteTrigger, inputTimer, inputTrigger;
		enum unitState {right, left, idle}; 
		unitState curState;
		bool isValMove(uint32_t destX, uint32_t destY);
		virtual void updateTiming(std::chrono::milliseconds deltaTime);
		virtual void inputHandling() = 0;
		bool movCooldown;

//	private:
		void movePosX(int32_t moveX);
		void movePosY(int32_t moveY);
		void moveVelX(int32_t moveX);
		void moveVelY(int32_t moveY);

		virtual bool getCooldown() = 0;
		virtual bool burnCooldown() = 0;



};


#endif
