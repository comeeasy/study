#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node* left;
    struct _node* right;
} Node;

typedef struct _heap {
    Node* head;         // head
    Node* last_node;    // indicate last node
} Heap;

Heap* init_heap(Heap* heap) {
    heap = (Heap*)malloc(sizeof(Heap));
    heap->head = NULL;
    heap->last_node = NULL;
}


