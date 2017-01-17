#include <iostream>
#include <chrono>
#include <random>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple.hpp>
#include <boost/shared_ptr.hpp>


using namespace std;


int main() {
	//initialize an array of size 5 to contain obects of type 'boost::shared_ptr<Shape>'
	Array<boost::shared_ptr<Shape>> shapes  = Array<boost::shared_ptr<Shape>>(5);
	//create a number of different shapes using shared pointers.
	boost::shared_ptr<Circle> c(new Circle());
	boost::shared_ptr<Point> p(new Point());
	boost::shared_ptr<Line> l(new Line());
	// place the new pointers into the array we created 
	shapes[0] = c;
	shapes[1] = p;
	shapes[2] = l;
	//print out each shape's details
	for (int i = 0; i < 3; i++) cout << shapes[i]->ToString() << endl;

	return 0 ;
}
