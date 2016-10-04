#ifndef LINE_HPP
#define LINE_HPP
#include <iostream>
#include "Point.hpp"
#include "Shape.hpp"

class Line : public Shape{
private:
	Point ptStart;
	Point ptEnd;

public:
	//Default Constructor
	//sets start and end points to origin
	Line();
	Line(Point start_, Point end_);
	//copy constructor
	Line(const Line& sauce);
	~Line();

	Line& operator= (const Line& source);

	Point start() const;
	Point end() const;
	
	void start(Point candidate_);
	void end(Point candidate_);

	std::string ToString();
	double Length() const;
	

};
#endif
