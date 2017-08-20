#ifndef BASEGFX_H
#define BASEGFX_H
#include <SFML/Graphics.hpp>

class baseGFX {

	public:
		baseGFX(); 	
		~baseGFX();
		virtual void print() = 0;
		sf::Sprite gFXSprite;
		uint64_t posX, posY, velX, velY;
// !!! TODO[ ] implement sprite timer after core PoC phase.
//		std::chrono::nanoseconds spriteTimer;
//		std::chrono::milliseconds cursTrigger{250};
//		void updateTimer(std::chrono::nanoseconds timer);
		void movePosX(uint64_t moveX);//for table operations
		void movePosY(uint64_t moveY);//for table operations
		void updatePos();//for classic graphics


};


#endif
