/*
Level 4, Sect 4, Ex 2
Author Rob Rivera
Date 9-21-2016

*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

using namespace std;
int main() {
	// initialization
	
	Point pt1 = Point(5,5);
	cout << "testing '<<' operator overload\n";
	cout << pt1 << endl;
	
	return 0;

}
