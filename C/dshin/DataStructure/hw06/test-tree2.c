// =====================================================

#include <stdio.h>
#include <stdlib.h>
#include "tree2.h"

// =====================================================

int main() {
    int sum;
    NODE *t0, *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11;

    printf("==== test-tree2 ====\n");

    // 0, 10, 20 의 순서대로 11개의 노드를 생성하여
    // 각 주소들을 tn(0<=n<=11) 에 저장하였다.
    t0 = create_node(0);
    t1 = create_node(10);
    t2 = create_node(20);
    t3 = create_node(30);
    t4 = create_node(40);
    t5 = create_node(50);
    t6 = create_node(60);
    t7 = create_node(70);
    t8 = create_node(80);
    t9 = create_node(90);
    t10 = create_node(100);
    t11 = create_node(110);
    
    add_child(t3, t7, t8);
    add_child(t4, t9, t10);
    add_child(t5, t11, NULL);
    add_child(t1, t3, t4);
    add_child(t2, t5, t6);
    add_child(t0, t1, t2);

    sum = sum_tree(t0);
    printf("sum_tree(t0)=%d\n", sum);

    sum = sum_tree(t1);
    printf("sum_tree(t1)=%d\n", sum);

    sum = sum_tree(t2);
    printf("sum_tree(t2)=%d\n", sum);

    sum = sum_tree(t4);
    printf("sum_tree(t4)=%d\n", sum);

    sum = sum_tree(t5);
    printf("sum_tree(t5)=%d\n", sum);    

    return EXIT_SUCCESS;
}