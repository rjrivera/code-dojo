#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//a global function used as criteria for a comparison operation
/*
bool isSmaller(double a) {
	if (a < 3) return true;
	return false;
}
*/

//functionally similiar implementation above, using functors.
class isSmaller{
	public:
		isSmaller(double criteria) : criteria_(criteria) {}
		bool operator() (double x) {
			if (x<criteria_) return true;
			return false; 
		}

	private:
		double criteria_;
};

int main( int argc) {

	list<double> myLD = list<double>();
	myLD.push_back(1);
	myLD.push_back(2);
	myLD.push_back(3);
	myLD.push_back(4);
	cout << count_if(myLD.begin(), myLD.end(), isSmaller(3)) << endl;
	
	return 0;
}
