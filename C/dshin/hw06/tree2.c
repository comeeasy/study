//==================================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree2.h"

//==================================================================

NODE* create_node(int item) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));

    new_node->data = item;
    // 노드의 좌우 자식 노드들은 초기에 NULL로 설정한다.
    // 아무것도 없기 때문이다.
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//==================================================================

// test-tree2.c 를 보면 각 NODE* 에 각 노드들을 메모리 할당하여 
// 가리키게 하고 그 포인터들을 가지고 트리를 만드는 것이므로
// root 노드의 left, right 링크들만 설정해주면 된다.
void add_child(NODE* root, NODE* left, NODE* right) {
    // 주어진 root 노드를 부모 노드로 하고
    // left를 왼쪽 자식 노드
    root->left = left;
    // right를 오른쪽 자식노드로 설정한다.
    root->right = right;
}

//==================================================================

int sum_tree(NODE* root) {
    // return할 sum 변수 선언
    int sum = 0;

    // root가 NULL이라면 해당 노드가 존재하지 않는 것이므로 
    // 0을 return 하고, 탈출 구문에 해당함
    if(root == NULL) return 0;

    // inorder traverse 방식으로 진행 하되 
    // 왼쪽 자식의 subtree의 sum_tree 값을 더하고
    sum += sum_tree(root->left);
    // 현재 노드의 data값을 더하고
    sum += root->data;
    // 오른쪽 자식 노드의 subtree의 sum_tree값을 더한다.
    sum += sum_tree(root->right);

    return sum;
}

//==================================================================