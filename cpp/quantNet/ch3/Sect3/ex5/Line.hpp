#ifndef LINE_HPP
#define LINE_HPP
#include <iostream>
#include "Point.hpp"

class Line {
private:
	Point * ptStart;
	Point * ptEnd;

public:
	//Default Constructor
	//sets start and end points to origin
	Line();
	Line(Point& start_, Point& end_);
	//copy constructor
	Line(const Line& sauce);
	~Line();

	Point start() const;
	Point end() const;
	
	void start(Point candidate);
	void end(Point candidate);

	std::string ToString();
	double Length() const;
	

};
#endif
