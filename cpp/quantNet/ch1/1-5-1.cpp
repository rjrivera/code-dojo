/*
Title: freq.c (Level 1, S 5, Ex 1)
Author: Rob Rivera
Date: 9/12/2016
Write a C-program that calls a function minus(). this function receives two arguments and returns the difference (regular subtraction, not absolut). This difference should be printed on screen)
*/

#include <stdio.h>

int minus(int argone_, int argtwo_) {
	return (argone_ - argtwo_);
}

int main() {
	//ADMIN ONLY CHANGE CONSTANTS
	const int ARGONE = 5;
	const int ARGTWO = 10;

	printf("\nargone: %d\nargtwo: %d\n difference: %d\n", ARGONE, ARGTWO, minus(ARGONE, ARGTWO));

	return 0;
	
}
