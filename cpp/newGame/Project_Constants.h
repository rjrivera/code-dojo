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
const int maxTerrain_const = 10;
const int roadTerrain_const = 1; 
const int mountTerrain_const = 2; 
const int waterTerrain_const = 3; 
const int plainTerrain_const = 4;
const int forestTerrain_const = 5;
const int moveTerrain_const = 6;
const int atkTerrain_const = 7;
const int barracksTerrain_const = 8;
const int barracks1Terrain_const = 9;
const int barracks2Terrain_const = 10;
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

//dashboard textures
const int maxDash_const		= 1;
const int dash1_const		= 1;



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
//uint32_t getBSlot(uint32_t posX_, uint32_t posY_);
void battle(uint32_t attackerInd_, uint32_t defenderInd_, std::vector<baseTerrain*>& board_);
//int32_t getBelowBSlot(int32_t sourceBSlot); 
//int32_t getAboveBSlot(int32_t sourceBSlot); 

enum actionMenuState {move, atkUI, back, atkB};
enum inputState {terrainSelect, gameMenu, terrainInfo, unitInfo, atkSelect, unitSelected, actionMenu, lastEnum};

//given a cursors raw x,y coord. extrapolate which slot of the board container is associated with the cursors pos. 
static uint32_t getBSlot(uint32_t posX_, uint32_t posY_) {
	uint32_t scaledX, scaledY;
	scaledX = posX_/tilesize_const;
	scaledY = posY_/tilesize_const;
	return ((scaledY*width) + scaledX);

}

static int32_t getScaledPosX(uint32_t bSlot_) {
	if ( bSlot_ >= width*height || bSlot_ < 0  ) return -1;
	return ( bSlot_ % width ) * tilesize_const;

}

static int32_t getScaledPosY(uint32_t bSlot_) {
	if ( bSlot_ >= width*height || bSlot_ < 0  ) return -1;
	return ( (bSlot_ + 1) / width ) * tilesize_const;
}

// must be signed to indicate when outside of bounds
static int32_t getAboveBSlot(int32_t sourceBSlot) {
	return sourceBSlot - width;
}

// must be signed to indicate when outside of bounds
static int32_t getBelowBSlot(int32_t sourceBSlot) {
	if ((sourceBSlot + width) > (height * width)) return -1; 
	else return (sourceBSlot + width);
}

#endif
