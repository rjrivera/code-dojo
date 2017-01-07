#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdint.h>
#include <queue>
#include <deque>
#include <screen.hpp>
#include <list>
#include <functional>
#include <boost/lexical_cast.hpp>
#include <map>
#include <unordered_map>
#include <sstream>

//#include "print.h"
using namespace std;

//static int i = 3;
//int count[5] = {2, 4, 6, 8, 10} ;

int a = 5;

/*
int& function () { };
namespace { static int n; }
namespace A {
	namespace { static int n; }
}
*//*
class A {
	public:
	A() {}
	A(A& a) {}
	A& operator=(const A& a)
	{ return(*this); }
	
};
*/
/*
class sc 	{
	int x;
	public: 
	sc(int xx) : x(xx) {}
};

template<typename T> class DynA{
	T * contents;
	int size;
	public:
		explicit DynA(int initial_size);
};



template<class T>
struct sum{
	static void foo(T op1, T op2) {
		cout << " sum j= " << endl;		
	}	


};

*/
/*
void swap(uint32_t& varA_, uint32_t& varB_) {
	varA_ = varB_ - varA_;
	varB_ -= varA_;
	varA_ += varB_;

}


//given that 0 = empty, 1 = 'x', 2 = 'o'. -- amended to n-sized games - only checking horizontal and verticals as is because moving on. 
bool winnerTTT(string gameState_) {
	// very limited number of winning states. check for each state seperately. 
	uint32_t streak = 0;
	// for each side - traverse through all possible winning starting positions. 
	uint32_t sideLength = sqrt(gameState_.size());
	for (uint32_t i = 1; i < 3; i++) {
		// 0 - 3 - 6
			for (uint32_t start = 0; start < sideLength; start++) {
				// check horizontal
				for (uint32_t streakPos = 0; streakPos < sideLength; streakPos++) {
					if (gameState_.at(start*sideLength + streakPos) == boost::lexical_cast<char>(i))  {
						streak++;
						cout << "streak value: " << streak << "after increment" << endl;
					}
					else { break;} //found a broken link, abandon loop to reduce operation overhead.  
				}
				if (streak == sideLength) { return true;}
				streak = 0; //reset tracker for next iteration. 
				// check vertical. 
				for (uint32_t streakPos = 0; streakPos < sideLength; streakPos++) {
					if ( (gameState_.at(start*sideLength + (streakPos*sideLength)) ) ==  boost::lexical_cast<char>(i)) {
						streak++;
						
					}
					else { break;}
				}
				if ( streak== sideLength ) { return true;} 
				streak = 0;

			}
			
	}
	return false;

}
uint32_t calcFact(uint32_t factCand_ ){
	return (factCand_ == 1 || factCand_ == 0) ? 1 : calcFact(factCand_ - 1 ) * factCand_;

}

typedef struct PTNode{
	char ltr = NULL;
	bool terminal = false;
	map<char, PTNode>  cNodes;

};


string compressString(string word_){	
	char currentChar = word_.at(0);
	uint32_t count = 0;
	string cString;
	for (uint32_t i = 0; i < word_.size(); i++) {
		if (word_.at(i) != currentChar && i > 0) {
			cString+=currentChar;
			cString+= to_string(count);
			count = 1;
			currentChar = word_.at(i);
		}
		else {
			count++;
		}
	}
	cString += currentChar;
	cString += to_string(count); 
	return cString;

}

string expandString(string word_){
	string cString;
	for (uint32_t i = 0; i < word_.size()-1; i+= 2) {
		for (uint32_t j = 0; j < boost::lexical_cast<uint32_t>(word_.at(i+1)); j++) {
			cString += word_.at(i);
		}

	}
	return cString;
}
// presumes that the head node is properly initialized. 
void insertWord(PTNode& head_, string word_) {
	if ( word_.size() <= 0) {
		return; //robustness measure. 
	}
	char firstChar = word_.at(0);
	if (head_.cNodes.find(firstChar) == head_.cNodes.end()) {  // no word in our prefix tree exists starting with the current letter 
		//create new node, insert char and move on through the candidate string. 
		PTNode  tempNode;
		tempNode.ltr = firstChar;
		
		head_.cNodes[firstChar] = tempNode;
		if ( word_.size() > 1 )  {
			insertWord(head_.cNodes[firstChar], word_.substr(1));
		}
		else {
			head_.cNodes[firstChar].terminal = true;
			return;
		}

	}	
	else { //easy step, letter already exists in tree, just follow along. 
		if ( word_.size() > 1  ) {
			insertWord(head_.cNodes[firstChar], word_.substr(1));
		}
		else {
			head_.cNodes[firstChar].terminal = true;
			
			return;
		}
	}
}

void traverseTree(PTNode& head, string word_){
	
//	else {
		word_ += head.ltr;
		
		if ( head.terminal ) { 
			cout << word_ << endl;


		} 
		for (auto& node : head.cNodes) {
			traverseTree(node.second, word_);
		}
//	}
}

unordered_map<string, int> createDict(string book[], uint32_t length_){
	unordered_map<string, int> * tempMap = new unordered_map<string, int>();
	uint32_t temp = 0;
	for (uint32_t i = 0 ; i < length_ ; i++ ) {
		cout << "at word: " << book[i] << endl;
		if ( tempMap->count(book[i]) == 0){ 
			tempMap->insert({book[i], 1});
			cout << book[i] << " not in dict, creating key" << endl;
//			tempMap->at(book[i]) = 1;
		}
		else {

			temp = tempMap->at(book[i]);
			cout << book[i] << " encountered " << temp+1 << " times\n";
			tempMap->at(book[i]) = temp + 1;
			cout << "count after insert-> command: " << tempMap->at(book[i]) << endl;
		}
	}
	return *(tempMap);
}
*/
/*
struct Foo{
Foo() {cout << "d";}
Foo(int i) {cout << "i";}
Foo(char c) {cout << "c";}
Foo(long l) {cout << "l";}
Foo(float f) {cout << "f";}
};
*/
/*
class foo {
public:
	virtual !foo()};
	
class foobar2 : public bar2{
};

class bar2 : public foo {


};

*/
/*
class base{
protected int b;
};

class derived : base{
	friend class Friend;

};
class Friend{
	derived der;

};
*/
/*
class professor{
	~professor() {cout << "destruct professor\n";
};*/
/*
class Base{};
class derived : Base{};
*/
// maze node structure used to demonstrate bfs traversal and stack tracking of a maze shortest path solution. We have no knowledge of the end point. 
// REF: mazeNode
// 
/*
typedef struct mazeNode {
	uint32_t id;
	uint32_t val;
	bool end;
};
typedef struct pTNode{
	string id; //using char reduces the number of lexical casts from uint32_t to char
	map<string, pTNode> cPaths;
};

// upon proper path tracing and return of the new total path, the client protocol can manage a number of paths. 
// this was honestly the biggest waste of fucking time ever 
string insertPath(pTNode& node, deque<string> cPath, uint32_t cVal) { //using a string bc we need to remember our paths
	if (node.id == "root" ) {//is root 
		if (cPath.size() == 0) { //easy pz, we are the last step in a potential path. 
			pTNode temp;
			temp.id = boost::lexical_cast<string>(cVal);
			node.cPaths[boost::lexical_cast<string>(cVal)] = temp;
			return boost::lexical_cast<string>(cVal);
		}
		else{//traverse
			//if it exists move accordingly.
			if (node.cPaths.find(cPath.at(0)) != node.cPaths.end())  {
				// return the current letter plus the next or null letter. 
				string tempS = cPath.at(0);
				cPath.pop_front();
				return (tempS + insertPath(node.cPaths[tempS], cPath, cVal));
			}
			else {
				pTNode temp;
				temp.id = cPath.at(0);
				node.cPaths[cPath.at(0)] = temp;
				string tempS = cPath.at(0);
				cPath.pop_front();
				return (tempS + insertPath(node.cPaths[tempS], cPath, cVal));
			}
		}
	}
	else {
		if (cPath.size() == 0) { //easy pz, we are the last step in a potential path. 
			pTNode temp;
			temp.id = boost::lexical_cast<string>(cVal);
			node.cPaths[boost::lexical_cast<string>(cVal)] = temp;
			return boost::lexical_cast<string>(cVal);
		}
		else{//traverse
			//if it exists move accordingly.
			if (node.cPaths.find(cPath.at(0)) != node.cPaths.end()) {
				// return the current letter plus the next or null letter. 
				string tempS = cPath.at(0);
				cPath.pop_front();
				return (tempS + insertPath(node.cPaths[tempS], cPath, cVal));
			}
			else {
				pTNode temp;
				temp.id = cPath.at(0);
				node.cPaths[cPath.at(0)] = temp;
				string tempS = cPath.at(0);
				cPath.pop_front();
				return (tempS + insertPath(node.cPaths[tempS], cPath, cVal));
			}
		}
	}
	
}
//construct a trie internal to this function to track the paths in an efficient manner using the parents and children as nodes. 
vector<uint32_t> solveMaze(mazeNode maze_[][4], uint32_t goal_)  {
	vector<uint32_t> * path = new vector<uint32_t>();
	pTNode pathRoot;
	pathRoot.id = "root";
	// now begin a bfs while tracking a stack for EACH path and then identify the first stack that reaches id == goal_;
	deque<mazeNode> unprocessed;
	unordered_map<uint32_t, bool> processed; //mazeNode.id, false/true
	processed[0] = true;
	unprocessed.push_back(maze_[0][0]);
	uint32_t xInd, yInd, maxX, maxY;
	xInd = yInd = 0;
	maxX = 7;
	maxY = 4;
	mazeNode temp;
		// accounting variables for efficiently tracking paths. 
	uint32_t unProcIndex = 0; // used to keep a track record of previously accomplished work. ...
	deque<uint32_t> stackNodes;
	uint32_t numPaths = 1;
	bool firstPass = true;
	map<uint32_t, uint32_t> discovered;
	while (unprocessed.size() > 0) {
		temp = unprocessed.front();
		stackNodes.push_back(temp.id);
		//currentString = insertPath(pathRoot, currentString[currentPath], temp.id);//find the valid path. 
		// calculate xInd and yInd based on the temp being processed. 
		yInd = temp.id / maxX;
		xInd = temp.id % maxX;
		unprocessed.pop_front();
		cout << "processing node id: " << temp.id << " => " << boost::lexical_cast<string>(temp.val) << endl;
		//start checking all cardinal directions and act accordingly.
		if (xInd > 0 ) {// can look left. 
			//if its our target...
			if ( temp.id == goal_ ) {
				//return the corresponding path stack TODO: [ ] determine tracking system for various paths. 
				cout << "I think the shortest path is [ asdf] : " << endl;
				int tDec = 1;
				for (uint32_t& sNode: stackNodes) {

					cout << sNode << endl;
				}
				cout << "enough lollygagging\n";

				uint32_t tID = temp.id;
				while (tID != 0) {
					cout << discovered[tID] << endl;
					tID = discovered[tID];

				}

				break;
			}
			else if (maze_[xInd-1][yInd].val == 1)  {
				//check if it's been encountered and queue accordingly. 
				if (!processed[maze_[xInd-1][yInd].id]) { 
					processed[maze_[xInd-1][yInd].id] = true; 
	//				stackNodes.push_back(maze_[xInd-1][yInd].id);
					discovered[maze_[xInd-1][yInd].id] = temp.id;
					unprocessed.push_back(maze_[xInd-1][yInd]);
					cout << "pushing node:  " << boost::lexical_cast<string>(maze_[xInd-1][yInd].id) << 
						" from node " << boost::lexical_cast<string>(maze_[xInd][yInd].id) << " left " << endl;
					numPaths++;
					
				} 
			}
		}
		if (yInd < (maxY-1) ) { // can look down./if its our target...
			if ( temp.id == goal_ ) {
				//return the corresponding path stack TODO: [ ] determine tracking system for various paths. 
				cout << "I think the shortest path is [ asdf] : " << endl;
				int tDec = 1;
				for (uint32_t& sNode: stackNodes) {

					cout << sNode << endl;
				}
				cout << "enough lollygagging\n";

				uint32_t tID = temp.id;
				while (tID != 0) {
					cout << discovered[tID] << endl;
					tID = discovered[tID];

				}

				break;

			}
			else if (maze_[xInd][yInd+1].val == 1)  {
				//check if it's been encountered and queue accordingly. 
				if (!processed[maze_[xInd][yInd+1].id]) { 
					processed[maze_[xInd][yInd+1].id] = true; 
					//stackNodes.push_back(maze_[xInd][yInd+1].id);
					discovered[maze_[xInd][yInd+1].id] = temp.id;
					unprocessed.push_back(maze_[xInd][yInd+1]);
					cout << "pushing node: " << boost::lexical_cast<string>(maze_[xInd][yInd+1].id) << 
						" from node " << boost::lexical_cast<string>(maze_[xInd][yInd].id) << " down " << endl;
					numPaths++;
				} 
			} 
		
		}
		if (yInd > 0) { // can look up. 
			if ( temp.id == goal_ ) {
				//return the corresponding path stack TODO: [ ] determine tracking system for various paths. 
				cout << "I think the shortest path is [ asdf] : " << endl;
				int tDec = 1;
				for (uint32_t& sNode: stackNodes) {

					cout << sNode << endl;
				}
				cout << "enough lollygagging\n";

				uint32_t tID = temp.id;
				while (tID != 0) {
					cout << discovered[tID] << endl;
					tID = discovered[tID];

				}

				break;
			}
			else if (maze_[xInd][yInd-1].val == 1)  {
				//check if it's been encountered and queue accordingly. 
				if (!processed[maze_[xInd][yInd-1].id]) { 
					processed[maze_[xInd][yInd-1].id] = true; 
					unprocessed.push_back(maze_[xInd][yInd-1]);
	//				stackNodes.push_back(maze_[xInd][yInd-1].id);
					discovered[maze_[xInd][yInd-1].id] = temp.id;
					cout << "pushing node: " << boost::lexical_cast<string>(maze_[xInd][yInd-1].id) << endl;
					numPaths++;
				} 
			} 

		}
		if (xInd < (maxX-1) ) { // can look right.
		
				if ( temp.id == goal_ ) {
				//return the corresponding path stack TODO: [ ] determine tracking system for various paths. 
				cout << "I think the shortest path is [ asdf] : " << endl;
				int tDec = 1;
				for (uint32_t& sNode: stackNodes) {

					cout << sNode << endl;
				}
				cout << "enough lollygagging\n";

				uint32_t tID = temp.id;
				while (tID != 0) {
					cout << discovered[tID] << endl;
					tID = discovered[tID];

				}

				break;
			}
			
			else if (maze_[xInd+1][yInd].val == 1)  {
				
				//check if it's been encountered and queue accordingly. 
				if (!processed[maze_[xInd+1][yInd].id]) { 
					processed[maze_[xInd+1][yInd].id] = true; 
					unprocessed.push_back(maze_[xInd+1][yInd]);
	//				stackNodes.push_back(maze_[xInd+1][yInd].id);
					discovered[maze_[xInd+1][yInd].id] = temp.id;
					cout << "pushing node: " << boost::lexical_cast<string>(maze_[xInd+1][yInd].id) <<
						" from node " << boost::lexical_cast<string>(maze_[xInd][yInd].id) << " right " << endl;
					numPaths++;
				} 
			} 
		}
		++unProcIndex;
	}

	return *(path);
}

int binSearch(vector<int> nums_, int target, int lB, int rB) {
	int pos;

	while ((rB - lB) > 1) {
		pos = (rB-lB) / 2 + lB; // the offset
		if (nums_[pos] == target ) return pos;
		else if ( nums_[pos] > target ) {
			rB--;	
		}
		else lB++;
	}

}

struct gNode{
	int val;
	vector<gNode*> eV;
	gNode(int i) : val(i) { }
};

void traverseGraph(gNode root) {
	map<int, bool> discovered;
	deque<gNode> toProcess;
	toProcess.push_back(root);
	discovered[root.val] = true;
	while (toProcess.size() >0) {
		root = toProcess.front();
		toProcess.pop_front();
		cout << "at node: " << root.val << endl;
		
		for (gNode* gN : root.eV) {
			if (!discovered[gN->val]) {
				toProcess.push_back(*(gN));
				discovered[gN->val] = true;
			}
		}
		
		
	}
}

void insert(int& count) {
	count++;
}
*/
//Kruskal's algorithm 6.1.2 Alg Des Man
//
struct kNode {
	int weight;
	char vertex;
};

