#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdint.h>
#include <queue>
#include <deque>
#include <screen.hpp>
#include <list>
#include <functional>
#include <boost/lexical_cast.hpp>
#include <map>
//#include "print.h"
using namespace std;

//static int i = 3;
//int count[5] = {2, 4, 6, 8, 10} ;

int a = 5;

/*
int& function () { };
namespace { static int n; }
namespace A {
	namespace { static int n; }
}
*//*
class A {
	public:
	A() {}
	A(A& a) {}
	A& operator=(const A& a)
	{ return(*this); }
	
};
*/
class sc 	{
	int x;
	public: 
	sc(int xx) : x(xx) {}
};

template<typename T> class DynA{
	T * contents;
	int size;
	public:
		explicit DynA(int initial_size);
};



template<class T>
struct sum{
	static void foo(T op1, T op2) {
		cout << " sum j= " << endl;		
	}	


};
void swap(uint32_t& varA_, uint32_t& varB_) {
	varA_ = varB_ - varA_;
	varB_ -= varA_;
	varA_ += varB_;

}


//given that 0 = empty, 1 = 'x', 2 = 'o'. -- amended to n-sized games - only checking horizontal and verticals as is because moving on. 
bool winnerTTT(string gameState_) {
	// very limited number of winning states. check for each state seperately. 
	uint32_t streak = 0;
	// for each side - traverse through all possible winning starting positions. 
	uint32_t sideLength = sqrt(gameState_.size());
	for (uint32_t i = 1; i < 3; i++) {
		// 0 - 3 - 6
			for (uint32_t start = 0; start < sideLength; start++) {
				// check horizontal
				for (uint32_t streakPos = 0; streakPos < sideLength; streakPos++) {
					if (gameState_.at(start*sideLength + streakPos) == boost::lexical_cast<char>(i))  {
						streak++;
						cout << "streak value: " << streak << "after increment" << endl;
					}
					else { break;} //found a broken link, abandon loop to reduce operation overhead.  
				}
				if (streak == sideLength) { return true;}
				streak = 0; //reset tracker for next iteration. 
				// check vertical. 
				for (uint32_t streakPos = 0; streakPos < sideLength; streakPos++) {
					if ( (gameState_.at(start*sideLength + (streakPos*sideLength)) ) ==  boost::lexical_cast<char>(i)) {
						streak++;
						
					}
					else { break;}
				}
				if ( streak== sideLength ) { return true;} 
				streak = 0;

			}
			
	}
	return false;

}
uint32_t calcFact(uint32_t factCand_ ){
	return (factCand_ == 1 || factCand_ == 0) ? 1 : calcFact(factCand_ - 1 ) * factCand_;

}

typedef struct PTNode{
	char ltr = NULL;
	bool terminal = false;
	map<char, PTNode>  cNodes;

};


string compressString(string word_){	
	char currentChar = word_.at(0);
	uint32_t count = 0;
	string cString;
	for (uint32_t i = 0; i < word_.size(); i++) {
		if (word_.at(i) != currentChar && i > 0) {
			cString+=currentChar;
			cString+= to_string(count);
			count = 1;
			currentChar = word_.at(i);
		}
		else {
			count++;
		}
	}
	cString += currentChar;
	cString += to_string(count); 
	return cString;

}

