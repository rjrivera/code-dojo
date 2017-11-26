#include "bckTerrain.h"
#include "Project_Constants.h"

/*
 * End goal of the bckTerrain object is to handle all terrain features - excluding foreground objects. 
 */

bckTerrain::bckTerrain() {


}


bckTerrain::bckTerrain(const sf::Texture * bckTexture) {
	bckSprite = sf::Sprite();
	bckSprite.setTexture(*bckTexture);
	bckSprite.setPosition(0 - backX, 0 - backY);
}

bckTerrain::~bckTerrain(){

}

void bckTerrain::updateTiming(std::chrono::milliseconds deltaTime) {
	bckSprite.setPosition(tL.X() - backX, 0 - backY);

}

void bckTerrain::setFloor(double floor_) {
	maxHeight = floor_;
}


void bckTerrain::setCeiling(double ceiling_) {
	minHeight = ceiling_;
}
