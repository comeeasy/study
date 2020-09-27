//==================================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree1.h"

//==================================================================

// array로 tree를 구현하기 위해 root index는 1부터 시작하며
// node가 없는 메모리에는 -1을 저장한다
void init_tree(TREE* t) {
    for(int i=0; i<MAX_TREE_SIZE; ++i)
        // 처음엔 아무 노드도 없으므로 모두 -1
        t->data[i] = -1;
}

//==================================================================

/*
    preorder : left-node -> current-node -> right_node
    inorder  : current-node -> left-node -> right-node
    postorder: left-node -> right-node -> current-node

    예를 들어 inorder의 순서를 살펴보면 왼쪽 노드를 먼저 방문하고 현재 노드를 방문 후,
    오른쪽 노드를 방문하는 것이다. 이 의미를 조금더 자세히 살펴보면
    왼쪽 노드 아래에 있는 모오든 노드를 방문하고 현재 노드로 오고, 
    그 다음 오른쪽의 모오든 노드를 방문하라는 의미이다. 

    따라서 각 노드들을 방문하기전에 왼쪽 노드를 모두 스택에 넣어놓고 더 이상 넣을 노드가 없다면
    그 위에 있는 현재 노드와 오른쪽 노드를 방문함이 맞다. 혹은 재귀적으로 함수를 정의하는 방법이 
    있을 것이며, 여기서는 재귀적으로 방문하는 방법으로 프로그램을 짤 것이다.
*/

// parent node -> left_node -> right_node
// test-tree1.c를 보면 preorder함수에서 tree의 방문 노드의 data값을
// 출력해야함을 알 수 있다.
void preorder_tree(TREE* t, int root) {
    // 탈출 조건
    if(t->data[root] == -1 || root >= MAX_TREE_SIZE) return;

    // 현재 노드 방문
    printf("(%d)", t->data[root]);
    // left child
    preorder_tree(t, root*2);
    // right child
    preorder_tree(t, root*2 + 1);
}

//==================================================================

// preorder와 전혀 다를 것이 없다. 방문의 순서만 다르다
// inorder는 left child를 먼저 방문하고 자신을 방문하고
// right child를 방문한다.
void inorder_tree(TREE* t, int root) {
    // 탈출 조건
    if(t->data[root] == -1 || root >= MAX_TREE_SIZE) return;

    // left child
    inorder_tree(t, root*2);
    // 현재 노드 방문
    printf("(%d)", t->data[root]);
    // right child
    inorder_tree(t, root*2 + 1);
}

//==================================================================

void postorder_tree(TREE* t, int root) {
    // 탈출 조건
    if(t->data[root] == -1 || root >= MAX_TREE_SIZE) return;

    // left child
    postorder_tree(t, root*2);
    // right child
    postorder_tree(t, root*2 + 1);
    // 현재 노드 방문
    printf("(%d)", t->data[root]);

}
//==================================================================