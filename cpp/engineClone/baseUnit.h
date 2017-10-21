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
		bool movCooldown;
		uint32_t posX, posY, hp, player, spriteOffset, numSprites;
		std::chrono::milliseconds spriteTimer, spriteTrigger;
		enum unitState {right, left, idle}; 
		unitState curState;
		void movePosX(int64_t moveX);
		void movePosY(int64_t moveY);
		bool isValMove(uint32_t destX, uint32_t destY);
		virtual void updateTiming(std::chrono::milliseconds deltaTime) = 0;



};


#endif
