#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <algorithm>

using namespace std;

static default_random_engine gen;
static uniform_int_distribution<int> distribution(1,5);
static uniform_int_distribution<int> deckdist(1,12);

double rand5() {
	return distribution(gen);

}

int rand7() {
	double num = rand5();
	num += rand5(); //num is now a larger range than rand7;

	return (int)((num/10)*7);
}

vector<pair<int, int>> findAllPairsK(int target, vector<int>& array) {
	vector<pair<int,int>> myAns;
	//perform 2 linear traversals which permit a quick lookup for pairs.
	map<int, vector<int>> myMap;
//build a map.
	for (int i = 0; i < array.size(); i++) {
		myMap[target - array[i]].push_back(array[i]);
		cout << "mapping " << (target - array[i]) << " to " << array[i] << endl;
	}
	//start building an answer. 
	bool repeat;
	int candidate;
	map<pair<int,int>, int> repTracker;
	for (int i = 0; i < array.size(); i++) {
		repeat = true;
		candidate = array[i];
		if (myMap[candidate].size() > 0)  {

			for(int& val : myMap[candidate]) {
				if (val==candidate &&!repeat)  {
					//repeat = true;
					myAns.push_back(make_pair(val,candidate));
					repTracker[make_pair(val, candidate)]++;
				}
				else if (val==candidate && repeat ) repeat = false;
				else {
					myAns.push_back(make_pair(val, candidate));
					repTracker[make_pair(val, candidate)]++;
				}
			}
		}
		
	}
	//purge the answer of repeat using the repTracker solution 
	sort(myAns.begin(), myAns.end());

	return myAns;
	
}


vector<int> shuffleDeck(vector<int>& d_) {
	//deckdist(1,d_.size());
	int card = 0;
	vector<int> newDeck;
	for (int i = d_.size(); i > 0; i--) {
		//card = i;
		//deckdist(1,12);
		uniform_int_distribution<int> ddist(1,i);
		
		card = ddist(gen);
	//	cout << card << endl;
		newDeck.push_back(d_.at(card-1));
		d_.erase(d_.begin()+card-1);
	}
	
	
	
	return newDeck;
}
int main() {


/*
	int * rolls = new int [8];
	for (int i = 0; i < 8; i++) rolls[i] = 0;
	int rng = 0;
	for (int i = 0; i < 5000; i++) {
		rng = rand7();
		rolls[rng] += 1;
		cout << rng << endl;
	}
	for (int i = 1; i < 8; i++) {
		cout << "rng val: " << rolls[i] << endl;
	}
*/
/*
//allows repeats.
//design an algorithm that finds all pairs of integers in an array that sum to a specific value. 
	vector<int> myArr;
	myArr.push_back(2); 
	myArr.push_back(4); 
	myArr.push_back(6); 
	myArr.push_back(10); 
	myArr.push_back(55); 
	myArr.push_back(-8); 
	myArr.push_back(0); 
	myArr.push_back(47); 
	myArr.push_back(1); 
	myArr.push_back(2);  
	//{2, 4, 6, 10, 55, -8, 0, 47, 1, 2};

	vector<pair<int, int>> ans = findAllPairsK(2, myArr);
	for (pair<int, int>& num : ans) {
		cout << num.first << " pairs with " << num.second << endl;
	}

*/

//perfectly shuffle a deck of cards.
//
//using only a 4-suite deck with numbers 1-3 for demo purposes. 
	vector<int> deck;
	deck.push_back(1);
	deck.push_back(1);
	deck.push_back(1);
	deck.push_back(1);
	deck.push_back(2);
	deck.push_back(2);
	deck.push_back(2);
	deck.push_back(2);
	deck.push_back(3);
	deck.push_back(3);
	deck.push_back(3);
	deck.push_back(3);
	
	vector<int> shDeck = shuffleDeck(deck);
	for(int& card : shDeck) cout << card << endl;
	return 1;
}
