#ifndef BASETERRAIN_H
#define BASETERRAIN_H
#include <SFML/Graphics.hpp>
#include "baseUnit.h"

class baseTerrain {

	public:
		baseTerrain(); 	
		baseTerrain(const sf::Texture * highlightTexture);
		~baseTerrain();
		virtual void print() = 0;
		sf::Sprite tileSprite, highlightSprite, atkSprite;
		baseUnit * attachedUnit;
		uint32_t gridX, gridY, unitSize, cost, defBonus;
		void attachUnit(baseUnit *& unit, std::vector< baseTerrain*> * board);
		void detachUnit();
		void setAtkSprite(const sf::Texture * atkSprite_);
		void setGridPos(uint32_t x, uint32_t y);
		void setUnitSize(uint32_t size);
		baseUnit * getUnit();
};


#endif
