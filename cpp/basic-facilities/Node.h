#ifndef NODE_H
#define NODE_H

class Node{

     friend class LList;

     private:
   	     int data;
             Node * nextNode;

     public:
	     Node();
             Node(int Data_);
             int getData(){ return data;}
	     Node * getNextNode(){ return nextNode;}
             void setData(int num);
             void setNextNode(Node* n1);
	     
};
#endif
