#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"

using namespace std;

/*
	RELEASE NOTE v 4-4b-1

	Amended the template for Array to hold a static variable along with appropriate accessor/mutator functions. 

	Observations on output of: 10 10 10 15 15 10 
		- The static variable is excluse to the T type instatiaed. In other words, the Array<int> instances share a unique static variable from the Array<double> instances.

		- behavior is consistent with the student's understanding of metaprogramming as per the compiler. 
*/

int main() {
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.DefaultSize()<<endl;
	cout << intArray2.DefaultSize()<<endl;
	cout << doubleArray.DefaultSize() << endl;

	intArray1.DefaultSize(15);

	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

}
