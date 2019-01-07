#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H
#include "baseUnit.h"
#include "cursor.h"
#include "Project_Constants.h"

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
