//
//  Heap.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/22/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include <stdio.h>
#include "Heap.h"
#include "Vertex.h"

Heap::Heap(){
    occupied=0;
    capacity=10;
    array=new LinkedListNode[capacity];
    
}

Heap::Heap(int capacity){
    occupied = 0;
    this->capacity = capacity+1;
    array = new LinkedListNode[capacity];
}

void Heap::percolateUp(int index){//for children
    int k = index/2;
    if(index>occupied || index<=1) //array
        return;
    if(array[index].getMax()>array[index/2].getMax())
        return;
    if(array[index].getMax()<array[index/2].getMax()){
        swap(array[index],array[index/2]);
        this->percolateUp(index/2);
    }
    if(compareMax(array, k, index)){
        swap(array[index],array[index/2]);
        this->percolateUp(index/2);
    }
    return;
}
void Heap::percolateDown(int index){//for parent
    if(index*2>occupied) //leaves
        return;
    int minChildIndex=minOf(index*2,index*2+1);
    if(array[index].getMax()<array[minChildIndex].getMax())
        return;
    if(array[index].getMax()>array[minChildIndex].getMax()){
        LinkedListNode temp = LinkedListNode();
        temp = array[index];
        array[index] = array[minChildIndex];
        array[minChildIndex] = temp;
        percolateDown(minChildIndex);
    }
    if(compareMax(array, index, minChildIndex)){
        LinkedListNode temp = LinkedListNode();
        temp = array[index];
        array[index] = array[minChildIndex];
        array[minChildIndex] = temp;
        percolateDown(minChildIndex);
    }
    
    return;
}

void Heap::swap(LinkedListNode firstEntry, LinkedListNode secondEntry){
    LinkedListNode temp = LinkedListNode();
    temp = firstEntry;
    firstEntry = secondEntry;
    secondEntry = temp;
}


int Heap::minOf(int index1, int index2) { //We will input left child first
    if(index2 > occupied) //because we won't call this method if we have no children
        return index1;
    
    if(array[index1].getMax()<array[index2].getMax())
        return index1;
    if(array[index1].getMax()>array[index2].getMax())
        return index2;
    if(compareMax(array, index1, index2)){
        return index2; 	//because we would care only about right child and the parent
    }
    else
        return index1;
}

Heap::Heap(const Heap& src){
    this->occupied=src.occupied;
    this->capacity=src.capacity;
    this->array= new LinkedListNode[this->capacity];
    for(int i=1; i<this->capacity;i++)
        this->array[i]=src.array[i];
}

Heap& Heap::operator=(const Heap& src){
    this->occupied=src.occupied;
    this->capacity=src.capacity;
    this->array= new LinkedListNode[this->capacity];
    for(int i=1; i<this->capacity;i++)
        this->array[i]=src.array[i];
    return *this;
}

LinkedListNode Heap::deleteMin(){
    LinkedListNode MinNode= LinkedListNode();
    MinNode = array[1];
    LinkedListNode temp = LinkedListNode();
    temp = array[1];
    array[1] = array[occupied];
    array[occupied] = temp;
    occupied--;
    percolateDown(1);
    return MinNode;
}

void Heap::insert(LinkedListNode* array, int size){
    for(int i=0;i<size;i++){
        if(array[i].getMax()!=0){
            this->array[this->occupied+1]=array[i];
            occupied++;
        }
    }
}

void Heap::insert(LinkedListNode *entry){
  //  if(occupied>capacity){
      //  this->resize();
  //  }
    array[occupied] = *entry;
       // this->percolateUp(occupied);
        this->occupied++;
    
}

void Heap::resize(){
    LinkedListNode* oldHeap = array;
    capacity = capacity*2;
    array = new LinkedListNode [capacity];
    for(int i=1;i<=occupied; i++)
        array[i]=oldHeap[i];
    delete[] oldHeap; //will it segfault?
}

void Heap::makeHeap(){
    for(int i=occupied/2;i>=1; i--)
        this->percolateDown(i);
}

bool Heap::compareMax(LinkedListNode *array, int Llow, int Lhigh){
    if(array[Llow].getMax() == array[Lhigh].getMax()){
        array[Llow].W.size--;
        array[Lhigh].W.size--;
        return compareMax(array, Llow, Lhigh);
    }
    if(array[Llow].getMax() < array[Lhigh].getMax()){
        array[Llow].W.size =  array[Llow].W.constSize;
        array[Lhigh].W.size =  array[Lhigh].W.constSize;
        return false;
    }
    array[Llow].W.size =  array[Llow].W.constSize;
    array[Lhigh].W.size =  array[Lhigh].W.constSize;
    return true;
}