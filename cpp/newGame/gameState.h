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
		std::map<uint32_t, baseTerrain*> * buildings;// this is a referential container...all items in this map are also in the board.
		// the board is authoritative, the buildings is used for accessibility. 
		uint32_t width, height, curPlayer, numPlayers;
		void incrementPlayer();
};


#endif
