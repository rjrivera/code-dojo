/*
Lvl3, Sect2, Ex2
Author: Rob Rivera
Date: 9-17-2016
*/

#include <iostream>
#include "Point.hpp"

using namespace std;
int main() {
	// constructors
	Point pt1 = Point(14, -14);
	Point pt2 = Point(5, 8);

	
	cout << pt1.ToString() << endl;
	cout << pt2.ToString() << endl;

	cout << "distance between point 1 and origin: " << pt1.DistanceOrigin() << endl;

	cout << "distance between point 1 and 2: " << pt1.Distance(pt2) << endl;
	return 0;

}
