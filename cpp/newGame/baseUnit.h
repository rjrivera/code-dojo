#ifndef BASEUNIT_H
#define BASEUNIT_H
#include <SFML/Graphics.hpp>
#include "moveGrid.h"

class baseUnit {

	public:
		baseUnit(); 	
		~baseUnit();
		virtual void print() = 0;
		sf::Sprite unitSprite, gridSprite;
		bool movCooldown;
		uint64_t posX, posY, hp, atk, mvt;
		std::vector<moveGrid * > * validMoves;
// !!! TODO[ ] implement sprite timer after core PoC phase.
//		std::chrono::nanoseconds spriteTimer;
//		std::chrono::milliseconds cursTrigger{250};
//		void updateTimer(std::chrono::nanoseconds timer);
		void movePosX(uint64_t moveX);
		void movePosY(uint64_t moveY);
		virtual void initMoveGrids(uint32_t mvtRemaining);



};


#endif
