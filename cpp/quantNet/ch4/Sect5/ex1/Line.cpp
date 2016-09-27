#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <cmath>
#include <string>

	//Default Constructor
	//sets start and end points to origin
Line::Line(){
	
	ptStart = Point();
	ptEnd = Point();

}
Line::Line(Point start_, Point end_) {
	
	ptStart = start_;
	ptEnd = end_;

}
	//copy constructor
Line::Line(const Line& sauce) {
	ptStart = sauce.start();
	ptEnd = sauce.end();
	
}

Line::~Line() {

}

//overload = operator
Line& Line::operator= (const Line& source) {
	ptStart = source.start();
	ptEnd = source.end();
	return *this;
}

Point Line::start() const{
	
	return ptStart;
}

Point Line::end() const{
	return ptEnd;
}	
	
void Line::start(Point candidate_) {
	ptStart = candidate_;
}

void Line::end(Point candidate_) {
	ptEnd = candidate_;
}

std::string Line::ToString(){
	return ptStart.ToString() + ptEnd.ToString();
}

double Line::Length() const{

	return ptStart.Distance(ptEnd);
}
	



