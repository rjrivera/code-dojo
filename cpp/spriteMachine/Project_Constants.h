#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H
#include <string>
#include <vector> 

const int maxPlayers_const = 2;

// utility setup
const int maxMenuDepth = 3;
int height = 0;
int width = 0;
//terrain textures
const int maxTerrain_const =7;
const int roadTerrain_const = 1; 
const int mountTerrain_const = 2; 
const int waterTerrain_const = 3; 
const int plainTerrain_const = 4;
const int forestTerrain_const = 5;
const int moveTerrain_const = 6;
const int atkTerrain_const = 7;
//unit textures
const int maxUnit_const = 1;
const int infantryUnit_const = 1;

//ui textures
const int maxUI_const		= 4;
const int ui1_const		= 1;
const int ui2_const		= 2;
const int ui3_const		= 3;
const int ui4_const		= 4;

const int tilesize_const = 16;
const int menusize_const = tilesize_const * 2;
//board container

#endif
