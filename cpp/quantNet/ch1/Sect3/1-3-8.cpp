/*
Title: Level 1, S 3, Ex 8
Author: Rob Rivera
Date: 9/10/2016
The following program uses assignement-operators. Predict what will be printed on screen (provide code file with comments). the ooperators + and == have a higher priority than the assignment-operators.
*/

/* Assignment operators */

#include <stdio.h>

int main() {
	// init int values
	int x=2;
	int y, z;

	x *= 3+2;
	// x=10\n
	printf("x=%d\n", x);

	x *=y=z=4;
	// x=40\n
	printf("x=%d\n", x);

	x=y==z;
	//x=1\n
	printf("x=%d\n", x);

	return 0;

	
}
