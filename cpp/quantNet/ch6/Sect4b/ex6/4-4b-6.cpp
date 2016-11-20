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
#include "PointArray.cpp"
#include "Stack.cpp"

using namespace std;

/*
	RELEASE NOTE v 4-4b-1

	Implemented a Templated Stack class and used the Array<T> class as a data member for the data storage component demonstrating the composition concept of OOP.

	Current file implements tests to validate proper implementation of the Stack API annotated in Stack.hpp

*/

int main() {
	Stack<int, 5> myS = Stack<int, 5>();
	Stack<int, 5> m;
	m.push(5);
	myS.push(5);
	
	myS.push(4);
	//myS.pop();
	myS.push(2);
	// should yield 2;
	cout << myS.front() << endl;
	// should yield 5;
	//myS.pop();
	cout << myS.front() << endl;
	myS.push(10);
	
	cout << myS.front() << endl;
	try {
	myS.push(1);
	myS.push(2);
	myS.push(3);
	myS.push(4);
	myS.push(5);
	}
	catch (StackFullException e) {
		cout << e.getMessage() << endl;
	}
	catch (...) {
		cout << "unknown Exception caught\n";
	}
	try{
	myS.pop();
	myS.pop();
	myS.pop();
	myS.pop();
	myS.pop();
	myS.pop();
	myS.pop();
	}
	catch (StackEmptyException e) {
		cout << e.getMessage() << endl;
	}

	return 0 ;
}
