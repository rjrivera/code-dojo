#include <iostream>
#include <string>

using namespace std;


/* A personal review and implementation for CLRS R-B TREES
 *
 * notes: the semantics of 13.3 pseudocode of RB-Insert-Fixup is ambiguous.
 * 	Line 9 does not differentiate the de facto "else { if() {"
 * 	from a possible interpretation of "else if() {".
 * 	since it states verbatum "else if z == right[p[z]]"
 *
 * 	Notes to understanding this. 
 *
 * 	Treat this like a regular tree, with the needed coloring scheme added. 
 * 	understand the left and right rotation operators and appropriately test them. 
 *
 * 	the insert-fix operation is the meat-potatoes of the self-balancing act and requires that all inserted nodes are painted red. 
 *
 * 	Figure 13.4 walks through the operation very well. 
 * 	
 *	Motivation for the hassle: guarentee a balanced tree with minimal cost. 
 *
 *	TODO[ ] Delete-Fix analogue operation to preserve R-B features after deletion. 
 */

struct tNode {
	int32_t val;
	bool red = false; //default to black.
	tNode * lC;
	tNode * rC;
	tNode * p;
};

class binTree {
private:
	tNode * root;//do NOT allow duplicates.
	tNode * sentinel;
	/*initial value insertion - returns reference to node for vixing.
 */
	tNode* insertHelper(tNode* cNode, int32_t value) {
		if (cNode->val == value) return cNode; 
		else if (cNode->rC->val == -1 && value > cNode->val)  {
			tNode * temp = new tNode();
			temp->val = value;
			temp->p = cNode;
			temp->red = true;
			temp->rC = temp->lC = sentinel;
			cNode->rC = temp;
		
			return temp;
			
		}
		else if (cNode->lC->val == -1 && value < cNode->val)  {
			tNode * temp = new tNode();
			temp->val = value;
			temp->p = cNode;
			temp->red = true;
			temp->rC = temp->lC = sentinel;
			cNode->lC = temp;
			
			return temp;
		}
		else if (cNode->val < value )  	return insertHelper(cNode->rC, value);
		else if (cNode->val > value ) return insertHelper(cNode->lC, value);
		return cNode; 

	}

	/**
 *	helper function designed to traverse and find a value givent it is NOT valud bst;
 */

	void deleteHelper(tNode*& cNode, int32_t value) {
		if (cNode->val == -1) return; 
		if (cNode->val == value) { //we found the value. 
			//determine how to amend the tree;
			cout << "found it!\n";
			if (cNode->rC->val == -1 && cNode->lC->val == -1)  cNode = sentinel;
			else if (cNode->rC->val == -1) {
				cNode->lC->p = cNode->p;
				cNode = cNode->lC;
					
			}
			else {
				cNode->rC->p = cNode->p;
				cNode = cNode->rC; //remember, if lC is not null, rC is still > lC. 
			}
			return; 
		} 
		deleteHelper(cNode->rC, value);
		deleteHelper(cNode->lC, value);
	

	}
	
/*
 *	in order traversal print to console.
 *	used for validity testing. 
 */

	void inOrderTraversalHelper(tNode * cNode) {
		if (cNode == sentinel) return; 
		inOrderTraversalHelper(cNode->lC);
		cout << ", " << cNode->val;
		inOrderTraversalHelper(cNode->rC);

	}
	/* see CLRS Figure 13.2
 */

	void leftRotate(tNode*& lN, tNode*& rN) {
		rN->p = lN->p;
		lN->p = rN;
		lN->rC = rN->lC;
		rN->lC->p = lN;
		rN->lC = lN;


	}

/*	see CLRS Figure 13.2
 */

	void rightRotate(tNode*& lN, tNode*& rN) {
		lN->p = rN->p;
		rN->lC = lN->rC;
		lN->rC->p = rN;
		lN->rC = rN;
		rN->p = lN;

	}

	/*	see CLRS Tree-Insertion-Fix 13.3 
 *	Perform rotations to preserve r-b nature. 
 */
	void rbInsertFix(tNode* newC){
/*
		cout << "debug call -\n" <<
			"children of node should have -1 (be NIL)\n" <<
			"lC->val = " << newC->lC->val << 
			"rC->val = " << newC->rC->val << endl;
		cout << "sentinel val: " << sentinel->val << endl;
		//if the root is red, spot correct and return. 
		// very simple heuristic. 
		if (newC->p->val == -1)  {
			newC->red = false;
			return;
		}*/
		tNode * y = new tNode();
		//while loop maintains invariants. 
		while (newC->p->red) { //a red node CANNOT hava a red child. 
			//if parent is teh lC of gN
		//	cout << "insertfix while-loop\n" << endl;
			if (newC->p->val < newC->p->p->val)  {
				// y is the uncle. 
				y = newC->p->p->rC;
				if (y->red) 		{
					newC->p->red = false;
					y->red = false;
					newC->p->p->red = true;
					newC = newC->p->p;
				}
				// new node is right child. 
				else {
					if (newC->val > newC->p->val) {
						newC = newC->p;
						leftRotate(newC, newC->rC);
					}
					newC->p->red = false;
					newC->p->p->red = true;
					rightRotate(newC->p, newC->p->p);
				}
			}
//if parent is teh lC of gN
			else { //same as above with "right' "left" exchanged.
				// y is the uncle. 
				y = newC->p->p->lC;
				if (y->red) 		{
					newC->p->red = false;
					y->red = false;
					newC->p->p->red = true;
					newC = newC->p->p;
				}
				// new node is left child. 
				else {
					if (newC->val > newC->p->val) {
						newC = newC->p;
						leftRotate(newC, newC->rC);
					}
					newC->p->red = false;
					newC->p->p->red = true;
					rightRotate(newC->p, newC->p->p);
				}
			}

		}

		root->red = false;
		return;

	}

public:
	//root's parent and all leaves == sentinel (NIL) 
	binTree():root(new tNode()), sentinel(new tNode()) {
		sentinel->val = -1;
		sentinel->rC = root;
		sentinel->lC = sentinel;
		root->p = sentinel;
		root->lC = root->rC = sentinel;
	};
	void insertVal(int32_t value){
		tNode * temp;
		insertHelper(root, value);
		//rbInsertFix(insertHelper(root, value));//performs the insertion

	}
	void deleteVal(int32_t value){
		deleteHelper(root, value);
	}

	void inOrderTraversal(){
		inOrderTraversalHelper(root);
		cout << endl;
	}
};

int main( int argc, char** argv ) {
	cout << "BATCCH ONE *****************\n";
	binTree t1;
	t1.insertVal(5);
	t1.insertVal(15);
	t1.insertVal(25);
	t1.insertVal(2);
	t1.insertVal(3);
	t1.insertVal(9);
	t1.insertVal(29);
	
	t1.inOrderTraversal();
	t1.deleteVal(25);
	t1.deleteVal(9);
	t1.inOrderTraversal();

	return 0;
}
