#ifndef BCKTERRAIN_H
#define BCKTERRAIN_H
#include <SFML/Graphics.hpp>

/* Repurposed version of BASETERRAIN_H 
 *
 */
class bckTerrain {

	public:
		bckTerrain(); 	
		bckTerrain(const sf::Texture * bckTexture);
		~bckTerrain();
		virtual void updateTiming(std::chrono::milliseconds deltaTime);
		sf::Sprite bckSprite;
};


#endif
