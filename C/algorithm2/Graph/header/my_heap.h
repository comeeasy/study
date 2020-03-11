#ifndef __MY_HEAP_H__
#define __MY_HEAP_H__

#include "adj_list.h"
#include <iostream>
#include <cstdlib>
#include <climits>

#define MAX_HEAP 1
#define MIN_HEAP 0
#define MAX_COMPO 100

#define BY_KEY 0
#define BY_WEIGHT 1
using namespace std;

class heap {
private :
    int container[MAX_COMPO];
    int n;      // num of components in heap
    int config;
public  :
    heap();
    heap(int _config);

    void push(int key);
    void push(int key, int by);
    int top() const;
    void pop();
    int is_empty() const;

    void show_heap() const;
};

#endif
