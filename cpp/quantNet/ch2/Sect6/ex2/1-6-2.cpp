/*
Title: Level 2, S 6, Ex 2
Author: Rob Rivera
Date: 9/14/2016

Create the two macros MAX2(x, y) and MAX3(x,y,z) these macros must return the maximum value of the given arguments. Let the macro MAX3 make use of the macro MAX2. Add these macros to the file Defs.h.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Defs.h"

int main() {

	int a, b, c;
	a = b = 1;
	c = 4;

	printf("%d\n", MAX3(a,b,c));
	
	return 0;
}
