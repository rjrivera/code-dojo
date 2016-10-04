#include <iostream>
#include "Point.hpp"
#include <string>
#include <cmath>

/*
	RELEASE NOTES v 3-5-1

	Amended class definition to override virtual function of base class Shape.
*/

//constructors
Point::Point() : x(0), y(0), Shape(){
}

Point::Point(double x_, double y_) : x(x_), y(y_), Shape(){

}

Point::Point(double z_) : x(z_), y(z_), Shape(){
}

Point::~Point() {
}

//copy constructor
Point::Point(const Point& sauce) {
	x = sauce.x;
	y = sauce.y;
	m_id = sauce.m_id;

}

//operator overloading

Point Point::operator-() const{
	Point temp = Point(x*-1, y*-1);
	return temp;
}

Point Point::operator* (double factor) const {
	Point temp = Point(x*factor, y*factor);	
	return temp;
}

Point Point::operator+ (const Point& p) const{ // Add Coordinates
	
	Point temp = Point(x + p.X(), y + p.Y());
	return temp;
}

bool Point::operator== (const Point& p) const {
	if (p.x == x && p.y == y && p.m_id == m_id) {
		return true;
	}
	return false;
}

Point& Point::operator= (const Point& source) {
	x = source.x;
	y = source.y;
	m_id = source.m_id;
	return *this;	
}

Point& Point::operator*= (double factor) {
	x *= factor;
	y *= factor;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Point& source) {
	os << "Point ID: " << source.m_id << "(" << source.x << ", " << source.y << ")" << std::endl;
	return os;
}
//selectors
double Point::X() const {
	return x;
}

double Point::Y() const {
	return y;
}
	
std::string Point::ToString() const {
	return ("Point ID: " + std::to_string(m_id) + 
		"( " + std::to_string(x) + ", " + 
			std::to_string(y) + " )\n" + 
			"Shape base ID: " + Shape::ToString());
}

	//mutators
void Point::X(double x_){
	x = x_;
}
	
void Point::Y(double y_){
	y = y_;
}

double Point::Distance() const {
	double a = std::abs(x);
	double b = std::abs(y);
	return (std::sqrt(pow(a,2) + pow(b,2)));
}

//altered signature to pass-by-reference in order to avoid copy constructor call and reduce overhead. Made argument const as per instructions so function cannot alter state of referenced value. 
double Point::Distance(const Point& p) const{	
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

	

