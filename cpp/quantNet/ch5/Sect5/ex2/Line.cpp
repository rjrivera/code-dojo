#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "Shape.hpp"
/*

	RELEASE NOTES v. 2-5-3

	Amended default constructor utilize colon syntax in initializing the Point objects. 

	Amended definitions in .hpp and here to inherit from shape class.

*/


//Default Constructor
//sets start and end points to origin
Line::Line() : ptStart(), ptEnd(), Shape(){

}

//Alt constructor
//utilize Shape constructor
Line::Line(Point start_, Point end_) : Shape() {
	
	ptStart = start_;
	ptEnd = end_;

}
//copy constructor
Line::Line(const Line& sauce){
	ptStart = sauce.ptStart;
	ptEnd = sauce.ptEnd;
	//copy Shape::m_id
	m_id = sauce.m_id;
	
}

//no dynamic objects to delete. 
Line::~Line() {

}

//overload = operator

Line& Line::operator= (const Line& source) {
	ptStart = source.ptStart;
	ptEnd = source.ptEnd;
	//copy Shape::m_id
	m_id = source.m_id;
	return *this;
}

//getter method
//return start point of line. 
Point Line::start() const{
	
	return ptStart;
}
//getter method
//return copy of end point of line. 
Point Line::end() const{
	return ptEnd;
}	
	
//setter method
//set start point to candidate value. 
void Line::start(Point candidate_) {
	ptStart = candidate_;
}

//setter method 
//set end point to candidate value.
void Line::end(Point candidate_) {
	ptEnd = candidate_;
}

//to string must manuall call base class to string method. 
std::string Line::ToString() const {
	return 	ptStart.ToString() + ptEnd.ToString() +
			"\n" + Shape::ToString() + "\n";
}
// calculates and returns the euclidean distance between start
// and end point. 
double Line::Length() const{

	return ptStart.Distance(ptEnd);
}
	



