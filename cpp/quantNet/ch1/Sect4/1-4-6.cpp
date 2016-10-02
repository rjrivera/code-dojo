/*
Title: freq.c (Level 1, S 4, Ex 6)
Author: Rob Rivera
Date: 9/12/2016
Write a C-program that counts how many times each of the numbers 0-4 have been typed. Use a switch-case construction. Use default to count the number of other characters. the input will be halted with ^Z (EOF) 
print the amount of times a certain number has been typed

name the program freq.c
*/
#include <stdio.h>

int main() {
	
	printf("|~~~~~Harby's Temperature Widget 3000~~~~~|\n");
	//WARNING: Admin adjust constants ONLY
	//===========================
	const int startTemp = 0;
	const int endTemp = 19;
	const int step = 1;
	//===========================

	float C =(float) startTemp;
	float F = C*9/5 + 32;
	printf("| Degrees Celsius    |   Degrees Fahrenheit|\n");
	while (C <= endTemp ) {
		printf("|%10.1f                  | %10.1f                      |\n", C, F);
		C += step;
		F = C*9/5 + 32; 
		

	}	
	printf("____________________________________________\n");
	return 0;	
}
