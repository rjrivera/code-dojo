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
int viewPortRight = 540;
int viewPortLeft = 100;

// engine management
int maxEnemies = 2;
int numEnemies = 0;

int curTerrain = 0;

//terrain textures
const int maxTerrain_const =1;
const int pirateBkg_const = 1;
const int pirate2Bkg_const = 2;

//unit textures
const int maxUnit_const = 1;
const int maxUnitState_const = 4; // all units need not use all 3

const int donUnit_const = 1;
const int footPurpUnit_const = 2; // picking 23 to demonstrate the arbitrary nature of the constant itself EDIT; Lol jokes on me, not arb

//projectile textures
const int maxProj_const = 1;
const int starProj_const = 1;
const int maxProjState_const = 2; // all units need not use all 3
//experiment, globally accessible vector of textures
std::vector<sf::Texture *> projTexts;

//there can be only one
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0,9);

//signals
bool atkCheck = false;
#endif
