/*                                                                          */
/*  PFS.C : Priority First Serarch                                          */
/*                                                                          */
/*      Programmed by Lee Jaekyu                                            */
/*                                                                          */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX 100
#define UNSEEN (-INT_MAX)

typedef struct _node {
    struct _node* next;
    int vertex;
    int weight;
} node;

node* G[MAX_VERTEX];
int check[MAX_VERTEX];  // 우선 순위와 방문 여부를 저
int parent[MAX_VERTEX];

FILE* fp;

int nheap=0;
int heap[MAX_VERTEX];

int name2int(char c) {return c-'A';}
int int2name(int i)  {return i+'A';}

// k번째 힙의 원소를 올바른 위치로 상승시킴
void upheap(int h[], int k) {
    int v = h[k];
    while(check[h[k/2]] <= check[h[k]] && k/2>0) {
        h[k] = h[k/2];
        k /= 2;
    }
    h[k]=v;
}
// k번째 원소를 올바른 위치로 내림
void downheap(int h[], int k) {
    int i, v = h[k];
    while(k <= nheap/2) {
        i = k << 1;
        if(i<nheap && check[h[i+1]]>check[h[i]]) ++i;
        if(check[v]>=check[i]) break;
        h[k] = h[i];
        k = i;
    }
    h[k] = v;
}
// 상향식 힙 생성, 최초 실행시와 우선 순위가 변경되었을 경우 실행됨
void adjust_heap(int h[], int n) {
    //internal componenet에 한하여 밑에서 부터 루트노드까지 downheap
    for(int i=n/2; i>=1; --i) downheap(h, i);
}
// h는 힙, v는 정점의 번호, p는 간선의 가중치
// 힙에 새로운 원소를 추가하거나 우선 순위가 변경되면 거기에 맞게 힙을 재조정
int pq_update(int h[], int v, int p) {
    if(check[v] == UNSEEN) {
        h[++nheap] = v;
        check[v] = p;
        upheap(h, nheap);
        return 1;
    }
    else {  // 정점 v가 주변 정점이면,
        if(check[v] < p) {
            check[v] = p;   // 더 작은 가중치로 갱신
            adjust_heap(h, nheap);
            return 1;
        }
        else return 0; // 힙에 변화가 없다면 return 0
    }
}
void pq_init() {nheap=0;}
int pq_empty() {
    if(nheap==0) return 1;
    else         return 0;
}
int pq_extract(int h[]) {
    int v = h[1];

    h[1] = h[nheap--];
    downheap(h, 1);
    return v;
}
void input_adjlist(node* g[], int* V, int* E) {
    char vertex[3];
    int w;

    printf("\ninput number of vertex & edge\n");
    fscanf(fp, "%d %d", V, E);
    for(int i=0; i<*V; ++i) g[i] = NULL;
    for(int i=0; i<*E; ++i) {
        printf("\ninput two vertex consist of edge & its weight -> ");
        fscanf(fp, "%s %d", vertex, &w);

        int i = name2int(vertex[0]);
        node* t = (node*)malloc(sizeof(node));
        t->vertex = name2int(vertex[1]);
        t->weight = w;
        t->next = g[i];
        g[i] = t;

        i = name2int(vertex[1]);
        t = (node*)malloc(sizeof(node));
        t->vertex = name2int(vertex[0]);
        t->weight = w;
        t->next = g[i];
        g[i] = t;
    }
}
void print_adjlist(node* g[], int V) {
    for(int i=0; i<V; ++i) {
        printf("\n%c : ", int2name(i));
        for(node* t=g[i]; t!=NULL; t=t->next) {
            printf("->%c:%d", int2name(t->vertex), t->weight);
        }
    }
}
void print_cost(int check[], int n) {
    int cost=0;
    for(int i=1;i<n; ++i) cost += check[i];
    printf("cost = %d\n", cost);
}
void visit(int vertex) {printf("->%c", int2name(vertex));}
void print_heap(int h[]) {
    printf("\n");
    for(int i=1; i<nheap; ++i) printf("%c:%d ", int2name(h[i]), check[h[i]]);
}
void pfs_adjlist(node* g[], int V) {
    int tmp;

    pq_init();
    for(int i=0; i<V; ++i) {
        check[i] = UNSEEN;
        parent[i] = 0;
    }
    for(int i=0; i<V; ++i) {
        if(check[i] == UNSEEN) {
            parent[i] = -1;
            pq_update(heap, i, UNSEEN);
            while(!pq_empty()) {
                print_heap(heap);
                tmp = pq_extract(heap);
                check[i] = -check[i];
                visit(i);

                for(node* t=g[i]; t!=NULL; t=t->next) {
                    if(check[t->vertex] < 0) {
                        if(pq_update(heap, t->vertex, -t->weight)) {
                            parent[t->vertex] = i;
                        }
                    }
                }
            }
        }
    }
}
void print_tree(int tree[], int n) {
    printf("son    ");
    for(int i=0; i<n; ++i) printf("%c ", int2name(i));
    printf("-----------------------------\n");
    printf("parent ");
    for(int i=0; i<n; ++i) printf("%c ", int2name(tree[i]));
}
void main(int argc, char* argv[]) {
    int V, E;

    if(argc<2) fp = stdin;
    else {
        if((fp = fopen(argv[1], "rt")) == NULL) {
            printf("\n---------file is not available------------\n");
            exit(1);
        }
    }

    input_adjlist(G, &V, &E);
    printf("\n\nOriginal Graph\n");
    print_adjlist(G, V);
    printf("\n\nVisit order of Minimum Spanning Tree\n");
    pfs_adjlist(G,V);
    printf("\n\ntree structure\n");
    print_tree(parent, V);
    printf("\n\nMinimum Cost is \n");
    print_cost(check, V);
    fclose(fp);
}
