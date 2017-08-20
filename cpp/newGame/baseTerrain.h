#ifndef BASETERRAIN_H
#define BASETERRAIN_H
#include <SFML/Graphics.hpp>
#include "baseUnit.h"

class baseTerrain {

	public:
		baseTerrain(); 	
		~baseTerrain();
		virtual void print() = 0;
		sf::Sprite tileSprite;
		baseUnit * attachedUnit;
		uint32_t gridX, gridY, unitSize;
		void attachUnit(baseUnit * unit);
		void detachUnit();
		void setGridPos(uint32_t x, uint32_t y);
		void setUnitSize(uint32_t size);
		baseUnit * getUnit();
};


#endif
