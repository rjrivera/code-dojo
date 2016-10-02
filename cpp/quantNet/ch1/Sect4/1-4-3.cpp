/*
Title: Level 1, S 4, Ex 3
Author: Rob Rivera
Date: 9/12/2016
Perform exercise 1 againg, but change your solution so that the switch-case statement is used instead of the if blocks
*/

/* Conditional expressions */
#include <stdio.h>

int main() {
	printf("please provide text input for processing\n");

	int words, lines, characters;
	words = lines = characters = 0;
	int input;
	bool newWord = true;
	
	while ((input=getchar()) != EOF) {
	
	switch (input) {
		default://NOT MY PREFERENCE would rather...
		/*
		case 33..126: 
		*/
		//above is an STL implementation however.
			if (newWord) {
				newWord = false;
				words++;
				characters++;
			}
			else {
				characters++;
			}				
			break;
		
		
		case ('\n') :
			lines++;
			newWord = true;
			break;
		case ('\t') :
			newWord = true;
		case (' ') :
			newWord = true;
			break;
		
		
	}
	}
	lines++; //fencepost problem. 
	printf("\nwords: %d\nlines:%d\ncharacters:%d\n", words, lines, characters);
	return 0;

	
}
