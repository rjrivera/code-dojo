#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int x;

	x = -3+4*5-6;
	//x=11
	printf("x=%d\n", x);
	
	//x=1
	x = 3+4%5-6;
	printf("x=%d\n", x);
	

	x = 3*4%-6/5;
	printf("x=%d\n", x);

	return 0;

}
