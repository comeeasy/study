#ifndef __MYNODE_H__
#define __MYNODE_H__

#include <iostream>
using namespace std;

class node {
public :
    int key;
    node* next;
public  :
    node();
    node(int _key);
    ~node();
    void set_key(int _key);
    void set_next(node* _next);
    node* get_next();
    int get_key();
    bool is_next_null();
};

#endif
