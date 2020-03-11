/*
    < 우선 순위 탐색을 이용하여 최단 경로 나무를 구하는 알고리즘 >

    탐색의 시작 정점을 주변 정점으로 만든다.(시작 정점을 우선 순위 큐에 집어넣는다.)
    while(모든 정점이 나무 정점이 될 때까지) {
        주변 정점 중의 한 정점 V를 나무 정점으로 만든다.
            (V는 가장 가중치가 작은 정점이다.)
        정점 V와 연결된 정점에 대해
            보이지 않는 정점 W이면 정점 V의 가중치에 W의 가중치를 더해 pq에 넣는다.
            주변 정점 W이면 기존의 가중치와 정점 V의 가중치에 W의 가중치를 더한 것을..
            ..비교하여 작은 가중치로 갱신한다.
    }
*/
#include <climits>

#include "my_heap.h"
#include "my_node.h"

#define UNSEEN (-INT_MAX)

// 교재의 C버전으로 먼저 작성
void shortest_adjlist(weightedNode* graph[], int start, int V) {
    int check[MAX_COMPO], parent[MAX_COMPO];
    int tmp;
    heap h(MAX_HEAP);

    for(int i=0; i<V; ++i) {
        check[i] = UNSEEN;
        parent[i] = 0;
    }

    tmp = start;
    if(check[tmp] == UNSEEN) {
        parent[tmp] = -1;
        h.push(tmp);
        while(!h.empty()) {
            h.show_heap();
            tmp = h.top(); h.pop();
            check[tmp] = -check[tmp];
            // visit(tmp);
            for(weightedNode* j=graph[tmp]; j!=NULL; j=j->next) {
                
            }
        }
    }
}
