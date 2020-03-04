#ifndef __SET_H__
#define __SET_H__

#include <iostream>
#include <string>
#include <fstream>

#define ONLY_FIND 0
#define UNION 1
#define MAX_ELEMENT 30
using namespace std;

class set {
    int num_elem;
    int parent[MAX_ELEMENT];
    int height[MAX_ELEMENT];
public  :
    set();
    void union_set(int elem, int asso);
    int find_set(int elem, int asso, int flag);
    void union_set2(int elem, int asso);
    void print_set() const;
    void input_relation(const char* file_name);
    void input_relation2(const char* file_name);
};

#endif
