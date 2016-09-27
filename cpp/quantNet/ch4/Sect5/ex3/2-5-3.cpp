/*
Level 4, Sect 5, Ex3
Author Rob Rivera
Date 9-23-2016
*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Array.hpp"

using namespace std;

int main() {
	// initialize an array of Point pointers with 3 elements
	Array myArr = Array();
	Array * myPtrArr = new Array();
	Array * myPtrArr2 = new Array(50);	
	
	// ==== me personally testing the nature of the class. 
	/*
	Point testPoint = myPtrArr2->point(0);
	cout << testPoint << endl;
	testPoint = myPtrArr->point(0);
	cout << testPoint << endl;	
	*/
	//=========== 

	return 0;

}
