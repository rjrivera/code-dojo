/*
Level 3, Sect 3, Ex 4
Author Rob Rivera
Date 9-17-2016

Creating a const point and attemptint to set the x-coord.:

const Point cp(1.5, 3.9);
cp.X(0.3);

*/

#include <iostream>
#include "Point.hpp"

using namespace std;
int main() {
	// initialization
	Point pt1 = Point(14, -14);
	Point pt2 = Point(5, 8);

	const Point cp(1.5, 3.9); //caueses an error at compile until the functions are made const.  call below does not compile because it DOES alter the state of the object...even tho the point is const
	//cp.X(0.3);

	cout << cp.X() << endl; // still gives compiler error. 
	
	cout << pt1.ToString() << endl;
	cout << pt2.ToString() << endl;

	cout << "distance between point 1 and 2: " << pt1.Distance(pt2) << endl;
	//constructor is called two times
	//destructor is called three times
	return 0;

}
