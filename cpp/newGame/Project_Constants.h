#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H
#include <string>
#include <vector> 
#include "baseTerrain.h"

//terrain textures
const int maxTerrain_const = 6;
const int plainTerrain_const = 0;
const int mountTerrain_const = 1; 
const int waterTerrain_const = 2; 
const int roadTerrain_const = 3; 
const int forestTerrain_const = 4;
const int moveTerrain_const = 5;
//unit textures
const int maxUnit_const = 3;
const int infantryUnit_const = 0;
const int tankUnit_const = 1;
const int planeUnit_const = 2;
const int boatUnit_const = 3;

const int tilesize_const = 16;

//board container
extern std::vector<baseTerrain*> board = std::vector<baseTerrain*>();


//board index calculator function
uint32_t getBSlot(uint32_t posX_, uint32_t posY_);
void battle(uint32_t attackerInd_, uint32_t defenderInd_, std::vector<baseTerrain*>& board_);
#endif
