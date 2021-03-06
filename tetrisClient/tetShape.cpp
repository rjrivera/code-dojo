#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "tetShape.hpp"
/*
	Release Notes v0.1
	tetShape class definition
	Documentation: 
	Author: Rob Rivera
	
	Initial draft, no amendments to annotate. 

	

*/

//distribution / generator are global variables

tetShape::tetShape() : x(0), y(0), bState(ONE), mySprites(std::vector<sf::Sprite>()) {

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::default_random_engine generator (seed);
	std:: normal_distribution<double> distribution (1, 1.0);
	m_id = distribution(generator);
	onFloor_ = false;
}


tetShape::tetShape(double x_, double y_) : x(x_), y(y_), mySprites(std::vector<sf::Sprite>()){
	// ======== code block - std::normal_distribution::(constructor)
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::default_random_engine generator (seed);
	
	std:: normal_distribution<double> distribution (1, 1.0);
	// =========
	m_id = distribution(generator);
	onFloor_ = false;
}


tetShape::~tetShape() {
	
}

// copy constructor
tetShape::tetShape(const tetShape& source_) {

	m_id = source_.m_id;

}

double tetShape::X() const{

	return x;
}

double tetShape::Y() const{
	return y;
}

tetShape& tetShape::operator= (const tetShape& source_) {
	m_id = source_.m_id;
}


bool tetShape::operator== (const tetShape& source_) const {
	if (source_.m_id == m_id) {
		return true;
	}
	return false;

}

std::vector<sf::Sprite>& tetShape::getSprites() {
	return mySprites;
}

bool tetShape::rBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const {
	return false;

}


bool tetShape::lBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const {
	return false;
}

bool tetShape::floorBoundCheck(std::vector<std::vector<bool>>& y_) const {
	return false;
}


void tetShape::amendGrid(std::vector<std::vector<bool>>& grid) const {
	return; // do nothing for proto-typing
}

void tetShape::onFloor(bool val) {
	onFloor_ = val;
}

/*
void tetShape::morph(std::vector<std<vector<bool>>& grid){

}*/
/*
bool tetShape::onFloor() const{
	return onFloor_;
}
*/

		// modifiers
		// choosing a diameter vice rad method to take advantage of overloading. 
void tetShape::ID(double target_) { 
	m_id = target_;
}

double tetShape::ID() const{
	return m_id;
}

void tetShape::move(double x_, double y_) {

}
void tetShape::Draw() {
	std::cout << "void tetShape::Draw()\n";

}
