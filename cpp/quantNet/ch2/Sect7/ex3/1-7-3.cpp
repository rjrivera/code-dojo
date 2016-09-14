/*
Title: Level 2, S 7, Ex 3
Author: Rob Rivera
Date: 9/14/2016

predict what will be printed on the screen (indicated via comments)
*/
#include <stdio.h>
#include <stdlib.h>

#define PRD(a) printf("%d", (a) ) // PRINT DECIMAL
#define NL		printf("\n");//print new line

// create and initialize array

int a[]={0, 1, 2, 3, 4};

int main(){

	int i;
	int * p;
	// 01234
	for (i = 0; i <=4; i++) PRD(a[i]);	//1
	NL;

	// 01234
	for (p=&a[0]; p<=&a[4]; p++) PRD(*p);	//2
	NL;

	// 01234
	for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); //3
	NL;

	// 024
	for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); //4
	NL;	
	NL;

	// 43210
	for (p=a+4; p>=a; p--) PRD(*p); //5
	NL;

	// 43210
	for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); //6
	NL;

	// 43210
	for (p=a+4; p>=a; p--) PRD(a[p-a]); //7
	NL;

	
	return 0;



}

