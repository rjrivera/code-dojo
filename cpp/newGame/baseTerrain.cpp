#include "baseTerrain.h";
#include "moveGrid.h";
#include <iostream>;

baseTerrain::baseTerrain()  	{
	attachedUnit = nullptr;
}

baseTerrain::baseTerrain(const sf::Texture * highlightTexture)  	{
	attachedUnit = nullptr;
	highlightSprite = sf::Sprite();
	highlightSprite.setTexture(*highlightTexture);
}

baseTerrain::~baseTerrain(){
	std::cout << "baseTerrain destroyed\n";

}

void baseTerrain::attachUnit(baseUnit * unit) {
	if (attachedUnit!=nullptr) {
		std::cout << "cannot attach Unit, slot already occupied\n";
		return;
	}
	attachedUnit = unit;
	unit->posX = gridX*unitSize;
	unit->posY = gridY*unitSize;
	attachedUnit->unitSprite.setPosition(gridX*unitSize, gridY*unitSize);
	attachedUnit->validMoves->clear();
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
