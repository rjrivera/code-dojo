/*
requires cardDeck.cpp


*/

#include "cardDeck.h"
#include<iostream>
using namespace std;

int main()
{

     int Bank;
     double numHours;
     int numPlayers = 0;
     double minBet;
     double maxBet;
     int handsPerHour;
     int *deck;
     deck = cardDeck();
     
     cout << "\nEnter your starting Bank Roll\n";
     cin >> Bank;
   
     cout << "\nEnter Number of Hours at the Table\n";
     cin >> numHours;
     

     cout << "\nEnter Number of Players, outside yourself\n";
     cin >> numPlayers;
     numPlayers++;
     while(numPlayers > 5)
     {
          cout << "\nNot enough seats at the table\n";
          cout << "\nEnter Number of Players, outside yourself\n";
          cin >> numPlayers;
          numPlayers++; //now including yourself. 
     }
     

     cout << "\nEnter minimum bet\n";
     cin >> minBet;

     maxBet = minBet *100; //as per best practices. 
     //simulation will assume a reasonable dealer speed, as defined by Casino Operations Management (Jim Kilby)
     switch (numPlayers)
     {

          case 1:
               handsPerHour = 209;
               break;
          case 2:
               handsPerHour = 139;
               break;
          case 3:
               handsPerHour = 105;
               break;
          case 4:
               handsPerHour = 84;
               break;
          case 5:
               handsPerHour = 70;
               break;
          default:
               handsPerHour = 209;
     }

    //review the deck here
    // cout << deck[0] << endl;
     for(int i = 0; i < 52; i++){
       
          cout << "\nReviewing Deck\n";
          cout << "\n Card Value: " << deck[i] << "\n";
     }
     // end review here

     // begine simulation here
     bool gaming = true;
     double numHandsRemaining = handsPerHour * numHours;
     bool shuffle = true; //must shuffle first. 
     cout << "beginning simulation";
     //list<int> hands ((numPlayers+1), 0);//initiate list of ints. 
     int hands[(6)] = { }; //initialized to max hands on table
     int currentCard = 1;//accounts for initial card burn. 
     while(gaming)
     {

      //implement shuffle check
           if(shuffle){
           //TODO insert shuffle method after implementation.
                shuffle = false;
                currentCard = 1;
            }

      //implement gaming logic here.

          //deal - remember, dealer is not included in numPlayers.
          for(int i = 0; i < 2; i++){//each round of cards.
              for(int j =0; j <= numPlayers; j++){
                      hands[j]+= deck[currentCard];
                      currentCard++;
              }

          }
          //auto-decide basic strategy to stay TODO basic strat

          //reveal dealer action and collect/payout
          if(hands[0]<17 || hands[0] > 21){
               hands[0] += deck[currentCard];
               currentCard++;
          }

          if(hands[1] > hands[0])//dealer bust or player win. 
          {
               Bank+=minBet;
               cout << "WIN! dealer hand: " << hands[0]<<"\n";
               cout << "     your hand: " << hands[1] << "\n";
          }
          else if(hands[0]>hands[1])
          {
               Bank-=minBet;
               cout << "LOSE! dealer hand: " << hands[0]<<"\n";
               cout << "     your hand: " << hands[1] << "\n";
          }
          else if(hands[1] == hands[0])//push
          {
               //do nothing. 
               cout<< "PUSH dealer hand: " << hands[0] << "\n";
               cout << "    your hand: " << hands[1] << "\n";
          }
      cout << "\nCurrent Bank: " << Bank << "\n";
      for(int i =0 ; i < numPlayers+1; i++){
          hands[i] = 0;//clear the table. 
      }
      //implement cut-check
      if(currentCard >32) //temporary test value for reshuffle.
      {
     
          shuffle = true;
      }

          
          numHandsRemaining -= 1;// control measure for simulation length.
          if(numHandsRemaining < 0) {
               gaming = false;
               cout << "approximate game time reached";
               cout << "approximatly " << handsPerHour*numHours<< " hands played";
          cout << "Bank after gameplay: " << Bank;

           }
     }



     // end simulation here

     

     cout << "\nEnd of Simulation\n";

     cout << "\nCurrent Bank: " << Bank << "\n";

     return 0;

}

