/*
Level 3, Sect 3, Ex 5
Author Rob Rivera
Date 9-17-2016

Creating a const point and attemptint to set the x-coord.:

const Point cp(1.5, 3.9);
cp.X(0.3);

*/

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

using namespace std;
int main() {
	// initialization

	Point pt1 = Point(14, -14);
	Point pt2 = Point(5, 8);

	Line ln1 = Line();
	Line ln2 = Line(pt1, pt2);

	cout << "point 1 & 2 info" << endl;
	cout << pt1.ToString() << endl;
	cout << pt2.ToString() << endl;

	cout << "line 1 and line 2 information" << endl;
	cout << ln1.ToString() << endl;
	cout << ln2.ToString() << endl;

	//interesting note: cout statements in Length() output prior to the original cout call - observe what is written between above and before. Text found in Point::Distance(Point candidate)
	cout << "distance of line 2: " << ln2.Length() << endl;
	//constructor is called two times
	//destructor is called three times

	return 0;

}
