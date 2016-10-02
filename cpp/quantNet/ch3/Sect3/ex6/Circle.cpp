#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include <cmath>
#include <string>
/*
Default constructor
params: NONE
Description: creates a circle with default values of 5 radius
and center at origin. 
*/
Circle::Circle() {
	m_radius = 5;
	center = Point();
}

/*
Constructor
params: Point, unsigned double
Descriptiong: creates a circle with defined center_ and radius. 
*/
Circle::Circle(Point center_, double rad_) {
	//question: should i trust the default copy constructor to assign center the parameter outright? (center = center_;)
	center = center_;
	m_radius = rad_;
}

/*
Destructor
*/
Circle::~Circle(){
	//still don't understand necesity of defining anything here...do I destroy the component data members? does compiler take care of that ? I presume it does. 

}

/*
copy constructor
*/
Circle::Circle(const Circle& source) {
	Radius(source.Radius());
	CentrePoint(source.CentrePoint());
}

// view methods

/*
Diameter()
Params: NONE
Description: calculates a diameter based on radius and returns value. 
*/
double Circle::Diameter() const {
	return 2 * (m_radius);
}

/*
Area()
Params: NONE
Description: returns the area of the circle described by it's radius. 
*/
double Circle::Area() const {
	double Area = M_PI * (pow(m_radius, 2));
	return Area;
}

/*
Circumference
Params: NONE
Description: returns the circumference of the circle described by it's radius. 
*/

double Circle::Circumference() const{
	return M_PI * Diameter();

}

/*
ToString()
Params: NONE
Description: returns a string representation of the circle data:
*/

std::string Circle::ToString() const {
	return center.ToString() + " \nRadius: " + 
			std::to_string(m_radius) + 
			"\nArea: " + std::to_string(Area()) + 
			"\n Circumference: " +
			std::to_string(Circumference());
}

/*
Point CentrePoint()
Params: none
Description: returns a Point object clone of the center point indicated in the Circle object. 
*/
Point Circle::CentrePoint() const {
	Point newPoint = center;
	return newPoint;

}

/*
double Radius()
Params: NONE
Description: returns the double value representing the m_radius data member of the instance of Circle object invoking this method. 
*/

double Circle::Radius() const {
	return m_radius;
}

		// modifiers
/*
Diameter(unsigned double diam_)
Params: unsigned double
Description: alters the state of the circle object to change the radius data member. 
*/


// choosing a diameter vice rad method to take advantage of overloading. 
void Circle::Diameter(double diam_) {
	m_radius = diam_/2;
}

/*
void CentrePoint(Point candPoint)
Params: Point
Description: modifies the center point of the Circle Object. 
*/

void Circle::CentrePoint(Point center_) {
	center = center_;
}

/*
void radius(double rad_) 
Params: double
Descriptiong: changes the radius state of the Circle instance invoking the function. 
*/

void Circle::Radius(double rad_) {
	m_radius = rad_;
}	

