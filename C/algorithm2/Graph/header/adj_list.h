#ifndef __ADJ_LIST_H__
#define __ADJ_LIST_H__

#include <iostream>
#include <cstdio>
#include "myNode.h"

#define MAX_VERTEX 100
using namespace std;

class listGraph {
private :
    int V, E;
    node* graph[MAX_VERTEX];
public :
    listGraph();
    void input_adj_list(const char* source_file);
    void show_graph();
    int char_to_int(char c);
    char int_to_char(int i);
};

#endif
