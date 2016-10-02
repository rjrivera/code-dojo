/*
Title: Level 1, S 3, Ex 2
Author: Rob Rivera
Date: 9/9/2016
In the following program various operators are used to assign a value to the variable x. In this example the string that is passed to printf() has the format specification %d. This decimal is passed to printf() as the second argument. the first argument of printf() must be a string. In this example the second argument is the variable x. 

Predict what will be printed on scream (via commented line) 
*/
#include <stdio.h>

int main() {
	int x;

	x = -3+4*5-6;
	// 11
	printf("x=%d\n", x);
	// 1
	x=3+4%5-6;
	printf("x=%d\n", x);
	// 0
	x=-3*4%-6/5;
	printf("x=%d\n", x);
	// 1
	x=(7+6)%5/2;
	printf("x=%d\n", x);

	return 0;
}
