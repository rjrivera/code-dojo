#include <iostream>
#include <string>
#include <vector>

using namespace std;

class node {
	public:

	int key;
	int value;
	
	node * parent;
	node * lC;
	node * rC;

	node() : key( -1 ), value ( 0 ), lC( NULL ), rC( NULL ), parent( NULL ) { };
	node(int key_, int value_ ) : key( key_ ), value ( value_ ), lC( NULL ), rC( NULL ), parent( NULL ) { };

	void print() {
		cout << "node key => " << key << "\nnode value => " << value << endl;
	};
};

class bst {

	public:
	node * root;
	bst() : root(new node() ) { };
	bst( int key_, int value_ ) : root(new node(key_, value_)) { };

	void print(){
		printHelper( root );
	};

	void insert( node * nN ) {
		//special case of a naked tree - ie. root->key == -1
		if( root->key == -1 ){
			root = nN;
			return;
		}
		insertHelper( nN, root);

	};

	node * retrieve(int key_) {

	};

	void rotateRight( node * curN ) {
		if( curN->lC == NULL ) return; //can't rotate if the left childe is NULL. 
		node * tmp;
		tmp = curN->lC;
		node *tRc = tmp->rC;
		node *tLc = tmp->lC;
		tmp->rC = curN->rC;
		tmp->parent = curN->parent;
		if( tmp->parent->rC == curN ) tmp->parent->rC = tmp;
		else tmp->parent->lC = tmp;
		curN->rC = tRc;
		curN->parent = curN->lC;
		curN->lC = tLc;
		tmp->lC = curN;
		
		

	};
	
void rotateLeft( node * curN ) {
		if( curN->rC == NULL ) return; //nothing to rotate with.
		node * tmp = curN->rC;
		tmp->parent = curN->parent;
		node * tLc = tmp->lC;
		node * tRc = tmp->rC;
		tmp->rC = curN;
		tmp->lC = curN->lC;
		if( tmp->parent != NULL ) {
			if( tmp->parent->rC == curN ) tmp->parent->rC = tmp;
			else tmp->parent->lC = tmp;
		}
		curN->rC = tRc;
		curN->lC = tLc;
		curN->parent = tmp;
	};

	private:
	
	void printHelper( node * curN ) {
		if( curN == NULL ) return;
		printHelper(curN->lC);
		curN->print();
		printHelper(curN->rC);
	};

	void insertHelper( node * nN, node * curN ) {
		if( curN->key == nN->key ) {
			cout << "key currently exists in tree, ignore\n";
			return;
		}	
		if( curN->key > nN->key && curN->lC == NULL ) {
			curN->lC = nN;
			nN->parent = curN;
			return;
		}
		if( curN->key > nN->key ) {
			return insertHelper(nN, curN->lC);
		}
		if( curN->key < nN->key && curN->rC == NULL ) {
			curN->rC = nN;
			nN->parent = curN;
			return;
		}
		if( curN->key < nN->key ) {
			return insertHelper( nN, curN->rC );
		}
		return;

		
	};

	

	


};

int main() {

	int keys[] = { 3, 5, 1, 6, 4 };
	int values[] = { 30, 50, 10, 60, 40 };
	bst * tree = new bst();
	
	for(int i = 0; i < 5; i++ ) tree->insert( new node(keys[ i ], values[ i ]) ); 
	tree->print();
	tree->rotateLeft( tree->root->rC );
	tree->print();
	
	return 0;
}
