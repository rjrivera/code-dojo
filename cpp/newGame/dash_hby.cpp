#include "dash_hby.h"
// sf::Sprite tileSprite;
// std::vector<dash_hby *> subMenus;

dash_hby::dash_hby() {
	subMenus = new std::vector<dash_hby *>();
}

dash_hby::dash_hby(const sf::Texture * image_) : subMenus( new std::vector< dash_hby * >() ) {
	tileSprite = *(new sf::Sprite());
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
}

/*
dash_hby::dash_hby(const dash_hby& A) {

}*/

dash_hby::~dash_hby(){

}

/*
dash_hby * dash_hby::clone() {


}
*/

		//  cursor will just map to the px, py of all submenus, who inherit locations based off parents. 
		// when adding a new menu item, besides setting name and action to it... everything should be self setting.
	/*	
void dash_hby::dashAction( gameState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, dashnt32_t destBSlot, dashnt32_t sourceBSlot ) {
	switch( command ) {
		case 1 : { 
 //			cmdMove(gState_, myC, curInputState_, curUnit, destBSlot, sourceBSlot);
			break;
		}
		case 2 : {
			std::cout << "atk selected\n";
			break;
		}
		case 3 : {
			cmdBackMenu(gState_, myC, curInputState_, curUnit, destBSlot, sourceBSlot);
			break;
		}
		default : {
			std::cout << "Unknown command enum\n";
			break;
		}
	}
	return;
	
}
*/

void dash_hby::setPosition( int x_, int y_) {
	tileSprite.setPosition( x_, y_ );
	x = x_;
	y = y_;
	return;
}

int dash_hby::getX(){
	return x;
}

int dash_hby::getY(){
	return y;
}