string expandString(string word_){
	string cString;
	for (uint32_t i = 0; i < word_.size()-1; i+= 2) {
		for (uint32_t j = 0; j < boost::lexical_cast<uint32_t>(word_.at(i+1)); j++) {
			cString += word_.at(i);
		}

	}
	return cString;
}
// presumes that the head node is properly initialized. 
void insertWord(PTNode& head_, string word_) {
	if ( word_.size() <= 0) {
		return; //robustness measure. 
	}
	char firstChar = word_.at(0);
	if (head_.cNodes.find(firstChar) == head_.cNodes.end()) {  // no word in our prefix tree exists starting with the current letter 
		//create new node, insert char and move on through the candidate string. 
		PTNode  tempNode;
		tempNode.ltr = firstChar;
		
		head_.cNodes[firstChar] = tempNode;
		if ( word_.size() > 1 )  {
			insertWord(head_.cNodes[firstChar], word_.substr(1));
		}
		else {
			head_.cNodes[firstChar].terminal = true;
			return;
		}

	}	
	else { //easy step, letter already exists in tree, just follow along. 
		if ( word_.size() > 1  ) {
			insertWord(head_.cNodes[firstChar], word_.substr(1));
		}
		else {
			head_.cNodes[firstChar].terminal = true;
			
			return;
		}
	}
}

void traverseTree(PTNode& head, string word_){
	
//	else {
		word_ += head.ltr;
		
		if ( head.terminal ) { 
			cout << word_ << endl;


		} 
		for (auto& node : head.cNodes) {
			traverseTree(node.second, word_);
		}
//	}
}


