#include <iostream>
#include <vector>
#include <string>


using namespace std;


template<class T>
void swap(vector<T>& input_, int lV, int rV) {
	T temp = input_[lV];
	input_[lV] = input_[rV];
	input_[rV] = temp;
}

/* Using templating to get my ass used to using them. 
 *
 */
template<class T>
void qSortHelper(vector<T>& input_, int lB, int rB) {
	if (rB-lB <= 1) return;
	//calculate the middle value
	int midVal =  ((rB-lB)/2) + lB;

	//pick a pivot value - in this implementation, it will be the mid value 
	T pV = input_[midVal];
	int pVInd = lB;
	//swap the pV inplace with the lB value
	swap<T>(input_, lB, midVal);
	//begin comparing each value with the pviot value. 
	for (int i = lB+1; i <= rB; i++) {
		if (input_[i] < pV) {
			//swap the value in question with the pv
			swap<T>(input_, pVInd, i);
			pVInd++;
			//inc the pvInd then put it back in it's place. 
			swap<T>(input_, pVInd, i);
		}
		//else do nothing.

	}
	//divide and conquer based on the pvIndex after iterating
	//through the current partition. 
	qSortHelper<T>(input_, lB, pVInd-1);
	qSortHelper<T>(input_, pVInd+1, rB);
	

}

template<class T>
void quickSort(vector<T>& input_) {

	qSortHelper<T>(input_, 0, input_.size()-1);
};

int main( int argc, char** argv ) {
	vector<int> batchOne;
	batchOne.push_back(5);
	batchOne.push_back(3);
	batchOne.push_back(10);
	batchOne.push_back(45);
	batchOne.push_back(33);
	batchOne.push_back(8);
	

	quickSort<int>(batchOne);
	for (int& val : batchOne) cout << val << endl;

	vector<string> batchTwo;
	batchTwo.push_back("greetings");
	batchTwo.push_back("cerebrate");
	batchTwo.push_back("i");
	batchTwo.push_back("hope");
	batchTwo.push_back("your");
	batchTwo.push_back("slumber");
	batchTwo.push_back("served");
	batchTwo.push_back("well");

	quickSort<string>(batchTwo);
	for (string& val : batchTwo) cout << val << endl;
	return 0;
}
