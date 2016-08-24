#include <iostream>
#include <string>
/*
Whire a C-program that efficiently multiplies a number by a factor 2 to the power n

*/

using namespace std;

int main() {
	int i,j,k;
	i = j = k = 0;
	string input = "";
	bool inGame = true;
	while (inGame) {

		cout << "please input a number to multiply by 2\n";

		cin >> i;

		cout << "how many times do you want to multiply it?\n";

		cin >> j;
		
		i = i << j;
		
		cout << "new value of integer is: " << i << endl;

		cout << "would you like another go yes/no?\n";
		cin >> input;

		if (input == "no") {
			cout << "goodbye\n";
			inGame = false;
		}
	}
}
