#include "cardDeck.h"
#include<cstdlib>
#include<cmath>
#include<iostream>

#if !defined(_MSC_VER)
using namespace std;
#endif

double* cardDeck(){

     double deck[52]; //declares empty array.

     //faceCards - initial prototype ignores dual nature
     //of the "Ace"

     for(int i =0; i < 52; i++)
     {
          if(i < 12){//facecards
               deck[i] = 10;
          }
          else if(i < 16){
               deck[i] = 11;
          }
          else if(i < 20){
               deck[i] = 1;
          }
          else if(i < 24){
               deck[i] = 2;
          }
          else if(i < 30){
               deck[i] = 3;
          }
          else if(i < 34){
               deck[i] = 4;
          }
          else if(i < 38){
               deck[i] = 5;
          }
          else if(i < 42){
               deck[i] = 6;
          }
          else if(i < 48){
               deck[i] = 7;
          }
          else if(i < 52){
               deck[i] = 8;
          }
          else if(i < 56){
               deck[i] = 9;
          }

     }
     double* out = deck;
     return out; 
}

void cardDeck(double &deck){

     cout << "Function Undefined; nothing to see here";

}
