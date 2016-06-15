//
//  Heap.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/20/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include "LinkedList.h"
#include "LinkedListNode.h"
#include "WeightList.h"

class Heap{
public:
    int occupied;
    int LArrayoccupied;
    int capacity;
    LinkedListNode *array;
    void percolateUp(int index);
    void percolateDown(int index);
   	int minOf(int index1, int index2);
    Heap();
    Heap(int capacity);
    Heap(const Heap& src); //copy constructor
    Heap& operator=(const Heap& src);
    LinkedListNode *getRoot(){return array;}
    LinkedListNode deleteMin();
    void insert(LinkedListNode* array, int size);//insert before makeHeap
    void insert(LinkedListNode *entry);//insert during consolidateTrie
    void resize();
    void makeHeap();
    void swap(LinkedListNode firstEntry, LinkedListNode secondEntry);
    bool compareMax(LinkedListNode *array, int Llow, int Lhigh);//low vs high index
    
};
#endif /* Heap_h */

