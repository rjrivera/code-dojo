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
	
	Point * tptr = new Point(4, 50);
	myPtrArr2->SetElement(49, *tptr);
	myPtrArr2->SetElement(0, *tptr);
	// ==== me personally testing the nature of the class. 
	//testing 'get element' used prior to reviewing specifications.
	//not removing because
	Point testPoint = Point();
	try {
		testPoint = myPtrArr2->GetElement(0);
	}
	catch (int i) {
		cout << "bad access error caught" << endl;
	}
	myPtrArr2->SetElement(48, testPoint);
	//testing getelement
	try {
		cout << myPtrArr2->GetElement(48) << endl;
		cout << myPtrArr2->GetElement(49) << endl;
	}
	catch (int i) {
		cout << "bad access error caught" << endl;

	}
	//testing [] operator
	cout << (*myPtrArr2)[48] << endl;
	cout << (*myPtrArr2)[49] << endl;


	tptr = new Point(55, 55);
	myPtrArr2->SetElement(48, *tptr);
	//testing operator= and setelement
	cout << (*myPtrArr2)[48] << endl;
	cout << (*myPtrArr2)[49] << endl;
	//testing size
	cout << myPtrArr2->Size() << endl;
	cout << myPtrArr->Size() << endl;

	(*myPtrArr) = (*myPtrArr2);
	cout << myPtrArr2->Size() << endl;
	cout << myPtrArr->Size() << endl;
	
	//=========== 

	

	return 0;

}
