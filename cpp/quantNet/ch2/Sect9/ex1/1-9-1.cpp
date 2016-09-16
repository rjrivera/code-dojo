/*
Title: Level 2, S 9, ex1
Author: Rob Rivera
Date: 9/15/2016

Create a C-programt that reads thecharacters from the keyboard and shows them on screen (the inputted characters should only be displayed when the user hits 'enter', line by line).

When ^A is entered, the program must end properl. then the following message will: "CTRL + A is a correct ending"

Tip: getchar() reads and putchar() writes the type int. the value of ^A is 1. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(){
	// initialization
	/* defining an initial static array of size 100 and using 
	count variable to track the active 'slot' ready to be filled using pointer arithmetic. 

	   Upon count breaking the size, malloc is caused to dynamically expand the buffer. 
	*/
	char input;
	int size = 10;
	int count = 0;
	char * buffer = (char*)(malloc(size*sizeof(char)));
	char * tempBuffer; 
	// main loop
	while((input = getchar()) != 1) {
		// checks if 'enter' isn't pressed. 
		// queues buffer with inputted character. 
		if (input != '\n') {
			*(buffer + count) = input;	
			count++;
		}
		// recant user input 
		else {
			printf("%s\n", buffer);
			count = 0; 
			*buffer = '\0';
		}
		// tracks whether static size has been busted to dynamically allocate more memory. 
		if (count > size - 1) {
			size += 20;
			tempBuffer = (char*)(realloc(buffer, size*sizeof(char)));
			if (tempBuffer){
				buffer = tempBuffer;	
				printf("Increasing static array by sizeOf(char)*20\n");
			}
			else {
				printf("error allocating memory, exiting\n");
				exit(0);
			}

			
		}
	}

	// final processing
	printf("\nCTRL + A is the correct ending\n");
	return 0;



}

