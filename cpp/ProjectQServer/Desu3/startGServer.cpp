#include <iostream>
#include "GServer.cpp"


int main() {
	// init testbench code here
	Event * testEvent = new Event();

	// =======================END TEST BENCH


	GServer * myGServer = new GServer();



	while(1) myGServer->iterateGameLoop();

	return 0;
}

