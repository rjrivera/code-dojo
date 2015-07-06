#include "Character.h"
#include <SDL2/SDL.h>
#include "Rectangle.h"

CharacterRed::CharacterRed(SDL_Surface* sprite_) : sprite(sprite_){

}
	
Character* CharacterRed::clone() const{

	return new CharacterRed(*this);

}

CharacterBlue::CharacterBlue(SDL_Surface* sprite_) : sprite(sprite_){

}

Character* CharacterBlue::clone() const{

	return new CharacterBlue(*this);

}
	
/*


Copyright {c} 2015

Robert Rivera

Permission to use, copy, modify, distribtue and sell this 
software for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that 
copyright notice ad this permission notice appear in supporting documentation.
Robert Rivera makes no representations about the suitability of this software for any purpose. It is provided "as is" without express or implied warrantly.

*/
