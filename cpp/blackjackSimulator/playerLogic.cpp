#include "playerLogic.h"
#include<iostream>
using namespace std;

//an initial basic strategy that returns hit/stay (true/fals)
//TODO: implement doubledown, split option.
bool basicStrat(int dealerHand, int playerHand)
     {

           if(dealerHand > 6 && playerHand < 17 && dealerHand < 12)
           {
                  cout << "\nHIT ME\n";
                  return true;

           }
           else if(dealerHand > 1 && dealerHand < 7 && playerHand < 12)
           {
                  cout << "\nHIT ME\n";
                  return true;

           }
           else if(dealerHand >1 && dealerHand < 3 && playerHand > 11 && playerHand < 13)
          {

                  cout << "\nHIT ME\n";
                  return true;

          }
           cout << "\nSTAY\n";
           
           return false;
      }

//Implements the HI-LO blackjack counting system. 
void updateCount(int &currentCount, int recentCard)
     {
          if(recentCard < 6)
          {
               currentCount++;
          }
          else if(recentCard>9)
          {
               currentCount--;
          }

     }
