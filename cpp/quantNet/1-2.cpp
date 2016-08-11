#include <iostream>


using namespace std;

static int surfaceAreaTri(int height_, int base_) {


	return (.5 * height_ * base_);
} 

int main() {

	int base, height;
	base = 10;
	height = 100;

	cout << "calculating the value of right triangle with:\n "  <<
	"base: 10, height: 100 = should be 500\n";

	cout << "surface area calculated is: " << surfaceAreaTri(height, base) << endl;

	return 0;
}


