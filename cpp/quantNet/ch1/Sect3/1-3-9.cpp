/*
Title: Level 1, S 3, Ex 9
Author: Rob Rivera
Date: 9/10/2016
Predict what the following program prints on screen (provide a code file with comments stating the output for each line). 
*/

/* Conditional expressions */

#include <stdio.h>

int main() {
	int x, y, z;
	x = y = z= 1;

	x+=y+=x;//evaluates to 3 (right to left)
	//3\n\n
	printf("%d\n\n", (x<y)?y:x);
	//2\n
	printf("%d\n", (x<y)?x++:y++);
	//3\n
	printf("%d\n", x);
	//3\n
	printf("%d\n", y);
	return 0;

	
}
