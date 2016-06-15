//
//  LinkedList.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/6/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include "LinkedListNode.h"
class LinkedList{

public:
    LinkedListNode *head;
    LinkedListNode *tail;
    LinkedList();//Default
    ~LinkedList();//Destructor
    LinkedList(LinkedList &orig);//Constructor
    void addTail(LinkedListNode *L);
    LinkedList &operator=(const LinkedList &rhs);
    void printLinkedListTest();
   
};

#endif /* LinkedList_h */
