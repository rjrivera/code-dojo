#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdint.h>
#include <queue>
#include <deque>
//#include "print.h"
using namespace std;

typedef struct Node {
	int value;
	Node * next; 

};

typedef struct tNode {
	int value;
	tNode * l;
	tNode * r;

};

void push_back(Node * nptr_, Node * target_) {
	if (target_->next == NULL) {
		target_->next = nptr_;
	}
	else {
		push_back(nptr_, target_->next);
	}
	
}

void traverse(Node * target_) {
	if (target_->next == NULL) {
		cout << target_->value << endl;
	}
	else {
		cout << target_->value << endl;
		traverse(target_->next);
	}

}

void dfs(tNode * head_){
	if (head_->l == NULL) {
		cout << head_->value << endl;
	}
	else {
		dfs(head_->l);
		dfs(head_->r);
		cout << head_->value << endl;	
	}
}

//bst only guarenteed if ordered. ie. no rebalancing done. 
void dumbInsert(tNode * leaf, tNode * cNode) {

	if (leaf->value <= cNode->value && cNode->l == NULL) {
		cNode->l = leaf;
	}
	else if (leaf->value > cNode->value && cNode->r == NULL) {
		cNode->r = leaf;	
	}

	else {
		if (leaf->value > cNode-> value) {
			dumbInsert(leaf, cNode->r);
		}
		else {
			dumbInsert(leaf, cNode->l);
		}
	}
}

int main() {

	tNode * head = new tNode();
	head->value = 10;
	tNode * n1 = new tNode();
	tNode * n2 = new tNode();
	tNode * n3 = new tNode();
	tNode * n4 = new tNode();
	tNode * n5 = new tNode();
	tNode * n6 = new tNode();
	tNode * n7 = new tNode();

	n1->value = 5;
	n2->value = 6;
	n3->value = 1;
	n4->value = 10;
	n5->value = 4;
	n6->value = 11;
	n7->value = 0;

	dumbInsert(n1, head);
	dumbInsert(n2, head);
	dumbInsert(n3, head);
	dumbInsert(n4, head);
	dumbInsert(n5, head);
	dumbInsert(n6, head);
	dumbInsert(n7, head);

	dfs(head);
	/*
	int num[] = { 3, 5, 8 ,2,4,8,10,15,37,28};
	int champ, champ2, temp;
	
	temp = champ = champ2 = 0;
	for (int i = 0; i < 10; i++) {
		if (num[i] > champ2) {
			champ2 = num[i];
		}
		if (champ2 > champ) {
			//swap value with temp value then bubble up new champ
			temp = champ;
			champ = champ2;
			champ2 = temp;
		}
		cout << "value " << i << ": " << num[i] << endl;
	}
	
	cout << "champ of list: " << champ << endl;
	cout << "runnerup: " << champ2 << endl;

	*/


	/* BEGIN LINKED LIST USING ABOVE DEFINITIONS. 	
	Node * head = new Node();
	head->value = 5;
	Node * ptr1 = new Node();
	ptr1->value = 1;
	Node * ptr2 = new Node();
	ptr2->value = 2;
	Node * ptr3 = new Node();
	ptr3->value = 3;

	// =========== END INITIALIZATIION PHASE OF PROGRAM.	

	//begin constructing a list. 
	push_back(ptr1, head);
	push_back(ptr2, head);
	push_back(ptr3, head);

	traverse(head);
	*/
	return 0;	
}
