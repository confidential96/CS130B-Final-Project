//
//  LinkedListNode.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/8/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#ifndef LinkedListNode_h
#define LinkedListNode_h

#include <string>
#include "WeightList.h"


using namespace std;

class LinkedListNode{//This will represent the destination vertex and edge
public:
    WeightList W;
    int origin;
    int dest;
    int maxIndex;
    bool fixedMark;
    LinkedListNode *next;
    LinkedListNode();
    LinkedListNode(int *&weights, int dest, int size, int origin);
    LinkedListNode& operator=(LinkedListNode& rhs);
    LinkedListNode(LinkedListNode const& orig);
    void setLinkedListNode(WeightList W, LinkedListNode *next);
    int getWeight();
    void setWeight();
    void printLinkedListNodeTest();
    ~LinkedListNode();
    int getMax();
    
    
};
#endif /* LinkedListNode_h */

