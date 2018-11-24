#include <iostream>
#include <string>

// now hashing is a broad and deep topic which can be expanded greatly upon. 
// a hash function's design is a function of resources annd the anticipated input set. 
// This is a decently featured hashtable. 
using namespace std;
static string hashTable[256];

int hashVal( string val ){
	//potential for collision must be tested via simulation. 
	int hash 	= 0;
	for( int i = 0; i < val.size(); i++ ) hash += (val[i]*1) % 256;
	return (hash % 256);
}

void insertValue( string val ){
	int hash = hashVal( val );
	hashTable[hash] = val;
}

bool valPresent( string val ) {
	int hash = hashVal( val );
	if ( hashTable[hash] != "" ) return true;
	return false; 

}

void printHashTable() {
	for( int i = 0; i < 256; i++ ) {
		if( hashTable[i] != "" )  cout << hashTable[i] << endl ;
	}

}

int main( int argc, char** argv ) {
	insertValue( "aa"    );
	insertValue( "dummy" );
	string t1, t2, t3;
	(valPresent( "aa" ) ) ? t1 = "aa is present" : t1 = "aa is not present";
	(valPresent( "dummy" ) ) ? t2 = "dummy is present" : t2 = "dummy is not present";
	(valPresent( "banana" ) ) ? t3 = "banana is present" : t3 = "banana is not present";

	printHashTable();
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;

	return 0;
}

