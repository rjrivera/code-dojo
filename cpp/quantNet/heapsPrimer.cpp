#include <vector>
#include <iostream>
#include <climits>
/****
 *	a from-scratch implementation of a heap - 4 jan 2017
 *	purpose is to test my understanding of the data structure and algorithms to properly leverage that data structure. 
 *	todo[x] redefine the push operation to search the pStack and the parent tree for proper insertion. 
 *	solution: simple fix, just be sure to check the ranges from bottom-up in the pStack vector and only the parent if it
 *	isn't appropriate to insert in any subtrees. 
 *
 *	overall - takes a little cleverness and ingenuity, but this permits rapid pop and reduces the cost of reshuffling the heap 
 *	this entire excercise was motivated from my amazon interview experience. 
 *
 *
 */


using namespace std;

//no generic yet, just do double. 
struct hNode{
	double data;
	hNode * lN;
	hNode * rN;
	hNode(double init_):data(init_){}
	hNode():data(0){}
};

class maxHeap{
	private:
		hNode * parent;	
		vector<hNode*> pStack;
		int nNodes;

		// push_helper provides the "heavy lifting" of the push function. 
		// abstracted to helper to improve readability and modularity. 
		void push_helper(hNode * curNode, double val_) {
			if (curNode == nullptr)  {
				curNode =  new hNode(val_);
				nNodes++;
				return;
			}
			if (val_ == curNode->data) {
				cout << "value: " << val_ << " is already in max heap\n";
				nNodes--;//nNodes is incremented every init call to push_helper, dec at repeat value. 
				return;	
			}
			if (val_> curNode->data) {
				//found our location - begin rearranging the true.
				// 1 - create  a new node
				hNode * temp = new hNode(val_);
				// right node is the old parent by def. (if rN.data > lN.data)
				temp->rN = parent;
				temp->lN = parent->rN;
				// clean old parent's children appropriately.
				parent->rN = parent->lN;
				parent->lN = nullptr;
				// now redefine the parent since all maniluplations are done.
				parent = temp;
			}
			//are we at a right leaf?
			else if (curNode->rN == nullptr) {
				hNode * temp = new hNode(val_);
				curNode->rN = temp;
				return;
			}
			else if (val_>=parent->lN->data) push_helper(curNode->rN, val_);
			// are we at a left leaf?
			else if (curNode->lN == nullptr)  {
				hNode * temp = new hNode(val_);
				curNode->lN  = temp;
				return;	
				
			}
			else push_helper(curNode->lN, val_);

		}

		void traverse_helper(hNode * curNode){
			if (curNode==nullptr)  return;
			traverse_helper(curNode->lN);
			traverse_helper(curNode->rN);
			cout << curNode->data << endl;
			return;
		}
		
	public:
		maxHeap() :parent(new hNode()), nNodes(0){}
		maxHeap(double seed) : parent(new hNode()), nNodes(1){}
		
		void push(double val_) {
			if (parent==nullptr)  {
				parent = new hNode(val_);
				nNodes++;
				return;
			}
			//base case - fulfill the parent node requirement.
			if (nNodes==0)  {
				parent->data = val_;
				nNodes++;
				return;
			}
			//else - proceed to traverse the max heap 
			for(int i = 0; i < pStack.size(); i++) {
				if (val_ < pStack[i]->data) {
					push_helper(pStack[i], val_);
					nNodes++;
					return;
				}
			}
			push_helper(parent, val_); 
			nNodes++;

		}

		double pop() { //a different approach to maxHeap rebalancing using a stack of subTrees. 
			cout << "pop debug data:\n" <<
				"parent-> data: " << parent->data << 
				"nNodes: " << nNodes << endl;
			if (nNodes > 0 ) { 
					double val = parent->data;
					
					// we don't want to allow a nullptr in our pstack.
					if (parent->lN != nullptr) pStack.push_back(parent->lN);			
					parent = parent->rN;
					nNodes--;
					//if our current parent tree is done, redefine from vector of subtrees. 
					if (parent == nullptr && nNodes>0)  {
						parent = pStack.back();
						pStack.pop_back();
					}
					return val;

				
			}
			else cout << "Empty heap\n";

			return 0;

		}

		int size() const{
			return nNodes;

		}
	
		void print() {
			for (int i = 0; i < pStack.size(); i++) traverse_helper(pStack[i]);
			traverse_helper(parent);
			
			return;
		}
		
		double top() {
			if (nNodes >0) return parent->data;
			cout << "empty heap\n";
			return INT_MIN;
		}
};



int main( int argc, char** argv ) {

	cout << "pushing 5 test values into the development heap\n";
	maxHeap myHeap;
	// test batch
	myHeap.push(5);
	myHeap.push(17);
	myHeap.push(25);
	myHeap.push(6);
	myHeap.push(2);


	int currentSize = myHeap.size();
	cout << "current number of elements in heap " << myHeap.size() << endl;
	int curVal = 0;
	
	cout << "traversing heap, bottom up\n";
	myHeap.print();
	//testing post 'pop' insertion of new values using the pStack
	cout << "testing post 'pop' insertion of new values using the pStack" << endl;
	myHeap.pop();
	myHeap.pop();
	myHeap.push(7);
	myHeap.push(19);
	myHeap.print();
	currentSize = myHeap.size();
	for (int i = 0; i < currentSize; i++) {
		curVal = myHeap.pop();
		cout << "Pushing max value from heap: " << curVal << endl;
	}

	cout << "*************END BATCH TESTING ************************" << endl;
	
	return 0;
}
