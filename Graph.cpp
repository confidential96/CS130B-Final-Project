//
//  Graph.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/18/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include "Graph.h"
#include <stdio.h>
#include "LinkedList.h"
#include "Vertex.h"
#include "LinkedListNode.h"
#include "WeightList.h"
#include "Heap.h"
#include <iostream>
#include "UnionFind.h"
using namespace std;

Graph::Graph(){
    //You don't make empty graphs.
}

Graph::Graph(int size){
    this->V = new Vertex[size];
    for(int i = 0; i <size; i++){
        this->V[i].vertex = i+1;
    }
}

Graph::Graph(Graph const &G){
    
}

Graph::~Graph(){
    
}

void Graph::YILI(int size, int capacity, int numVertices){
    UnionFind U(numVertices);
    int occupied =0;
    int x = 1;
    this->LArray = new LinkedListNode[capacity];
    int *totals = new int[size];
    int temp = 0;
    int mintemp = 0;
    int *tempArray = new int[size];
    for(int i = 0; i < size; i++){
        totals[i] = 0;
    }
    Heap H = Heap(capacity);
    for(int m = 1; m <=numVertices; m++){
        LinkedListNode *current = this->V[m].L.head;
        while(current != NULL){
            if(x <= capacity){
                H.array[x] = *current;
                current = current -> next;
                x++;
                H.occupied++;
            }
        }
    }
    H.makeHeap();
    for(int i = 0; i < numVertices-1; i++){
        LinkedListNode min = LinkedListNode();
        min = H.array[1];
        for(int j = 0; j < size; j++){
            int k = min.W.weights[j]+totals[j];
            int l = min.W.weights[mintemp]+totals[mintemp];
            if((k) > (l)){
                mintemp = j;
            }
        }
        for(int j = 1; j < H.occupied; j++){
            for(int t = 0; t < size; t++){
                if((H.array[j].W.weights[t]+totals[t]) > (H.array[j].W.weights[temp]+totals[temp])){
                    temp = j;
                }
            }
            int e = H.array[j].W.weights[temp]+totals[temp];
            int d = min.W.weights[mintemp]+totals[mintemp];
            if((e) < (d)){
                if(!U.find(H.array[j].origin, H.array[j].dest)){
                    min = H.array[j];
                    mintemp = temp;
                }
                
                
            }
            else if(e == d){
                if(H.array[j].origin!=min.origin || H.array[j].dest!=min.dest){
                    int *fIndices = new int[size];
                    int *sIndices = new int[size];
                    for(int r = 0; r < size; r++){
                        fIndices[r] = 0;
                        sIndices[r] = 0;
                    }
                    if(compareSollins(H.array[j].W.weights, min.W.weights, totals, fIndices, sIndices, mintemp, temp, size)){
                        if(!U.find(H.array[j].origin, H.array[j].dest)){
                            min = H.array[j];
                            mintemp = temp;
                        }
                    }
                    
                }
            }
        }
        for(int t = 0; t < size; t++){
            totals[t]+=min.W.weights[t];
        }
        U.unite(min.origin,min.dest);
        LArray[i] = min;
        
    }
    LinkedListNode t = LinkedListNode();
    for(int i = 0; i < numVertices-1; i++)
    {
        for(int j = 0; j < numVertices-1; j++)
        {
            if(LArray[j].origin > LArray[i].origin)
            {
                t = LArray[i];
                LArray[i] = LArray[j];
                LArray[j] = t;
            }
        }
    }
    
    for(int i = 0; i < numVertices-1; i++){
        LArray[i].printLinkedListNodeTest();
    }
    for(int i = 0; i < size; i++){
        cout << totals[i] << " ";
    }
    
}

