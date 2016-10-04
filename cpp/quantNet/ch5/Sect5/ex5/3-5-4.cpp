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
	RELEASE NOTE v 3-5-4

	Amended Point, Line, and Shape class to implement Draw() interface of ABC Shape, No you cannot instantiate a Shape clase because the presence of an interface makes it an ABC
*/

// global random seeded at program execution. 
// TODO: improve class by making single seed and rng 
// as-is, each object instantiates it's own random object--inefficient.
//normal_distribution<double> distribution;
//default_random_engine generator;

int main() {

	Shape * s[3];
	s[0] = new Circle;
	s[1] = new Point;
	s[2] = new Line;
	for (int i = 0; i < 3; i++) {
		s[i]->Draw();
	}
	return 0;

}
