#ifndef __ADJ_LIST_H__
#define __ADJ_LIST_H__

#include <fstream>
#include <iostream>
#include <cstdio>
#include "myNode.h"
#include <vector>
#include <queue>
#include <functional>
#include <tuple>
#include <string>

#define MAX_VERTEX 100
#define UNSEEN (-INT_MAX)
using namespace std;

class listGraph {
private :
    int V, E;
    node* graph[MAX_VERTEX];
public :
    listGraph();
    void input_adj_list(const char* source_file);
    void show_graph() const;
    void dfs_adj_list_nonrecur() const;
    void bfs_adj_list_nonrecur() const;
    // too hard..
    //int ap_non_recur() const; // print articulation point
    //int ap_recur(int i);

    friend void heap::push(int key, int by);
};

// I can't guarantee if it works..
class weightedListGraph {
private :
    int V, E;
    weightedNode* graph[MAX_VERTEX];
public  :
    weightedListGraph();

    void input_data(const char* file_name);
    void input_data(int from, int end, int weight);
    void show_graph() const;
    //void pfs_adjlist();
};

#endif
