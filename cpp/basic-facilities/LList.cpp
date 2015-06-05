#include "Node.h"
#include "LList.h"
#include <cstddef>
#include <iostream>
LList::LList(int Data_){
     
     
     
     head = new Node(Data_);
     tail = head;
     

}

void LList::Push(int Data_){

    
     tail->nextNode = new Node(Data_);
     tail = tail->nextNode;

}
void LList::Pop(){
     head = head->nextNode;
}

void LList::traverseList(){
     //why am i going to copy the entire thing? TODO find canon to travers list
     Node * current = head;
     while(current != NULL){
        
         
         std::cout << "current data item is: \n" << current->data << "\n";
         current = current->nextNode;
         
     }
     std::cout<< "final test bench \n";

}
