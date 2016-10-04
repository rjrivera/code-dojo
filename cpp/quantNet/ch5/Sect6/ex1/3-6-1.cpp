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
	RELEASE NOTE v 3-6-1

	Amended Array to throw an error for exception handling bounds erros. 

	after attempting to access out of bounds elements, exception is thrown but no caught, abort call made. 
*/

int main() {

	Array arr = Array(5); //create an array of length 5. 
	try {
		cout << arr[5] << endl;//attempt to access the nonexistent 6th element. 
	}
	catch(...) {
		cout << "exception thrown and caught\n";
	}
	return 0;

}
