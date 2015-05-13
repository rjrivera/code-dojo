/*
requires cardDeck.cpp


*/

#include "cardDeck.h"
#include<iostream>
using namespace std;

int main()
{

     double Bank;
     double numHours;
     double numPlayers = 0;
     double minBet;
     double maxBet;
     double handsPerHour;
     double *deck;
     deck = cardDeck();
     cout << "\nEnter your starting Bank Roll\n";
     cin >> Bank;
   
     cout << "\nEnter Number of Hours at the Table\n";
     cin >> numHours;
     

     cout << "\nEnter Number of Players, outside yourself\n";
     cin >> numPlayers;

     while(numPlayers > 4)
     {
          cout << "\nNot enough seats at the table\n";
          cout << "\nEnter Number of Players, outside yourself\n";
          cin >> numPlayers;          
     }
     
     cout << "\nEnter minimum bet\n";
     cin >> minBet;

     maxBet = minBet *100; //as per best practices. 
     //simulation will assume a reasonable dealer speed, as defined by Casino Operations Management (Jim Kilby)
     switch ( (int)(numPlayers + 1) )
     {

          case '1':
               handsPerHour = 209;
          case '2':
               handsPerHour = 139;
          case '3':
               handsPerHour = 105;
          case '4':
               handsPerHour = 84;
          case '5':
               handsPerHour = 70;
          default:
               handsPerHour = 209;
     }


     //begin simulation here
    // cout << deck[0] << endl;
     for(int i = 0; i < 52; i++){
       
          cout << "\nReviewing Deck\n";
          cout << "\n Card Value: " << deck[i] << "\n";
     }
     // end simulation here

     

     cout << "\nEnd of Simulation\n" ;

     cout << "\nCurrent Bank: " << Bank << "\n";

     return 0;

}
