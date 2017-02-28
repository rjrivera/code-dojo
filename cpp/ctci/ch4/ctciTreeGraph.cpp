#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tNode {
	private:
		int data;
		tNode * lC;
		tNode * rC;
	public:
		tNode() : data(0), lC(nullptr), rC(nullptr) {}
		tNode(int val_) : data(val_), lC(nullptr), rC(nullptr) {}
		int getVal() { return data;}
		void putVal(int num_) {data = num_;}
		void putRC(tNode * cand_) {rC = cand_;}
		void putLC(tNode * cand_) {lC = cand_;}
		tNode* getLC(){return lC;}
		tNode* getRC(){return rC;}
};

struct tree {
	private:
		tNode * root;
		int maxH;
	public:
		tree(tNode * rootCand): root(rootCand){}
		tree(): root(nullptr), maxH(0){}
		bool dfsHelper(tNode * curNode, int curH){
			if (curNode == nullptr) {
				if (maxH == 0) maxH = curH;
				if (maxH-curH > 1 || curH - maxH > 1 ) return false; 		
	//			cout << "maxH is: " << maxH << endl;
	//			cout << "curH is: " << curH << endl;
				return true;
			}
			curH++;
			if (maxH > 0 && (maxH-curH > 1 || curH - maxH > 1) ) return false;
			cout << "curH is: " << curH << endl;
			if ( !dfsHelper(curNode->getLC(), curH)) return false;
			if ( !dfsHelper(curNode->getRC(), curH)) return false;
			cout << "node val: " << curNode->getVal() << endl;
			return true;
		}
		void dfs() {
			dfsHelper(root, 0);
		}
		bool isBal() {
			return dfsHelper(root, 0);
		}
};


/* 4.1 Implement a function to check if a tree is balanced. For the purposes of the ? a bal. tree is defined to be a tree such that no two leaf nodes differ in distancce from the root by more than one
 *
 * okay - my approach is to track a height for each leaf, and keep a delta between the min and max for each dfs iteration and if a delta exists > 1 return false, else return true. 
 * so it probably may have not been the best way to go about it, but hey this was a great muscle flex.
 */

bool isBalHelper() {
	return true;

}

bool isBal(tNode * root) {
	return isBalHelper();

}

/* Given a directed graph, design an algorthm to findout whether there is a route between two nodes. 
 * for this problem I will design nodes such that they only hold information regarding the nodes they direct to, so a graph is not a series of connected nodes perse, but rather a collection of nodes.
 *
 *
 */

struct gNode {
	private:
		int id;
		vector<gNode * > neighbors;
	public:
		gNode() : id(0) { };
		gNode(int id_) : id(id_) { };
		void putNeighbor(gNode* cand) {neighbors.push_back(cand);}
};

struct graph{
	private:
		vector<gNode*>* nodes;
	
	public:

		graph():nodes(new vector<gNode*>()) {}
		void pushNode(gNode * newNode) {
			nodes->push_back(newNode);
		}
};


int main( int argc, char** argv ) {
	/*4.1 test bench
 * 	==========================
	//for testing purposes I will manually link the values.*/
	/*
	tNode * myTree = new tNode();
	tNode * chA = new tNode(5);
	tNode * chB = new tNode(10);
	tNode * chC = new tNode(8);
	tNode * chD = new tNode(14);
	// now manually link them.
	myTree->putLC(chA);
	myTree->putRC(chB);
	chB->putRC(chD);
	chB->putLC(chC);
	tree * myT =  new tree(myTree);
	//myT->dfs();
	if (myT->isBal()) cout << "This tree is bal\n";
	else cout << "imbalance detected\n"; 

	tNode * chE = new tNode(16);
	tNode * chF = new tNode(18);
	chD->putRC(chE);
	chE->putRC(chF);
	//myT->dfs();
	if (myT->isBal()) cout << "This tree is bal\n";
	else cout << "imbalance detected\n"; 
*/
//============4.2 TEST BENCH ==============
//
	gNode * g1 = new gNode(1);
	gNode * g2 = new gNode(2);
	gNode * g3 = new gNode(3);
	gNode * g4 = new gNode(4);
	gNode * g5 = new gNode(5);

	g1->putNeighbor(g2);
	g1->putNeighbor(g4);
	g2->putNeighbor(g4);
	g5->putNeighbor(g2);
	g4->putNeighbor(g3);

	graph * myG = new graph();
	myG->pushNode(g1);	
	myG->pushNode(g2);	
	myG->pushNode(g3);	
	myG->pushNode(g4);	
	myG->pushNode(g5);	

	return 0;
}
