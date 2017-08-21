#include "baseTerrain.h";
#include "moveGrid.h";
#include <iostream>;

baseTerrain::baseTerrain()  	{
	std::cout << "baseTerrain instatiated\n";
	attachedUnit = nullptr;
	
}
baseTerrain::~baseTerrain(){
	std::cout << "baseTerrain destroyed\n";

}

void baseTerrain::attachUnit(baseUnit * unit) {
	attachedUnit = unit;
	attachedUnit->unitSprite.setPosition(gridX*unitSize, gridY*unitSize);
	attachedUnit->validMoves = new std::vector<moveGrid * >(); //TODO[ ] destroy the container after PoC.
	attachedUnit->initMoveGrids(attachedUnit->mvt, gridX*unitSize, gridY*unitSize);
}

void baseTerrain::detachUnit(){
	attachedUnit = nullptr;

}

void baseTerrain::setGridPos(uint32_t x, uint32_t y){
	gridX = x;
	gridY = y;
}

void baseTerrain::setUnitSize(uint32_t size) {
	unitSize = size;

}

baseUnit * baseTerrain::getUnit(){
	return attachedUnit;
}
