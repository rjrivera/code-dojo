/*
Title: Level 1, S 3, Ex 2
Author: Rob Rivera
Date: 9/9/2016
Write a program that calculates the surface of a triangle with one 90 degree angle. The formula is half the height multiplied by the base. The program should take an input from the user ( base& height), and output the result. 
*/
#include <stdio.h>//import the standard io library. 

float areaTri(float base_, float height_) {
	//commented code refered to in testing. 
	//printf("height: %d\nbase: %d", height_, base_);
	float area = (base_ * height_)/2; 
	
	return area;
}

int main() {
	//initialization. 
	int base, height;
	base = height = 0;
	//prompt user for input
	printf("right triangle Area routine v0.x\n");
	printf("please provide dimensions of your triangle\n");
	
	//ignoring input sanitation due to C-style restriction of assignment. Can use GOTO to simulate try/catch in C
	
	printf("provide base and press 'Enter' key:\n");
	scanf("%d", &base);
	printf("provide height and press 'Enter' key:\n");
	scanf("%d", &height);

	printf("area of triangle is: %f", areaTri(base, height));
	return 0;
}
