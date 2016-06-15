//
//  UnionFind.h
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/23/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#ifndef UnionFind_h
#define UnionFind_h
class UnionFind{
public:
    int *ID;
    int size;
    UnionFind(int size);
    int root(int index);
    bool find(int a, int b);
    void unite(int a, int b);
};

#endif /* UnionFind_h */
