#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H
#include <string>
#include <vector> 
#include "baseTerrain.h"

//terrain textures
const int maxTerrain_const = 5;
const int plainTerrain_const = 0;
const int mountTerrain_const = 1; 
const int waterTerrain_const = 2; 
const int roadTerrain_const = 3; 
const int forestTerrain_const = 4;

const int tilesize_const = 16;

//board container
extern std::vector<baseTerrain*> board = std::vector<baseTerrain*>();

//board index calculator function
uint64_t getBSlot(uint64_t posX_, uint64_t posY_);

#endif
