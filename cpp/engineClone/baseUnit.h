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
		bool alive, active;
		int32_t posX, posY, velX, velY,  hp, tId; 
		double maxHeight, minHeight; // POINT OF ORDER - MAX IS MAX MAGNITUED, THE FLOOR -- MIN IS MIN MAGNITUDE, THE CEILING!!!
		uint32_t player, spriteOffset, numSprites;
		std::chrono::milliseconds spriteTimer, spriteTrigger, inputTimer, inputTrigger, aiTimer, aiTrigger;
		// apparently - enums are not exclusive to enum types so just collapse ai and player states into one enum
		enum unitState {right, left, idle, attack, toPlayer, toSpot, dLeft, uLeft, dRight, uRight}; 
		unitState curState;
		bool isValMove(uint32_t destX, uint32_t destY);
		void setCeiling(double ceiling_);
		void setFloor(double floor_);
		virtual void updateTiming(std::chrono::milliseconds deltaTime);
		virtual void updateBehavior();
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
