#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
#include "moveGrid.h"
#include <vector>
#include "hitBox.h"
#include "projectile.h"



class projectile {

	public:
		projectile(); 	
		projectile(std::vector<const sf::Texture *>& images_);
		~projectile();
		std::vector<sf::Sprite> * sprites;
		sf::Sprite * unitSprite;
		hitBox * defHB, * offHB;
		bool alive, active;
		int32_t posX, posY, velX, velY,  hp, tId; 
		uint32_t player, spriteOffset, numSprites;
		std::chrono::milliseconds spriteTimer, spriteTrigger, projTimer, projTrigger;
		virtual void updateTiming(std::chrono::milliseconds deltaTime);
		virtual void updateBehavior();
		virtual void updateHitBox();
	//	virtual void inputHandling();
		bool movCooldown;

//	private:
		void movePosX(int32_t moveX);
		void movePosY(int32_t moveY);
		void moveVelX(int32_t moveX);
		void moveVelY(int32_t moveY);

		virtual bool getCooldown();
		virtual bool burnCooldown();



};


#endif
