//
//  Vertex.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/18/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "WeightList.h"

#ifndef Vertex_h
#define Vertex_h
class Vertex{

public:
    
    LinkedList L;
    int vertex;
    bool visited;
    LinkedListNode getLinkedListHead();
    void setLinkedList(LinkedList L);
    void addNode(LinkedListNode *E);//Edge and Vertex destination
    void printVertexTest();
    Vertex();
    Vertex(LinkedList L, int vertex);
    Vertex &operator=(const Vertex &rhs);
    
};

#endif /* Vertex_h */
