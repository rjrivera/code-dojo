/*
Title: Level 1, S 3, Ex 4
Author: Rob Rivera
Date: 9/10/2016
Create a C-program that uses the fact that 0 is interpreted as FALSE and non-zero is interpreted as TRUE. The C-program can be made easier to read when this 0 is assigned to a variable e.g. an int called married. Use the ?: operator to print if somepne is married or not. (see if you can use a single printf)
*/
#include <stdio.h>

int main() {
	int married = 2010;
	printf(((married)?("married"):("not married")));
	return 0;
}
