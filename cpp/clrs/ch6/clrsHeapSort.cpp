#include <iostream>
#include <vector>

using namespace std;

//readers note - these definitions seem to work for 1-based heaps
//NOT zero- based...which is odd so ok. 
//as per clrs - best implemented as an inline function. 
inline int parent(int i) {
	return i/2; //return i/2

};

inline int left(int i) {
	return i<<1; //return 2*i;
};

inline int right(int i){
	return (i<<1) + 1; //return 2*i + 1
};

void buildMaxHeap(vector<int> inputArr) {


};

/* The max-heapify function maintains the property of a heap
 * The expected input array left(i) and right(i) ought to be valid
 * The parent at input index is expected to be in the wrong place
 * goal of function is to shuffle it into the right place. 
 */
void max_Heapify(vector<int>& inputArr, int index){
	int l = left(index);
	int rgt = right(index);
	int largest;
	//if a valid range value for left and left is greater than index
	if (l <=inputArr.size() && inputArr[l] > inputArr[index]) 
		largest = l;
	else largest = index;
	//if a valid range value and right is greater than 'largest'
	if (rgt <= inputArr.size() && inputArr[rgt] > inputArr[largest])
		largest = rgt;
	if (largest!=index)    {
		//swap the values
		int temp = inputArr[largest];
		inputArr[largest] = inputArr[index];
		inputArr[index] = temp;
		max_Heapify(inputArr, parent(index));
	}

};


/* The min-heapify function maintains the property of a heap
 * The expected input array left(i) and right(i) ought to be valid
 * The parent at input index is expected to be in the wrong place
 * goal of function is to shuffle it into the right place. 
 */
void min_Heapify(vector<int>& inputArr, int index){
	int l = left(index);
	int rgt = right(index);
	int smallest;
	//if a valid range value for left and left is greater than index
	if (l <=inputArr.size() && inputArr[l] < inputArr[index]) 
		smallest = l;
	else smallest = index;
	//if a valid range value and right is greater than 'largest'
	if (rgt <= inputArr.size() && inputArr[rgt] < inputArr[smallest])
		smallest = rgt;
	if (smallest!=index)    {
		//swap the values
		int temp = inputArr[smallest];
		inputArr[smallest] = inputArr[index];
		inputArr[index] = temp;
		min_Heapify(inputArr, smallest);
	}

};

void heapSort(vector<int> inputArr) {

};

int main( int argc, char** argv ) {
	/* validation of the parent, left, right inline functions. 
	int a, b, c;
	a = b = c = 5;
	a = parent(a);
	b = left(b);
	c = right(c);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	*/
	//valid heap vector.
	vector<int> input;
	input.push_back(10);
	input.push_back(6);
	input.push_back(9);
	input.push_back(2);
	input.push_back(5);
	input.push_back(7);
	input.push_back(8);
	
	for(int& val : input) cout << val << " ";
	cout << endl;
	//insert a value then proceed to reheapify it.
	input.push_back(12);
	max_Heapify(input, parent(input.size()-1));

	for (int& val: input) cout << val << " ";
	cout << endl;	
	// so I got this to work, but the interesting thing
	// is that the pseudocode from clrs didnt function as thought
	// since I missed a detail, I amended it to fit my understanding
	// Amendment is made to the call, when calling the heapify functions, one must call the parent of the index of the new inserted value. if pushing from the back, simply calling parent(arr.size()-1) will suffice. 
	return 0;

}
