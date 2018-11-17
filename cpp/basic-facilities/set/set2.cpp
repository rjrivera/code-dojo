#include <unordered_set>
#include <iostream>
#include <string>

int main( int argc, char** argv ) {

	std::cout << "not bad, lets further explore some of unordered set's facilities...One thing to note...\n";
	std::cout << "THe iterator for unordered_sets appears to point directly to the value, no other data..\n";

	std::unordered_set<std::string> mySet( {"earth", "Fire", "WInd", "Water", "HEART!" } );
	for( std::unordered_set<std::string>::iterator it = mySet.begin(); it != mySet.end(); it++) std::cout << *it << std::endl;

	std::cout << "Let's printout some of the observers of the unordered set\n";
	std::cout << "max_load factor 	-> " << mySet.max_load_factor() << std::endl;
	std::cout << "load_factor 	-> " << mySet.load_factor() << std::endl;

	std::cout << "Let's add to set and observe if we have any changes in lf's\n";
	mySet.insert( { "Eevee", "Vaporean", "Flareon", "Jolteon" } );
	for( std::unordered_set<std::string>::iterator it = mySet.begin(); it != mySet.end(); it++) std::cout << *it << std::endl;
	std::cout << "max_load factor 	-> " << mySet.max_load_factor() << std::endl;
	std::cout << "load_factor 	-> " << mySet.load_factor() << std::endl;

	std::cout << "Let's bust the set! see if a mlf rebalance is automatic!\n";
	mySet.insert( { "Zapdos", "Articuno", "Moltres", "Mewtwo" } );
	for( std::unordered_set<std::string>::iterator it = mySet.begin(); it != mySet.end(); it++) std::cout << *it << std::endl;
	std::cout << "max_load factor 	-> " << mySet.max_load_factor() << std::endl;
	std::cout << "load_factor 	-> " << mySet.load_factor() << std::endl;

	std::cout << "Looks like a bucket refactor occurs to maintain mlf > lf\n";

	std::cout << "tre bizzare!\n";
	return 0;
}
