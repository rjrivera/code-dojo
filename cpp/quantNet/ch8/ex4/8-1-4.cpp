#include <iostream>
#include <chrono>
#include <boost/random.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "OutOfBoundsException.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple.hpp>
#include </home/rob/Downloads/boost_1_63_0/boost/tuple/tuple_io.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>
#include <boost/variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <map>

using namespace std;


int main() {

	//Throwing Dice
	//Mersenne Twister
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1,6);

	map<int, long> statistics;
	// ==========input processing ===========
	int numTrials;
	string input;
	bool isNum;
	do{
		isNum = true;
		cout << "please enter how many trials\n";
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			if(!isdigit(input.at(i))) isNum = false;
			break;
		}	
	}while(!isNum);
	numTrials = stoi(input);
	//====================END INPUT PROCESSING==========
	//RUN TRIALS
	for (int i = 0; i < numTrials; i++) statistics[six(myRng)] += 1;
	//OUTPUT RESULTS
	for (map<int,long>::iterator it= statistics.begin(); it != statistics.end(); it++) cout << "Trial " << it->first << " => " << it->second/(numTrials/100) << "% of outcomes" << endl;

	return 0 ;
}
