#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


//swaps values in different arrays.
void swapVals(int arrA[], int arrB[], int indA, int indB) {
	int temp = arrB[indB];
	arrB[indB] = arrA[indA];
	arrA[indA] = temp;
}
	
/* you are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. merge them.
 * using a swap function for readability
 *
 * notes - so this is a bit of a neat question - you have to ask yourself 
 * rather basic questions. Is it worth it to try to sort them through insertion,
 * or is it better so simply emplace in back and sort using an nlogn algo?
 * You don't want to use more memory than you need too...that would be kind of defeating the constraint...
 * bc that's what I would do - simply just build a new vector and feed off the tops of the sorted arrays. 
 *
 * neat question.
 */
 
void mergeSArrs(int arrA[], int arrB[], int lengthA, int lengthB) {
	//create indices to track them.
	int indA, indB;
	indA = indB = 0;
	while (indA < lengthA) {
		//either the current a value is valid or 
		//must be swapped from arrayB
		if (arrB[indB] < arrA[indA])  {
			//swapVals(arrA, arrB, indA, indB);
			int temp = arrB[indB];
			arrB[indB] = arrA[indA];
			arrA[indA] = temp;
			indA++;
			continue;
		}
		//else indA++;
		//either way, A is getting filled and moving along
		indA++;
		
	}
	for (int i = lengthA; i < lengthB+lengthA; i++) arrA[i] = arrB[i];
	//linear traversal 

}



/* Write a method to sort an array of strings so that all the anagrams are next to each other
 * I can either iterate and then find an appropriate anagram for each string
 * OR I can simply traverse the vector, constructing the anagrams and mapping to a processed batch chaining the strings to their anagrams. I'll do the latter.
 * there that wasn't so bad.
 */

//helper function
string hashAna(string source) {
	sort(source.begin(), source.end());
	return source;
}

void sortAna(vector<string>& words) {
	//initialize our processed data storage container
	map<string, vector<string>> processedData;
	string temp = "";

	//linearly traverse our source.
	for (string& word : words) {
		temp = hashAna(word); //get the hash key
		processedData[temp].push_back(word);	
	}
	
	//now that we have all the anagrams grouped together, 
	//and given the fact that a map maintains an ordered sorting...
	//rebuild the original vector.
	int index = 0;
	for(map<string, vector<string>>::iterator it = processedData.begin(); 
		it != processedData.end(); it++) {
		for(string& word : it->second) {
			words[index] = word;
			index++;
		}
	}

}

/* 9.3 Given a sorted array of n integers that has been rotated an unknown number
 * of times, give an O(logN) algo that finds an element in the array
 * you may assume it was originally sorted in increasing order
 *
 */
//so implement a binary search algorithm for a rotated sorted algo.
//
//I will do a binary search for the base value (where i-1 > i)
// I need a max of a pair of partitions since I can't tell which partition a value is in. 

int baseIndex(vector<int>& nums, int left, int right) {
	if (right - left <= 1) return -1; //not in this partition 
	int middle = (right - left)/2 + left;
	if (nums[middle-1] > nums[middle]) return middle;
	return max(baseIndex(nums, left, middle-1), 
			baseIndex(nums, middle+1, right));
}
//5, 7, 9, 12, 1, 2

int baseTest(vector<int>& nums) {
	return baseIndex(nums, 0, nums.size()-1);
}


//ok cool - now lets SOLVE the original question, find a value. 
//and now I can't think because Lexi threw off my groove and I have lost my concentration. 

int findNumHelper(vector<int>& nums, int left, int right, int offset, int target) {
	if (right-left <= 1) return -1; //check base case with nominal values. 
	int midInd = (right - left)/2 + left; //a nominal index.  
	if (left + offset < nums.size()) left += offset; //convert the fench post to real
	if (right + offset < nums.size()) right += offset;//indexes for operations.
	int midVal = nums[midInd + offset];  //todo, this isn't right but can't think
	if (midVal ==  target) return midInd;

}

int findNum(vector<int>& nums, int val) {
	int offset = baseIndex(nums, 0, nums.size()-1);
	
	return findNumHelper(nums, 0, nums.size()-1, val);

}

/*
 *
 *
 */

int main( int argc, char** argv ) {

	int A[10] = {1, 2, 2, 3, 4};
	int B[5] = {0, 0, 2, 3, 6};

	mergeSArrs(A, B, 5, 5);
	for (int i = 0; i < 10; i++) cout << A[i] << " ";
	cout << endl;

//===========================9.2
	vector<string> initData;
	initData.push_back("dog");
	initData.push_back("god");
	initData.push_back("doge");
	initData.push_back("good");
	sortAna(initData);
	for(string& word : initData) cout << word << " ";
	cout << endl;

//============================
//
	vector<int> batch;
	batch.push_back(5);
	batch.push_back(7);
	batch.push_back(9);
	batch.push_back(12);
	batch.push_back(1);
	batch.push_back(2);
	//expecting to get back 4.
	cout << "testing baseeIndex function: " << baseTest(batch) << endl;

	return 0;
}
