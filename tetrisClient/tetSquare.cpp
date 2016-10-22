#include <iostream>
#include "tetSquare.hpp"
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>
/*
	RELEASE NOTES v 3-5-1

	Amended class definition to override virtual function of base class Shape.
*/

//constructors
tetSquare::tetSquare(const sf::Texture* blkText_) : tetShape(0, 0){

	mySprites; //std::vector<sf::Sprite>
        myInts; //std::vector<int> for test purposes.
        for (int i = 0; i < 4; i++) {
                mySprites.push_back(sf::Sprite());
                mySprites[i].setTexture(*blkText_);
        }
        mySprites[0].setPosition(sf::Vector2f((float)(16*5) , (float)(16*3)));
        mySprites[1].setPosition(sf::Vector2f((float)(16*(5+1)) , (float)(16*3)));
        mySprites[2].setPosition(sf::Vector2f((float)(16*5) , (float)(16*(3+1))));
        mySprites[3].setPosition(sf::Vector2f((float)(16*(5+1)) , (float)(16*(3+1))));
        for (auto& sprite : mySprites) {
                std::cout << "X, Y: " << (sprite.getPosition()).x << " " << (sprite.getPosition()).y << std::endl;
        }
        //tetShape->myInts = *(new std::vector<int>);
        //        for (int i = 0; i < 4; i++) {
        //                        myInts.push_back(i);
        //                                        std::cout << "init int: " << myInts[i] << std::endl;
        //                                                }
        //        }


}

tetSquare::tetSquare(double x_, double y_,const sf::Texture* blkText_) : tetShape(x_, y_){
	mySprites; //std::vector<sf::Sprite>
	myInts; //std::vector<int> for test purposes.
	for (int i = 0; i < 4; i++) {
		mySprites.push_back(sf::Sprite());
		mySprites[i].setTexture(*blkText_); 
	}
	mySprites[0].setPosition(sf::Vector2f((float)(16*x_) , (float)(16*y_))); 
	mySprites[1].setPosition(sf::Vector2f((float)(16*(x_+1)) , (float)(16*y_))); 
	mySprites[2].setPosition(sf::Vector2f((float)(16*x_) , (float)(16*(y_+1)))); 
	mySprites[3].setPosition(sf::Vector2f((float)(16*(x_+1)) , (float)(16*(y_+1)))); 
	for (auto& sprite : mySprites) {
		std::cout << "X, Y: " << (sprite.getPosition()).x << " " << (sprite.getPosition()).y << std::endl;
	}
	//tetShape->myInts = *(new std::vector<int>);
	for (int i = 0; i < 4; i++) {
		myInts.push_back(i);
		std::cout << "init int: " << myInts[i] << std::endl;
	}
}

tetSquare::tetSquare(double z_) : tetShape(z_, z_){
}

tetSquare::~tetSquare() {
	//delete mySprites;
}

//copy constructor
tetSquare::tetSquare(const tetSquare& sauce) {
	x = sauce.x;
	y = sauce.y;
	m_id = sauce.m_id;

}

//operator overloading

tetSquare tetSquare::operator-() const{
	tetSquare temp = tetSquare(x*-1, y*-1, mySprites[0].getTexture());
	return temp;
}

tetSquare tetSquare::operator* (double factor) const {
		//TODO[ ] find a suitable operation for this...perhaps implement the transform here?
	return *this;
}

tetSquare tetSquare::operator+ (const tetSquare& p) const{ // Add Coordinates
	
	tetSquare temp = tetSquare(x + p.X(), y + p.Y(), p.mySprites[0].getTexture());
	return temp;
}

bool tetSquare::operator== (const tetSquare& p) const {
	if (p.x == x && p.y == y && p.m_id == m_id) {
		return true;
	}
	return false;
}

tetSquare& tetSquare::operator= (const tetSquare& source) {
	x = source.x;
	y = source.y;
	m_id = source.m_id;
	return *this;	
}

tetSquare& tetSquare::operator*= (double factor) {
	x *= factor;
	y *= factor;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const tetSquare& source) {
	os << "Point ID: " << source.m_id << "(" << source.x << ", " << source.y << ")" << std::endl;
	return os;
}
//selectors
double tetSquare::X() const {
	return x;
}

double tetSquare::Y() const {
	return y;
}
	
	//mutators
void tetSquare::X(double x_){
	x = x_;
}
	
void tetSquare::Y(double y_){
	y = y_;
}

double tetSquare::Distance() const {
	double a = std::abs(x);
	double b = std::abs(y);
	return (std::sqrt(pow(a,2) + pow(b,2)));
}

//altered signature to pass-by-reference in order to avoid copy constructor call and reduce overhead. Made argument const as per instructions so function cannot alter state of referenced value. 
double tetSquare::Distance(const tetSquare& p) const{	
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

void tetSquare::Draw() {

	std::cout << ".\n";

}


