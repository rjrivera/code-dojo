#ifndef BCKTERRAIN_H
#define BCKTERRAIN_H
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Line.hpp"

/* Repurposed version of BASETERRAIN_H 
 *
 */
class bckTerrain {

	public:
		Point tL, bR;
		double minHeight, maxHeight;
		bckTerrain(); 	
		bckTerrain(const sf::Texture * bckTexture);
		~bckTerrain();
		virtual void updateTiming(std::chrono::milliseconds deltaTime);
		void setCeiling(double ceiling_);
		void setFloor(double floor_);
		sf::Sprite bckSprite;
};


#endif