void Graph::Kruskals(int size, int capacity, int numVertices){
    UnionFind U(numVertices);
    this->LArray = new LinkedListNode[capacity];
    int *totals = new int[size];
    int temp = 0;
    int mintemp = 0;
    int *tempArray = new int[size];
    for(int i = 0; i < size; i++){
        totals[i] = 0;
    }
    for(int x = 0; x < numVertices-1; x++){
        LinkedListNode *min = this->V[1].L.head;
        for(int j = 0; j < size; j++){
            int k = min->W.weights[j]+totals[j];
            int l = min->W.weights[mintemp]+totals[mintemp];
            if((k) > (l)){
                mintemp = j;
            }
        }
    for(int i = 0; i < numVertices; i++){
        LinkedListNode *current = this->V[i].L.head;
        while(current != NULL){
            for(int j = 0; j < size; j++){
                if((current->W.weights[j]+totals[j]) > (current->W.weights[temp]+totals[temp])){
                    temp = j;
                }
            }
            int e = current->W.weights[temp]+totals[temp];
            int d = min->W.weights[mintemp]+totals[mintemp];
            if((e) < (d)){
                if(!U.find(current->origin, current->dest)){
                    min = current;
                    mintemp = temp;
                    }
                
        
                }
            else if(e == d){
                if(current->origin!=min->origin || current->dest!=min->dest){
                int *fIndices = new int[size];
                int *sIndices = new int[size];
                for(int r = 0; r < size; r++){
                    fIndices[r] = 0;
                    sIndices[r] = 0;
                }
                if(compareSollins(current->W.weights, min->W.weights, totals, fIndices, sIndices, mintemp, temp, size)){
                    if(!U.find(current->origin, current->dest)){
                        min = current;
                        mintemp = temp;
                    }
                }
                
            }
            }
            
            current = current -> next;
        }
      }
        for(int t = 0; t < size; t++){
            totals[t]+=min->W.weights[t];
        }
        U.unite(min->origin,min->dest);
        LArray[x] = *min;
   }
    LinkedListNode t = LinkedListNode();
    for(int i = 0; i < numVertices-1; i++)
    {
        for(int j = 0; j < numVertices-1; j++)
        {
            if(LArray[j].origin > LArray[i].origin)
            {
                t = LArray[i];
                LArray[i] = LArray[j];
                LArray[j] = t;
            }
        }
    }

    for(int i = 0; i < numVertices-1; i++){
        LArray[i].printLinkedListNodeTest();
    }
    for(int i = 0; i < size; i++){
        cout << totals[i] << " ";
    }
}
bool Graph::compareNodes(int *first, int *second, int *checkArray,  int temp, int mintemp, int size){
    if(first[temp] == second[mintemp]){
        first[temp] = temp;
        second[mintemp] = mintemp;
        for(int j = 0; j < size; j++){
            if((first[j]+checkArray[j]) > (first[temp]+checkArray[temp])){
                for(int i = 0; i < size; i++){
                    if(first[i] == j){
                        j =j+1;
                    }
                }
                temp = j;
                }
            }
        
        for(int j = 0; j < size; j++){
            if((second[j]+checkArray[j]) > (second[mintemp]+checkArray[mintemp])){
                for(int i = 0; i < size; i++){
                    if(second[i] == j){
                        j =j+1;
                    }
                }
                mintemp = j;
            }
        }
        return compareNodes(first, second, checkArray, temp, mintemp, size);
    }
    if(first[temp] < second[mintemp]){
        return false;
    }
    
    return true;
}
LinkedListNode &Graph::compareMax(LinkedListNode *L1, LinkedListNode *L2){
    if(L1->getMax() == L2->getMax()){
        L1->W.weights[L1->maxIndex] = 0;
        L2->W.weights[L2->maxIndex] = 0;
        LinkedListNode L(compareMax(L1, L2));
        return L;
    }
    if(L1->getMax() < L2->getMax()){
        return *L2;
    }
    return *L1;
}

