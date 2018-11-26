#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int levD(string p, string s)  {
	if ( p.size() == 0 && s.size() == 0 ) return 0; 
	// initialize a blank grid that is m+1xn+1
	vector< vector<int> * > mat = vector<vector<int> *>();
	for( int i = 0; i <= p.size(); i++ ) {
		mat.push_back( new vector<int>() );
		for( int j = 0; j <= s.size(); j++ ) {
			mat[i]->push_back(0);
		}
	}

	// for empty string prefixes...	

	for( int j = 0; j <= s.size(); j++ ) 
		mat[0]->at(j) = j;

	for( int i = 0; i <= p.size(); i++ ) 
		mat[i]->at(0) = i;
		
	int subCost	= 0;
	for( int i = 1; i <= p.size(); i++ ) {
		for( int j = 1; j <= s.size(); j++ ) {
			if ( p.at(i - 1) == s.at(j - 1) ) 
				subCost = 0;
			else
				subCost = 1;
			mat[i]->at(j) = min( min( mat[i - 1]->at(j) + 1, mat[i]->at(j - 1) + 1 ), mat[i-1]->at(j-1) + subCost);
			subCost = 0;
			
		}
		cout << endl;
	}
	
	return mat[ p.size() ]->at(s.size() );
}

int main( int argc, char** argv ) {

	string p = "kitten"; // p ==> pattern
	string t = "sitting";// t ==> target text

	int lD	= levD( p, t );
	cout << "the levenshtein distance of p/t  " << p << "   " << t << endl;
	cout << lD << endl;

	return 0;
}
