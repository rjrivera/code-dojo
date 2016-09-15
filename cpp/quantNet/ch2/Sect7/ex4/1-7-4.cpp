/*
Title: Level 2, S 7, Ex 4
Author: Rob Rivera
Date: 9/15/2016

Create a C-program that has a function DayName() which can print the day of a given day-number. for example: 1 gives: Day 1 is a SUnday, 7 gives: Day 7 is a Saturday. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create and initialize array

void DayName(int day_, char dict_[][10]) {
	if (day_ >0 && day_ < 8) {
		printf("Day %d is a %s\n", day_, dict_[day_ - 1]);
	}
	else { printf("Day %d is an invalid input\n", day_) ;}

}

int main(){
	char days[][10] = { "Sunday", "Monday","Tuesday", "Wednesday","Thursday","Friday","Saturday"};
	const int TESTNUMBER = 4;
	DayName(TESTNUMBER, days);
	return 0;



}

