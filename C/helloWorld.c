#include<stdio.h>
#define MAX_VERTEX 100

int G[MAX_VERTEX][MAX_VERTEX];

// 정의된 배열이나 키보드나 파일로부터 그래프를 구성하는 자료를 입력받아
// 인접 행렬을 구축하는 함수를 작성해보자
void input_adjmatrix( int a[][MAX_VERTEX], int* V, int* E ) {
	char vertex[3];
	fscanf( fp, "%d %d", V, E );
	for
