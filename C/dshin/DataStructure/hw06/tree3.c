//==================================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree3.h"

//==================================================================

// 노드를 계속 생성하고 초기화해야하므로
// tree2.h에서 정의하였던 create_node함수를 
// 다시 사용하였다.
NODE* create_node(int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));

    new_node->key = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//==================================================================

NODE* insert_node(NODE* root, int key) {
    NODE *new_node, *current;

    // root에 아무것도 없다면 그냥 root에 새로운 노드를 삽입하면 된다.
    if(root == NULL) {
        root = create_node(key);
        return root;
    }
    else {
        // 그렇지 않다면 새로운 노드를 생성하고 비교할 노드를 가리킬
        // current를 설정하고 가장 먼저 root부터 비교한다.
        current = root;
        new_node = create_node(key);

        // 만약 새로운 노드의 key값이 현재 가리키는 
        while(1) {
            // 새로운 노드가 현재 노드보다 작다면
            if(key < current->key ) {
                // 현재 노드의 왼쪽 노드가 없다면 해당 위치에 삽입
                if(current->left == NULL) {
                    current->left = new_node;
                    return root;
                }
                // 현재 노드의 왼쪽 노드가 존재한다면 current node를
                // 왼쪽 자식 노드로 옮김
                else {
                    current = current->left;
                }
            }
            // 새로운 노드가 현재 노드보다 크다면 
            else {
                // 그리고 현재 노드의 오른쪽 자식 노드가 비어있다면
                if(current->right == NULL) {
                    current->right = new_node;
                    return root;
                }
                // 오른쪽 자식 노드가 있다면 다시 current node를
                // 오른쪽 자식 노드로 옮김
                else {
                    current = current->right;
                }
            }
        }
    }
}

//==================================================================

/*
    binary search tree의 기본 구조는 왼쪽 자식 노드의 key값이 부모 노드의
    것보다 작고 오른쪽 자식 노드의 key값이 부모 노드의 것보다 크다는 것이다.

    따라서 기본적으로 왼쪽 자식 노드 -> 부모 노드 -> 오른쪽 자식 노드 의 순서대로
    출력한다면 오름차순으로 정렬된 형태로 출력될 것이다.
    
    inorder 순서대로 출력하는 것은 tree2에서 보였기 때문에 설명하지 않겠다.
*/
void print_inorder(NODE* root) {
    if(root == NULL) return;

    print_inorder(root->left);
    printf("(%d)", root->key);
    print_inorder(root->right);
}

//==================================================================