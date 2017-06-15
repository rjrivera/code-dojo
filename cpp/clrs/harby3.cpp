#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct tN {

private:
	

public:

	int val;
	tN * lC;
	tN * rC;

	tN():val(0) { }
	tN(int val_): val(val_) { }

};

void insertVal(tN * root, int nVal){

	if (root->lC == nullptr && root->rC == nullptr )  {
		tN * nNode = new tN(nVal);
		if (nVal < root->val)  {
			root->lC = nNode;
			return;
		}
		else if (nVal > root->val ) root->rC = nNode;
		return;
	}
	if (nVal < root->val )  {
		if (root->lC == nullptr )  {
			tN * nNode = new tN(nVal);
			root->lC = nNode;
			return;
		}
		return insertVal(root->lC, nVal);

	}
	else if (nVal > root->val )  {
		if (root->rC == nullptr )  {
			tN * nNode = new tN(nVal);
			root->rC = nNode;
			return;
		}
		return insertVal(root->rC, nVal);

	}
	return;
}

void dfs(tN * root) {
	if (root == nullptr ) return; 
	dfs(root->lC);
	dfs(root->rC);
	cout << root->val << endl;

}

void bfs(tN * root) {

	if (root == nullptr ) return;
	cout << root->val << endl;
	bfs(root->lC);
	bfs(root->rC);

}

int main( int argc, char** argv ) {

	tN * myN = new tN(10);
	insertVal(myN, 5);
	insertVal(myN, 15);

	cout << "root -> " << myN->val << endl;
	cout << "root's left child -> " << myN->lC->val << endl;
	cout << "root's right child -> " << myN->rC->val << endl;
	
	dfs(myN);
	bfs(myN);

	return 0;
}
