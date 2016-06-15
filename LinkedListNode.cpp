//
//  LinkedListNode.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/8/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include <stdio.h>
#include "LinkedListNode.h"
#include "WeightList.h"
#include <iostream>
using namespace std;

LinkedListNode::LinkedListNode(){
    this->origin = 0;
    this->dest = 0;
    this->W.size = 0;
    this->W.constSize = 0;
    this->W.weights = NULL;
    this->next = NULL;
}

LinkedListNode::LinkedListNode(int *&weights, int dest, int size, int origin){
    
   // this->W = WeightList(size, weights);
    this->W.size = size;
    this->W.constSize = size;
    for(int i = 0; i < size; i++){
        this->W.weights[i] = weights[i];
    }
    this->origin = origin;
    this->dest = dest;
    this->next = NULL;
}

LinkedListNode& LinkedListNode::operator=(LinkedListNode& rhs){
    this->origin = rhs.origin;
    this->dest = rhs.dest;
    this->W.size = rhs.W.size;
    this->W.constSize = rhs.W.size;
    if(this->W.weights == NULL){
        this->W.weights = new int[this->W.size];
    }
    for(int i = 0; i < rhs.W.size; i++){
        this->W.weights[i] = rhs.W.weights[i];
    }
    this->next = rhs.next;
    return *this;
}

LinkedListNode::LinkedListNode(LinkedListNode const& orig){
    this->W = orig.W;
    this->next = orig.next;
}

void LinkedListNode::printLinkedListNodeTest(){
    this->getMax();
    //cout << "Max Index:" << maxIndex << endl;
    cout << origin << " ";
    cout << dest << " ";
    this->W.printWeightList();
   // cout << endl;
}

LinkedListNode::~LinkedListNode(){
    this->W.~WeightList();
    
}

int LinkedListNode::getMax(){
    int temp = 0;
    for(int i =0; i<this->W.size; i++){
        if(this->W.weights[i] > temp){
            temp = W.weights[i];
            this->maxIndex = i;
        }
    }
    return temp;
}