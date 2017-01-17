#include <iostream>
#include <cassert>
#include <vector>

/* Author: Robert Rivera
 * Description: Merge Sort Algorithm
 *
 * expected average runtime is ln(n)
 * 
 *
 */

using namespace std;

//the heavily lifting aspect of the algorithm that merges two sorted arrays. 
//imagine reviewing two sorted deck of cards from the bottom and assigning them into a new deck. thats what we are doing. 
void mergeCombine(vector<int32_t>& nums, int32_t lI, int32_t mI, int32_t rI) {
	int32_t indA, indB;
	indA = lI;
	indB = mI;
	int32_t newVect[rI-lI] = { };
	int count = 0;
	// array partitions are [lI, mI-1] and [mI,rI-1]
	while (indA < mI && indB < rI) {
		if (nums[indA] <= nums[indB])  {
			newVect[count] = nums[indA];
			count++;
			indA++;
		}
		else {
			newVect[count] = nums[indB];
			count++;
			indB++;
		}
	}


	//place remaining cards on top, no extra comparisons needed. 
	if (indA == mI)  {
		for (int32_t i = indB; i < rI; i++) {
			newVect[count] = nums[i];
			count++;
		}
	}

	else  {
		for (int32_t i = indA; i < mI; i++) {
			newVect[count] = nums[i];
			count++;
		}
	}
	
	//now that it's implemented, lets leverage call-by-ref
	//rewrite the section of the original nums vector
	for(int32_t i = 0; i< rI - lI; i++) {
		nums[i+lI] = newVect[i];
	}

}

/*
 * We use a Helper function because we desire to keep the API simple and leave all inference of information to the developer, not the client code. 
 * parameters: source vector<int>, leftbound, rightBound, bounds are inclusive and exlusive, respectively. 
 *
 */
void mergeSortHelper(vector<int32_t>& nums, int32_t lI, int32_t rI) {
	//base case - if our working vector is size one. 
	if (rI-lI <= 1) return; //there is no more work to be done. 
	//divide - work the math in your head with a size 4 value. 
	int32_t midI = ((rI-lI)/2) + lI;
	mergeSortHelper(nums, lI, midI - 1);
	mergeSortHelper(nums, midI, rI); 
	mergeCombine(nums, lI, midI, rI);

}

//a divide/conquer approach that described in chapter 2 of CLRS. 
void mergeSort(vector<int32_t>& nums) {
	mergeSortHelper(nums, 0, nums.size());
}


//defining function for use with assert. 
bool isSorted(vector<int32_t>& nums) {

	for (int32_t i = 0; i < nums.size()-1; i++) if (nums[i] > nums[i+1]) return false;
	return true;
}


//problem 2.1-3 of CLRS - a linear search. obviosly once sorted, it is better to do a quick/radix search
int32_t indexOf(vector<int32_t>& nums, int32_t val) {
	for (int32_t i = 0; i < nums.size(); i++) if (nums[i] == val) return i; 
	return -1;
}


//initial testing bench.
int main( int argc, char** argv ) {
	
	vector<int32_t> * batchOne = new vector<int32_t>();
	batchOne->push_back(5);
	batchOne->push_back(15);
	batchOne->push_back(25);
	batchOne->push_back(3);
	batchOne->push_back(1);
	batchOne->push_back(-21);

	mergeSort(*batchOne);
	for (int32_t i = 0; i < batchOne->size(); i++) cout << batchOne->at(i) << " ";
	cout << endl;
	//assert(isSorted(batchOne));

	cout << "value 25 is at index: " << indexOf(*batchOne, 25) << endl;

	delete batchOne;

	return 0;
}
