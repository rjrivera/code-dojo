/*
Level 3, Sect 3, Ex 1
Author Rob Rivera
Date 9-17-2016

ref used: https://msdn.microsoft.com/en-us/library/6t4fe76c.aspx
	for better understanding of destructors.

1 - the distance function WAS call by value - I altered to call-by-reference to reduce overhead

*/

#include <iostream>
#include "Point.hpp"

using namespace std;
int main() {
	// initialization
	Point pt1 = Point(14, -14);
	Point pt2 = Point(5, 8);

	
	cout << pt1.ToString() << endl;
	cout << pt2.ToString() << endl;

	cout << "distance between point 1 and 2: " << pt1.Distance(pt2) << endl;
	//constructor is called two times
	//destructor is called three times
	return 0;

}
