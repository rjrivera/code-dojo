#include "gameState.h"
#include "Project_Constants.h"
#include "baseTerrain.h"
#include <iostream>

gameState::gameState():curPlayer(1), numPlayers(2){
	std::cout << "gameState initializing\n";
	board = new std::vector<baseTerrain*>();
	buildings = new std::map<uint32_t, std::vector<baseTerrain*> *>;
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 0, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 1, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 2, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 3, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 4, new std::vector< baseTerrain*>()  ) );

}

gameState::gameState(uint32_t width_, uint32_t height_): width(width_), height(height_), curPlayer(1),numPlayers(2) {
	std::cout << "gameState initializing\n";
	board 	= new std::vector<baseTerrain*>();
	buildings = new std::map<uint32_t, std::vector<baseTerrain*> *>;
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 0, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 1, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 2, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 3, new std::vector< baseTerrain*>()  ) );
	buildings->insert( std::pair<uint32_t, std::vector<baseTerrain*> *>( 4, new std::vector< baseTerrain*>()  ) );
	
}

void gameState::incrementPlayer(){
	curPlayer++;
	if(curPlayer == numPlayers + 1) curPlayer = 1;
}
