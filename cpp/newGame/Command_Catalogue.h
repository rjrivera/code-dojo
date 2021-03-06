#ifndef COMMAND_CATALOGUE_H
#define COMMAND_CATALOGUE_H
#include <string>
#include <vector> 
#include <map>
#include <cmath>
#include "cursor.h"
#include "gameState.h"
#include "baseTerrain.h"
#include "baseUnit.h"
#include "ui_hby.h"
#include "Project_Constants.h"

// return code for client response/state manipulation
// Command Catalogue will handle the actions the game server should until we migrate to a proper client / server paradigm. 
static int cmdMove( gameState * gState_, clientState * cState_ ) {
//	myC = cursorStack[myC->stackInd - 1];					
	cState_->myC->burnCooldown();
	cState_->destBSlot = getBSlot( cState_->myC->posX, cState_->myC->posY);
	bool valMove = gState_->board->at(cState_->sourceBSlot)->attachedUnit->isValMove(cState_->myC->posX, cState_->myC->posY);
	if ( cState_->destBSlot != cState_->sourceBSlot && valMove &&
		gState_->board->at( cState_->destBSlot )->attachedUnit == nullptr )  {
		gState_->board->at( cState_->destBSlot )->attachUnit( cState_->selectedUnit, gState_->board);
		gState_->board->at( cState_->sourceBSlot )->detachUnit();					 
		gState_->incrementPlayer();
	}
	cState_->curInputState = terrainSelect;
	return 0;

};

static int cmdBackMenu( gameState * gState_, clientState * cState_ ) {
	// this should be based off a stack
	cState_->myC->burnCooldown();
	cState_->curInputState = terrainSelect;
	return 0;
};

static int cmdAtkSelect( gameState * gState_, clientState * cState_ ) {
	cState_->myC->burnCooldown();
	cState_->destBSlot = getBSlot( cState_->myC->posX, cState_->myC->posY);
	bool valMove = gState_->board->at(cState_->sourceBSlot)->attachedUnit->isValMove(cState_->myC->posX, cState_->myC->posY);
	if ( cState_->destBSlot != cState_->sourceBSlot && valMove &&
		gState_->board->at( cState_->destBSlot )->attachedUnit == nullptr )  {
		gState_->board->at( cState_->destBSlot )->attachUnit( cState_->selectedUnit, gState_->board);
		gState_->board->at( cState_->sourceBSlot )->detachUnit();					 
		gState_->incrementPlayer();
	}
	cState_->selectedUnit->findEnemyNeighbors(cState_->myC->posX, cState_->myC->posY, gState_->board);
	cState_->curInputState = atkSelect;
	if( cState_->selectedUnit->enemyNeighbors->size() > 0 ) {
		cState_->myC->movePosXAbs( getScaledPosX((uint32_t)cState_->selectedUnit->enemyNeighbors->at(0)) ); 
		cState_->myC->movePosYAbs( getScaledPosY((uint32_t)cState_->selectedUnit->enemyNeighbors->at(0)) ); 
		cState_->enemyNeighborsIndex = 0;
	}
	return 0;

};

//enum actionMenuState {move, atkUI, back, atkB};
//enum inputState {terrainSelect, gameMenu, terrainInfo, unitInfo, atkSelect, unitSelected, actionMenu, lastEnum};

static int cmdAtk( gameState * gState_, clientState * cState_ ) {
	cState_->myC->burnCooldown();
	cState_->curInputState = terrainSelect;
	baseUnit * defender = gState_->board->at( cState_->selectedUnit->enemyNeighbors->at( cState_->enemyNeighborsIndex ) )->attachedUnit;
	baseUnit * attacker = cState_->selectedUnit;
	baseTerrain * terrain = gState_->board->at( cState_->destBSlot );
	// place holder for battle initiation. 
	int atkDamage = ( attacker->atk * (attacker->hp / 10 ) ) - ( defender->def * (defender->hp / 10) ) -  (terrain->defBonus * ( defender->hp / 10 ) );
	defender->hp -= std::max(0, atkDamage);
	if( defender->hp <= 0 ) {
		delete gState_->board->at( cState_->destBSlot )->attachedUnit;
		gState_->board->at( cState_->destBSlot )->attachedUnit = nullptr;
		return 1;
	}
	terrain = gState_->board->at( cState_->sourceBSlot );
	atkDamage = ( defender->atk * (defender->hp % 10 ) ) - ( attacker->def * (attacker->hp % 10) ) -  (terrain->defBonus * ( attacker->hp % 10 ) );
	attacker->hp -= std::max(0, atkDamage);
	if( attacker->hp <= 0 ) {
		delete gState_->board->at( cState_->sourceBSlot )->attachedUnit;
		gState_->board->at( cState_->sourceBSlot )->attachedUnit = nullptr;
	}
	
	// 

	return 1;

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
