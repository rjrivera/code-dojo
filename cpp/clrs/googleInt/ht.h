#ifndef HT_H
#define HT_H
//HASH used to identify palindromes for a given library.a
#include<map>
#include<string>
using namespace std;
struct node {
public:
	string word;
	node * nextWord;
	node():nextWord(nullptr){}
	node(string data): word(data), nextWord(nullptr){}

};
class ht{

private:
	std::map<string, node*> table;
	bool duplicate(string word);
	string myHFun(string word);
public:

//default constructor
	ht();
	
	void insert(string word);
	vector<string> getPalindromes(string word);
};

#endif
