#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdint.h>
#include <queue>
#include <deque>
//#include "print.h"
using namespace std;

//static int i = 3;
//int count[5] = {2, 4, 6, 8, 10} ;

int main() {
	//int count[5] = {2, 4, 6, 8, 10};
	int *pC = new int[100];
	if(!pC) {cout <<"hi" << endl;}
	//for (int i = 0; i < 5; i++) {
	//	cout << ++*++pC << endl;
	//}//
//	cout << true << endl;
	// suppose you are given two arrays of departures and arrivals for an airport where all planes are not native to the airport.
	// what is the maximum number of ramps needed?

	// sort - then find. sort costs logN (provided it's a quicksort) 
	// traverse afterwards through data costs N
	// total operation costs NlogN
/*
	int32_t * arrivals = new int32_t[10];
	int32_t * departures = new int32_t[10];
	arrivals[0] = 800;
	arrivals[1] = 1000;
	arrivals[2] = 700;
	arrivals[3] = 2100;
	arrivals[4] = 2200;
	arrivals[5] = 1700;
	arrivals[6] = 1430;
	arrivals[7] = 1730;
	arrivals[8] = 1920;
	arrivals[9] = 2300;
	
	departures[0] = 2330;
	departures[1] = 1100;
	departures[2] = 800;
	departures[3] = 1300;
	departures[4] = 2200;
	departures[5] = 2300;
	departures[6] = 1800;
	departures[7] = 1930;
	departures[8] = 1950;
	departures[9] = 2000;

	cout << "known flight arrivals/departures unsorted\n";
	for (int i = 0; i < 10; i++) {
		cout << "arrival: " << arrivals[i] << endl;
		cout << "departure: " << departures[i] << endl;
	}	

	cout << "know flight arrivals/departures sorted\n";
	sort(arrivals, arrivals + 10);
	sort(departures, departures + 10);

	for (int i = 0; i < 10; i++) {
		cout << "arrival: " << arrivals[i] << endl;
		cout << "departures: " << departures[i] << endl;
	}

	cout << "now determining ramps needed\n";
	uint32_t ramps = 0;
	uint32_t maxRamps = 0;
	uint32_t arrInd, depInd;
	arrInd = depInd = 0;
	while (arrInd + depInd < 20) {
		if (arrivals[arrInd] <= departures[depInd] && arrInd < 10) {
			ramps++;
			arrInd++;
			if (maxRamps < ramps) { maxRamps = ramps;}
		}
		else {
			ramps--;
			depInd++;
		} 
		cout << "currently using this many ramps: " << ramps << endl;
	}

	cout << "max ramps needed: " << maxRamps << endl;
	
	cout << "input integer value please " << endl;
	cin >> a;
	
	cout << "your int32_t value is: " << a << endl;

	vector<int32_t> * intVect = new vector<int32_t>();
	cout << "constructing a vector of int32_t's, please input three values\n";

	for (int i = 0 ; i < 3; i++) {
		//separated to two lines for readability. 
		cin >> a;
		intVect->push_back(a);

	}
	//int32_t current;
	for (auto &current : *intVect) {
		cout << current << endl;
	}
	
	cout << "current size of the vector is: " << intVect->size() << endl;
	cout << "popping values off the back because vector is not a queue\n" ;

	for (int i = 0 ; i < 3; i++) {
		cout << intVect->back() << endl;
		intVect->pop_back();
	}
	cout << "current size of the vector is: " << intVect->size() << endl;


	cout << "input three numbers into a queue now please: \n" ;
	deque<uint32_t> * myQ = new deque<uint32_t>();
	for (int i = 0; i < 3; i++) {
		cin >> a;
		myQ->push_back(a);
	}

	cout <<"popping off the front now: " << endl;

	for (int i = 0 ; i < 3; i++) {
		cout << myQ->front() << endl;
		myQ->pop_front();
	}	
	*/
	return 0;


}
