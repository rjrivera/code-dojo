#include "Node.h"
#include "LList.h"
#include <cstddef>
#include <iostream>
LList::LList(int Data_){
     
     
     Node n1 = Node(Data_);
     head = &n1;
     tail = head;
     

}

void LList::Push(int Data_){

     Node n1 = Node(Data_);
     tail->nextNode = &n1;
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
