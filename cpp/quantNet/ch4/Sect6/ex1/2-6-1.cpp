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

using namespace RobRivera;

int main() {
	// initialize an array of Point pointers with 3 elements
	Containers::Array myArr = Containers::Array();
	
	Containers::Array * myPtrArr = new Containers::Array();
	Containers::Array * myPtrArr2 = new Containers::Array(50);	
	CAD::Point * tptr = new CAD::Point(4, 50);
	myPtrArr2->SetElement(49, tptr);
	
	// ==== me personally testing the nature of the class. 
	std::cout << myPtrArr2->GetElement(49) << std::endl;
	std::cout << (*myPtrArr2)[49] << std::endl;

	tptr = new CAD::Point(55, 55);
	myPtrArr2->SetElement(48, tptr);
	std::cout << (*myPtrArr2)[48] << std::endl;
	std::cout << (*myPtrArr2)[49] << std::endl;
	//=========== 
	return 0;

}
