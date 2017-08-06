#ifndef BASEUNIT_H
#define BASEUNIT_H
#include <SFML/Graphics.hpp>

class baseUnit {

	public:
		baseUnit(); 	
		~baseUnit();
		virtual void print() = 0;
		sf::Sprite unitSprite;
		bool movCooldown;
		uint64_t posX, posY, hp, atk, mvt;
		std::vector<std::pair<uint64_t, uint64_t> > validMoves;
// !!! TODO[ ] implement sprite timer after core PoC phase.
//		std::chrono::nanoseconds spriteTimer;
//		std::chrono::milliseconds cursTrigger{250};
//		void updateTimer(std::chrono::nanoseconds timer);
		void movePosX(uint64_t moveX);
		void movePosY(uint64_t moveY);


};


#endif
