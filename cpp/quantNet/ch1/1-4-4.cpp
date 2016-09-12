/*
Title: Level 1, S 4, Ex r
Author: Rob Rivera
Date: 9/12/2016
Write a C-program that prints two columns on the screen with the temperature in degrees fahrenheit and the equivalent temperature in degtrees celsius. 

the left column shows the temperature in fahrenheit. the right column shows the temperature in celsius. 

strat with 0 degrees fahrenheit and proceed untill 300 degrees fahrenheit. Take steps of 20 degrees. print degrees celsius with 1 position behind the comma (use "%10.1f" as format specifier). also print a header text.

make the program maintenance insenstive which means it's easy to modernize. 
*/

/* Conditional expressions */
#include <stdio.h>

int main() {
	
	printf("|~~~~~Harby's Temperature Widget 3000~~~~~|\n");
	//WARNING: Admin adjust constants ONLY
	//===========================
	const int startTemp = 0;
	const int endTemp = 300;
	const int step = 20;
	//===========================

	int F = startTemp;
	float C = (F- 32)*5/9;//((5/9)*(F-32));
	printf("| Degrees Fahrenheit    |   Degrees Celsius|\n");
	while (F <= endTemp ) {
		printf("|%d                      | %10.1f                  |\n", F, C);
		F += step;
		C =(F-32)*5/9;//((5/9)*(F-32)); 
		

	}	
	printf("____________________________________________\n");
	return 0;

	
}
