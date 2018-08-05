#ifndef BASEUNIT_H
#define BASEUNIT_H
#include <SFML/Graphics.hpp>
#include "moveGrid.h"
#include <vector>
#include "hitBox.h"
#include "projectile.h"



class baseUnit {

	public:
		baseUnit(); 	
		baseUnit(uint32_t player_); 	
		~baseUnit();
		virtual void print() = 0;
		std::vector<sf::Sprite> * sprites;
		sf::Sprite * unitSprite;
		//std::vector<projectile *> projectiles; 
		hitBox * defHB, * offHB;
		bool alive, active, projReady, atkCheck;
		int32_t posX, posY, velX, velY,  hp, tId; 
		double maxHeight, minHeight; // POINT OF ORDER - MAX IS MAX MAGNITUED, THE FLOOR -- MIN IS MIN MAGNITUDE, THE CEILING!!!
		uint32_t player, spriteOffset, numSprites, projConst;
		std::chrono::milliseconds spriteTimer, spriteTrigger, inputTimer, inputTrigger, aiTimer, aiTrigger;
		// apparently - enums are not exclusive to enum types so just collapse ai and player states into one enum
		enum unitState {right, left, idle, attack, toPlayer, toSpot, dLeft, uLeft, dRight, uRight}; 
		unitState curState;
		bool isValMove(uint32_t destX, uint32_t destY);
		void setCeiling(double ceiling_);
		void setFloor(double floor_);
		virtual void updateTiming(std::chrono::milliseconds deltaTime);
		virtual void updateBehavior();
		virtual void updateDefHitBox();
		virtual void updateOffHitBox();
		virtual void inputHandling() = 0;
		virtual void hbCheck( std::vector< baseUnit * > * enemies ) = 0;
		virtual void fireProjectile( projectile * proj) = 0;
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
