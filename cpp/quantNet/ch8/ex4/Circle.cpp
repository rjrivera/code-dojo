#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include <cmath>
#include <string>

/*
	RELEASE NOTES v 3-5-4
	amended with interface implementation of Shape::Draw()

*/
/*
Default constructor
params: NONE
Description: creates a circle with default values of 5 radius
and center at origin. 
*/
Circle::Circle() : m_radius(5), center(), Shape() {
}

/*
Constructor
params: Point, unsigned double
Descriptiong: creates a circle with defined center_ and radius. 
*/
Circle::Circle(Point center_, double rad_) : center(center_), m_radius(rad_), Shape() {
}

/*
Destructor
*/
Circle::~Circle(){
	
}

/*
copy constructor
*/
Circle::Circle(const Circle& source) : m_radius(source.m_radius), center(source.center), Shape(){
}

/*
operator= overload
*/
Circle& Circle::operator=(const Circle& source) {
	m_radius = source.m_radius;
	center = source.center;	
	// copy Shape::m_id directly from source
	m_id = source.m_id;
	return *this;
}

// view methods
bool Circle::operator==(const Circle& source) const {
	if (m_radius == source.m_radius &&
		center == source.center && m_id == source.m_id) {
		return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream& os, const Circle& source) {
	os << source.ToString();
	return os;
}

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
	return "Shape ID: " + std::to_string(m_id) + center.ToString() + " \nRadius: " + 
			std::to_string(m_radius) + 
			"\nArea: " + std::to_string(Area()) + 
			"\n Circumference: " +
			std::to_string(Circumference()) + 
			"\n Center: " + center.ToString();
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

void Circle::Draw() {

	std::cout <<"  _ \n" <<
		    " / \\\n" <<
		    "|   |\n" <<
		    " \\_/\n";

}

void Circle::Print() const {
	std::cout << this->ToString() << std::endl;
}
