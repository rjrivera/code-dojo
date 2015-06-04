#ifndef LList_H
#define LList_H
#include "Node.h"

class LList
{
private: 
        Node * head;
        Node * tail;

public: 
        LList(int Data_);
        void Push(int Data_);
        void Pop();
        int getHead(){return head->data;}
        void traverseList();
};
#endif
