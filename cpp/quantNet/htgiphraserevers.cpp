#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* reverse the words in a phrase
 *
 *
 */

void reverseWord(string& phrase_) {
	char temp;
	int length = phrase_.length();
	vector <int> spaces; 
	//reverse the string outright, identify locations of "\n" chars. track them with a stack. 
	for (int i = 0; i < length/2; i++) {
		temp = phrase_.at(i);
		phrase_.at(i) = phrase_.at(length-1-i);
		if (phrase_.at(i) == ' ') spaces.push_back(i);
		phrase_.at(length-1-i) = temp;
		if (phrase_.at(length-1-i) == ' ') spaces.push_back(length-1-i);
		cout << "new char at index: " << i << " " << phrase_.at(i) << endl;	 
	}
	cout << phrase_ << endl;
	//reverse the words themselves
	int start = 0;
	sort(spaces.begin(), spaces.end());
	for (int& space : spaces) {
		//iterate through the word.
		for (int i = start; i < (space-start)/2 + start; i++) {
			temp = phrase_.at(i);
			phrase_.at(i) = phrase_.at(space-1-(i-start));
			phrase_.at(space-1-(i-start)) = temp;
		}
		start = space + 1;
	}
	// fencepost problem
	for (int i = start; i < (length-start)/2 + start; i++) {
		temp = phrase_.at(i);
		phrase_.at(i) = phrase_.at(length-1-(i-start));
		phrase_.at(length-1-(i-start)) = temp;
	}
		
	cout << phrase_ << endl;
}

int main( int argc, char** argv ) {
	
	string batchOne = "Ready to fight";
	string batchTwo = "Destiny Best zerg NA";
	string batchThree = "youre Waifu a shit";

	
		cout << "batchOne\n" << batchOne << endl;
		reverseWord(batchOne); 
		cout << batchOne << endl;
	
		cout << "batchTwo\n" << batchTwo << endl;
		reverseWord(batchTwo); 
		cout << batchTwo << endl;
	
		cout << "batchThree\n" << batchThree << endl;
		reverseWord(batchThree); 
		cout << batchThree << endl;

	return 0;
}
