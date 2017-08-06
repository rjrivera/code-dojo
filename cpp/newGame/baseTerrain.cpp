#include "baseTerrain.h";
#include <iostream>;

baseTerrain::baseTerrain()  	{
	std::cout << "baseTerrain instatiated\n";
	attachedUnit = nullptr;
	
}
baseTerrain::~baseTerrain(){
	std::cout << "baseTerrain destroyed\n";

}



