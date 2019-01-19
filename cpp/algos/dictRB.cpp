#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node {
	public:
	int key;
	int value;
	int color; //0 = black, 1 = red
	node * lC;
	node * rC;
	node * parent;
	node() : key(-1), value(0), color(1), lC(NULL), rC(NULL), parent(NULL) {

	};
	node(int key_, int value_) : key(key_), value(value_), color(1), lC(NULL), rC(NULL), parent(NULL) { };
	node(int key_, int value_, int color_) : key(key_), value(value_), color(color_), lC(NULL), rC(NULL), parent(NULL) { };
	void print(){
		cout << " key -- " << key << " value -- " << value  << endl;
	};
};

class dictRB {
	public:
	node * root;
	node * sentinel;

	dictRB() : root( new node() ), sentinel( new node( -1, 0, 0 )) {
		node * tmp = new node( -1, 0, 0 );
		root->parent = tmp;
		
	 };	

	node * retrieve( int key_ ) {
		cout << "retrieve placeholder\n";
		return root;
	};

	void print() {
		printHelper( root );
	};

	void deleteKey( int key_ ) {
		cout << "delete placeHolder\n";
	};

	void insert( int key_, int value_ ) {
		node * tmp = new node( key_, value_ );
		tmp->lC = new node( sentinel->key, sentinel->value, sentinel->color );
		tmp->rC = new node( sentinel->key, sentinel->value, sentinel->color );
		tmp->print();
		insertHelper( tmp, root );
	};

	private:

	void insertHelper( node * nNode, node * curNode ) {
		if( curNode->key == -1 ) {
			nNode->parent = curNode->parent;
			curNode = nNode;
			if( nNode->parent->key != -1 ) nNode->parent->color = 1;
			return;
		}
		if( curNode->key > nNode->key ) insertHelper( nNode, curNode->lC );
		if( curNode->key < nNode->key ) insertHelper( nNode, curNode->rC );
		return;
	}

	void rotateLeft( /**/ ) {
		return;
	};

	void rotateRight( /**/ ) {
		return;
	};
	void printHelper( node * curNode ) {
		if(curNode->key == -1 ) return;
		printHelper( curNode->lC );		
		cout << " key " << curNode->key << " --- value " << curNode->value << endl;
		printHelper( curNode->rC );		



	}


};

int main () { 
	dictRB * myDict = new dictRB();
	int keys[] = { 1, 4, 6, 10, 7 };
	int values[] = { 10, 40, 60, 100, 70 };
	for (int i = 0; i < 5; i++ ) myDict->insert(keys[i], values[i] );

	myDict->print();
	myDict->root->print();

	return 0;
};

