#ifndef BASEUNIT_H
#define BASEUNIT_H
#include <SFML/Graphics.hpp>
#include <vector>

class baseUnit {

	public:
		baseUnit(); 	
		baseUnit(uint32_t player_); 	
		~baseUnit();
		virtual void print() = 0;
		sf::Sprite unitSprite, unitInfoSprite;
		const sf::Texture * gridSprite;
		bool movCooldown;
		uint32_t posX, posY, atk, mvt, def, player, spriteOffset, numSprites, spriteTimer, spriteTrigger;
		int32_t hp;
// !!! TODO[ ] implement sprite timer after core PoC phase.
//		std::chrono::nanoseconds spriteTimer;
//		std::chrono::milliseconds cursTrigger{250};
//		void updateTimer(std::chrono::nanoseconds timer);
		void moveX(int64_t moveX);
		void moveY(int64_t moveY);

};


#endif
