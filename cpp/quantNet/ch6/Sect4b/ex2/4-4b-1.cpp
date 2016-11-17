#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.cpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "NumericArray.cpp"

using namespace std;

/*
	RELEASE NOTE v 4-4b-1

	Amended the template for Array to hold a static variable along with appropriate accessor/mutator functions. 

	Observations on output of: 10 10 10 15 15 10 
		- The static variable is excluse to the T type instatiaed. In other words, the Array<int> instances share a unique static variable from the Array<double> instances.

		- behavior is consistent with the student's understanding of metaprogramming as per the compiler. 

	Assumptions made: the numeric array assumes that all possible instances of T can be implicitly typecasted to (int) by the runtime environment, with no proper use of a lexical cast.
*/

int main() {
	NumericArray<int> intArray1(5);
	intArray1[0] = 1;
	intArray1[1] = 2;
	intArray1[2] = 3;
	intArray1[3] = 4;
	intArray1[4] = 5;
	NumericArray<int> intArray2(5);
	intArray2[0] = 1;
	intArray2[1] = 2;
	intArray2[2] = 3;
	intArray2[3] = 4;
	intArray2[4] = 5;
	int tempDP = intArray1.DotProduct(intArray2);
	cout << "dot product of arrays 1 and 2 is: " << tempDP << endl;
	
	NumericArray<int> intArray3(4);
	intArray2[0] = 1;
	intArray2[1] = 2;
	intArray2[2] = 3;
	intArray2[3] = 4;

	cout << "attempting to dp two numarrays that are differenct lenghts: " << endl; 
	intArray1.DotProduct(intArray3);
	
	intArray1 = intArray1 + intArray2;
	intArray1 = intArray1 * 2;
	
	for (int i = 0 ; i < 5; i++) {
		cout << intArray1[i] << endl;

	}

}
