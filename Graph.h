//
//  Graph.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/18/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//
#include "Vertex.h"
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "WeightList.h"

#ifndef Graph_h
#define Graph_h
class Graph{
public:
    Vertex *V;
    LinkedListNode *LArray;
    int LArrayOccupied;
    Graph ();
    Graph (Graph const &G);
    Graph (int size);
    ~Graph();
    void YILI(int size, int capacity, int numVertices);
    void Kruskals(int size, int capacity, int numVertices);
    LinkedListNode &compareMax(LinkedListNode *L1, LinkedListNode *L2);
    bool compareNodes(int *first, int *second, int *checkArray, int temp, int mintemp, int size);
    void Sollins(int size, int capacity, int numVertices);
    bool compareSollins(int *first, int *second, int *totals, int *fIndices, int * sIndices, int mintemp, int temp, int size);
    void Prims(int size, int capacity, int numVertices);
    void FixedStart(int size, int capacity, int numVertices);
};

#endif /* Graph_h */
