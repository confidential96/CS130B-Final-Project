//
//  UnionFind.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/24/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include "UnionFind.h"
#include "Vertex.h"
#include "LinkedList.h"
#include "LinkedListNode.h"

UnionFind::UnionFind(int size){
    ID = new int[size+1];
    this->size = size;
    for(int i = 1; i <=size; i++){
        ID[i] = i;
    }
}

int UnionFind::root(int index){//compresses the path
    while(index != ID[index]){
        ID[index] = ID[ID[index]];
        index = ID[index];
    }
    return index;
}

bool UnionFind::find(int a, int b){
    return root(a)==root(b);
}

void UnionFind::unite(int a, int b){
    int aID = ID[a];
    for(int i = 0; i <= this->size; i++){
        if(ID[i] == aID){
            ID[i] = ID[b];
        }
    }
}