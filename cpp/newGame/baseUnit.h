#ifndef BASEUNIT_H
#define BASEUNIT_H
#include <SFML/Graphics.hpp>
#include "moveGrid.h"
//#include "baseTerrain.h"



class baseUnit {

	public:
		baseUnit(); 	
		~baseUnit();
		virtual void print() = 0;
		sf::Sprite unitSprite;
		const sf::Texture * gridSprite;
		bool movCooldown;
		uint64_t posX, posY, hp, atk, mvt;
		std::vector<moveGrid * > * validMoves;
// !!! TODO[ ] implement sprite timer after core PoC phase.
//		std::chrono::nanoseconds spriteTimer;
//		std::chrono::milliseconds cursTrigger{250};
//		void updateTimer(std::chrono::nanoseconds timer);
		void movePosX(uint64_t moveX);
		void movePosY(uint64_t moveY);
		virtual void initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY);
		bool isValMove(uint32_t destX, uint32_t destY);



};


#endif
