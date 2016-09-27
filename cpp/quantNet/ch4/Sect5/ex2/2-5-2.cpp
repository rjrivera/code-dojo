/*
Level 4, Sect 5, Ex2
Author Rob Rivera
Date 9-23-2016
TODO: make a drawing of the memory layout. 
*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

using namespace std;
int main() {
	// initialize an array of Point pointers with 3 elements
	Point ** ptrArr = new Point*[3];
	for (int i = 0; i < 3; i++) {
		//initialize each element with a Point on the heap 
		ptrArr[i] = new Point();
	
	}
	for (int i = 0; i < 3; i++) {
		cout << *ptrArr[i] <<endl;
	}
	//deleting each point. 
	for (int i = 0; i < 3; i++) {
		delete ptrArr[i];
	}
	delete[] ptrArr;
	
	return 0;

}
