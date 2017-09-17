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
		sf::Sprite unitSprite;
		const sf::Texture * gridSprite;
		bool movCooldown;
		uint32_t posX, posY, atk, mvt, def, player;
		int32_t hp;
		std::vector<uint32_t> *validMoves;
// !!! TODO[ ] implement sprite timer after core PoC phase.
//		std::chrono::nanoseconds spriteTimer;
//		std::chrono::milliseconds cursTrigger{250};
//		void updateTimer(std::chrono::nanoseconds timer);
		void movePosX(uint64_t moveX);
		void movePosY(uint64_t moveY);
		virtual void initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY);
		//prototyping function which will migrate to unit classes (direct fire units will use baseUnit definition, indirect will override)
		int32_t findFirstNeighbor(); 
		//void defineGridSprite(const sf::Texture * image);
		bool isValMove(uint32_t destX, uint32_t destY);



};


#endif
