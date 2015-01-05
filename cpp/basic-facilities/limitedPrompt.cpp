#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool accept()
{
    int tries = 1;
    while(tries < 4){

        cout << "Do you want to proceed (y/n)?\n";

        char answer = 0;
        cin >> answer;
        switch(answer){
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I do not understand\n";
                tries= tries + 1; 
         }
    }
    cout << "I'll just... take that as a no";
    return false;
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
