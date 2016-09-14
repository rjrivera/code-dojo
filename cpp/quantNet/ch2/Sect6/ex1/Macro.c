/*
Title: Level 2, S 6, Ex 1
Author: Rob Rivera
Date: 9/14/2016

Write a C-program that contains two print macro calls. THe firt prints the variable a, the second prints the variables a and b. Printing happens by the use of the PRINT1 and PRINT2 macros that accept arguments These macros must b defined in an include-file. 
the variables a and b gets their value in the function main().

Name the program "Macro.c" and the include-file "Defs.h" Don't forget to implement the mechanism to avoid multiple inclusion of the header file.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Defs.h"



int main() {

	int a, b;
	a = b = 1;

	PRINT1(a);
	PRINT2(a, b);
	return 0;
}
