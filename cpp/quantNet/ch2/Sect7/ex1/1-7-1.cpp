/*
Title: Level 2, S 7, Ex 1
Author: Rob Rivera
Date: 9/14/2016

Try to create a function Swap(). this function must exchange the value of two variables. for example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has been called. The variables i and j are declared, initialised and printed in the functin main(). This problem can be solved by using pointers as arguments for the Swap() function
*/
#include <stdio.h>
#include <stdlib.h>

void Swap(int * a_, int * b_) {
	int tempInt = *a_;
	*a_ = *b_;
	*b_ = tempInt;
}

int main() {
	int i = 456;
	int j = 123;
	printf("before swap: i = %d , j = %d\n", i, j);

	Swap(&i, &j);
	
	printf("after swap: i = %d , j = %d\n", i, j);
	
	return 0;
}
