#include <iostream>
#include <string>

using namespace std;

bool isSubString(string parent, string child) {
	int cSize = child.size();
	int count = 0;

	for (int i = 0; i < parent.size(); i++) {
		if (parent.at(i) == child.at(count)) count++;
		else count = 0;
		if ( count++ == cSize ) return true;
	}

	return false;

}

int main( int argc, char** argv ) {
	//batch testing 
	string word = "bate";
	string sWord = "bat";
	if (isSubString(word, sWord)) cout << word << " contains the string: " << sWord << endl; 
	else cout << word << " contains the string: " << sWord << endl; 

	//batch testing 
	word = "bate";
	sWord = "at";
	if (isSubString(word, sWord)) cout << word << " contains the string: " << sWord << endl; 
	else cout << word << " contains the string: " << sWord << endl; 


	return 0;
}
