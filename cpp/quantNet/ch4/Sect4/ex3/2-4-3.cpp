/*
Level 4, Sect 4, Ex 2
Author Rob Rivera
Date 9-21-2016

*/

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

using namespace std;
int main() {
	// initialization
	
	Point p = Point(1.0,1.0);
	if (p==1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
	
	return 0;

}
