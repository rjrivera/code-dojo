#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <cmath>
#include <string>

	//Default Constructor
	//sets start and end points to origin
Line::Line(){
	
	ptStart = new Point();
	ptEnd = new Point();

}
Line::Line(Point& start_, Point& end_) {
	
	ptStart = new Point(start_.X(), start_.Y());
	ptEnd = new Point(end_.X(), end_.Y());

}
	//copy constructor
Line::Line(const Line& sauce) {
	*ptStart = sauce.start();
	*ptEnd = sauce.end();
	
}

Line::~Line() {

}

Point Line::start() const{
	// ?do I want to return a dereference object or a new object created in the function then return it?
	return *ptStart;
}

Point Line::end() const{
	return *ptEnd;
}	
	
void Line::start(Point candidate) {
	ptStart->X(candidate.X());
	ptStart->Y(candidate.Y());
}

void Line::end(Point candidate) {
	ptEnd->X(candidate.X());
	ptEnd->Y(candidate.Y());
}

std::string Line::ToString(){
	return ptStart->ToString() + ptEnd->ToString();
}

double Line::Length() const{

	return ptStart->Distance(*ptEnd);
}
	



