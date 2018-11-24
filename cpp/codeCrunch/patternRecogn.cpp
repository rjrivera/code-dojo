#include <iostream>
#include <string>

using namespace std;

// This is the Ragen-Karp algorithm for substring pattern recognition. 

bool findText( string source, string pattern ) {
	int prime 	= 541; // 100th prime number oh what a joy. 
	int charSetSize	= 256;
	int patHash	= 0;
	int sourceHash	= 0;
	
	// initial generation of the hash. 
	for( int i = 0; i < pattern.size(); i++ ){
		patHash += (pattern[i]*1) * charSetSize % prime;	
		sourceHash += (source[i]*1) * charSetSize % prime;	
	}
	cout << "init Hashing for (pattern, source) : " << " (" << patHash << "," << sourceHash << " )" << endl;
	

	if ( patHash == sourceHash ) return true;	

	for ( int i = 1; i < source.size() - pattern.size(); i++ ) {
		// deload one char's hash and increment the new char's hash
		sourceHash += charSetSize*(source[i + pattern.size() - 1]*1) % prime;
		sourceHash -= charSetSize*(source[i - 1]*1) % prime;
		cout << "curSource Hash pos " << i << " ---> " << sourceHash << endl;	

		if ( patHash == sourceHash ) return true;		
	}

	return false;
}

// naive response is a (m - n) * N worstcase performance algo. 
/* implemented in five minutes. let us "hash-out" the hash solution. 
bool findText( string source, string pattern ) {

	for ( int i = 0; i < source.size() - pattern.size(); i++ ) {
	// start a new base.
		for( int j = 0 ; j < pattern.size(); j++ ) {
			if ( source[ i + j] != pattern[ j ]  ) break; 
			if ( j == pattern.size() - 1 ) return true; 
		}

	}

	return false;
}
*/
int main( int argc, char** argv ) {

	string subtext, text, response;
	text	= "I am the champchimpchampagne";
	subtext	= "champ";

	( findText( text, subtext ) ) ? response = "substring found" : response = "substring not found";

	cout << response << endl;

	return 0;
}
