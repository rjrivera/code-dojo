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


