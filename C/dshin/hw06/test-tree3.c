// ================================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree3.h"

// ================================================================

int main() {
    int key;
    NODE* t1;

    printf("==== test-tree3 ====\n");

    key = 30;
    printf("insert=%d\n", key);
    t1 = insert_node(NULL, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 80;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 90;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 10;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 70;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 50;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 60;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 20;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 40;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    return EXIT_SUCCESS;
}