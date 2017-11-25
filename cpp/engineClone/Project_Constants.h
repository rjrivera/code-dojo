#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H
#include <string>
#include <vector> 
#include <random>
#include "baseTerrain.h"

const int maxPlayers_const = 2;

// networking =====================
#define MYPORT 3490
#define CLIENTPORT 3491

// utility setup
const int maxMenuDepth = 3;
int height = 400;
int width = 640;
int backX = 0;
int backY = 0;
//terrain textures
const int maxTerrain_const =1;
const int pirateBkg_const = 1;

//unit textures
const int maxUnit_const = 1;
const int maxUnitState_const = 4; // all units need not use all 3

const int donUnit_const = 1;
const int footPurpUnit_const = 2; // picking 23 to demonstrate the arbitrary nature of the constant itself EDIT; Lol jokes on me, not arb

//there can be only one
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0,9);


#endif
