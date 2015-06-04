#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Node.h"
#include"LList.h"

using namespace std;

int main()
{
    cout << "Initial CPP scratch pad: meant to crudely test development\n";

    cout << "Testing the List class out. \n";
    cout << "Input data for an initial list...\n";
    int i1, i2, i3;

    cin >> i1;

    LList l1 = LList(i1);
 
    cout << "Now we will add to this list, enter 2 numbers:\n";

    cin >> i2;
    cin >> i3;
    
    //l1.Push(i2);
    //l1.Push(i3);

    l1.traverseList();
}

