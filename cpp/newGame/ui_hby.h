#ifndef UI_HBY_H
#define UI_HBY_H
#include "gameState.h"
#include "clientState.h"
#include "cursor.h"
#include "Project_Constants.h"
#include "baseUnit.h"
#include "Command_Catalogue.h"

class ui_hby {

	public:
		ui_hby(); 	
		ui_hby(const sf::Texture * image_);
	//	ui_hby(const ui_hby& A);
		~ui_hby();
	//	ui_hby * clone();

		sf::Sprite tileSprite;
		int x, y, command;
		std::vector<ui_hby *> * subMenus;
		//  cursor will just map to the px, py of all submenus, who inherit locations based off parents. 
		// when adding a new menu item, besides setting name and action to it... everything should be self setting.	
	//	void uiAction(gameState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, uint32_t destBSlot, uint32_t sourceBSlot );
		void uiAction(gameState * gState_, clientState * cState_ );
		void setPosition( int x_, int y_ );
		int getX();
		int getY();
		std::vector<ui_hby *> * uiSelectMenu();
};

#endif
