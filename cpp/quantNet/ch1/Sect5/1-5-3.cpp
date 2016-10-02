/*
Title: freq.c (Level 1, S 5, Ex 3)
Author: Rob Rivera
Date: 9/12/2016
Write a C-program that consists of two source-files. The first( Main.c) contains the main() function and gives the variable ia value. the second source-file (print.c) multiplies i by 2 and prints it. 

Print.c contains the function print() which ca be called by main().
*/

#include <stdio.h>
#include "print.h"

int main() {
	
	const int i = 5;
	printf("value i provided: %d\n", i);
	mult2Print(i);
	return 0;
}
