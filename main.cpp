//
//  main.cpp
//  cs130b Final Project
//
//  Created by Vikram Sastry on 5/5/16.
//  Copyright © 2016 Vikram Sastry. All rights reserved.
//

#include <iostream>
#include "Vertex.h"
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "WeightList.h"
#include "Graph.h"
#include <string>
#include <sstream>
#include "Heap.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    bool compareSollins(int *first, int *second, int *totals, int *fIndices, int *sIndices, int mintemp, int temp, int size);
   // ifstream in("data.txt");
   // streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    //cin.rdbuf(in.rdbuf());
    
     cout << "Welcome to Vikram's CS 130b Final Project" << endl;
     cout << "You will enter a Graph and this program will create a Minimum Spanning Tree with various algorithms." << endl;
     cout << "Please specify which algorithm to use for this run through (1 for Kruskal's, 2 for Prim's, 3 for Sollin's, 4 for Fixed Start, 5 for Personal" << endl;
     int algorithmType;
     cin >> algorithmType;
     cout << "Now enter the number of Vertices in the graph." << endl;
     int numVertices;
     cin >> numVertices;
     cout << "Now enter the number of Edges in the graph." << endl;
     int capacity;
     cin >> capacity;
     cout << "Now enter the number of weights in each vector for each Edge." << endl;
     int vectorSize;
     cin >> vectorSize;
     cout << "Now enter the output type" << endl;
     int outputType;
     cin >> outputType;
    clock_t begin = clock();
    Graph G  = Graph(numVertices+1);
    cout << "Enter the edges" <<endl;
    string edge;
    int i = 0;
    int n;
    while(getline(cin, edge)){
        int *temp = new int[vectorSize+2];
        if(i == capacity+1)
            break;
        istringstream stream(edge);
        int k = 0;
        while(stream >> n){
            if(k >= vectorSize+2)
                break;
            temp[k] = n;
            k++;
        }
        int *temp1 = new int[vectorSize];
        for(int f = 0; f < vectorSize; f++){
            temp1[f] = temp[f+2];
        }
        
        i++;
        
        G.V[temp[0]].addNode(new LinkedListNode(temp1, temp[1], vectorSize, temp[0]));
    }
   // LinkedListNode *L1 = new LinkedListNode(w, 2, 4, 1);
    //G.V[1].addNode(new LinkedListNode(w, 2, 4, 1));
    
    
   // for(int i = 0; i < 4; i++){
    //    G.V[1].L.printLinkedListTest();
    //}

    //  for(int i = 1; i < numVertices+1; i++){
    //  G.V[i].printVertexTest();
   //}
 
    if(algorithmType == 1){
      G.Kruskals(vectorSize, capacity, numVertices);
    }
    
    if(algorithmType == 2){
        G.Prims(vectorSize, capacity, numVertices);
    }
    
    if(algorithmType ==3){
        G.Sollins(vectorSize, capacity, numVertices);
    }
    
    if(algorithmType == 4){
        G.FixedStart(vectorSize, capacity, numVertices);
    }
    
    if(algorithmType == 5){
        G.YILI(vectorSize, capacity, numVertices);
    }
 
    /*  int x = 1;
    Heap H = Heap(capacity+1);
    for(int m = 1; m <=numVertices; m++){
        LinkedListNode *current = G.V[m].L.head;
        while(current != NULL){
            if(x <= capacity){
                H.array[x] = *current;
                current = current -> next;
                x++;
            }
        }
    }
    H.occupied = 40;
    H.makeHeap();

  
   for(int t = 1; t <= H.occupied; t++){
        H.array[t].printLinkedListNodeTest();
       cout << t << endl;
    }
*/
    
    
    //for(int i = 1; i < numVertices+1; i++){
      //     G.V[i].printVertexTest();
        //}
    
   /* int *totals = new int[vectorSize];
    int *fIndices = new int[vectorSize];
    int *sIndices = new int[vectorSize];
    int *first = new int [vectorSize];
    int *second = new int[vectorSize];
    for (int i = 0; i < vectorSize; i++){
        totals[i] = 0;
        fIndices[i] = 0;
        sIndices[i] = 0;
        first[i] = i+10;
        second[i] = i+10;
    }
    first[2] = 8;
    second[2] = 9;
    int temp = 3;
    int mintemp = 3;
    if(compareSollins(first, second, totals, fIndices, sIndices, mintemp, temp, vectorSize)){
        cout << "It worked bro"<< endl;
    }
    */
    cout << endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time elapsed: " << elapsed_secs << endl;
    return 0;
}

