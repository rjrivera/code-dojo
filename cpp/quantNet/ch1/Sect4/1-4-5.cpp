/*
Title: Level 1, S 4, Ex 5
Author: Rob Rivera
Date: 9/12/2016
Write a C-program that prints two columns on the screen with the temperature in degrees C and the equivalent temperature in degtrees F. 

the left column shows the temperature in C. the right column shows the temperature in F. 

strat with 0 degrees C and proceed untill 19 degrees C. Take steps of 1 degree. print degrees F with 1 position behind the comma (use "%10.1f" as format specifier). also print a header text.

make the program maintenance insenstive which means it's easy to modernize. 
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
