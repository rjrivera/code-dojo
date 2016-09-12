/*
Title: freq.c (Level 1, S 4, Ex 6)
Author: Rob Rivera
Date: 9/12/2016
*/

#include <stdio.h>

int main() {
	printf("please provide text input for processing\n");

	int zero, one, two, three, four, xChars, input;
	zero = one = two = three = four = xChars = input = 0;
	
	while ((input=getchar()) != EOF) {
	
	switch (input) {
		
		case ('0') :
			zero++;
			break;
		
		case ('1') :
			one++;
			break;
		case ('2') :
			two++;
			break;
		case ('3') :
			three++;
			break;
		case ('4') :
			four++;
			break;
		default:
			xChars++;
			break;
		
		
	}
	}
	printf("\nzero: %d\none: %d\ntwo: %d\nthree%d\nfour%d\nother charactrs: %d\n", zero, one, two, three, four, xChars);
	return 0;

	
}
