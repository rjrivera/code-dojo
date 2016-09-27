/*
Level 4, Sect 5, Ex1
Author Rob Rivera
Date 9-23-2016

*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

using namespace std;
int main() {
	// initialization
	Point * p1 = new Point();
	Point * p2 = new Point(10, 10); 
	Point * p3 = new Point(*p1); 
	cout << *p1 << *p2 << *p3 << endl;
	
	cout <<	p1->Distance() << endl;
	cout << p2->Distance() << endl;
	cout << p3->Distance() << endl;

	int numPoints;
	cout << "How manypoints do you wish to make?\n";
	cin >> numPoints; 
	//can't use any constructors but the default
	// so ... my compiler doesn't give me a compiler error for the below line...
	Point p5[numPoints] = {};
	Point * p4 = new Point[numPoints];

	delete p1,p2,p3;
	delete[] p4;
	
	
	
	
	return 0;

}
