/*
Level 4, Sect 4, Ex 1
Author Rob Rivera
Date 9-17-2016

*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"

using namespace std;
int main() {
	// initialization
	
	Point pt1 = Point(5,5);
	cout << pt1.ToString() << endl;
	cout << "testing - operator\n";
	pt1 = -pt1;
	cout << pt1.ToString() << endl;
	
	pt1 = pt1 * 3;
	cout << "testing * operator, scaling by 3\n";
	cout << pt1.ToString() << endl;

	Point pt2 = Point(-10, 5);
	pt1 = pt1 + pt2;
	cout << "testing + operator with this point: " << pt2.ToString() << endl;
	
	cout << pt1.ToString() << endl;

	cout << "testing cmp operator" << endl;
	if(pt1==pt2) {cout << "pt1 == pt2\n";}
	else { cout << "pt1 != pt2\n"; }

	cout << "testing assignment operator\n";
	pt1 = pt2;
	cout << "pt1 = pt2 operation results: \n";
	cout << pt1.ToString() << endl << pt2.ToString() << endl;

	cout << "testing *= operator\n";
	pt1 *= 5;
	cout << "pt1 after *=5: " << pt1.ToString() << endl;
	
	
	return 0;

}
