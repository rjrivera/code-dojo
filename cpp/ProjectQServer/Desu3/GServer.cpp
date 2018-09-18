#include "GServer.h"
#include "GState.cpp"
#include <boost/chrono.hpp>

GServer::GServer() {
	curGState = new GState();
	initEventQ();
}

void GServer::iterateGameLoop() {
	// timing 
	GSTime = boost::chrono::system_clock::now();

	std::cout << "iterating gameloop\n";

	std::cout << "current time: " << GSTime << std::endl;

	// IF Event queue is NOT full. 	
	if(curEventInd != latestEventInd) {
		curGState->eventHandler(eventQueue->at(curEventInd)); // manipulate gameState based off eventQueue //HANDLE ALL EVENTS OF SAME TICK...after introducing concept of tick. 
	curEventInd++;
	}

	else std::cout << "no Events to process\n";

	curGState->iterateAI();	
}


void GServer::initEventQ() {
	eventQueue = new std::vector<Event *>();
	for (uint64_t i = 0; i < 100; i++) eventQueue->push_back( new Event() );
	latestEventInd = curEventInd = 0;
};



