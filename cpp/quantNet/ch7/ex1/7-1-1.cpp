#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main( int argc) {
	//Create a list of doubles, add some data
	list<double> myLD = list<double>();
	myLD.push_back(1.234);
	myLD.push_back(123.4);
	myLD.push_back(12.4);
	myLD.push_back(1.20034);

	//use the front() and back() functions to access the first and last element
	cout << "front of the double list" << myLD.front() << endl;
	cout << "back of the double list" << myLD.back() << endl;

	//create a vector of doubles, add some data
	vector<double> myV = vector<double>();
	myV.push_back(1.234);
	myV.push_back(12.34);
	myV.push_back(12.00034);
	myV.push_back(1.200034);
	
	//access the front and back using th index operator
	cout << "front of the double vector using index operator " <<
	myV[0] << endl;

	cout << "back of the double vector using index operator " <<
	myV[myV.size()-1] << endl;

	//create a map that maps strings to doubles.
	map<string, double> myMap = map<string, double>();
	myMap["Im"] = 1.234;
	myMap["Here"] = 1.23402;
	myMap["To"] = 0.234;
	myMap["Fly"] = 1.324;
	myMap["Planes"] = 3.14;

	cout << "Im => " << myMap["Im"] << endl;
	cout << "Here => " << myMap["Here"] << endl;

	return 0;
}
