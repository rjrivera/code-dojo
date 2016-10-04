#ifndef LINE_HPP
#define LINE_HPP
#include <iostream>
#include "Point.hpp"
#include "Shape.hpp"

/*
	RELEASE NOTES v3-5-2

	ToString() amended to override the Shape virtual function
*/

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
	~Line() override;

	Line& operator= (const Line& source);

	Point start() const;
	Point end() const;
	
	void start(Point candidate_);
	void end(Point candidate_);

	std::string ToString() const override;
	double Length() const;
	

};
#endif
