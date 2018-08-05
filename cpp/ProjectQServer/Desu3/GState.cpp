#include "GState.h"
#include "Event.cpp"
#include "Point.cpp"

GState::GState() : GPoint(new Point()){ // INFO: Point() defaults to X->0, Y->0;

}

//public
void GState::eventHandler(Event * curEvent){

	switch(curEvent->eventType){
			case 0:
			GPoint->X(GPoint->X() + 1); // set the Point->X to Point->X + 1 via the public api of Point.h
			break;
			default:
			std::cout << curEvent->eventType << " is not a recognized eventType\n";

		}

//	std::cout << GPoint->X() << ", " << GPoint->Y() << std::endl;
}

void GState::iterateAI(){
	// no AI Behavior currently defined. 


}

//private	
void GState::eventProcessor(Event * curEvent){ 

}




