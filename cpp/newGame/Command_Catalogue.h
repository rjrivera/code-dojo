#ifndef COMMAND_CATALOGUE_H
#define COMMAND_CATALOGUE_H
#include <string>
#include <vector> 
#include <map>
#include "cursor.h"
#include "baseTerrain.h"
#include "ui_hby.h"

static void move(std::map< 

/*
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
							switch(curActionMenuState) { 
								case(move) : {
									myC = cursorStack[myC->stackInd - 1];					
									myC->burnCooldown();
									destBSlot = getBSlot(myC->posX, myC->posY);
									bool valMove = board[sourceBSlot]->attachedUnit->isValMove(myC->posX, myC->posY);
								if ( destBSlot != sourceBSlot && valMove &&
										board[destBSlot]->attachedUnit == nullptr )  {
										board[destBSlot]->attachUnit(curUnit);
										board[sourceBSlot]->detachUnit();	
									 
								}
									curInputState = terrainSelect;
									break;
									}
								case(atk) : {
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
							
						}				
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
							if (curUI < uiElements->at(actionMenu)->size() - 1 ) { // I need to update this to be based off of the ui_hby data structure. 

*/
#endif
