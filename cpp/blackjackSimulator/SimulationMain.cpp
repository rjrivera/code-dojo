/*
requires cardDeck.cpp


*/

#include "cardDeck.h"
#include<iostream>
#include "playerLogic.h"

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
     int count = 0;
     int currentBet = 0;
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
    // for(int i = 0; i < 52; i++){
       
    //      cout << "\nReviewing Deck\n";
    //      cout << "\n Card Value: " << deck[i] << "\n";
    // }for loop was used for verifying deck...not needed atm. 
     // end review here

     // begine simulation here
     bool gaming = true;
     double numHandsRemaining = handsPerHour * numHours;
     bool shuffle = true; //must shuffle first. 
     cout << "beginning simulation";
     //list<int> hands ((numPlayers+1), 0);//initiate list of ints. 
     int hands[(6)] = { }; //initialized to max hands on table
     int currentCard = 1;//accounts for initial card burn. 
     int showingCard = 0;//card Dealer is showing. 
     while(gaming)
     {
          cout << "\n *** NEW GAME ***\N Best of Luck \n";
      //implement shuffle check
          if(shuffle){
 
                shuffleDeck(deck);
                shuffle = false;
                currentCard = 1;
                count = 0;
            }
          currentBet = max(minBet * count + minBet, minBet);
          cout << "\ncurrent count: " << count;
          cout << "\ncurrent Bet: " << currentBet;
      //implement gaming logic here.

          //deal - remember, dealer is not included in numPlayers.
          for(int i = 0; i < 2; i++){//each round of cards.
              for(int j =0; j <= numPlayers; j++){
                      hands[j]+= deck[currentCard];
                      if(i == 0 && j == 0){
                            showingCard = deck[currentCard];
                            cout << "\ndealers Card: ";
                            cout << showingCard << "\n";
                      }
                      updateCount(count, deck[currentCard]);
              
                      currentCard++;
              }

          }
          //auto-decide basic strategy to stay TODO basic strat

          for(int i = 1; i <= numPlayers; i++){
            
                while(basicStrat(showingCard,
                                   hands[i]))
                {//hit logic should be method. use while loop to hit UNTIL 17. 
 
                      hands[i]+=deck[currentCard];
                      updateCount(count, deck[currentCard]);
                      currentCard++;
                      if (hands[i]>21)
                      {
                            cout << "\nBUST!";
                      }
                }

          }
          //dealer hits now.

          while(hands[0] < 17){

                hands[0] += deck[currentCard];
                updateCount(count, deck[currentCard]);
                currentCard++;

          }

          //reveal dealer action and collect/payout
         
          
          if( hands[1] > 21)
          {
               Bank-=currentBet;
               cout << "LOSE! dealer hand: " << hands[0]<<"\n";
               cout << "     your hand: " << hands[1] << "\n";
          }
          else if(hands[0] > 21)
          {
               Bank+=currentBet;
               cout << "WIN! dealer hand: " << hands[0]<<"\n";
               cout << "     your hand: " << hands[1] << "\n";
          }
          else if(hands[1] > hands[0] )//dealer bust or player win. 
          {
               Bank+=currentBet;
               cout << "WIN! dealer hand: " << hands[0]<<"\n";
               cout << "     your hand: " << hands[1] << "\n";
          }
          else if(hands[0] > hands[1])
          {
               Bank-=currentBet;
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

