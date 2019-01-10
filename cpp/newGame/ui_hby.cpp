#include "ui_hby.h"
// sf::Sprite tileSprite;
// std::vector<ui_hby *> subMenus;

ui_hby::ui_hby() {
	subMenus = new std::vector<ui_hby *>();
}

ui_hby::ui_hby(const sf::Texture * image_) : subMenus( new std::vector< ui_hby * >() ) {
	tileSprite = *(new sf::Sprite());
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);
}

/*
ui_hby::ui_hby(const ui_hby& A) {

}*/

ui_hby::~ui_hby(){

}

/*
ui_hby * ui_hby::clone() {


}
*/

		//  cursor will just map to the px, py of all submenus, who inherit locations based off parents. 
		// when adding a new menu item, besides setting name and action to it... everything should be self setting.
	/*	
void ui_hby::uiAction( gameState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, uint32_t destBSlot, uint32_t sourceBSlot ) {
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
void ui_hby::uiAction( gameState * gState_, clientState * clientState_ ) {
	switch( command ) {
		case 1 : { 
 			cmdMove(gState_, clientState_);
			break;
		}
		case 2 : {
			cmdAtkSelect(gState_, clientState_);
			break;
		}
		case 3 : {
			cmdBackMenu(gState_, clientState_);
			break;
		}
		case 4 : {
			cmdAtk(gState_, clientState_);
			break;
		}
		default : {
			std::cout << "Unknown command enum\n";
			break;
		}
	}
	return;
	
}

void ui_hby::setPosition( int x_, int y_) {
	tileSprite.setPosition( x_, y_ );
	x = x_;
	y = y_;
	return;
}

int ui_hby::getX(){
	return x;
}

int ui_hby::getY(){
	return y;
}

std::vector<ui_hby *> * ui_hby::uiSelectMenu() {
	return subMenus;
};
