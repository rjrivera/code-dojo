#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<iostream>
using namespace std;

int main()
{
    char c = 'a';
    for(int i = 97; i < 123; ++i){
        c = (char)i;
        cout << c << " dec: " << dec << int(c) << " 0x" << hex << int(c) << endl;
    }
    return(0);
}
