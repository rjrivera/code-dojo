#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>
#include "baseUnit.h"

class gameState {

	public:
		gameState(); 	
		gameState(uint32_t width_, uint32_t height_);
		~gameState();
		std::vector<baseTerrain*> * board;
		uint32_t width, height, curPlayer;
};


#endif
