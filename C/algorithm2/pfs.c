#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define UNSEEN (-INT_MAX)

typedef struct _node {
    struct _node* next;
    int vertex;
    int weight;
} node;

node* G[MAX_VERTEX];
int check[MAX_VERTEX];
int parent[MAX_VERTEX];

FILE* fp;

int nheap=0;
int heap[MAX_VERTEX];

void upheap(int k) {
    
}
