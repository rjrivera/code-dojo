#ifndef UI_HBY_H
#define UI_HBY_H

class ui_hby {

	public:
		ui_hby(); 	
		ui_hby(const sf::Texture * image_);
	//	ui_hby(const ui_hby& A);
		~ui_hby();
	//	ui_hby * clone();

		sf::Sprite tileSprite;
		int x, y;
		std::vector<ui_hby *> * subMenus;
		//  cursor will just map to the px, py of all submenus, who inherit locations based off parents. 
		// when adding a new menu item, besides setting name and action to it... everything should be self setting.	
		void uiAction();
		void setPosition( int x_, int y_ );
		int getX();
		int getY();
		std::vector<ui_hby *> * uiSelectMenu();
};

#endif
