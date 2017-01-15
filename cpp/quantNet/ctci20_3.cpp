#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Write a function that returns the number of 2's between 0, n.
// wow - this one is decently hard relying on critical 
// mathematical review and intuition...
int numTwos(int val) {
	// prepare a working copy of the value. 
	int tempV;
	if (val<0) tempV = val*-1; 
	else tempV = val;
	//determine the number of digits. 
	int maxPow = 0;
	while (tempV >=10) {
		maxPow++;
		tempV /= 10;
	}
	
	int numTwos = 0;
	//make a running sum for the terms in our series. 
	for (int i = 0; i < maxPow; i++) {
		numTwos += (pow(10,i)*pow(10, (maxPow-i-1)));

	}

	//now that our baseline is established up to 1xxxxx,
	//lets consider everything above. 
	
	//return our value.
	return numTwos;
	
	

}


//introduce test cases here;
int main( int argc, char** argv ) {

	cout << "batch one **************\n";
	// 10 => 1
	cout << "10 => " << numTwos(10) << endl;


	cout << "batch two **************\n";
	// 100 => 10*1  + 1*10 = 20;
	cout << "100 => " << numTwos(100) << endl;
	

	cout << "batch three **************\n";
	// -100 => 20
	cout << "-100 => " << numTwos(-100) << endl;

	cout << "batch four **************\n";
	// 1000 => 100*1 + 10*10 + 1*100 => 300; 
	cout << "1000 => " << numTwos(1000) << endl;
	return 0;
}
