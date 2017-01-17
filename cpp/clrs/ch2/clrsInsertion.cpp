#include <iostream>
#include <cassert>
#include <vector>

/* Author: Robert Rivera
 * Description: Insertion Sort Algorithm
 *
 * expected average runtime is n
 * better alternative is mergesort
 *
 */

using namespace std;

//a linear approach that described in chapter 2 of CLRS. 
void insertSort(vector<int32_t>& nums) {
	int32_t tempA, tempB;
	tempA = tempB  = -1;
	bool pushBack = false;
	for (int32_t i = 0; i < nums.size(); i++) {
		// put a value into the 'left hand' as-it-were with the deck-of-cards metaphor by incrememting i. 

		for (int32_t j = 0; j < i; j++) 	{
			if (pushBack)  {
				if (tempA<=nums[j]) {
					tempB = nums[j];
					nums[j] = tempA;
					tempA = tempB;
				}
				else nums[j] = tempA;
			}
			if (nums[j] > nums[i] && !pushBack)  {
				tempA = nums[j];
				nums[j] = nums[i];
				nums[i] = nums[i-1];
				//push back all other values 
				pushBack = true;
			}
		}
		//reset control signals.

		pushBack = false;
	}

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

int main( int argc, char** argv ) {
	
	vector<int32_t> batchOne;
	batchOne.push_back(5);
	batchOne.push_back(15);
	batchOne.push_back(25);
	batchOne.push_back(3);
	batchOne.push_back(1);
	batchOne.push_back(-21);

	insertSort(batchOne);
	for (int32_t i = 0; i < batchOne.size(); i++) cout << batchOne[i] << " ";
	cout << endl;
	assert(isSorted(batchOne));

	cout << "value 25 is at index: " << indexOf(batchOne, 25) << endl;

	return 0;
}
