#include <iostream>
#include <string>



using namespace std;

/* setting the stage - a simple minimum function 
 * given an unsorted set of numbers.
 * (N)
 * an upper-bound is set at n-1;
 */

int minEl(int arr[], int length) {
	int min = arr[0];
	for (int i = 1; i < length; i++){
		if (arr[i] < min ) min = arr[i]; 
	}
	
	return min;
}

/* randomized partition used in ithHelper
 * this isn't going to be a rand implementation for me - 
 * I'm just going to make whatever the center value is my pivot
 */
int randPartition(int arr[], int l, int rgt) {
	int pivotInd = ((rgt-l)/2) + l;
	int pivotVal = arr[pivotInd];
	int temp = 0;
	arr[pivotInd] = arr[l];
	arr[l] = pivotVal;
	pivotInd = l;
	//iterate through this partition and move all 
	//elements < than pivotInd left of the pivotVal.
	for (int i = l + 1; i <= rgt; i++) {
		if(arr[i] < pivotVal) { //do a swap
			//review - you need two swaps
			//first swap index with pivot
			arr[pivotInd] = arr[i];
			//iterate pInd
			pivotInd++;
			//swap item THERE with location of i
			arr[i] = arr[pivotInd];
			arr[pivotInd] = pivotVal;
		}
	}

	//partition sorted, just return the index of the pivot value
	return pivotInd; //that wasn't so hard - the book is weird
	//random nature would simply improve performance over large inputs.
}


/* helper function for below.
 * - uses the randomized-partition procedure - similar 
 *   to randomized-quicksort
 *
 * - returns the ith value of this partition
 */

int ithHelper(int arr[], int l, int rgt, int targ) {
	//base case
	if (l == rgt) return arr[l];
	int q = randPartition(arr, l, rgt); //q is pivot
	cout << "first iteration: " << endl;
	cout << "q => " << q << endl;
	int k = q - l + 1; //remember - zero based 
	if (targ == k) return arr[q]; //pivot val is our answer
	else if (targ < k)
		return ithHelper(arr, l, q-1, targ);
	else return ithHelper(arr, q+1, rgt, targ - k);
}

/* general selection problem - a little more difficult
 * still (N) - proceed with divide and conquer.
 *
 */

int ithEl(int arr[], int length, int target){
	return ithHelper(arr, 0, length-1, target);
}

int main( int argc, char** argv ) {

	int iArr[10] = {2, 5, 6, 6, 7, 11, 8, 2, 3, 1};
	cout << "Min value in batchOne sorted set: " << 
		minEl(iArr, 10) << endl;

	cout << "the 4th smallest element is: " << 
		ithEl(iArr, 10, 4) << endl;

	return 0;
}
