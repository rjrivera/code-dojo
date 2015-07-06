#include"Rectangle.h"
#include<iostream>

using namespace std;

int main(){

	std::cout << "This is a test strap program\n";

        Rectangle* myFirstRect = new Rectangle(5, 10, 4, 8);

	std::cout << "Incoming data on rectangle (x, y, width, height): \n " <<
	myFirstRect->x << "\n" <<
	myFirstRect->y << "\n" <<
	myFirstRect->width << "\n" <<
	myFirstRect->height;


	return 1; 

}
