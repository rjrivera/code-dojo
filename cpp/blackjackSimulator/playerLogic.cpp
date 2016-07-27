#include "playerLogic.h"
#include<iostream>
using namespace std;


//an initial basic strategy that returns hit/stay (true/fals)
//TODO: implement doubledown, split option.
void initStratTable(bool stratTable[31][31]) {
	//initialize all to false;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			stratTable[i][j] = false;
		}
	}
	
	//manually initializing all hands
	for (int i = 12; i <=16; i++) {
		for (int j = 7; j <= 11; j++) {
			stratTable[i][j] = true;
		}
	}

	stratTable[12][2] = true;
	stratTable[12][3] = true;
	
	for (int i = 5; i <= 11; i++) { 
		for (int j = 2; j <= 11; j++) {
			stratTable[i][j] = true;
		}
	}

	
	
     }

bool basicStrat(int dealerHand, int playerHand, bool stratTable[31][31])
     {
	   cout << "dealer showing: " << dealerHand << "\n" <<
		"player showing total of: " << playerHand << "\n" ;
           if(stratTable[playerHand][dealerHand])
           {
                  cout << "\nHIT ME\n";
                  return true;

           }
	   else {
           	cout << "\nSTAY\n";
           	return false;
	   }
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
