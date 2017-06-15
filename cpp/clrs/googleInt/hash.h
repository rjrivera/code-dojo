#ifndef HASH_H
#define HASH_H
//HASH used to identify palindromes for a given library.a
#include<map>
#include<string>

struct node {
public:
	string word;
	node * nextWord;
	node():nextWord(nullptr){}
	node(string data): word(data), nextWord(nullptr){}

};
class hash{

private:
	std::map<string, node*>();
public:

//default constructor
	hash();
	
	
};



#endif
