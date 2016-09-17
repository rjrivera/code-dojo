#include <iostream>
#include "Point.hpp"

using namespace std;
int main() {
	// using contructor with/without (new) keyword
	Point * pt1 = new Point();
	Point pt2 = Point(5, 8);

	
	cout << pt2.ToString() << endl;
	cout << (*pt1).ToString() << endl;
	return 0;

}
