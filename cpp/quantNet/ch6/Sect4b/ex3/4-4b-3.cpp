#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "NumericArray.cpp"
#include "PointArray.cpp"

using namespace std;

/*
	RELEASE NOTE v 4-4b-1

	Amended the template for Array to hold a static variable along with appropriate accessor/mutator functions. 

	Observations on output of: 10 10 10 15 15 10 
		- The static variable is excluse to the T type instatiaed. In other words, the Array<int> instances share a unique static variable from the Array<double> instances.

		- behavior is consistent with the student's understanding of metaprogramming as per the compiler. 

	Assumptions made: the numeric array assumes that all possible instances of T can be implicitly typecasted to (int) by the runtime environment, with no proper use of a lexical cast. This is largely based on the implementation of the DotProduct function, as the attempted compilation would lead to.
*/

int main() {
	PointArray<Point> pA(3);
	pA[0] = Point();
	pA[1] = Point(2, 2);
	pA[2] = Point(3, 5);

	cout << "distance between the 3 predefined points in the PArray: " << pA.Length();

	return 0 ;
}
