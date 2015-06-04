#include "Node.h"
#include<cstddef>

Node::Node(){
     data = 0;
     nextNode = NULL;
}
Node::Node(int Data_): data(Data_), nextNode(NULL){
}

void Node::setData(int num){
          data = num;
}
        
void Node::setNextNode(Node* n1){
          nextNode = n1;
}

             


