#include <iostream>
#include "tetL.hpp"
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
/*
	RELEASE NOTES v 3-5-1

	Amended class definition to override virtual function of base class Shape.
*/

//constructors
tetL::tetL() : tetShape(0, 0){
}

tetL::tetL(double x_, double y_,const sf::Texture* blkText_) : tetShape(x_, y_){
	mySprites; //std::vector<sf::Sprite>
	//myInts; //std::vector<int> for test purposes.
	for (int i = 0; i < 4; i++) {
		mySprites.push_back(sf::Sprite());
		mySprites[i].setTexture(*blkText_); 
	}
	mySprites[0].setPosition(sf::Vector2f((float)(16*x_) , (float)(16*y_))); 
	mySprites[1].setPosition(sf::Vector2f((float)(16*(x_)) , (float)(16*(y_+1)))); 
	mySprites[2].setPosition(sf::Vector2f((float)(16*x_) , (float)(16*(y_+2)))); 
	mySprites[3].setPosition(sf::Vector2f((float)(16*(x_+1)) , (float)(16*(y_+2)))); 
	tetShape::bState = ONE;
}

tetL::tetL(double z_) : tetShape(z_, z_){
}

tetL::~tetL() {
	//delete mySprites;
	//
}

//copy constructor
tetL::tetL(const tetL& sauce) {
	x = sauce.x;
	y = sauce.y;
	m_id = sauce.m_id;
	for (int i = 0; i < 4; i++) {
		mySprites.push_back(sauce.mySprites[0]);
	}
}

//operator overloading

tetL tetL::operator-() const{
	tetL temp = tetL(x*-1, y*-1, mySprites[0].getTexture());
	return temp;
}

tetL tetL::operator* (double factor) const {
		//TODO[ ] find a suitable operation for this...perhaps implement the transform here?
	return *this;
}

tetL tetL::operator+ (const tetL& p) const{ // Add Coordinates
	
	tetL temp = tetL(x + p.X(), y + p.Y(), p.mySprites[0].getTexture());
	return temp;
}

bool tetL::operator== (const tetL& p) const {
	if (p.x == x && p.y == y && p.m_id == m_id) {
		return true;
	}
	return false;
}

tetL& tetL::operator= (const tetL& source) {
	x = source.x;
	y = source.y;
	m_id = source.m_id;
	return *this;	
}

tetL& tetL::operator*= (double factor) {
	x *= factor;
	y *= factor;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const tetL& source) {
	os << "Point ID: " << source.m_id << "(" << source.x << ", " << source.y << ")" << std::endl;
	return os;
}
//selectors
double tetL::X() const {
	return x;
}

double tetL::Y() const {
	return y;
}
	
std::vector<sf::Sprite>& tetL::getSprites() {
	return mySprites;
}

bool tetL::onFloor() const {
	return onFloor_;
}
	//mutators
void tetL::X(double x_){
	x = x_;
}
	
void tetL::Y(double y_){
	y = y_;
}

void tetL::onFloor(bool val){
	onFloor_ = val;
}

double tetL::Distance() const {
	double a = std::abs(x);
	double b = std::abs(y);
	return (std::sqrt(pow(a,2) + pow(b,2)));
}

bool tetL::rBoundCheck(double x_,std::vector<std::vector<bool>>& grid) const {
	if (x+2 >= x_ ) return false;
	if (grid.at(x+2-2)[y+2] || grid.at(x+1-2)[y+1] || grid.at(x+1-2)[y]) return false; 
	return true;
}

bool tetL::lBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const {
	if ( (x-1) <= x_ )  return false;
	if (grid.at(x-1-2)[y+2] || grid.at(x-1-2)[y+1] || grid.at(x-1-2)[y]) return false; 
	return true; 
}

bool tetL::floorBoundCheck(std::vector<std::vector<bool>>& y_) const {
	switch(bState) {
		case(ONE):
			if (y_.at(x-2)[y+3] || y_.at(x-2+1)[y+3]) return false;
			break;
		case(TWO):
			if (y_.at(x-2)[y+1] || y_.at(x-2+1)[y+1] || y_.at(x-2+2)[y+1]) return false;
			break;
		case(THREE):
			if (y_.at(x-2)[y+1] || y_.at(x-2+1)[y+3]) return false;
			break;
	}
	return true;
	//same TODO as tetSquare.cpp


}

