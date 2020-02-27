#include "./header/myNode.h"

node::node() : key(0) { next = NULL; }
node::node(int _key) : key(_key) { next = NULL; }
node::~node() { delete this; }
void node::set_key(int _key) { key = _key; }
void node::set_next(node* _next) { next = _next; }
node* node::get_next() { return next; }
int node:: get_key() { return key; }
bool node::is_next_null() {
    if(this->next) return 0;
    else     return 1;
}
