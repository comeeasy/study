#ifndef __MY_HEAP_H__
#define __MY_HEAP_H__

#include <iostream>
#include <cstdlib>
#include <climits>

#define MAX_COMPO 100
using namespace std;

class heap {
    int container[MAX_COMPO];
    int n;      // num of components in heap
public  :
    heap();

    void push(int key);
    int top() const;
    void pop();

    void show_heap() const;
};

#endif
