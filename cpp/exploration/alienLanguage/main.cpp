#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

// Given my exploits this time last year - I revisited this question...given a sorted library of a language which has every letter represented,
// find the correct sorting of the alphabet.
//
// I found that the best route was to treat the sets of relations as independent graphs, then procedurally link the graphs...will seem apparent in a video...so I'll leave that to myself in the future. 
//
// this exercise falls under the desired outcome of mental durability and technical problem solving. 


int main( int argc, char** argv ) {

	// my test set will be a subset of the english language, my exhaustive set will be more thorough
	
	std::vector<std::string> library = std::vector<std::string>();
	library.push_back("ab");
	library.push_back("ar");
	library.push_back("at");
	library.push_back("bar");
	library.push_back("bat");
	library.push_back("brat");
	
	std::vector<std::vector < char > > relations = std::vector<std::vector < char> >();

	//iterate through the libary identifying relations
	std::vector<std::tuple<uint64_t,uint64_t>> uniMarkers = std::vector<std::tuple<uint64_t, uint64_t>>();
	
	bool newUni = true;
	char left, right;
	left = right = ' ';
	uint64_t leftMark, rightMark;
	leftMark = rightMark = 0;
	uint64_t uniLeft, uniRight;
	uniLeft = uniRight = 0;
	std::vector<std::tuple<uint64_t, uint64_t>> oldMarkers = std::vector<std::tuple<uint64_t, uint64_t>>();
	for (uint64_t depth = 0; depth < 4; depth++){  //statically define the max length -- return to determing this. 
		if ( depth == 0 ) oldMarkers.push_back(std::make_tuple(0, (uint64_t) (library.size() - 1) ) );
		else { 

			std::vector<std::tuple<uint64_t, uint64_t>> oldMarkers = std::vector<std::tuple<uint64_t, uint64_t>>();
			for(std::tuple<uint64_t, uint64_t>& marker : uniMarkers) {
				oldMarkers.push_back(marker);
			}
			uniMarkers.clear();
		}

		for(std::tuple<uint64_t, uint64_t>& markers : oldMarkers) {
			
		
			uniLeft = std::get<0>(markers);
			uniRight = std::get<1>(markers);
			newUni = true;	
			
			relations.push_back(std::vector<char>());
			for(uint64_t i = uniLeft; i <= uniRight; i++)  {
				if ( newUni )  	{ //set left post and toggle control signal. 
					if (depth >= library[i].size() ) {
						std::cout << "depth is out of ranges\n";
						continue; //found end of word continue exploring depth from next word. 
					}
					left = library[i].at(depth); //set left post to the letter at depth desired. 
					std::cout << "found letter " << left << " at depth " << depth << std::endl;
					leftMark = i;
					newUni = false;
					//register the new letter relation discovered in appropriate data structure. 
					relations[depth].push_back(left);
				}
				else {
					if ( i == uniRight )  {
						right = ' ';
						rightMark = i;
						uniMarkers.push_back(std::make_tuple<uint64_t, uint64_t>((uint64_t)leftMark, (uint64_t)rightMark));
						newUni = true; 
					}
					else if ( depth >= library[i].size() )  {
						right = ' ';
						rightMark = i-1;
						newUni = true;
						uniMarkers.push_back(std::make_tuple<uint64_t, uint64_t>((uint64_t)leftMark, (uint64_t)rightMark));
					}
					else if ( library[i].at(depth) > left )  {
						rightMark = i - 1;
						i--;
						std::cout << "accessing letter " << depth << " at word " << library[i] << std::endl;
						right = library[i].at(depth);
						std::cout << "found letter " << right << " at depth " << depth << std::endl;
						newUni = true;
						uniMarkers.push_back(std::make_tuple<uint64_t, uint64_t>((uint64_t) leftMark, (uint64_t)rightMark));

					}
				}


			}
		}
	}
	for(std::string & word : library) std::cout << word << std::endl;

	std::cout << "Printing all relationships identified. \n";
	for(std::vector<char>& relation : relations) {
		for( char letter : relation ) std::cout << letter << std::endl;
		std::cout << std::endl;
	
	}


	return 0;
}
