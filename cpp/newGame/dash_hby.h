#ifndef DASH_HBY_H
#define DASH_HBY_H
#include "gameState.h"
#include "clientState.h"
#include "cursor.h"
#include "Project_Constants.h"
#include "baseUnit.h"
#include "Command_Catalogue.h"

class dash_hby {

	public:
		dash_hby(); 	
		dash_hby(const sf::Texture * image_);
	//	dash_hby(const dash_hby& A);
		~dash_hby();
	//	dash_hby * clone();

		sf::Sprite tileSprite;
		int x, y;
		std::vector<dash_hby *> * subMenus;
		//  cursor will just map to the px, py of all submenus, who inherit locations based off parents. 
		// when adding a new menu item, besides setting name and action to it... everything should be self setting.	
	//	void dashAction(gameState * gState_, cursor * myC, inputState& curInputState_, baseUnit * curUnit, dashnt32_t destBSlot, dashnt32_t sourceBSlot );
	//	void dashAction(gameState * gState_, clientState * cState_ );
		void setPosition( int x_, int y_ );
		int getX();
		int getY();
	//	std::vector<dash_hby *> * dashSelectMenu(); //potentially redefine the dash similar to ui...
};

#endif
