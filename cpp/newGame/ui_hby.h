#ifndef UI_HBY_H
#define UI_HBY_H

class ui_hby {

	public:
		ui_hby(); 	
		ui_hby(const sf::Texture * image_);
		ui_hby(const ui_hby& A);
		~ui_hby();
		ui_hby * clone();
		void print();

		sf::Sprite tileSprite;
		std::vector<ui_hby *> subMenus;
		//  cursor will just map to the px, py of all submenus, who inherit locations based off parents. 
		// when adding a new menu item, besides setting name and action to it... everything should be self setting.
		
};

#endif
