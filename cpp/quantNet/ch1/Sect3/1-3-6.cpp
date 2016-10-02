/*
Title: Level 1, S 3, Ex 6
Author: Rob Rivera
Date: 9/10/2016
Write a c-program that shifts any number two places to the right. Input should be an integer. Output should be the shifted result, <b>as well as output an indication of whether a logical or arithmetic shift is performed</b> (if a 1 or 0 shifted in at the left side) for the inputted number. For more infor and example, see http://wn.wikipedia.org/wiki/Logical_shift
*/
#include <stdio.h>

int main() {
	//prompt user for input. 
	printf("to demonstrate right bitshift operator, please type an integer and press 'Enter' key:\n");

	// init int value. 
	unsigned int value = 0;
	signed sValue = 0;
	scanf("%d", &sValue);
	value = sValue;
	printf("current number: %d\n", value);
	
	//perform bit operations.

	value = value >> 2;
	printf("logical shift right x2: %d\n", value);
	sValue = sValue >>2;
	printf("arithmetic shift right x2: %d\n", sValue);
	return 0;
}
