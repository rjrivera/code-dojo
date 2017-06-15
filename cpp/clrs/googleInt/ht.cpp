#include<iostream>
#include<algorithm>
#include<vector>
#include"ht.h"
using namespace std;

ht::ht(){
	cout <<"hash table initialized\n";
}

bool ht::duplicate(string word){ 
	vector<string> pals = getPalindromes(word);
	if (find(pals.begin(), pals.end(), word) == pals.end()) return true;
	return false;
}
string ht::myHFun(string word) {
	sort(word.begin(), word.end());
//	cout << word << endl;
	return word;	
}

void ht::insert(string word) {
	string key = myHFun(word);
	if (!duplicate(word))  {
		string key = myHFun(word);
		node * val = table[key];
		if (val == nullptr)  {
			table[key] =new node(word);
			return;
		}
		while (val->nextWord != nullptr) val = val->nextWord;
		val->nextWord = new node(word);

	}

}
vector<string> ht::getPalindromes(string word){
	vector<string> ans;
	string key = myHFun(word);
	node * temp = table[key];
	while(temp != nullptr) {
		ans.push_back(temp->word);	
		cout << temp->word << endl;
		temp = temp->nextWord;
	}
	return ans;

}

int main( int argc, char** argv ) {

	ht myHash = ht();
	myHash.insert("cat");
	myHash.insert("tac");
	myHash.insert("atc");
	myHash.insert("cat");

	vector<string> pals = myHash.getPalindromes("cat");
	for(string& word : pals) cout << word << endl;
	return 0;
}