class kGraph {
	protected:
	 	map<char, vector<kNode*>> edges;

	public: 
		kGraph();
		~kGraph();
		void insertEdge(char P, char C, int weight);
		void iterateEdges();
		vector<char> primAlgo(char spawn);
	
};

kGraph::kGraph() {
	edges = *(new map<char, vector<kNode*>>);
}
kGraph::~kGraph(){

//	delete *edges;
}
void kGraph::insertEdge(char P, char C, int weight) {
	kNode * temp = new kNode();
	temp->weight = weight;
	temp->vertex = C;
	edges[P].push_back(temp);
	temp = new kNode();
	temp->weight = weight;
	temp->vertex = P;
	edges[C].push_back(temp);
}

void kGraph::iterateEdges() {
	for (map<char, vector<kNode*>>::iterator it = edges.begin(); it != edges.end(); it++) {
		cout << it->first << " connects with these nodes:\n";
		for (kNode* n : it->second) {
			cout << "Node - " << n->vertex << " Edge weight: " << n->weight << endl;
		}
	}
}

/*
 * The prim algorithm for defining minimum spanning trees is a greedy algorithm
 * Traversing a graph, building the tree, each new path is selected by the cheapes local edge leading to an undiscovered edge.
 */

vector<char> kGraph::primAlgo(char spawn) {
	//map<char, vector<kNode*>>::iterator it;
	vector<char> disc; 
	disc.push_back(spawn);
	int numKeys = edges.size();
	int lWeight;// 'local weight'. 
	char nNode;
	int iterations; 
	int totalW = 0;
	// robustness measure, the spawn and subsequent traversal may lead to a dead end, at which point, start from the original spawn and just go the other way. 
	char start = spawn;
	while (numKeys > disc.size()){
		
		lWeight = INT_MAX;
		if ( iterations == numKeys ) {
			spawn =  start; //robustness measure
			iterations = 0;//incase it happens again lol. 
		}

		for (kNode* e : edges[spawn]) {
			if (e->weight < lWeight && 
				find(disc.begin(),disc.end(),e->vertex) == disc.end()) {
				nNode = e->vertex;
				lWeight = e->weight;	
		
			}
	
		}
		// robustness measure 
		if (lWeight!=INT_MAX ) { 
			disc.push_back(nNode);
			cout << spawn << " routes to " << nNode << " with weight " << lWeight << endl;
			spawn = nNode;
			totalW += lWeight;
		}
		iterations++;
	}
	cout << "traversal cost: " << totalW << endl;
	return disc;
}

