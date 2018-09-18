#ifndef GSERVER_H
#define	GSERVER_H

#include "GState.h"
#include "boost/chrono.hpp"
#include <vector>


class GServer {

	public:
		GServer();
		void iterateGameLoop();

	private:
		// pointers and objects
		GState * curGState;
		// if curEventInd == latestEventInd, then eventQueue is empty. 
		std::vector<Event *> * eventQueue;
		uint64_t curEventInd;
		uint64_t latestEventInd;
		boost::chrono::system_clock::time_point GSTime;

		// functions
		void initEventQ();		

};
#endif


