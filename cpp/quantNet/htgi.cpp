#include<iostream>
#include<string>
#include<vector>

using namespace std;

//binary search
//

template<class T>
int binarySearch(T target, T * arrs, int size) {
	int rInd = size-1;
	int lInd = 0;
	int mid = (rInd - lInd)/2 + lInd;
	//use iterative versus recursive approach to save stack cost
	while (rInd-lInd >=1) {
		mid = (rInd - lInd)/2 + lInd;
		if (arrs[mid] == target) return mid;
		else if (arrs[mid] > target) rInd = mid - 1;
		else lInd = mid + 1;  
	}
	//fenchpost
	mid = (rInd - lInd)/2 + lInd;
	if (arrs[mid] == target) return mid;
	else if (arrs[mid] > target) rInd = mid - 1;
	else lInd = mid + 1;  
	//return negative val if not found since
	//arrs can't be made negative. 
	return -1;
}

int main( int argc, char** argv ) {

	cout << "hacking the google interview scratchpad: binSearch\n";
	int intArr[5] = { }; //default init to 0; 
	intArr[0] = 1;
	intArr[1] = 2;
	intArr[2] = 3;
	intArr[3] = 4;
	intArr[4] = 5;
	int defaultVal = binarySearch<int>(5, intArr, 5);
	cout << "**********BATCH ONE***********\n";
	for (int i = 0; i < 5; i++) cout << "index: " << i << " value: " << intArr[i] << endl;
	cout << "Index value of value 5: " << defaultVal << endl;
	cout << "**********BATCH TWO***********\n";
	string strArr[5] = { };
	strArr[3] = "The";
	strArr[0] = "Best";
	strArr[4] = "Things";
	strArr[1] = "In";
	strArr[2] = "Life";
	for (int i = 0; i < 5; i++) cout << "index: " << i << " value: " << strArr[i] << endl;
	defaultVal = binarySearch<string>("Best", strArr, 5);
	cout << "Index value of value \"Best\": " << defaultVal << endl;
	cout << "**********BATCH TWO***********\n";
	
	return 0;
}
