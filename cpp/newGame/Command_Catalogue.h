#ifndef COMMAND_CATALOGUE_H
#define COMMAND_CATALOGUE_H
#include <string>
#include <vector> 
#include <map>
#include "cursor.h"
#include "gameState.h"
#include "baseTerrain.h"
#include "ui_hby.h"
#include "Project_Constants.h"

// return code for client response/state manipulation
static int cmdMove( gameState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, uint32_t destBSlot, uint32_t sourceBSlot ) {
//	myC = cursorStack[myC->stackInd - 1];					
	myC->burnCooldown();
	destBSlot = getBSlot(myC->posX, myC->posY);
	bool valMove = gState_->board->at(sourceBSlot)->attachedUnit->isValMove(myC->posX, myC->posY);
	if ( destBSlot != sourceBSlot && valMove &&
		gState_->board->at(destBSlot)->attachedUnit == nullptr )  {
		gState_->board->at(destBSlot)->attachUnit(curUnit, gState_->board);
		gState_->board->at(sourceBSlot)->detachUnit();					 
	}
	curInputState_ = terrainSelect;
	return 0;

};

static int cmdBackMenu( gameState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, uint32_t destBSlot, uint32_t sourceBSlot ) {
	// this should be based off a stack
	std::cout << "old inputstate before actioning a back menu" << curInputState_ << std::endl;
	myC->burnCooldown();
	curInputState_ = terrainSelect;
	std::cout << "old inputstate before actioning a back menu" << curInputState_ << std::endl;
	return 0;
};

	/*							case(atk) : {
									// get the attack menu cursor
									myC = cursorStack[myC->stackInd + 1];
									myC->burnCooldown();
									curInputState = atkSelect;
									if (enemyNeighbors->size() == 0) {
										enemyNeighborIndex = -1;
										myC->movePosXAbs(0);
										myC->movePosYAbs(0);
									}
									else {
										enemyNeighborIndex = 0;
										uint32_t atkBSlot = enemyNeighbors->at(enemyNeighborIndex);
										int32_t absX = getScaledPosX(atkBSlot);
										int32_t absY = getScaledPosY(atkBSlot);
										if (absX >= 0 && absY >= 0) { 
											myC->movePosXAbs(absX);
											myC->movePosYAbs(absY);
											myC->burnCooldown();
										}
									}
									break;
									}
								case(back) : { 
									myC = cursorStack[myC->stackInd - 1];
									myC->burnCooldown();
									curInputState = terrainSelect;
									break;
									}
							}
	


	return 0;
};


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						
						}				
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
							if (curUI < uiElements->at(actionMenu)->size() - 1 ) { // I need to update this to be based off of the ui_hby data structure. 

*/
#endif
