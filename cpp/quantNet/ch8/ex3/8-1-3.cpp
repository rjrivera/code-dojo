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
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple_io.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>
#include <boost/variant.hpp>
#include <boost/variant/apply_visitor.hpp>


using namespace std;

//typedef defining boost::variant<...> ShapeType as per specs.
typedef boost::variant<Point, Line, Circle> ShapeType;

//specific print function for the Person typedef
ShapeType  queryShapeType() {
	cout << "What type of shape do you want to create?\n";
	cout << "[Circle] for cirlce, [Point] for point, [Line] for Line, then press enter\n";
	string input;
	do{
		cin >> input;
	}while(input != "Circle" && input != "Line" && input != "Point");

	ShapeType newShape;
	//battery of if statements processing the valid input. 
	if(input == "Circle") 		newShape = *(new Circle());
	else if(input == "Line")	newShape = *(new Line());
	else if(input == "Point") 	newShape = *(new Point());
			
	return newShape;

}

class move_visitor : public boost::static_visitor<> {
	private:
		double m_dx, m_dy;
	public:
		move_visitor(double x, double y):m_dx(x), m_dy(y){}
		void operator()(Point& p) const{
			p.X(p.X()+m_dx);
			p.Y(p.Y()+m_dy);

		}
	
		void operator()(Circle& c) const{
			Point curP = c.CentrePoint();
			curP.X(curP.X()+m_dx);
			curP.Y(curP.Y()+m_dy);
			c.CentrePoint(curP);
		}
	//void start(Point candidate_);
		void operator()(Line& l) const{
			Point curP = l.start();
			curP.X(curP.X()+m_dx);
			curP.Y(curP.Y()+m_dy);
			l.start(curP);
		}
};

int main() {

	//define dypedef to test the above function.
	ShapeType myS = queryShapeType();
	//all types of the variant typedef are now streamable
	cout << myS << endl;
	//create a visitor from boost library.
	move_visitor move = move_visitor(5, 5);
	boost::apply_visitor(move, myS); 	
	cout << myS << endl;
	return 0 ;
}
