/*
Title: Level 2, S 8, Ex 1
Author: Rob Rivera
Date: 9/15/2016

Errata: 1-08 slide 8, bullet 2, line 2/3 replace pt->/(*pt) with pp->/(*pp) respectively. 

Write a C-program that prints the contents of a struct called Article. An Articla has the following characteristics:
-Article Number
- Quantity
- Desciption (20 characters)
The test program must create an Article of which the contents are assigned at initialization level. 

Printing the Article is done with a Print() function. this function gets the address of the structure as a paramter. 

Tip: Suppose that p is the pointer to the structure. It will allow the fields to be printed by (*p).fieldname or p->fieldname.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create and initialize array

struct Article {
	int number;
	int quantity; 
	char description[21];
};

void Print (struct Article * candArt_) {
	printf("Printing information:\n");
	printf("number: %d\nquantity: %d\ndescription: %s\n", (*candArt_).number, (*candArt_).quantity, (*candArt_).description);
	
}
int main(){
	struct Article firstEd = {1, 5, "Radioactive Man V.1"};
	Print(&firstEd);
	return 0;



}