void qSHelper(int arr[], int left, int right){
	int temp;
	if (right-left <=1) {
		return;
	}
	//select pivot value. [heuristically today, middle of posts. 	
	//move it to the front of this partition. 
	int pivot = arr[((right-left)/2) + left];
	arr[((right-left))/2 + left] = arr[left];
	arr[left] = pivot;
	int pInd = left;
	//iterate through partition and sort according to pivot value. 
	for (int i = left+1;i<=right; i++) {
		if (arr[i] < pivot) {
			//swap pivot with neighbor
			arr[pInd] = arr[pInd+1];
			arr[pInd+1] = pivot;
			//now switch the neighbor with the current val
			temp = arr[pInd];
			arr[pInd] = arr[i];
			arr[i] = temp;
			//iterate index, move on 
			pInd++;
		}
	}
	//test
	cout << "left values:\n";
	for (int i = left; i < pInd; i++) cout << arr[i] << endl;
	cout << "pivot value: " << pivot << endl;
	cout << "right values:\n";
	for (int i = pInd+1; i <= right; i++) cout << arr[i] << endl;
	//divide and conquer based on the pivot index.
	qSHelper(arr, left, pInd-1);
	qSHelper(arr, pInd+1, right);
	
}

// quick sort, array addition.

void qSort(int arr[], int length) {
	for (int i = 0; i < length; i++) cout << arr[i] << endl;
	qSHelper(arr, 0, length-1);

}

