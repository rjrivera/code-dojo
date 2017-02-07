#include <iostream>
#include <vector>

using namespace std;


/* Using templating to get my ass used to using them. 
 *
 */
template<class T>
void quickSort(vector<T> input_) {

	for(T& val : input_) cout << val << endl;
};

int main( int argc, char** argv ) {
	vector<int> batchOne;
	for (int i = 0; i < 10; i++) {
		batchOne.push_back(i);
	}

	quickSort<int>(batchOne);

	return 0;
}
