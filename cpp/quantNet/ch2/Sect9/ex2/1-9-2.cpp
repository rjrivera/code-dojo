/*
Title: Level 2, S 9, ex2
Author: Rob Rivera
Date: 9/15/2016



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
	int size = 20;
	int count = 0;
	char * buffer = (char*)(malloc(size*sizeof(char)));
	char * tempBuffer; 
	char * fileName = (char*)(malloc(size*sizeof(char)));
	printf("Please enter a file name (<19 characters) for input, followed by 'Enter' \n");
	while ((input = getchar()) != '\n') {
		fileName[count] = input;
		count++;
		if (count >= 20) {
			printf("Input too large, defaulting to name: %s\n", fileName);
			count = 0;
			break;
		}	

	}
	
	// open file and write - if already there, DEL and write over. 
	printf("now writing to file <%s> please enter ^A to exit program\n", fileName);

	FILE * fp = fopen(fileName, "w");
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
			fprintf(fp, "%s\n", buffer);
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
	
	//close the file
	fclose(fp);
	return 0;



}

