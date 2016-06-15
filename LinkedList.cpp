//
//  LinkedList.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/13/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include "LinkedList.h"
#include "LinkedListNode.h"
#include <string>
#include <iostream>


using namespace std;

LinkedList::LinkedList(){
    head = tail = NULL;
}

LinkedList::LinkedList(LinkedList &orig){
    //this->~LinkedList();
    LinkedListNode *iter;
    iter = orig.head;
    while(iter != NULL){
        this->addTail(iter);
        iter = iter->next;
    }
}

void LinkedList::addTail(LinkedListNode * L){
    if(this->head== NULL || this->tail == NULL){
        this->head = this->tail = L;
    }
    else {
        tail -> next = L;
        tail = L;
    }
}


LinkedList::~LinkedList(){
    if(this->head != NULL){
        LinkedListNode *delNode;
        while(this->head != NULL){
            delNode = head;
            head = head->next;
            delNode->~LinkedListNode();
            delete delNode;
        }
        tail = head = NULL;
    }
}

LinkedList &LinkedList::operator=(const LinkedList &rhs){
    this->~LinkedList();
    LinkedListNode *current = rhs.head;
    while(current!=NULL){
        this->addTail(current);//add the current node to the list
        current = current->next;
    }
    return *this;
    
}

void LinkedList::printLinkedListTest(){
    LinkedListNode *current = this->head;
    while(current != NULL){
        current->printLinkedListNodeTest();
        current = current->next;
    }
}
