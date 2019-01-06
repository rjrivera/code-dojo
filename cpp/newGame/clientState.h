#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H
#include "baseUnit.h"
#include "cursor.h"
#include "Project_Constants.h"

//static int cmdBackMenu( clientState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, uint32_t destBSlot, uint32_t sourceBSlot ) {

class clientState {

	public:
		clientState(); 	
		~clientState();
		uint32_t destBSlot, sourceBSlot;
		cursor * myC;
		inputState curInputState;
		baseUnit * selectedUnit;
};

#endif
