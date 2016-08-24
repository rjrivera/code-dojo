#include <iostream>
#include <string>
/*
Write a C-program that shifts any number two places to the right. 

Input should be an integer. Output is shifted result. 
*/

using namespace std;

int main() {

	bool nextValue = true;
	string prompt = "";
	int val = 0;
	while (nextValue) {
		cout << "insert integer to shift: \n";
		cin >> val;
		val =  val >> 2;
		cout << "shifted output is: " << val << endl;
		cout << "Input another integer yes/no?\n";
		cin >> prompt;
		if (prompt == "no") {
			cout << "good bye\n";
			nextValue = false; 

		}

	}

	return 0;

}
