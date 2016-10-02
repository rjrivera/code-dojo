/*
Title: freq.c (Level 1, S 4, Ex 6)
Author: Rob Rivera
Date: 9/12/2016
*/

#include <stdio.h>
#include <string.h>

int main() {
	printf("please provide text input for processing\n");

	int zero, one, two, three, four, xChars, input;
	zero = one = two = three = four = xChars = input = 0;
	char * numThree= "two";
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
	
	switch(three) {
		case 0:
			numThree = "zero\0";
			break;
		case 1: 
			numThree = "one\0";
			break;
		default:
			//NOP initialized on line 14
			break;
	}
				
	if (three < 3) {	
		printf("\nzero: %d\none: %d\ntwo: %d\nnumber three is shown %s times\nfour%d\nother charactrs: %d\n", zero, one, two, numThree, four, xChars);
	}
	else {
		printf("\nzero: %d\none: %d\ntwo: %d\nnumber three is shown more than %s times\nfour%d\nother characters: %d\n", zero, one, two, numThree, four, xChars);
	}

	
}
