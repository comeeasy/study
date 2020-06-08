#include <stdio.h>
#include <stdlib.h>

//================================================

// 8bit unit
typedef char element;
typedef struct _node {
    element elem;
    struct _node* next;
} Node;

typedef struct _queue {
    Node* front;    // front
    Node* rear;     // rear
    int n;          // num of element
} Queue;

//================================================

Node* make_node(element elem);
void delete_node(Node* del);

//================================================

Queue* init_queue(Queue* q);
void enqueue(Queue* q, element elem);
void delete_queue(Queue* q);

//================================================