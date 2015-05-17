#include "cardDeck.h"
#include<cmath>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#if !defined(_MSC_VER)
using namespace std;
#endif

int * cardDeck(){

     static int deck[52]; //declares empty array.

     //faceCards - initial prototype ignores dual nature
     //of the "Ace"

     for(int i =0; i < 52; i++)
     {
          cout << "\nin for loop iteration: " << i << "\n";
          if(i < 16){//facecards
               deck[i] = 10;
          }
          else if(i < 20){
               deck[i] = 11;
          }
          else if(i < 24){
               deck[i] = 2;
          }
          else if(i < 28){
               deck[i] = 3;
          }
          else if(i < 32){
               deck[i] = 4;
          }
          else if(i < 36){
               deck[i] = 5;
          }
          else if(i < 40){
               deck[i] = 6;
          }
          else if(i < 44){
               deck[i] = 7;
          }
          else if(i < 48){
               deck[i] = 8;
          }
          else if(i < 52){
               deck[i] = 9;
          }
    //      cout << "\n Card Value: ";
    //      cout << deck[i] << "\n";
     }
     
     return deck; 
}
//should be able to shuffle any sized shoe. 
void shuffleDeck(int *deck){
       
     srand (time(NULL));
     cout << "***Shuffling***\n";
     int firstCard = 0;
     int secondCard = 0;
     int tempCard = 0;
     for(int i = 0; i < rand() % 100 + 50; i++){
                  
           //use a random value to pick two cards

           firstCard = rand() % 52; //TODO replace hard number
           secondCard = rand() % 52;

           //swap cards.

           tempCard = deck[firstCard];
           deck[firstCard] = deck[secondCard];
           deck[secondCard] = tempCard;
     }
     //for(int i= 0; i< 52; i++){
     //      cout << "\nCurrent Value: " << deck[i] << "\n";
     
     // }


}
