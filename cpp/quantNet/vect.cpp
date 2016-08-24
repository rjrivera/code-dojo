#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {

	int a = 0;
	vector<int> myV;
	for (int i = 0; i < 10; i++) {
		myV.push_back(i);
	}
	for (int elem : myV) {
	cout << "Current value iterating through: " << elem << "\n";
	}


	for (int i = 0; i < 10; i++) {
	cout << "retraversig using the [] operator: " << myV[i] << endl;
	}

	return 0;
}
