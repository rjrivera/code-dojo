#include <iostream>

using namespace std;


struct lN {
public:
	int val;
	lN * next = nullptr;

};

bool detectCycle(lN * parent) {
	lN * tortoise = parent;
	lN * hare = parent;
	
	while(1) {
		cout << "tortoise val: " << tortoise->val;
		tortoise = tortoise->next;
		
		if (hare->next == nullptr) return false;
		hare = hare->next->next;
		if (hare == tortoise) return true;   
	}
	return true;
}

int main( int argc, char** argv ) {
	lN* node = new lN();
	node->val = -1;
	lN* par = node;
	lN* tail = par;
	//construct a valid linked list;
	for (int i = 0; i < 10; i++) {
		
		node = new lN();
		node->val = i;
		tail->next = node;
		tail = tail->next;
	}

	if (!detectCycle(par)) cout << "no cycle detected\n";
	else cout << "cycle detected\n";
	//introduce a cycle then retest.
	tail->next = par;
	if (detectCycle(par)) cout << "cycle detected\n";
	else cout << "no cycle detected\n";  
	

	return 0;
}
