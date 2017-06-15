#ifndef CHARACTER_H
#define CHARACTER_H
#include"Rectangle.h"
#include<SDL2/SDL.h>
class Character
{
public:
	Character(){}; 

	virtual ~Character(){}
        virtual Character* clone() const=0;
	//virtual void update();

protected:

        Rectangle destRect;


};

class CharacterRed : public Character
{
public:
        CharacterRed(SDL_Surface* sprite_);
	virtual ~CharacterRed(){}
	virtual Character* clone() const;
	//virtual void update();
	
private:
        SDL_Surface* sprite;
	
};

class CharacterBlue : public Character
{
public:
	CharacterBlue(SDL_Surface* sprite_);
	virtual ~CharacterBlue(){}
	virtual Character* clone() const;
	//virtual void update();
private:
	SDL_Surface* sprite;

};
#endif
