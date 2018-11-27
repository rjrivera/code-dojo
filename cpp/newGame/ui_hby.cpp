#include "ui_hby.h"
// sf::Sprite tileSprite;
// std::vector<ui_hby *> subMenus;

ui_hby::ui_hby() {
	subMenus = std::vector<ui_hby *>();
}

ui_hby::ui_hby(const sf::Texture * image_) : subMenus( std::vector< ui_hby * >() ) {
	tileSprite = *(new sf::Sprite());
	tileSprite.setTexture(*image_);
	tileSprite.setPosition(0, 0);

	subMenus = std::vector< ui_hby * >();
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
		