void tetL::amendGrid(std::vector<std::vector<bool>>& grid) const{

	//same not as floorBoundCheck.
	switch(bState) {
		case(ONE):
			grid.at(x-2)[y]   =  true;
			grid.at(x-2)[y+1] = true;
			grid.at(x-2)[y+2] = true;
			grid.at(x-2+1)[y+2] = true;
			break;
		case(TWO):
			grid.at(x-2)[y]   =  true;
			grid.at(x-2+1)[y] = true;
			grid.at(x-2+2)[y] = true;
			grid.at(x-2+2)[y-1] = true;
			break;
		case(THREE):
			grid.at(x-2)[y]   =  true;
			grid.at(x-2+1)[y] = true;
			grid.at(x-2+1)[y+1] = true;
			grid.at(x-2+1)[y+2] = true;
			break;
	}

}

void tetL::morph(std::vector<std::vector<bool>>& grid) {
	switch(bState) {
		case(ONE):
			mySprites[1].setPosition(sf::Vector2f((float)(16*(x+1)) , (float)(16*(y)))); 
			mySprites[2].setPosition(sf::Vector2f((float)(16*(x+2)) , (float)(16*(y)))); 
			mySprites[3].setPosition(sf::Vector2f((float)(16*(x+2)) , (float)(16*(y-1)))); 
			bState = TWO;
			break;
		case(TWO):
			mySprites[1].setPosition(sf::Vector2f((float)(16*(x+1)) , (float)(16*(y)))); 
			mySprites[2].setPosition(sf::Vector2f((float)(16*(x+1)) , (float)(16*(y+1)))); 
			mySprites[3].setPosition(sf::Vector2f((float)(16*(x+1)) , (float)(16*(y+2)))); 
			bState = THREE;
			break;		
		case(THREE):
			mySprites[1].setPosition(sf::Vector2f((float)(16*(x)) , (float)(16*(y+1)))); 
			mySprites[2].setPosition(sf::Vector2f((float)(16*(x)) , (float)(16*(y+2)))); 
			mySprites[3].setPosition(sf::Vector2f((float)(16*(x+1)) , (float)(16*(y+2)))); 
			bState = ONE;
			break;
	}
}

bool tetL::morphCheck(std::vector<std::vector<bool>>& grid) {
	switch(bState) {
		case(ONE):
			if (grid.at(x-2+1)[y] || grid.at(x-2+2)[y] || grid.at(x-2+2)[y-1]) return false;
			break;
		case(TWO):
			if (grid.at(x-2+1)[y] || grid.at(x-2+1)[y+1] || grid.at(x-2+1)[y+2]) return false; 
			break;
		case(THREE):
			if (grid.at(x-2)[y+1] || grid.at(x-2)[y+2] || grid.at(x-2+1)[y+2]) return false; 
			break;

	}

	return true;
}


//altered signature to pass-by-reference in order to avoid copy constructor call and reduce overhead. Made argument const as per instructions so function cannot alter state of referenced value. 
double tetL::Distance(const tetL& p) const{	
	double a, b;
	// p.x = 55; uncomment to test read-only nature of const Point& reference. 
	if (p.x > x) {
		a = p.x - x;
	}
	else { a = x - p.x; }

	if (p.y > y) {
		b = p.y - y;
	}
	else { b= y - p.y; }
	std::cout << "a: " << std::to_string(a) << " b: " << std::to_string(b) << std::endl;
	std::cout << "a^2 = " << pow(a, 2) << std::endl;
	std::cout << "b^2 = " << pow(b, 2) << std::endl;
	return (std::sqrt(std::pow(a, 2) + std::pow(b,2)));
}

void tetL::move(double x_, double y_) {
	for (auto& gBlock : mySprites) {
		gBlock.move(x_*16, y_*16);
	}
	x += x_;
	y += y_;

}

void tetL::Draw() {

	std::cout << ".\n";

}


