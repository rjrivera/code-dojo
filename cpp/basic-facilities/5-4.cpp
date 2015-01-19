#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iostream>
using namespace std;

void swapValues(int* i1, int* i2){

    int temp  = *i1;
    *i1 = *i2;
    *i2 = temp;
}
int main()
{
  int i1 = 5;
  int i2 = 6;
  int* p1 = &i1;
  int* p2 = &i2;
  cout << "\ninitial values are: " << *p1 << " & " << *p2;
  swapValues(p1, p2);
  cout << "\nswapped valus are: " << *p1 << " & " << *p2;
  return(0);
}
