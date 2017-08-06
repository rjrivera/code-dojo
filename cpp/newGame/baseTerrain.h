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
};


#endif
