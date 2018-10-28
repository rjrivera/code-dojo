#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct node{
	int id;
	node * nextNode;
};

int main( int argc, char** argv ) {

	cout << "this is me reaffirming my lambda and struct knowledge\n";
	node * n1 	= new node();
	node * n2	= new node();
	node * n3	= new node();

	n1->id	= 1;
	n2->id	= 2;
	n3->id	= 3;

	// I have no desire to link these nodes, I am tracking them as heads to other datum schemes and they are 
	// tracked in the vector. 
	vector< node *> states = vector< node *>();
	states.push_back(n1);
	states.push_back(n2);
	states.push_back(n3);

	cout << "iterating through nodes to demonstrate i built this accurately" << endl;
	for( int i = 0; i < states.size(); i++ ) cout << states[i]->id << endl;

	return 0;
}
