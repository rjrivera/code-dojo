#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
//#include "global_vars.hpp"

using namespace std;

/*
	RELEASE NOTE v 3-5-2

	Amended Point and Line class ToString() to include base call to Shape ToString().

	AUTHORS NOTE - 

	I get the nature of the base call to the ToString from the derived class...but it appears I 'jumped the gun' in functionality by declaring the base class variables as 'protected' and accessing them directly. 

*/

// global random seeded at program execution. 
// TODO: improve class by making single seed and rng 
// as-is, each object instantiates it's own random object--inefficient.
//normal_distribution<double> distribution;
//default_random_engine generator;

int main() {

	Shape * sPtr1;
	Shape * sPtr2;		//Create shape pointer.
	Point p(10, 20);	//Create Point.
	Line l(p, Point(25, 25));
	sPtr1 = &p; 		//point in Point Object to Shape pointer
	sPtr2 = &l;

	cout << sPtr1->ToString() << endl; //Shape pointer now calls Point->ToString() 
	cout << sPtr2->ToString() << endl;

	return 0;

}
