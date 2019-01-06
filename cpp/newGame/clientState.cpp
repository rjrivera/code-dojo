#include "clientState.h"

//static int cmdBackMenu( clientState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, uint32_t destBSlot, uint32_t sourceBSlot ) {

clientState::clientState() : destBSlot(0), sourceBSlot(0) 
{ 
	curInputState = lastEnum;
	selectedUnit 	= nullptr;
	myC		= nullptr; 
}

clientState::~clientState(){

}

