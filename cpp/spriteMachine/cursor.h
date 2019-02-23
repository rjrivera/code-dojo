#ifndef CURSOR_H
#define CURSOR_H
#include <SFML/Graphics.hpp>
#include <chrono>

class cursor {

	public:
		cursor(); 	
		cursor(const sf::Texture * image_);
		cursor(const cursor& A);
		~cursor();
		cursor * clone();
		void print();
		sf::Sprite tileSprite;
		bool movCooldown;
		uint64_t posX, posY, stackInd;
		std::chrono::nanoseconds cursTimer;
		std::chrono::milliseconds cursTrigger{250};
		void updateTimer(std::chrono::nanoseconds timer);
		void moveX(int64_t moveX);
		void moveY(int64_t moveY);	
		void moveXAbs(int64_t moveX);
		void moveYAbs(int64_t moveY);
		bool getCooldown();
		bool burnCooldown();
	
		
};


#endif
