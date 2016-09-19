/*
Lvl3, Sect2, Ex1

Author Rob Rivera
Date 9-17-2016

*/

#include <iostream>
#include "Point.hpp"

using namespace std;
int main() {
	// initialize and requesnt user input. 
	double x, y;
	cout << "please enter integer for an 'x' coordinate" << endl;
	cin >> x;
	cout << "please enter an integer for a 'y' coordinate" << endl;
	cin >> y;
	//testing the two constructors AND exploring (new) keyword implementation.

	Point * pt1 = new Point();
	pt1->setX(x);
	pt1->setY(y);
	
	// testing other constructor
	Point pt2 = Point(x, y);

	//printing using the ToString function
	cout << pt2.ToString() << endl;
	cout << (*pt1).ToString() << endl;

	//printing using the get functions
	cout << "using get functions" << endl;
	cout << "( " << pt2.getX() << ", " << pt2.getY() << ")" << endl;
	return 0;

}
