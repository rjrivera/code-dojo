#include "Node.h"
#include "LList.h"

LList::LList(int Data_){

     head = Node(Data_);
     tail = *head.getNextNode();

}

void LList::Push(int Data_){
     Node n = Node(Data_);
     tail.setNextNode(&n);
     tail = *tail.getNextNode();


}
void LList::Pop(){
     head.setNextNode(*head.getNextNode());
}

void LList::traversList(){
     //why am i going to copy the entire thing? TODO find canon to travers list
     Node temp = head;
     while((temp.getNextNode()) != NULL){
          cout << "current data item is: \n" << temp.getData();
          temp = *temp.getNextNode();
     }

}
