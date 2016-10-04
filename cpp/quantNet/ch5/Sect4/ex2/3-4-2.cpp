#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
//#include "global_vars.hpp"

using namespace std;

// global random seeded at program execution. 
// TODO: improve class by making single seed and rng 
// as-is, each object instantiates it's own random object--inefficient.
//normal_distribution<double> distribution;
//default_random_engine generator;

int main() {

	Shape s;		//Create shape.
	Point p(10, 20);	//Create Point.
	Line l(Point(1,2), Point(3,4)); // Create Line.

	cout << s.ToString() << endl;//print shape. 
	cout << p.ToString() << endl;//print point.
	cout << l.ToString() << endl;//print line.

	cout << "Shape ID: " << s.ID() << endl; //ID of the shape
	cout << "Point ID: " << p.ID() << endl; //ID of the Point
	cout << "Line ID: " << l.ID() << endl; // ID of the line
	
	Shape* sp;			//Create point to a shape variable.
	sp = &p;			// Point in a shape variable? Possible? Sure why not? but it MUST be pointing to an instanted point, as is it's ok. if p was not instantied it would return garbage. 
	cout << sp->ToString() << endl;// What is printed? 
					// same information as p.ToString()

	//Create and copy Point p to a new point.
	Point p2; 
	p2 = p;
	cout << endl << p2<<", " <<p2.ID() << endl; //Is the ID Copied if you do not call the base class assignment in point?
//		no, which is why we manually assign the base class variable in the derived class. 	
	/* developmental testing code block	
	Line l, m;
	Circle a;
	Circle b;
	Shape d, e, f;
	
	cout << "Testing construction of Circle\n";
	cout << a.ToString() << endl;
	cout << b.ToString() << endl;

	cout << "Testing operator= of Circle\n";
	a = b;
	cout << a.ToString() << endl;
	cout << b.ToString() << endl;
	// ======================
	cout << "====================" << endl;
	cout << "Testing construction of Shape\n";
	cout << d.ToString() << endl;
	cout << e.ToString() << endl;
	cout << f.ToString() << endl;
	cout << "Testing operator= of Shape\n";
	d = e = f;
	cout << d.ToString() << " - " << e.ToString() << " - " << f.ToString() << endl << "===============~~~~~~~~~~~~===========" << endl;
	// ====================
	cout << "Testing construction of Circle\n";
	cout << l.ToString() << endl;
	cout << m.ToString() << endl;
	
	// testing assignment operator
	cout << "Testing construction of operator= for circle\n";
	l = m;
	cout << l.ToString() << " - " << m.ToString() << endl;
	// after changing from the manual call to Point() to 
	// colon syntax, I have observed a reduction in constructor
	// destructor and assignment calls. 
	*/
	return 0;

}
