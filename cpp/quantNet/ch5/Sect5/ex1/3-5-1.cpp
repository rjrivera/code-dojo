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
	
*/

// global random seeded at program execution. 
// TODO: improve class by making single seed and rng 
// as-is, each object instantiates it's own random object--inefficient.
//normal_distribution<double> distribution;
//default_random_engine generator;

int main() {

	Shape * sPtr;		//Create shape pointer.
	Point p(10, 20);	//Create Point.

	sPtr = &p; 		//point in Point Object to Shape pointer

	cout << sPtr->ToString() << endl; //Shape pointer now calls Point->ToString() 
	return 0;

}
