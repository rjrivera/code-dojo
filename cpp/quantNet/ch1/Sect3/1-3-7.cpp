/*
Title: Level 1, S 3, Ex 7
Author: Rob Rivera
Date: 9/10/2016
Write a C-program that efficiently multiplies a number by a factor 2 to the power n. The number too multiply and n are variables, which get a value at the start of the program.
Clue:
1 shift to the left is the same as multiplying by 2.
2 shifts to the left are the same as multiplying by 4.
3 shifts to the left are the same as multiplying by 8.
*/
#include <stdio.h>

int main() {
	// init int values
	int value, n;
	value = n = 0;

	//prompt user for input. 
	printf("to demonstrate bitwise multiplication, , please type an integer to multiply and press 'Enter' key:\n");
	scanf("%d", &value);
	
	printf("please enter a power of 2 to multiply the number by: \n");
	scanf("%d", &n);

	printf("echo: %d, %d\n", value, n);

	//note: operations can be done in one line
	// value = value << n; 
	// demonstrating with for-loop for instructional purposes. 
	for (int i = 1; i <= n; i ++) {
		value <<= 1;
		printf("Current value after %d powers of 2: %d\n", i, value);
	}
	
	//perform bit operations
	return 0;
}
