#include <arena.hpp>
#include <vector>
#include <iostream>
#include <tetShape.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>

arena::arena() : gridSize(16), grid(*(new std::vector<std::vector<bool>>())) {
	
};
arena::arena(double width, double height, double offSet) {};

/* copy constructor - used for multiplayer on same console to save time on resources and for consistency. 
 *		tetShape * actPiece_;		std::vector<std::vector<bool>> grid;
		double offSet, gridSize;	std::vector<sf::Sprite> arenaSprites; 
		std::vector<std::vector<sf::Sprite>> gridSprites;
 *
 */
arena::arena(const arena& source) {
	actPiece_ = source.actPiece_;
	grid = source.grid;
	offSet = source.offSet;
	gridSize = source.gridSize;
	arenaSprites = source.arenaSprites;
	gridSprites = source.gridSprites;
};

/*Provide a reference to the class sprites which must be drawn. 
 * Each sprite doesn't represent a unique screen object, they are just
 * used as props to paint one part of a <true> part of the vector<vector<bool>> grid. 
 *
 */
std::vector<sf::Sprite>& arena::getArenaSprites(){
		return arenaSprites;
}

/* check if the current grid has a valid horizontal line.
 * actual toggle of 'full' rows performed by different function "because best practices ;)" 
 *
 * RETURN vector of row indexes which meet criteria of "full"
 * 	will return a vector of size 0 if no such rows meet the criteria. 
 */

std::vector<double> arena::checkClear() {
	double width = grid.size();
	double height = grid.at(0).size();
	std::vector<double> clearRows = std::vector<double>();
	double cInd = 0;
	bool clear;
	for (double i = 0; i < height; i++) {
		clear = true;
		for (double j = 0; j < width; j++)  {
			//check if square is empty.
			if (!grid.at(j)[i]) {
				clear = false; 
				break; //save computation power.
			}
		}
		if (clear) clearRows.push_back(cInd);
		cInd++; 
	}
	return clearRows;
}

/* clear full rows
 * drop all blocks above row;
 *
 */

void arena::clearDropRows(std::vector<double>& fullRows) {
	double tallRow = *std::min_element(fullRows.begin(), fullRows.end());
	double numRows = fullRows.size();
	std::cout << "num full rows: " << numRows << std::endl;
	//clear the rows. 
	for (double j = 0; j < numRows; j++) {
		for (double i = 0; i < grid.size(); i++) grid.at(i)[fullRows[j]] = false;
		std::cout << "cleared row: " << fullRows[j] << std::endl;
	}

	//"clone" and drop all blocks above the tallest row (remember, the tallest row is the lowest value in this y-coord scheme).
	for (double cRow = tallRow - 1; cRow >= 0; cRow--) {
		for (double i = 0; i < grid.size(); i++) grid.at(i)[cRow+numRows] = grid.at(i)[cRow];
	}
	//empty the top [numRows] 
	for (double cRow = 0; cRow < numRows; cRow++) {
		for (double i = 0; i < grid.size(); i++) grid.at(i)[cRow] = false;
	}
	
	
}

/*
 * Read the provided text file 
 *
 * [NOTE TO HATERS] [THIS FILE IS A PROTOTYPE FOR A FUTURE SCALE UP IN A CONTENT DEVELOPMENT PIPELINE]. 
 *
 */

void arena::readLevelFile(std::string file_, std::vector<sf::Texture>& blocks){
			std::string line;
//			std::ifstream arenaStream;
	//		try{
			std::ifstream arenaStream = std::ifstream(file_);
	//		}
	/*		catch (...){
				std::cout << "file  " << file_ << " not found\n";
				return;
			} */
			uint32_t spriteIndex = 0;
			uint32_t numLine = 0;
			// ==============TODO[ ] migrate to global const. (extern uint32_t etc...)
			uint32_t WIDTH = 400;
			uint32_t HEIGHT = 600;  
			uint32_t arenaWidth, arenaOffset, arenaHeight;

			arenaWidth = arenaOffset = -1; // default  values used as flags below.
			arenaHeight = 0;
			bool newRow = true;
			if (arenaStream.is_open()  ) {
				while (getline(arenaStream, line)){
					for (uint32_t i = 0; i < WIDTH/16; i++) {
						if (line.at(i) == '1')  {
							 
							arenaSprites.push_back(sf::Sprite());
							arenaSprites[spriteIndex].setTexture(blocks[0]);		
							arenaSprites[spriteIndex].setPosition(sf::Vector2f((float)(16*(i % (WIDTH/16))) , (float)(16*numLine))); 
							spriteIndex++;
						}
						else if ( line.at(i) == '0' )  {
							if ( arenaOffset == -1 )  { //the first encounter with a '0' in our traversal 
											// is our left bound. 
								arenaOffset = i; //determine left boundary of our game arena.
								offSet = arenaOffset;
							}
							if (newRow) { //tabulate height of arena by presence of '0' in arena.txt line string. 
								arenaHeight++;
								newRow = false;
							}
							if ( numLine == 1  ) {
								arenaWidth++;
							}
						}
						
					}
					newRow = true;//reset row flag. 
					numLine++;
				}
				arenaStream.close();
				// based off information infered from arena.txt - tabulate the floor.
				//
				
				for (uint32_t i = 0; i <= arenaWidth ; i++) {
					grid.push_back(std::vector<bool>());//init the oncoming column.
					gridSprites.push_back(std::vector<sf::Sprite>());
					//gamegrid.at(i).push_back(true);//push the floor. 
					for (uint32_t j = 0; j < arenaHeight; j++) {
						grid.at(i).push_back(false);		 
						gridSprites.at(i).push_back(sf::Sprite());
						gridSprites.at(i)[j].setTexture(blocks[1]);		
						gridSprites.at(i)[j].setPosition(sf::Vector2f((float)(16*(i)+arenaOffset*16), (float)(16*j))); 
					}
					gridSprites.at(i).push_back(sf::Sprite());
					gridSprites.at(i)[arenaHeight].setTexture(blocks[1]);
					gridSprites.at(i)[arenaHeight].setPosition(sf::Vector2f((float)(16*(i)+arenaOffset*16), (float)(16*arenaHeight)));
					grid.at(i).push_back(true);
				}
			}
					
	std::cout << "grid width in arena info: " << grid.size() << std::endl;
	std::cout << "grid height in arena info: " << grid.at(0).size() << std::endl;

}

void arena::clearPiece() { delete actPiece_;}

//TODO[ ] make bool and return false if failed assignment??? MAYBE afer i migrate to a more complicatd system. 
void arena::definePiece(tetShape * newDef) { actPiece_ = newDef;}

tetShape * arena::getPiece(){
	return actPiece_;
}

std::vector<std::vector<bool>>& arena::getGrid(){
	return grid;

}

std::vector<std::vector<sf::Sprite>>& arena::getGridSprites() {
	return gridSprites;

}
