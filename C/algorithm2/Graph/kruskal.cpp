#include <iostream>
#include "./header/my_heap.h"
#include "./header/set.h"

#define MAX_VERTEX 50
#define MAX_EDGE 100

using namespace std;

typedef struct _edge {
    int v1;
    int v2;
    int weight;
} edge;

void kruskal() {
    weightedListGraph wg(weighted_graph.txt);
    heap h;
    set s;

    int n, try=0;
    

}
