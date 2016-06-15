//
//  WeightList.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/12/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//
#include "WeightList.h"
#include <stdio.h>
#include <iostream>
using namespace std;
WeightList::WeightList(){
    this->size = 0;
    this->weights = new int [size];
}

WeightList::WeightList(int size, int*&weights){
    this->size = size;
    this->weights = new int[size];
    for(int i = 0; i < size; i++){
        this->weights[i] = weights[i];
    }
}

/*void WeightList::copyWeights(int *&weightsOrig, int *&weightsNew){
    int size = weightsOrig[0];
    weightsNew = new int[size];
    for(int i = 1; i <=size; i++){
        if(weightsOrig==NULL){
            cout << "Error: weightsOrig has an error on element";
            return;
        }
        weightsNew[i] = weightsOrig[i];
        
    }
    return;
}
*/


WeightList& WeightList::operator=(WeightList const &rhs){
    this->size = rhs.size;
    if(this->weights != NULL){
       delete[] weights;
    }
    this->weights = new int[this->size];
    for(int i = 0; i < this->size; i++){
        this->weights[i] = weights[i];
    }
    //  memcpy(&this->weights, &rhs.weights, this->size);
    return *this;
}


WeightList::~WeightList(){
    if(this->weights[0]<100000 || this->weights != NULL){
      //   delete[] this->weights;
    }
   
}

void WeightList::printWeightList(){
    
    for(int i = 0; i<this->size; i++){
        cout << weights[i] << " ";
    }
    cout <<endl;
}