#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;


//Sum - template funtion
//return the sum of all values in the container provided. 
template<class T>
double sum(T a) {
	typename T::const_iterator it = a.begin();
	double sum = 0;
	while (it != a.end()){
		sum += *it; //dereference the iterator to grab the value.
		it++;
	}
	return sum;

}


//iterates and returns sum of values in a container between two points.
template<class T>
double sum(T a, T b) {
	double sum = 0;
	while (a != b){
		sum += *a; //dereference the iterator to grab the value.
		a++;
	}
	return sum;

}
int main( int argc) {

	list<double> myLD = list<double>();
	myLD.push_back(1.234);
	myLD.push_back(123.4);
	myLD.push_back(12.4);
	myLD.push_back(1.20034);

	cout << sum(myLD) << endl;	
	cout << sum(myLD.begin(), myLD.end()) << endl;

	//create a vector of doubles, add some data
	vector<double> myV = vector<double>();
	myV.push_back(1.234);
	myV.push_back(12.34);
	myV.push_back(12.00034);
	myV.push_back(1.200034);
	
	//access the front and back using th index operator
	cout << sum(myV) << endl;
	cout << sum(myV.begin(), myV.end()) << endl;

	//create a map that maps strings to doubles.
	map<string, double> myMap = map<string, double>();
	myMap["Im"] = 1.234;
	myMap["Here"] = 1.23402;
	myMap["To"] = 0.234;
	myMap["Fly"] = 1.324;
	myMap["Planes"] = 3.14;

	//cout << sum(myMap) << endl; //failes to properly sum with map

	return 0;
}
