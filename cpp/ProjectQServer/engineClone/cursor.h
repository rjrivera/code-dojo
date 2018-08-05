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
		void movePosX(uint64_t moveX);
		void movePosY(uint64_t moveX);	
		void movePosXAbs(uint64_t moveX);
		void movePosYAbs(uint64_t moveX);
		bool getCooldown();
		bool burnCooldown();

		
		
};


#endif
