/*
Title: Level 1, S 3, Ex 5
Author: Rob Rivera
Date: 9/10/2016
Create a C-program that clearly shows the difference between --i and i--
*/
#include <stdio.h>

int main() {
	//prompt user for input. 
	printf("to demonstrate the pre/post decrement operator, plese enter a number followed by the 'Enter' key\n");

	// init int value. 
	int value = 0;
	scanf("%d", &value);
	
	printf("current number: %d\n", value);
	
	//Predecrementing value while an argument of printf function. expect the number to remain the same. 
	printf("predecrement: %d\n", --value);
	printf("number after operation: %d\n", value);
	printf("postdecrement: %d\n", value++);
	printf("number after operation: %d\n", value);

	return 0;
}
