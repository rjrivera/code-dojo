#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iostream>
using namespace std;

int main()
{
   int i = 5;
   double d = 0.345;
   char c = 'p';


   std::cout << "size of integers is: " << sizeof i << '\n'
        << "size of doubles are: "      << sizeof d
        << "\nsize of characters are: " << sizeof c;

   return(0);
}