int main() {
	PTNode head;
	insertWord(head, "hello");
	insertWord(head, "hell");
	insertWord(head, "candy");
	insertWord(head, "candidate");
	traverseTree(head, "");
	string cand = "aaaabbbeeeeetttt";
	string comCand = compressString(cand);
	string dCand = expandString(comCand);
	cout << cand + " => " << comCand << " decompresses to => " << dCand << endl;
	cand = "aaddaabbbebbghjeeeetttt";
	comCand = compressString(cand);
	dCand = expandString(comCand);
	
	cout << cand + " => " << comCand << " decompresses to => " << dCand << endl;
	
	/*
	// write a function that counts the number of trailing zeros in n-factorial
	// yea I over though this, should have just used math from the beginning. 
	//first, lets calc. n!
	
	uint32_t factCand = 10;
	uint32_t fact = calcFact(factCand);
	cout << "factorial of " << factCand << " is " << fact << endl;
	 
	uint32_t numZeros = 0;
	
	while (fact % 10 == 0) {
		numZeros++;
		fact/=10;

	}
	numZeros;
	cout << "number of trailing zeros" << numZeros << endl;
	*/
	/*// convert to string abandoning the string approach
	string fs = boost::lexical_cast<string>(fact);
	cout << "As string: " << fs << endl;
	uint32_t numTrailingZeros = fs.size() - fs.find_last_of("0");
	cout << "number of trailing zeros: " << numTrailingZeros << endl;
	//uint32_t numTrailingZeros = distance((string::find_last_of(fs, "0")), fs.end());
	//cout << " number of trailing zeros: " << numTrailingZeros << endl;
	*/
	/*
	//test cases 
	vector<string> gameStates;
	

	// simple test cases - todo[ ] finish for verticals but it's good for reveiw purposes .
	gameStates.push_back("111020020");
	gameStates.push_back("000000000");
	gameStates.push_back("222010010");
	gameStates.push_back("120010021");
	gameStates.push_back("120120100");
	for (auto& game : gameStates) {

		if (winnerTTT(game))  {
			cout << "winner with string" << game << endl;
		}
		else {
			cout << "loser with string" << game << endl;

		}

	}
	*/
	// develope a function to determine if there is a winner in a game of tic-tac-toe
	/*
	// swap a number without a temp variable. est. Time taken...3 minutes
	uint32_t varA = 10;
	uint32_t varB = 20;
	cout << "before swap: " << varA << " " << varB <<endl;
	swap(varA, varB);
	cout << "after swap: " << varA << " " << varB <<endl;
	*/

/*
	for (int ii = 0; ii < 3; ++ ii) {

		switch(ii){
		case 0: cout << "ZERO";
		case 1: cout << "ONE"; continue;
		case 2: cout << "TWO"; break;
}
	cout << endl;
	}
*/
/*
	int myints[] = {1,2,3,4,5,4,3,2,1};
	vector<int> v(myints, myints+9);
	sort(v.begin(), v.end());
	cout << (binary_search(v.begin(), v.end(), 3)) << endl;
*/	

/*
	list<int> L;
	list<int>::iterator it;

	L.push_back(10);
	L.push_back(25);
	L.push_back(40);
	it = L.end();
	L.push_back(55);
	L.insert(it, 30);
	L.push_front(15);
	L.sort(greater<int>());
	it= find_if(L.begin(), L.end(), bind2nd(less<int>(), 40));
	cout << *it << endl;

*/
/*
 	vector<string> strVec;
	strVec.push_back("foo");
	strVec.push_back("bar");
	strVec.push_back("baz");
	strVec.push_back("bee");

	cout << count_if(strVec.begin(), strVec.end(), bind2nd(greater<string>(), "baz"));
	*/
//A a2(a1);
	
/* TODO [ ] read this and figure it out
	vector<int> v;
	for (int i =0; i < 5; ++i) v.push_back(i);
		v.erase(find(v.rbegin(), v.rend(), 2).base());
		v.insert(find(v.rbegin(), v.rend(), 1).base(),10);
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));*/
	
	
/*
	int myints[] = {1, 2,3,4,5,4,3,2,1};	
	vector<int> v(myints, myints+9);
	sort(v.begin(),v.end());
	cout << (binary_search(v.begin(),v.end(), 3)) <<endl;
*/	

	/*
	vector<string> strVec;
	strVec.push_back("foo");
	strVec.push_back("flip");
	strVec.push_back("Baz");
	cout << count_if(
		strVec.begin(),
		strVec.end(),
		bind2nd(greater<string>(), "Baz")
	);*/
	/*
	const int * cp;

	int y1, m1, d1, y2, m2, d2;
	y1 = 2008; 
	m1 = 1;
	d1 = 15;
	y2 = 2010;
	m2 = 5;
	d2 = 26;

	// goal is to efficiently calculate the number of days between two given dates. 

	// strategy: shave off the edges of the dates to normalize to 1-1, eg the number of days remaining in y1 and y2 then just add 365 * deltayears. 
	
	// baseline number of years * 365; assuming no leap years - 
	
	int numDays = 0;
	
	numDays += ((y2-1) - y1)*365;//addleap year functionality using modulo operator. 
	
	// add leapyear functionality later. 
	//now - calculate numyears int ending year.
	
	numDays += d2; //days elapsed in end date. 

	//add days in the month 
		for (int i = 1; i < m2; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
				numDays += 31;
			}
			else if (i == 2) {
				if (y2 % 4 == 0) { numDays += 29; }
				else {
					numDays += 28;	
				}
			}
			else {
				numDays += 30;
			}

		}
	

	// repeat proceducre for beginning edge, but tweak algorithms for the fact that "extra days" are at the end of the calender.
	// can't just add numDays because depending on which month, the value may change. 
	bool firstMonth = true;
	for (int i = m1; i <=12; i++) {
		if (i == 1 || i ==3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {

			if (firstMonth) {
				firstMonth = false;
				numDays += (31 - d1);
			}
			else {
				numDays += 31;
			}

		}
		else if (i == 2) {
			if (firstMonth) {
				firstMonth = false;
				if (y1 % 4 == 0) { numDays += (29 -d1); }
				else {
					numDays += (28 - d1);
				}
			}
			else {
				if (y1 % 4 == 0) {
					cout << y1 << "is a leap year!" << endl;
					numDays += 29;
				}
				else { 
					numDays += 28;
				}
			}
		}
		else {
			if (firstMonth) {
				firstMonth = false;
				numDays += (30  - d1);
			}
			else {
				numDays += 30;
			}
		}
	}
	
	cout << "number of days between: " << d1 << "-" << m1 << "-" << y1 << endl;
	cout << "and " << endl;
	cout << "                        " << d2 << "-" << m2 << "-" << y2 << endl;
	cout << numDays << endl;

	*/





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
