#include <iostream>
#include "Point.hpp"
#include <string>


//constructors
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int x_, int y_){
	x = x_;
	y = y_;
}
	
//selectors
int Point::getX(){
	return x;
}

int Point::getY(){
	return this->y;
}
	
std::string Point::ToString(){
	return ("( " + std::to_string(x) + ", " + std::to_string(y) + " )\n");
}

	//mutators
int Point::setX(int x_){
	x = x_;
}
	
int Point::setY(int y_){
	this->y = y_;
}

	

