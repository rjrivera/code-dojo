#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
using namespace std;

int main() {

	Line l;
	Circle a;
	Circle b;
	cout << l.ToString() << endl;
	cout << "Circle A" << endl;	
	cout << a.ToString() << endl;
	cout << "Circle B" << endl;
	cout << b.ToString() << endl;
	if (a==b) {
		cout << "Circle A equals Circle B according to '==' operator overload" << endl;
	}
	// after changing from the manual call to Point() to 
	// colon syntax, I have observed a reduction in constructor
	// destructor and assignment calls. 
	return 0;

}
