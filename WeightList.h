//
//  WeightList.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/12/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#ifndef WeightList_h
#define WeightList_h
//This contains k-weights of Edge E

class WeightList{
private:
    
public:
    int size=0;
    int constSize = 0;
    int *weights;
    WeightList();//Default Constructor
    WeightList(int size, int *&weights);//Copy Constructor
    int searchLowest();
    void copyWeights(int *&weightsOrig, int *&weightsNew);
    WeightList &operator=(WeightList const &rhs);
    ~WeightList();//Destructor
    void printWeightList();
};


#endif /* WeightList_h */