void Graph::Sollins(int size, int capacity, int numVertices){
    this->LArray = new LinkedListNode[numVertices];
    int temp = 0;
    int mintemp = 0;
    UnionFind U(numVertices);
    int numTrees = numVertices;
    int *totals = new int[size];
    int *checker = new int[numVertices];
    for(int i = 0; i < size; i++){
        totals[i] = 0;
    }
    for(int i = 0; i < numVertices; i++){
        checker[i] = 0;
    }
    while(numTrees > 1){
        int f = 0;
        for(int i = 1; i < numVertices; i++){
            checker[0] = i;
            int t = 1;
            for(int j = 0; j < numVertices; j++){
                if(U.find(checker[0], j)){
                    checker[t] = j;
                    t++;
                }
            }
            LinkedListNode *min = this->V[checker[0]].L.head;
            for(int j = 0; j < numVertices; j++){
                if(checker[j] != 0){
                    for(int x = 0; x < size; x++){
                        int k = min->W.weights[x]+totals[x];
                        int l = min->W.weights[mintemp]+totals[mintemp];
                        if((k) > (l)){
                            mintemp = x;
                        }
                    }
                    LinkedListNode *current = this->V[checker[j]].L.head->next;
                    while(current != NULL){
                        for(int q = 0; q < size; q++){
                            if((current->W.weights[q]+totals[q]) > (current->W.weights[temp]+totals[temp])){
                                temp = q;
                            }
                        }
                        int e = current->W.weights[temp]+totals[temp];
                        int d = min->W.weights[mintemp]+totals[mintemp];
                        if((e) < (d)){
                            if(!U.find(current->origin, current->dest)){
                                min = current;
                                mintemp = temp;
                            }
                        }
                        else if(e == d){
                                int *fIndices = new int[size];
                                int *sIndices = new int[size];
                                for(int r = 0; r < size; r++){
                                    fIndices[r] = 0;
                                    sIndices[r] = 0;
                                }
                                if(compareSollins(current->W.weights, min->W.weights, totals, fIndices, sIndices, mintemp, temp, size)){
                                    if(!U.find(current->origin, current->dest)){
                                        min = current;
                                        mintemp = temp;
                                    }
                                }
                                
                            }
                            
                             current = current->next;
                        }
                    
                    }
                
                }
                for(int t = 0; t < size; t++){
                    totals[t]+=min->W.weights[t];
                }
                U.unite(min->origin,min->dest);
                LArray[f] = *min;
            numTrees--;
            f++;
            }
        }
    LinkedListNode t = LinkedListNode();
    for(int i = 0; i < numVertices-1; i++)
    {
        for(int j = 0; j < numVertices-1; j++)
        {
            if(LArray[j].origin > LArray[i].origin)
            {
                t = LArray[i];
                LArray[i] = LArray[j];
                LArray[j] = t;
            }
        }
    }

    for(int i = 0; i < numVertices-1; i++){
        LArray[i].printLinkedListNodeTest();
    }
    for(int i = 0; i < size; i++){
        cout << totals[i] << " ";
    }
    
}

void Graph::Prims(int size, int capacity, int numVertices){
    UnionFind U(numVertices);
    this->LArray = new LinkedListNode[capacity];
    int *totals = new int[size];
    int temp = 0;
    int mintemp = 0;
    int *tempArray = new int[size];
    for(int i = 0; i < size; i++){
        totals[i] = 0;
    }
    this->V[1].visited = true;
    for(int x = 0; x < numVertices-1; x++){
        LinkedListNode *min = this->V[1].L.head;
        for(int j = 0; j < size; j++){
            int k = min->W.weights[j]+totals[j];
            int l = min->W.weights[mintemp]+totals[mintemp];
            if((k) > (l)){
                mintemp = j;
            }
        }
        for(int i = 1; i < numVertices; i++){
            if(this->V[i].visited == true|| x == 0){
            LinkedListNode *current = this->V[i].L.head;
            while(current != NULL){
                for(int j = 0; j < size; j++){
                    if((current->W.weights[j]+totals[j]) > (current->W.weights[temp]+totals[temp])){
                        temp = j;
                    }
                }
                int e = current->W.weights[temp]+totals[temp];
                int d = min->W.weights[mintemp]+totals[mintemp];
                if((e) < (d)){
                    if(!U.find(current->origin, current->dest)){
                        min = current;
                        mintemp = temp;
                    }
                    
                    
                }
                else if(e == d){
                    if(current->origin!=min->origin || current->dest!=min->dest){
                        int *fIndices = new int[size];
                        int *sIndices = new int[size];
                        for(int r = 0; r < size; r++){
                            fIndices[r] = 0;
                            sIndices[r] = 0;
                        }
                        if(compareSollins(current->W.weights, min->W.weights, totals, fIndices, sIndices, mintemp, temp, size)){
                            if(!U.find(current->origin, current->dest)){
                                min = current;
                                mintemp = temp;
                            }
                        }
                        
                    }
                }
                
                current = current -> next;
            }
        }
        }
        for(int t = 0; t < size; t++){
            totals[t]+=min->W.weights[t];
        }
        U.unite(min->origin,min->dest);
        this->V[min->origin].visited = true;
        this->V[min->dest].visited = true;
        LArray[x] = *min;
    }
    LinkedListNode t = LinkedListNode();
    for(int i = 0; i < numVertices-1; i++)
    {
        for(int j = 0; j < numVertices-1; j++)
        {
            if(LArray[j].origin > LArray[i].origin)
            {
                t = LArray[i];
                LArray[i] = LArray[j];
                LArray[j] = t;
            }
        }
    }

    for(int i = 0; i < numVertices-1; i++){
        LArray[i].printLinkedListNodeTest();
    }
    for(int i = 0; i < size; i++){
        cout << totals[i] << " ";
    }


}

