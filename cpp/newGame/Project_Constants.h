#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H
#include <string>
#include <vector> 
#include "baseTerrain.h"
//#include "ui_hby.h"

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
const int maxUnit_const = 3;
const int infantryUnit_const = 1;
const int tankUnit_const = 2;
const int planeUnit_const = 3;
//ui textures
const int maxUI_const		= 4;
const int ui1_const		= 1;
const int ui2_const		= 2;
const int ui3_const		= 3;
const int ui4_const		= 4;

//const int blueMenu_const	= 1;
//const int maxUIDepth		= 1;
// checklist for adding new ujnits
// [ ] update constants
// [ ] rename textures accordingly (push vals right by one)
//const int boatUnit_const = 3;

const int tilesize_const = 16;
const int menusize_const = tilesize_const * 2;
//board container
//extern std::vector<baseTerrain*> board = std::vector<baseTerrain*>(); // this needs to be remove TODO[ ] this is terribly bad practice. 


//board index calculator function
uint32_t getBSlot(uint32_t posX_, uint32_t posY_);
void battle(uint32_t attackerInd_, uint32_t defenderInd_, std::vector<baseTerrain*>& board_);
int32_t getBelowBSlot(int32_t sourceBSlot); 
int32_t getAboveBSlot(int32_t sourceBSlot); 

enum actionMenuState {move, atk, back};
enum inputState {terrainSelect, gameMenu, terrainInfo, unitInfo, atkSelect, unitSelected, actionMenu, lastEnum};
#endif
