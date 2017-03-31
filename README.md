# Graph MMST Analysis

Implementation of MST algorithms on Graph w/ edges with k-weight, k is a natural number
This program attempted to give solutions to an intractable problem. To find a Minimum Spanning Tree to a graph with edges with k-weights. 

Order of weights:
In this problem the order of weights mattered. If I receive an edge with a weight of vector A of 4 values: 1, 2, 3, 4 I may not rearrange them when adding to another edge in the current minimum spanning tree being created. That is if I have a current MST with a total weight of vector: w, x, y, z; I may not rearrange the vector A such that A's values added to the MST total weights will give the lowest maximum. 1 must be added to w, 2 must be added to x and so on and so forth. 

Proper MST: A proper MST is an MST that has the lowest Max value. That is, given an MST A when all it's edges are added together to get weights: w, x, y, z; the maximum of these weights will be lower than all other possible spanning tree's maximum weight. If not we go to the next lowest max and so on and so forth. 


This program implemented Kruskals, Prim's, Sollin's, Fixed Iterative, and a personal algorithm on a graph with k-weights. I then timed each one and found that Sollin's was in fact the fastest algorithm both with small and large sample sizes. 
