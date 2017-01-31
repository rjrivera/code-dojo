#ifndef ARENA_HPP
#define ARENA_HPP
#include <vector>
#include <iostream>
#include <tetShape.hpp>
#include <SFML/Graphics.hpp>
#include <string>


class arena {

	private:
		tetShape * actPiece_;		
		std::vector<tetShape*> penPieces_;
		std::vector<std::vector<bool>> grid;
		double offSet, gridSize;
		std::vector<sf::Sprite> arenaSprites; 
		std::vector<std::vector<sf::Sprite>> gridSprites;

	public:
		arena();
		arena(double width, double height, double offSet);
		arena(const arena& source);
		std::vector<sf::Sprite>& getArenaSprites();
		std::vector<double> checkClear();
		std::vector<std::vector<bool>>& getGrid();
		std::vector<std::vector<sf::Sprite>>& getGridSprites();
		void readLevelFile(std::string file_, std::vector<sf::Texture>& blocks);
		void clearDropRows(std::vector<double>& fullRows) ;
		void clearPiece();
		void definePiece(tetShape * newDef);
		void definePenPiece(tetShape * newDef);
		tetShape * getPiece();
		std::vector<tetShape*>& getPenPieces();

};

#endif


