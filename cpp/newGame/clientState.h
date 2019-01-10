#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H
#include "baseUnit.h"
#include "cursor.h"
#include "Project_Constants.h"
#include <vector>

class clientState {

	public:
		clientState(); 	
		~clientState();
		uint32_t destBSlot, sourceBSlot;
		cursor * myC;
		std::vector< cursor * > * cursorStack;
		inputState curInputState;
		baseUnit * selectedUnit;
};

#endif
