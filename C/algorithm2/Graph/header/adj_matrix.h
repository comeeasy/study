#ifndef _ADJ_MATRIX_H__
#define _ADJ_MATRIX_H__

#include <iostream>
#include <cstdio>
#include <string>
#include "myNode.h"

#define MAX_VERTEX 100
using namespace std;

class matrixGraph {
private :
    int graph[MAX_VERTEX][MAX_VERTEX];
    int V, E;
public  :
    matrixGraph();
    void get_adj_matrix(const char* filename);
    void show_graph();
    int char_to_int(char c);
    char int_to_char(int i);
    // int i is for recursive method
    void dfs_recur(int i) const;
    void dfs_adj_matrix_nonrecur() const;
};

#endif
