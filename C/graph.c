#include<stdio.h>
#define MAX_VERTEX 100

typedef struct _node {
	struct _node* next;
	int vertex;
} Node;

Node* graph[MAX_VERTEX];
int G[MAX_VERTEX][MAX_VERTEX];

// 정의된 배열이나 키보드나 파일로부터 그래프를 구성하는 자료를 입력받아
// 인접 행렬을 구축하는 함수를 작성해보자
void input_adjmatrix( int a[][MAX_VERTEX], int* V, int* E ) {
	char vertex[3];
	fscanf( fp, "%d %d", V, E );
	// 인접 행렬 0으로 initialize
	for( int i=0, i<*V; ++i ) for( int j=0; j<*E; ++j ) a[i][j] = 0;
	// reflexive 하다고 가정
	for( int i=0; i<*V; ++i ) a[i][i] = 1;
	for( int i=0; i<*V; ++i ) {
		fscanf( fp, "%s", vertex );
		a[vertex[0]-'a'][vertex[1]-'a'] = 1;
		a[vertex[1]-'a'][vertex[0]-'a'] = 1;
	}
}

int main() {
	return 0;
}
