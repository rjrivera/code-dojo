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
	RELEASE NOTE v 3-5-3

	Amended Point, Line, and Shape class destructors to include text for demonstration purposes. 

	Initial destructors (prior to virtual) only delete the base class portions of the objects, not the Point or Line. 

	Amended to add virtual to the base class destructor.
	Proper destructors are now called. 
*/

// global random seeded at program execution. 
// TODO: improve class by making single seed and rng 
// as-is, each object instantiates it's own random object--inefficient.
//normal_distribution<double> distribution;
//default_random_engine generator;

int main() {

	Shape * s[3];
	s[0] = new Shape;
	s[1] = new Point;
	s[2] = new Line;
	for (int i = 0; i < 3; i++) {
		delete s[i];
	}
	return 0;

}
