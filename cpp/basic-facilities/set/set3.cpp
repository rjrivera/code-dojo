#include <unordered_set>
#include <iostream>
#include <string>

typedef std::unordered_set< std::string > myLittleSet;

int main( int argc, char** argv ) {

	std::cout << "What else can we learn from just the unordered_set docs?\n";

	std::unordered_set<std::string> mySet( {"earth", "Fire", "WInd", "Water", "HEART!" } );
	mySet.insert( { "Zapdos", "Articuno", "Moltres", "Mewtwo" } );
	for( std::unordered_set<std::string>::iterator it = mySet.begin(); it != mySet.end(); it++) std::cout << *it << std::endl;
	std::cout << "max_load factor 	-> " << mySet.max_load_factor() << std::endl;
	std::cout << "load_factor 	-> " << mySet.load_factor() << std::endl;

	std::cout << "observing the hash_function" << std::endl;
	myLittleSet::hasher fn =  mySet.hash_function();
	std::cout << "Zapdos 	-> " << fn("Zapdos") << std::endl;
	std::cout << "Articuno 	-> " << fn("Articuno") << std::endl;

	std::cout << "Honestly thinking that we are tapping out our analysis of the unordered set here, should read theory from Skiena\n";



	return 0;
}
