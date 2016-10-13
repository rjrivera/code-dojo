#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdint.h>
#include <queue>
#include <deque>
#include <screen.hpp>
//#include "print.h"
using namespace std;

int main() {
	int y1, m1, d1, y2, m2, d2;
	y1 = 2008; 
	m1 = 12;
	d1 = 15;
	y2 = 2010;
	m2 = 5;
	d2 = 26;

	// goal is to efficiently calculate the number of days between two given dates. 

	// strategy: shave off the edges of the dates to normalize to 1-1, eg the number of days remaining in y1 and y2 then just add 365 * deltayears. 
	
	// baseline number of years * 365; assuming no leap years - 
	
	int numDays = 0;
	
	numDays += ((y2-1) - y1)*365;//addleap year functionality using modulo operator. 
	
	// add leapyear functionality later. 
	//now - calculate numyears int ending year.
	
	numDays += d2; //days elapsed in end date. 

	//add days in the month 
		for (int i = 1; i < m2; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
				numDays += 31;
			}
			else if (i == 2) {
				numDays += 28;
			}
			else {
				numDays += 30;
			}

		}
	

	// repeat proceducre for beginning edge, but tweak algorithms for the fact that "extra days" are at the end of the calender.
	// can't just add numDays because depending on which month, the value may change. 
	bool firstMonth = true;
	for (int i = m1; i <=12; i++) {
		if (i == 1 || i ==3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {

			if (firstMonth) {
				firstMonth = false;
				numDays += (31 - d1);
			}
			else {
				numDays += 31;
	

}
