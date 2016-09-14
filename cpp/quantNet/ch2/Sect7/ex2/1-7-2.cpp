/*
Title: Level 2, S 7, Ex 2
Author: Rob Rivera
Date: 9/14/2016

The following program reads a string with a 30 character maximum. Implement the Length() function. The function Length() must determine the length of the string. 
Givee Length() the address of the array as argument.
NOTE: your Length() function should be similar to the built-in strlen() function so your job is to mimic that function without using it. 

EOF is used in the function main().

In DOS, EOF can be entered by the key combination Ctrl-z (often written as ^Z).

note to grader: implemented in ubuntu, using ^D for EOF
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 30

int Length(char str[]) {
	int length = 0; 
	while (str[length] != '\0') {
		length++;
	}	
	return length;
}

int main() {
	char string[MAXLINE+1];
	int c;
	int i = 0;


	// Print intro text	
	printf("Type up to %d chars. Enter '^D' when done\n", MAXLINE);
	
	// Get the characters
	while ((c=getchar() != EOF) && i < MAXLINE) {
		//append entered character to string
		string[i++] = (char)c;
	}
	string[i]='\0'; // c-style string terminal flag. 

	printf("String length is %d\n", Length(string));
	return 0;
}
