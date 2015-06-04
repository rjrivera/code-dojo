#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Node.h"
using namespace std;

int main()
{
    cout << "Initial CPP scratch pad: meant to crudely test development\n";

    cout << "Testing the Node class out. \n";
    cout << "Input data for a few nodes...3 nodes to be exact\n";
    int i1, i2, i3;

    cin >> i1;
    cin >> i2;
    cin >> i3;

    Node n1 = Node(i1);
    Node n2 = Node(i2);
    Node n3 = Node(i3);

    cout << "Node 1 is as follows: \n" << n1.getData() << "\n";
    cout << "Node 2 is as follows: \n" << n2.getData() << "\n";
    cout << "Node 3 is as follows: \n" << n3.getData() << "\n";
}