int atoi(string num_) {
	if (num_.size() <1) return 0; 
	bool neg = false;
	if (num_.at(0) == '-') neg = true;
	int val = 0;
	for (int i = 1; i < num_.size(); i++) {
		val *=10;
		val += (int)num_.at(i);
		
	}
	if (neg) return -1*val;
	return val; 
}

void reverseWords(string& phrase) {
	istringstream myS(phrase);
	string temp;
	string ans = "";
	while(myS) {
		myS >> temp;
		cout << temp << endl;
		ans = temp + " " + ans;
	}
	phrase = ans;
}

bool isSub(string one, string two)  {
	if (two.size() < one.size()) return false;
	for (int i = 0; i < two.size()-one.size(); i++) {
		if (one == two.substr(i,one.size() )) return true; 
	}
	return false;
}

int main() {
	if (isSub("bat", "batman")) cout << "bat is a substr of batman" << endl;
	else cout << "bat is not a substr of batman" << endl;
	if (isSub("tab", "tannery")) cout <<"tab is a substr of tannery" <<endl;
	else cout << "tab is not a substr of tannery" << endl;
	cout << atoi("-12345") << endl;
	string oc = "MC Sucker Has to Pay";
	cout << oc << endl;
	reverseWords(oc);
	cout << oc << endl;
/*
	int Arr[10] = {5,26,73,85,12,4,7,10,3,2};
	int val;
	int l = end(Arr)-begin(Arr);
	for (int i = 0; i < l; i++) {
		val = Arr[i];
		cout << "val: " << val << endl;
	}
	qSort(Arr, l);
	cout << "after qsort" << endl;
	for (int i = 0; i < end(Arr)-begin(Arr); i++) {
		val = Arr[i];
		cout << "val: " << val << endl;
	}
*/
/*
	kGraph myKG = kGraph();
	myKG.insertEdge('a', 'b', 5);
	myKG.insertEdge('a', 'd', 4);
	myKG.insertEdge('a', 'i', 9);
	myKG.insertEdge('b', 'd', 3);
	myKG.insertEdge('g', 'd', 6);
	myKG.insertEdge('g', 'e', 6);
	myKG.insertEdge('d', 'e', 4);
	myKG.insertEdge('i', 'g', 2);
	myKG.insertEdge('i', 'j', 1);
	myKG.insertEdge('j', 'h', 4);
	myKG.insertEdge('h', 'g', 3);
	myKG.insertEdge('h', 'f', 11);
	myKG.insertEdge('f', 'c', 2);
	myKG.insertEdge('b', 'c', 3);
	myKG.insertEdge('c', 'e', 2);
	myKG.insertEdge('e', 'f', 8);
	myKG.insertEdge('h', 'e', 7);
	myKG.insertEdge('j', 'g', 2);
	myKG.insertEdge('e', 'b', 1);
	myKG.iterateEdges();
	myKG.primAlgo('c');
//another graph rep. paradigm - map<char, vector<nodes> Edges, Nodes retain weight and node name. 
*/
/*
	int test[10] = {};
	for (int i = 0; i < 10; i++) {
		cout << test[i] << endl;
	}
	int count = 0;
	insert(count);
	cout << count << endl;
	insert(count);
	cout << count << endl;
	
	gNode A(1);
	gNode B(2);
	gNode C(3);
	gNode D(4);
	gNode E(5);
	A.eV.push_back(&B);
	D.eV.push_back(&E);
	B.eV.push_back(&C);
	C.eV.push_back(&D);
		
	traverseGraph(A);

*/
/*
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	
	cout << binSearch(nums, 6, 0, nums.size()-1);	
*/
	//see REF: mazeNode
	//given an input of 0's and 1's defining a maze structre and a root of id=0 and GOAL of id=rand, find the shortest path to goal. 
	
	/* 1's are passable, 0's are not. 
 *	[1 1 1 0 0 1 0
 *	 1 1 0 1 1 1 0
 *	 1 1 1 1 0 1 1
 *	 1 1 0 0 0 0 1] start = 0, test goal = 28
 *
 *	return the inorder shortest path in any data structure. 
 * */

/*
	mazeNode maze[7][4];
	string mazeInit = "1110010110111011110111100001";
	uint32_t xInd, yInd, currentVal;
	xInd = yInd = currentVal = 0;
	uint32_t maxX, maxY; 
	maxX = 6;
	maxY = 4;
	
	while (mazeInit.size() > 0) {
		if (xInd > maxX)  {
			xInd = 0;
			++yInd; //preincrement is fastr than postincrement 
		}
		// populate your maze data Structure. 
		maze[xInd][yInd] = mazeNode();
		maze[xInd][yInd].id = currentVal;
		maze[xInd][yInd].val = boost::lexical_cast<uint32_t>(mazeInit.at(0));
		mazeInit = mazeInit.substr(1);
		++currentVal;
		++xInd;
	}
*/
/*
	for (uint32_t x = 0; x < maxX; x++) {
	
		for (uint32_t y = 0; y < maxY; y++) {
			cout << boost::lexical_cast<string>(maze[x][y].id) << " => " << boost::lexical_cast<string>(maze[x][y].val) << endl;
		}
	}
	vector<uint32_t> answer = solveMaze(maze, 27);
	for (uint32_t& path: answer) {
		cout << boost::lexical_cast<string>(path) << endl;
	}
	*/
/*
	try{ 
		derived * der = new derived();
		throw der;
	}
	catch(Base * ) { cout << "caught pBase\n";}
	catch(derived * ) { cout << "caught pDere\n";}
*/
/*
	int i = 5;
	for (int i =0; i < 10; i++) cout << i << endl;

	cout << i << endl;
*/
/*
	vector<int> numbers;
	numbers.push_back(55);
	numbers.push_back(37);
	numbers.push_back(87);
	numbers.push_back(1);
	sort(numbers.begin(), numbers.end(), greater<int>());
	for(int& number : numbers){
	cout << number << endl;
	}
*/
	//foobar2 * fb3 = new foo;
/*
	int i;
	try { foo(); }
	catch(double e) {i = 3;}
	catch(int e) {i = 4;}
	catch(bool e) {i = 5;}
	cout << i << endl;
*/
/*A: reference to n is ambiguous
	n = 5; 
	return 0;
*/
/*
	Foo f1('a');
	Foo f2('a' + 1);
	Foo f3(1);
	Foo f4(0x01);
*/
/*
//implement a dictionary of wordcounts for a given array of strings, to permit rapid lookup O(1) average of any query. 
	string words[] = {"cat", "dog", "bear", "cat", "beet", "dog", "beaver", "griffon", "dog"};
	unordered_map<string, int> dict = createDict(words, 9);
	for (auto& row: dict) {
		cout << "word: " << row.first << " frequency: " << row.second << endl;
	}
*/
// Given stock prices and ability to buy and sell one share at any one time, optimize returns. no commission requirements.
/*
	vector<uint32_t> GOOG;
	GOOG.push_back(55);
	GOOG.push_back(58);
	GOOG.push_back(60);
	GOOG.push_back(55);
	GOOG.push_back(58);
	GOOG.push_back(60);
	GOOG.push_back(55);
	GOOG.push_back(58);
	GOOG.push_back(60);
	GOOG.push_back(65);
	GOOG.push_back(85);
	uint32_t currentPoint = 0;
	uint32_t scoutPoint = 1;//scout point shoud always be ahead. 
	bool invested = false;
	uint32_t profit = 0;
	
	while (scoutPoint < GOOG.size()) {
		if (!invested) { 
		    if ( GOOG[scoutPoint] > GOOG[currentPoint] ) {
				//BUY ORDER
				currentPoint = scoutPoint-1;
				cout << "buy at: " << boost::lexical_cast<string>(GOOG[currentPoint]);
				invested = true;
				scoutPoint++;
			}
		    else {//price is dropping, do not buy because we are waiting for a buy price. 
				while (GOOG[scoutPoint] > GOOG[scoutPoint+1] && (scoutPoint + 1) < GOOG.size()) {
					scoutPoint++;
				//traverse the order until we see a viable place to by. 
				}
				if (scoutPoint < GOOG.size() - 1 )  { // we have a valid buy point. 
					invested = true;
					currentPoint = scoutPoint;
					scoutPoint++;
					cout << "buy at: " << boost::lexical_cast<string>(GOOG[currentPoint]);
				}
			}
		}
		else { //detect the maxima. 
			 while ((scoutPoint + 1) < GOOG.size() && GOOG[scoutPoint] < GOOG[scoutPoint+1]) {
				scoutPoint++;	
			 }
			 profit += (GOOG[scoutPoint] - GOOG[currentPoint]);
			cout << "sale at: " << GOOG[scoutPoint] << endl;
			cout << "capgains earned this transaction: " << (GOOG[scoutPoint] - GOOG[currentPoint]) << endl;
			currentPoint = scoutPoint;
			scoutPoint++;
			invested = false;

		}
	}
	cout << "total profit earned this cycle: " << profit << endl;
*/
/*
	PTNode head;
	insertWord(head, "hello");
	insertWord(head, "hell");
	insertWord(head, "candy");
	insertWord(head, "candidate");
	traverseTree(head, "");
	string cand = "aaaabbbeeeeetttt";
	string comCand = compressString(cand);
	string dCand = expandString(comCand);
	cout << cand + " => " << comCand << " decompresses to => " << dCand << endl;
	cand = "aaddaabbbebbghjeeeetttt";
	comCand = compressString(cand);
	dCand = expandString(comCand);
	
	cout << cand + " => " << comCand << " decompresses to => " << dCand << endl;
	*/
	/*
	// write a function that counts the number of trailing zeros in n-factorial
	// yea I over though this, should have just used math from the beginning. 
	//first, lets calc. n!
	
	uint32_t factCand = 10;
	uint32_t fact = calcFact(factCand);
	cout << "factorial of " << factCand << " is " << fact << endl;
	 
	uint32_t numZeros = 0;
	
	while (fact % 10 == 0) {
		numZeros++;
		fact/=10;

	}
	numZeros;
	cout << "number of trailing zeros" << numZeros << endl;
	*/
	/*// convert to string abandoning the string approach
	string fs = boost::lexical_cast<string>(fact);
	cout << "As string: " << fs << endl;
	uint32_t numTrailingZeros = fs.size() - fs.find_last_of("0");
	cout << "number of trailing zeros: " << numTrailingZeros << endl;
	//uint32_t numTrailingZeros = distance((string::find_last_of(fs, "0")), fs.end());
	//cout << " number of trailing zeros: " << numTrailingZeros << endl;
	*/
	/*
	//test cases 
	vector<string> gameStates;
	

	// simple test cases - todo[ ] finish for verticals but it's good for reveiw purposes .
	gameStates.push_back("111020020");
	gameStates.push_back("000000000");
	gameStates.push_back("222010010");
	gameStates.push_back("120010021");
	gameStates.push_back("120120100");
	for (auto& game : gameStates) {

		if (winnerTTT(game))  {
			cout << "winner with string" << game << endl;
		}
		else {
			cout << "loser with string" << game << endl;

		}

	}
	*/
	// develope a function to determine if there is a winner in a game of tic-tac-toe
	/*
	// swap a number without a temp variable. est. Time taken...3 minutes
	uint32_t varA = 10;
	uint32_t varB = 20;
	cout << "before swap: " << varA << " " << varB <<endl;
	swap(varA, varB);
	cout << "after swap: " << varA << " " << varB <<endl;
	*/

/*
	for (int ii = 0; ii < 3; ++ ii) {

		switch(ii){
		case 0: cout << "ZERO";
		case 1: cout << "ONE"; continue;
		case 2: cout << "TWO"; break;
}
	cout << endl;
	}
*/
/*
	int myints[] = {1,2,3,4,5,4,3,2,1};
	vector<int> v(myints, myints+9);
	sort(v.begin(), v.end());
	cout << (binary_search(v.begin(), v.end(), 3)) << endl;
*/
/*


	list<int> L;
	list<int>::iterator it;

	L.push_back(10);
	L.push_back(25);
	L.push_back(40);
	it = L.end();
	L.push_back(55);
	L.insert(it, 30);
	L.push_front(15);
	L.sort(greater<int>());
	it= find_if(L.begin(), L.end(), bind2nd(less<int>(), 40));
	cout << *it << endl;

*/
/*
 	vector<string> strVec;
	strVec.push_back("foo");
	strVec.push_back("bar");
	strVec.push_back("baz");
	strVec.push_back("bee");

	cout << count_if(strVec.begin(), strVec.end(), bind2nd(greater<string>(), "baz"));
	*/
//A a2(a1);
	
/* TODO [ ] read this and figure it out
	vector<int> v;
	for (int i =0; i < 5; ++i) v.push_back(i);
		v.erase(find(v.rbegin(), v.rend(), 2).base());
		v.insert(find(v.rbegin(), v.rend(), 1).base(),10);
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));*/
	
	
/*
	int myints[] = {1, 2,3,4,5,4,3,2,1};	
	vector<int> v(myints, myints+9);
	sort(v.begin(),v.end());
	cout << (binary_search(v.begin(),v.end(), 3)) <<endl;
*/	

	/*
	vector<string> strVec;
	strVec.push_back("foo");
	strVec.push_back("flip");
	strVec.push_back("Baz");
	cout << count_if(
		strVec.begin(),
		strVec.end(),
		bind2nd(greater<string>(), "Baz")
	);*/
	/*
	const int * cp;

	int y1, m1, d1, y2, m2, d2;
	y1 = 2008; 
	m1 = 1;
	d1 = 15;
	y2 = 2010;
	m2 = 5;
	d2 = 26;

	// goal is to efficiently calculate the number of days between two given dates. 

	// strategy: shave off the edges of the dates to normalize to 1-1, eg the number of days remaining in y1 and y2 then just add 365 * deltayears. 
	
	// baseline number of years * 365; assuming no leap years - 
	
	int numDays = 0;
	
	numDays += ((y2-1) - y1)*365;//addleap year functionality using modulo operator. 
	
	// add leapyear functionality later. 
	//now - calculate numyears int ending year.
	
	numDays += d2; //days elapsed in end date. 

	//add days in the month 
		for (int i = 1; i < m2; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
				numDays += 31;
			}
			else if (i == 2) {
				if (y2 % 4 == 0) { numDays += 29; }
				else {
					numDays += 28;	
				}
			}
			else {
				numDays += 30;
			}

		}
	

	// repeat proceducre for beginning edge, but tweak algorithms for the fact that "extra days" are at the end of the calender.
	// can't just add numDays because depending on which month, the value may change. 
	bool firstMonth = true;
	for (int i = m1; i <=12; i++) {
		if (i == 1 || i ==3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {

			if (firstMonth) {
				firstMonth = false;
				numDays += (31 - d1);
			}
			else {
				numDays += 31;
			}

		}
		else if (i == 2) {
			if (firstMonth) {
				firstMonth = false;
				if (y1 % 4 == 0) { numDays += (29 -d1); }
				else {
					numDays += (28 - d1);
				}
			}
			else {
				if (y1 % 4 == 0) {
					cout << y1 << "is a leap year!" << endl;
					numDays += 29;
				}
				else { 
					numDays += 28;
				}
			}
		}
		else {
			if (firstMonth) {
				firstMonth = false;
				numDays += (30  - d1);
			}
			else {
				numDays += 30;
			}
		}
	}
	
	cout << "number of days between: " << d1 << "-" << m1 << "-" << y1 << endl;
	cout << "and " << endl;
	cout << "                        " << d2 << "-" << m2 << "-" << y2 << endl;
	cout << numDays << endl;

	*/





	// suppose you are given two arrays of departures and arrivals for an airport where all planes are not native to the airport.
	// what is the maximum number of ramps needed?

	// sort - then find. sort costs logN (provided it's a quicksort) 
	// traverse afterwards through data costs N
	// total operation costs NlogN
/*
	int32_t * arrivals = new int32_t[10];
	int32_t * departures = new int32_t[10];
	arrivals[0] = 800;
	arrivals[1] = 1000;
	arrivals[2] = 700;
	arrivals[3] = 2100;
	arrivals[4] = 2200;
	arrivals[5] = 1700;
	arrivals[6] = 1430;
	arrivals[7] = 1730;
	arrivals[8] = 1920;
	arrivals[9] = 2300;
	
	departures[0] = 2330;
	departures[1] = 1100;
	departures[2] = 800;
	departures[3] = 1300;
	departures[4] = 2200;
	departures[5] = 2300;
	departures[6] = 1800;
	departures[7] = 1930;
	departures[8] = 1950;
	departures[9] = 2000;

	cout << "known flight arrivals/departures unsorted\n";
	for (int i = 0; i < 10; i++) {
		cout << "arrival: " << arrivals[i] << endl;
		cout << "departure: " << departures[i] << endl;
	}	

	cout << "know flight arrivals/departures sorted\n";
	sort(arrivals, arrivals + 10);
	sort(departures, departures + 10);

	for (int i = 0; i < 10; i++) {
		cout << "arrival: " << arrivals[i] << endl;
		cout << "departures: " << departures[i] << endl;
	}

	cout << "now determining ramps needed\n";
	uint32_t ramps = 0;
	uint32_t maxRamps = 0;
	uint32_t arrInd, depInd;
	arrInd = depInd = 0;
	while (arrInd + depInd < 20) {
		if (arrivals[arrInd] <= departures[depInd] && arrInd < 10) {
			ramps++;
			arrInd++;
			if (maxRamps < ramps) { maxRamps = ramps;}
		}
		else {
			ramps--;
			depInd++;
		} 
		cout << "currently using this many ramps: " << ramps << endl;
	}

	cout << "max ramps needed: " << maxRamps << endl;
	
	cout << "input integer value please " << endl;
	cin >> a;
	
	cout << "your int32_t value is: " << a << endl;

	vector<int32_t> * intVect = new vector<int32_t>();
	cout << "constructing a vector of int32_t's, please input three values\n";

	for (int i = 0 ; i < 3; i++) {
		//separated to two lines for readability. 
		cin >> a;
		intVect->push_back(a);

	}
	//int32_t current;
	for (auto &current : *intVect) {
		cout << current << endl;
	}
	
	cout << "current size of the vector is: " << intVect->size() << endl;
	cout << "popping values off the back because vector is not a queue\n" ;

	for (int i = 0 ; i < 3; i++) {
		cout << intVect->back() << endl;
		intVect->pop_back();
	}
	cout << "current size of the vector is: " << intVect->size() << endl;


	cout << "input three numbers into a queue now please: \n" ;
	deque<uint32_t> * myQ = new deque<uint32_t>();
	for (int i = 0; i < 3; i++) {
		cin >> a;
		myQ->push_back(a);
	}

	cout <<"popping off the front now: " << endl;

	for (int i = 0 ; i < 3; i++) {
		cout << myQ->front() << endl;
		myQ->pop_front();
	}	
	*/
	return 0;


}
