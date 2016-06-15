//
//  Vertex.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/18/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include <stdio.h>
#include "Vertex.h"
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "WeightList.h"

Vertex::Vertex(){
    this->L = LinkedList();
    this->vertex = -2;
    this->visited = false;
}


void Vertex::addNode(LinkedListNode *E){//Edge and Vertex destination
    this->L.addTail(E);
}

void Vertex::printVertexTest(){
    this->L.printLinkedListTest();
}

Vertex::Vertex(LinkedList L, int vertex){
    this->L = L;
    this->vertex = vertex;
    this->visited = false;
    
}
Vertex& Vertex::operator=(const Vertex &rhs){
    this->L = rhs.L;
    this->vertex = rhs.vertex;
    return *this;
}