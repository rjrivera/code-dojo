#include <vector>
#include <iostream>

using namespace std;

class HTable{
  private: 
     vector<vector<uint32_t>> table;

     uint32_t hash(uint32_t val_) {
	return val_ % 10;
     }

  public:	
     HTable() : table(vector<vector<uint32_t>>()) {

	//default to ten buckets to implement a basic vector based chaining version of a hash table.
	for (int i = 0; i < 10; i++) table.push_back(vector<uint32_t>());

     }

     vector<uint32_t> get(uint32_t key) {
	if (key >= 10 )  {
		cout << "invalid key (keys of [0-9] )\n";
		return vector<uint32_t>(); //return an empty vector
	}
	return table[key];

     }

     void insert(uint32_t value) {
	//generate the hash.
	uint32_t key = hash(value);
	
	//push into the table, permits repeats.
	table[key].push_back(value);
     }

};




int main( int argc, char** argv ) {
	//batch one 
	//
	HTable htOne = HTable();
	htOne.insert(55);
	htOne.insert(34);
	htOne.insert(47);
	htOne.insert(14);
	htOne.insert(38);
	htOne.insert(96);
	
	vector<uint32_t> tempBucket;
	for (int i = 0; i < 10; i++) {
		tempBucket = htOne.get(i);
		for(uint32_t& value : tempBucket) cout << "bucket: " << i << " value: " << value << endl;

	}

	return 0;
}
