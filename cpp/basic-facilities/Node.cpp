#include "Node.h"


Node::Node(int Data_){
          
          setData(Data_);//define Nod data.
          Node* p1; 
          setNextNode(p1);//define Node Pointer.
          
}

void Node::setData(int num){
          data = num;
}
        
void Node::setNextNode(Node* n1){
          nextNode = n1;
}

             


