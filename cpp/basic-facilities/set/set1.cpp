#include <unordered_set>
#include <iostream>
#include <string>

int main( int argc, char** argv ) {

	std::cout << "this is me pretending to improve\n";
	std::unordered_set<std::string> mySet( {"earth", "Fire", "WInd", "Water", "HEART!" } );

	for( std::unordered_set<std::string>::iterator it = mySet.begin(); it != mySet.end(); it++) std::cout << *it << std::endl;

	std::cout << "oh my!\n";
	return 0;
}
