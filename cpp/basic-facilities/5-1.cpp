#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iostream>
using namespace std;

int main()
{
  char c = 'a';
  char* p = &c;
  int numbers[10] = {0,1,2,3};
  int& r1 = *numbers;
  char c2[4] = {'a', 'b', 'c'};
  char* p2 = c2; 
  char* p2p = p; //pointer to a pointer to a char. 

  cout << "the following is a list of types\nchar a is: " << c
      << "\nchar pointer p is: " << p
      << "\narray of ints is: " << numbers
      << "\nreference to first element of an array is: " << r1
      << "\nc-style string of char's is: " << c2
      << "\n pointer to an array is: " << p2
      << "\n pointer to a pointer to a char is: " << p2p;
  return(0);
}
