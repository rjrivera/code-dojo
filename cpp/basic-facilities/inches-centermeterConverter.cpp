#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iostream>
using namespace std;

int main()
{
    const double factor = 2.54;
    double x, in, cm;
    char ch = 0;

    cout << "enter length (i for inch, c for centimeter): ";

    cin >> x;//read a floating point number because x is type double
    cin >> ch; //read a suffic char ch
    
    switch(ch){
    case 'i': //inch
        in = x;
        cm = x*factor;
        break;
    case 'c':
        in = x/factor;
        cm = x;
        break;
    default:
        in = cm =0;
        break;

        }
    cout << in << " in= " << cm << " cm\n";

}
