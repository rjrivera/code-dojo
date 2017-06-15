#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"baseTerrain.cpp"
#include"plainTerrain.cpp"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include <SFML/Graphics.hpp>
#include "Project_Constants.h"


#define WIDTH 400
#define HEIGHT 600

//todo - work on an x,y tracking schema
//todo - work on a content pipeline leveraging a json
//personal notes - migrate newGame to an instantiable client object that can sync with a Server.

//using namespace rapidjson;
/*
void foo() {
	const char * json = "{\"project\":\"json\",\"fucks\":\"none\"}";
	std::cout << json << std::endl; 

	Document myD;
	myD.Parse(json);
	Value& copyVal = myD["project"];
	//std::cout << ((std::string)(copyVal)) << std::endl;

	//stringify the value objects in Document
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	myD.Accept(writer);



}
*/



void foo(std::vector<sf::Texture *>& text_container) {
	for (int i = 0 ; i < maxTerrain_const; i++) {
		std::string textName = "textures/plain" + std::to_string(i)  + ".png";
		sf::Texture * tempText = new sf::Texture();
		tempText->loadFromFile(textName);
		text_container.push_back(tempText);
	}		

}



int main( int argc, char** argv ) {
	std::vector<sf::Texture *> terrainTexts = std::vector<sf::Texture *>();
	foo(terrainTexts);
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Advance Wars Clone");
	
	//load all textures into the program
	for (int i = 0; i < 2; i++) {
		
	}
	std::vector<baseTerrain * > board = std::vector<baseTerrain *>();
	board.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
	board.push_back(new plainTerrain(terrainTexts[plainTerrain_const]));
	board.push_back(new plainTerrain(terrainTexts[mountTerrain_const]));
	
	board[1]->tileSprite.setPosition(32, 32);
	board[2]->tileSprite.setPosition(64, 32);
	
	bool inGame = true;
	while(inGame) {

		// ===================================================
		// INPUT HANDLING
		// ===================================================

		// Escape Key pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			inGame = false;
		}	 
	

		// ===================================================
		// sprite draw logic
		// ===================================================
		window.clear();
		// note, blocks is simply a repo of texture. 
		// should iterate through a collection of sprites, not texutres. 
		for(baseTerrain * obj : board) window.draw(obj->tileSprite);
		
	
		window.display();
	}
	return 0;
}
