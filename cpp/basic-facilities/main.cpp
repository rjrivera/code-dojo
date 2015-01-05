#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool accept()
{
    cout << "Do you want to proceed (y/n)?\n";

    char answer = 0;
    cin >> answer;
    
    switch(answer){
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "I'll take that for a no.\n";
            return false;
    }
}

int main()
{
    printf("\nHellow World, \n Welcom to my first Cpp program in ooBoonToo\n\n");
    bool answer =  accept();
    while(answer){
        printf("you want more, eh?");
        answer = accept();
    }
    return(0);
}
