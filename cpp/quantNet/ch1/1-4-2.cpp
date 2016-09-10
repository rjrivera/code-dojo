/*
Title: Level 1, S 4, Ex 2
Author: Rob Rivera
Date: 9/10/2016
Write a C-program that asks for text input from the keyboard. The output of this program should be the amount of characters, the amount of words and the amount of newlines that have been typed. Multiple consecutive spaces shouldnot be counted as multiple words. 

Reading keys from the keyboard is possible by using the function getchar(). the reading of characters fro the keyboard can be stopped when the shutdown-code ^D is entered. ^D == 4. use a do-while loop. 
*/

/* Conditional expressions */
#include <stdio.h>

int main() {
	printf("please provide text input for processing\n");

	int words, lines, characters;
	words = lines = characters = 0;
	int input;
	bool newWord = false;
	
	do {		
		//input = getchar();
		if (!newWord && input == ' ') {
			newWord = true;
			words++;
		}
		else if (input == '\n') {
			lines++;
			newWord = false;
		}
		else {
			characters++;
			newWord = false;
		}
		
	}
	while ((input = getchar()) != EOF);
	lines++; //fencepost problem. 
	printf("\nwords: %d\nlines:%d\ncharacters:%d\n", words, lines, characters);
	return 0;

	
}
