#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.cpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"

using namespace std;

/*
	RELEASE NOTE v 3-6-1

	Amended Array to throw an error for exception handling bounds erros. 

	after attempting to access out of bounds elements, exception is thrown but no caught, abort call made. 

	If the Array.hpp included the code snippet to include the .cpp code, then you can continue using the .hpp FILE IN THE INLUDE STATEMENT FOR THE MAIN program, because then the header would also contain the source code as per the compiler's behavior. 
developer has chosen not to include the Header.
*/

int main() {

	Array<Point> arr = Array<Point>(5);// = Array<int>(5); //create an array of length 5. 
	try {
		cout << arr[3] << endl;//attempt to access the nonexistent 6th element. 
	}
	catch(ArrayException& e) {
		cout << e.GetMessage();
	}
	catch(...) {
		cout << "exception thrown and caught\n";
	}
	return 0;

}
