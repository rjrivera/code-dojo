#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

pair<int32_t, int32_t> findMaxSumRange(vector<int32_t> arr) {

	pair<int32_t , int32_t> ans; 
	int32_t maxBase = 0;
	int32_t maxRange = 1;
	int32_t maxSum = INT_MIN;
	int32_t prevSum = 0;
	int32_t cSum = 0;
	for (int32_t i = 0; i < arr.size(); i++) {
		for (int32_t j = i; j < arr.size(); j++) {
			cSum = prevSum + arr[j];
	
			if (cSum > maxSum)  {
				maxSum = cSum;
				maxBase = i;
				maxRange = j - i + 1;
			}
			prevSum = cSum;
		}
		prevSum = 0;

	}
	cout << "max sum: " << maxSum << endl;
	ans = make_pair(maxBase, maxRange + maxBase -1);

	return ans;

}

int main( int argc, char** argv ) {
	vector<int32_t> numbers;
	numbers.push_back(2);
	numbers.push_back(-8);
	numbers.push_back(3);
	numbers.push_back(-2);
	numbers.push_back(4);
	numbers.push_back(-10);

	pair<int32_t, int32_t> indices;
	indices = findMaxSumRange(numbers);
	cout << "base: " << indices.first << " endpoint: " << indices.second << endl;

	return 0;
}
