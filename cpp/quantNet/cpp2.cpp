#include <iostream>
#include <limits.h>
using namespace std;

int main() {

	int a = 0;
	long b = 0;
	short c = 0;

	//displaying information regarding basic types.
	cout << "integer datatypeinformation: size: " << sizeof(a) << 
		" max val: " << INT_MAX << " min val: " << INT_MIN << endl;
	cout << "long int info: size: " << sizeof(b) << 
		" max val: " << LONG_MAX << " min val: " << LONG_MIN << endl;
	cout << "short int info: size: " << sizeof(c) << "\n";
	

	return 0;
}
