/*                                                          */
/* KRUSKAL.C : Minimum Cost Spanning Tree                   */
/*                                                          */
/*      Programmed by Lee jaekyu                            */
/*                                                          */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 50
#define MAX_EDGE 100

#define ONLY_FIND 0
#define UNION 1

int parent[MAX_VERTEX]; // 집합을 나타내는 나무의 구조 유지 */
int height[MAX_VERTEX]; // 집합을 나타내는 나무의 높이를 저장 //
int cost = 0;

FILE* fp;

typedef struct _edge {
    int v1, v2;
    int weight;
} edge;
edge Edge[MAX_VERTEX];

int name2int(char c) {return (c-'A');}
char int2name(int i) {return (i+'A');}

int nheap=0;
int heap[MAX_VERTEX];

/* 여기서는 max heap이 아니라 min heap을 만들어야 최소 비용 신장 나무를 구할 수 있다.*/


// k번쨰 요소를 맨 마지막 번호에서 제자리로 올릴 함
// k는 보통 nheap+1 이 될 것이다.
void upheap(int h[], int k) {
    int v = h[k];
    // heap에는 edge들을 넣어준다 그리고 heap에 있는 vertex를 인덱스 삼아
    // 실제 weight를 비교한다.
    while(Edge[h[k/2]].weight >= Edge[v].weight && k/2 > 0) {
        // 부모 노드의 edge의 weight가  자식노드의 weight보다 크다면 보모노드를
        // 자식노드로 끌어 내린다.
        h[k] = h[k/2];
        k /= 2;
    }
    // 더 이상 끌어내리지 못한다면 그곳이 v의 자리이므로 assgin
    h[k] = v;
}
// k번째 요소를 제자리에 가도록 내릴 함수
// k에는 보통 1이 온다 (==root position)
void downheap(int h[], int k) {
    int i, v = h[k];
    while(k <= nheap/2) {  // k번째 노드가 internal node라면,
        i = k << 1; // k *= 2;
        // 자식 노드중 가장 큰 녀석을 선택
        if(i < nheap && Edge[h[i]].weight > Edge[h[i+1]].weight) ++i;
        if(Edge[v].weight <= Edge[h[i]].weight) break;
        h[k] = h[i];
        k = i;
    }
    h[k]=v;
}
void print_parent(int V) {
    printf("vertex | ");
    for(int i=0; i<V; ++i) printf("%c ", int2name(i));
    printf("\nparent | ");
    for(int i=0; i<V; ++i) printf("%c ", int2name(parent[i]));
    printf("\nheight | ");
    for(int i=0; i<V; ++i) printf("%d ", height[i]);
}
void print_heap(int h[], int n) {
    printf("\n---------------print_heap------------\n");
    for(int i=1; i<=n; ++i) {
        printf("%c%c %d ", int2name(Edge[h[i]].v1), int2name(Edge[h[i]].v2),
                                    Edge[h[i]].weight);
    }
    printf("\n---------------------------------------\n");
}
void pq_insert(int h[], int v) {
    h[++nheap] = v;
    // nheap번째 새로 들어온 요소를 upheap
    upheap(h, nheap);
}
void pq_init() {nheap=0;}
int pq_empty() {
    if(nheap == 0) return 1;
    return 0;
}
int pq_extract(int h[]) {
    int v = h[1];
    h[1] = h[nheap--];
    downheap(h, 1);
    return v;
}
// balancing tree 구조로 함수를 만듬
void union_set(int elem, int asso) {
    int t;
    if(height[elem] == height[asso]) height[asso]++;
    if(height[elem] > height[asso]) {
        t = elem;
        elem = asso;
        asso = t;
    }
    parent[elem] = asso;
}
int find_set(int elem, int asso, int flag) {
    int i=elem, j=asso, t;

    // elem, asso의 뿌리를 찾음
    while(parent[i] >= 0) i=parent[i];
    while(parent[j] >= 0) j=parent[j];
    if(flag==UNION && i!=j) union_set(i, j);
    return (i!=j);
}
void find_init(int elem) { for(int i=0; i<elem; ++i) parent[i] = -1; }
void input_edge(edge e[], int* V, int* E) {
    char vertex[3];
    int w;

    printf("\ninput number of Vertex & Edge\n");
    fscanf(fp, "%d %d", V, E);
    for(int i=0; i<*E; ++i) {
        //printf("input two Vertex consist of Edge & its weight-> ");
        fscanf(fp, "%s %d", vertex, &w);

        vertex[2] = '\0';
        e[i].v1 = name2int(vertex[0]);
        e[i].v2 = name2int(vertex[1]);
        e[i].weight = w;

        //printf("%s %d is inputted\n", vertex, w);
    }
}
void visit(int e) {
    printf("%c%c \n", int2name(Edge[e].v1), int2name(Edge[e].v2));
    cost += Edge[e].weight;
}
void kruskal(edge e[], int V, int E) {
    int n, try=0;
    // V개의 vertex 만 존재하므로 필요한 만큼만 init
    find_init(V);
    // nheap=0;
    pq_init();

    /* 이전 main 함수에서 edge에 대한 정보는 받았으므로 각 edge에 대하여
       weight 를 기준으로 min_heap에 넣어놓는다.                      */

    for(n=0; n<E; ++n) pq_insert(heap, n);
    n = 0;
    while(!pq_empty()) { // heap 에 남은 edge가 없을 때까지
        print_heap(heap, nheap);

        // try에  heap에서 꺼낸 edge의 index를 준다.
        try = pq_extract(heap);

        //  circuit 을 이루지 않으면 union
        if(find_set(e[try].v1, e[try].v2, UNION)) {
            visit(try);
            n++;
            print_parent(V);
        }
        //  edge의 수가 V-1개 라면 모든 정점을 지난것이다.
        if(n == V-1) break;
    }
}

int main(int argc, char* argv[]) {
    int V, E;

    if(argc < 2) fp = stdin;
    else {
        if((fp = fopen(argv[1], "rt")) == NULL) {
            printf("file doesn't exist\n");
            exit(1);
        }
        printf("\n\nfile is open successfully\n\n");
    }

    input_edge(Edge, &V, &E);
    printf("\n\nVisited edge if minimum spanning tree\n");
    kruskal(Edge, V, E);
    printf("\n\n Minimum Cost is %d\n", cost);
    fclose(fp);

    for(int i=0; i<V; ++i) printf("%d ", height[i]);
    printf("\n");

    return 0;
}
