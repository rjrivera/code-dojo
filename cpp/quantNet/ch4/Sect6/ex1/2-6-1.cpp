/*
Level 4, Sect 6, Ex1
Author Rob Rivera
Date 9-27-2016
*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Array.hpp"

#define cad RobRivera::CAD

//using namespace RobRivera; as per problem instructions. 

int main() {
	// initialize an array of Point pointers with 3 elements
	RobRivera::Containers::Array myArr = RobRivera::Containers::Array();
	
	RobRivera::Containers::Array * myPtrArr = new RobRivera::Containers::Array();
	RobRivera::Containers::Array * myPtrArr2 = new RobRivera::Containers::Array(50);	
	// in the main program, the full namespace for Point class
	RobRivera::CAD::Point * tptr = new RobRivera::CAD::Point(4, 50);

	// in the main program, using declaration for using a single class (Line).
	using RobRivera::CAD::Line;
	Line * myLine = new Line();

	std::cout << "line info: " << (*myLine).ToString() << std::endl;

	//in the main program, using declaration fo a complete namespace (containers) 
	
	using namespace RobRivera::Containers;
	Array * myPtrArr3 = new Array(25);
	std::cout << myPtrArr3->GetElement(24) << std:: endl;

	//in the main program, using the Circle class by ceating a shorter alias for the YourName::CAD namespace.
	//interpreting as use macros. 
	cad::Circle * myCircle = new cad::Circle();
	std::cout << myCircle->ToString() << std::endl;
	

	myPtrArr2->SetElement(49, tptr);
	
	// ==== me personally testing the nature of the class. 
	std::cout << myPtrArr2->GetElement(49) << std::endl;
	std::cout << (*myPtrArr2)[49] << std::endl;

	tptr = new RobRivera::CAD::Point(55, 55);
	myPtrArr2->SetElement(48, tptr);
	std::cout << (*myPtrArr2)[48] << std::endl;
	std::cout << (*myPtrArr2)[49] << std::endl;
	//=========== 
	return 0;

}
