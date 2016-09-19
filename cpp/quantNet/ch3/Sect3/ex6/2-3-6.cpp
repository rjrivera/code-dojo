/*
Level 3, Sect 3, Ex 6
Author Rob Rivera
Date 9-17-2016

*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"

using namespace std;
int main() {
	// initialization

	Point pt1 = Point(14, -14);
	Point pt2 = Point();
	Circle c1 = Circle();
	Circle c2 = Circle(pt1, 10);

	// information display
	cout << "point 1 info" << endl;
	cout << pt1.ToString() << endl;

	cout << "Circle 1 and 2 information" << endl;
	cout << c1.ToString() << endl;
	cout << c2.ToString() << endl;
	
	cout << "testing modification functions defined" << endl;
	//interesting note: cout statements in Length() output prior to the original cout call - observe what is written between above and before. Text found in Point::Distance(Point candidate)
	c2.CentrePoint(pt2);
	cout << "changed center point of circle 2 to origin" << endl;
	cout << c2.ToString() << endl;

	cout << "changing radius to 15.567" << endl;
	c2.Radius(15.567);
	cout << c2.ToString() << endl;

	cout << "\nusing point 1 to test point functions of Circle class " << endl << "point 1 information currently: " << endl << pt1.ToString();

	pt1 = c2.CentrePoint();
	cout << "after setting pt1 to center of c2 (origin): " << pt1.ToString() << endl;
	//constructor is called two times
	//destructor is called three times

	return 0;

}
