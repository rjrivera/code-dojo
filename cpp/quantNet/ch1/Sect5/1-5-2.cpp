/*
Title: freq.c (Level 1, S 5, Ex 2)
Author: Rob Rivera
Date: 9/12/2016
Write a C-program that prints the factorials of a number.
*/

#include <stdio.h>

int factHelper(int * count_, int * value_) {
	if (*count_ == 0) {
		return *value_;
	}
	else {
		*value_ *= *count_;
		*count_ -= 1;
		return factHelper(count_, value_);
	}
}

int main() {
	printf("Harby's factorial widget\n______---------______\n");
	// ADMIN only adjust FACTORIAL. 
	const int FACTORIAL = 10;
	//main loop. 
	int count = FACTORIAL;
	int * fPtr = &count;
	int value = 1;
	value = factHelper(fPtr, &value);
	printf("the factorial value of %d is: %d\n", FACTORIAL, value);
	return 0;
}
