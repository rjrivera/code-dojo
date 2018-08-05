#ifndef GSTATE_H
#define	GSTATE_H

#include "Point.h"
#include "Event.h"

class GState {

	private:
		// game state variables and collections
		Point * GPoint;

		// helper functions
	
		// manipulates the game state based on events. 
		void eventProcessor(Event * curEvent);

	public:
		// constructors
		GState();

		// public interfaces
		void eventHandler(Event * curEvent);
		void iterateAI();
	


};
#endif


