/*
Title: freq.c (Level 1, S 5, Ex 4)
Author: Rob Rivera
Date: 9/13/2016
Write a recursive function printnumer() which gets th number to be printed. This number is an integer. The function should print the number digit by digit by using the putchar() function. don't us printf(). 

Print.c contains the function print() which ca be called by main().
*/

#include <stdio.h>
#include <math.h>
//we will track the number of digits we encounter and when we begin outputting the digits, we decrement the value pointed to by value_ by the 10^digit_
void printnumber(int * value_, double * digit_) {
	//testing revealed negative values did not work.
	//this detects negative values, outputs the sign, then converts to a positive value for processing. 
	 if (*value_ < 0) {
		putchar('-');
		*value_ *= -1;
	}
	//if mod yields the same value as the dividend, then divisor is too big and we have found our leading digit. 
	if ((*value_ % ((int)pow(10, *digit_))) == *value_) {
		//lead digit, begin outputing. 
		*digit_ -= 1;
		int quotient = *value_/((int)(pow(10, *digit_)));
		putchar(quotient + '0');
		*value_ -= quotient * ((int)(pow(10, *digit_)));
		*digit_ -= 1;
	}
	else {
		//haven't found our lead digit, increment
		*digit_ +=1;
		//recursive call to find lead digit. 
		printnumber(value_, digit_);
		if (*digit_ >= 0) {
		int quotient = *value_ / ((int)(pow(10, *digit_)));
	
		putchar(quotient + '0');
		*value_ -= quotient * ((int)(pow(10, *digit_)));
		*digit_ -=1; 
		}
		
	}
	

}

int main() {
	
	int value = -8675309;
	double numDigits = 0;
	printnumber(&value, &numDigits);
	return 0;
}
