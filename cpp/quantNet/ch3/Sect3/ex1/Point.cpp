#include <iostream>
#include "Point.hpp"
#include <string>
#include <cmath>

//constructors
Point::Point() {
	x = 0;
	y = 0;
	std::cout << "inside default constructor" << std::endl;
}

Point::Point(double x_, double y_){
	x = x_;
	y = y_;
	std::cout << "inside Point(double x, double y) constructor" << std::endl;
}

Point::~Point() {
	// deallocate the memory that was previously reserved for object
	std::cout << "inside the destructor" << std::endl;
}

//copy constructor
Point::Point(const Point& sauce) {

	std::cout << "inside the copy constructor" << std::endl;

}
	
//selectors
double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}
	
std::string Point::ToString(){
	return ("( " + std::to_string(x) + ", " + std::to_string(y) + " )\n");
}

	//mutators
void Point::setX(double x_){
	x = x_;
}
	
void Point::setY(double y_){
	y = y_;
}

double Point::DistanceOrigin() {
	double a = std::abs(x);
	double b = std::abs(y);
	return (std::sqrt(pow(a,2) + pow(b,2)));
	
}

//altered signature to pass-by-reference in order to avoid copy constructor call and reduce overhead. 
double Point::Distance(Point& p){	
	double a, b;
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

	

