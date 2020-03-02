#ifndef __SET_H__
#define __SET_H__

#include <iostream>
#include <cstring>
#include <fstream>

#define MAX_ELEMENT 30
using namespace std;

class set {
    int num_elem;
    int parent[MAX_ELEMENT];
    int height[MAX_ELEMENT];
public  :
    set() {
        memset(parent, sizeof(int)*MAX_ELEMENT, -1);
        memset(height, sizeof(int)*MAX_ELEMENT, 0);
    }
    void union_set(int elem, int asso);
    int find_set(int elem, int asso);
    void union_set2(int elem, int asso);
    void print_set() const;
    void input_relation(const char* file_name);
    void input_relation2(const char* file_name);
};

#endif