void Graph::FixedStart(int size, int capacity, int numVertices){
    UnionFind U(numVertices);
    this->LArray = new LinkedListNode[capacity];
    int *totals = new int[size];
    int temp = 0;
    int mintemp = 0;
    int *tempArray = new int[size];
    for(int i = 0; i < size; i++){
        totals[i] = 0;
    }
    for(int x = 0; x < numVertices-1; x++){
        LinkedListNode *min = this->V[1].L.head;
        for(int j = 0; j < size; j++){
            int k = min->W.weights[j]+totals[j];
            int l = min->W.weights[mintemp]+totals[mintemp];
            if((k) > (l)){
                mintemp = j;
            }
        }
        for(int i = 0; i < numVertices; i++){
            LinkedListNode *current = this->V[i].L.head;
            while(current != NULL){
                for(int j = 0; j < size; j++){
                    if((current->W.weights[j]+totals[j]) > (current->W.weights[temp]+totals[temp])){
                        temp = j;
                    }
                }
                int e = current->W.weights[temp]+totals[temp];
                int d = min->W.weights[mintemp]+totals[mintemp];
                if((e) < (d)){
                    if(!U.find(current->origin, current->dest)){
                        min = current;
                        mintemp = temp;

                    }
                    
                    
                }
                else if(e == d){
                    if(current->origin!=min->origin || current->dest!=min->dest){
                        int *fIndices = new int[size];
                        int *sIndices = new int[size];
                        for(int r = 0; r < size; r++){
                            fIndices[r] = 0;
                            sIndices[r] = 0;
                        }
                        if(compareSollins(current->W.weights, min->W.weights, totals, fIndices, sIndices, mintemp, temp, size)){
                            if(!U.find(current->origin, current->dest)){
                                min = current;
                                mintemp = temp;

                            }
                        }
                        
                    }
                }
                
                current = current -> next;
            }
        }
        for(int t = 0; t < size; t++){
            totals[t]+=min->W.weights[t];
        }
        min->fixedMark = true;
        U.unite(min->origin,min->dest);
    }
    
    for(int i = 0; i < numVertices; i++){
        LinkedListNode *current = this->V[i].L.head;
        while(current != NULL){
            if(current->fixedMark == true){
                current->printLinkedListNodeTest();
            }
            current = current->next;
        }

    }
    for(int i = 0; i < size; i++){
        cout << totals[i] << " ";
    }

        }


bool Graph::compareSollins(int *first, int *second, int *totals, int *fIndices, int *sIndices, int mintemp, int temp, int size){
    fIndices[temp] = 1;//temp is now forbidden
    sIndices[mintemp] = 1;//mintemp ios now forbidden
    temp = -1;//reset
    mintemp = -1;//reset
    for(int i = 0; i < size; i++){
        if(fIndices[i]!=1){
            temp = i;//find first reference value
            i = size;//just break now
        }
    }
    
    for(int i = 0; i < size; i++){
        if(sIndices[i]!=1){
            mintemp = i;//find the first reference value
            i = size;//just break now
        }
    }
    if(mintemp == -1 || temp == -1){//no more reference values all possibilities are same
        return false;
    }
    
    for(int i = 0; i < size; i++){
        if(fIndices[i] != 1){
            if((first[i] + totals[i]) > (first[temp] + totals[temp]))
                temp = i;
        }
    }
    
    for(int i = 0; i < size; i++){
        if(sIndices[i] != 1){
            if((second[i] + totals[i]) > (second[mintemp] + totals[mintemp]))
                mintemp = i;
        }
    }
    int e = first[temp] + totals[temp];
    int d = second[mintemp] + totals[mintemp];
    if(e < d){
        return true;
    }
    if(e == d){
        return compareSollins(first, second, totals, fIndices, sIndices, mintemp, temp, size);//if it's equal we go back to the drawing board
    }
    return false;//e > d
}