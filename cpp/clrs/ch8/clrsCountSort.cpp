#include <iostream>


using namespace std;

//counting sort as per clrs section 8.2 pseudocode. 
/* description - 
 * leveraging a 'Lebensraum' array of length k (range of values)
 * The algorithm iterates through the input array keeping
 * Track of the frequency of an int's occurance
 * And constructs the sorted array based on the info
 * Derived from the derived from the number of values before it
 * (an excellent demonstration of dynamic programming) 
 * k is an inclusive data value, meaing the counting array must 
 * account for that in sizing .
 * Personal notes: the nature of the pseudocode requires critical reading;
 * the author's use of 1-based indexing is obscured by typical array operation.
 * I had to add an offest in this implementation (adding the '-1' to the final for-loop's first statement). 
 */

void countSort(int arr[], int n, int k) {
	int B[n+1] = {}; //target for new info. 

	int C[k+1] = {}; //Counting "working space" array.

	//for 1 - length of input array, c[arr[i]] = c[arr[i]] +1
	for (int i = 0; i <n; i++) {

		C[arr[i]] = C[arr[i]] + 1; //update the count for the data value at arr[i];

	}
	//now count how many values are less than a value 'i'.
	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i-1];
	}
	cout << "count of 11: " << C[11] << endl;
	for (int i = n-1; i >= 0; i--)  {
		B[C[arr[i]]-1] = arr[i];
		C[arr[i]] = C[arr[i]] - 1;//modify the working space.  
	}
	
	for (int i = 0; i < n; i++) cout << B[i] << endl;
}

int main( int argc, char** argv ) {

	int iArr[10] = {2, 5, 6, 6, 7, 11, 8, 2, 3, 1};
	countSort(iArr, 10, 11);
	cout << "original dataset\n";
	for (int i = 0; i < 10; i++) cout << iArr[i] << endl;


	return 0;
}
