#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {

	int i, j;
	i = j = 0;
	cout << "This program will demonstrate the difference between post and pre increment '++i v i++'\n";
	while (j < 10) {
		j = i++;
		cout << "current j and i values with i++ " << j << " " << i << endl;
	}
	i = j = 0;

	while (j < 10) {
		j = ++i;
		cout << "current j and i values with ++i " << j << " " << i << endl;
	}

	return 0;
}
