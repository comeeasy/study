// ======================================================================
     #include <stdio.h>
     #include <stdlib.h>                                                                                          
     #include "tree1.h"               
// ====================================================================== 

int main(void) {
    int i;
    // TREE를 포인터가 아닌 변수 자체로 선언
    TREE t1;

    printf("==== test-tree1 ====\n");

    // t1의 주소를 인자로 전달함으로써 포인터로서 인자로 전달
    init_tree(&t1);
    // root 노드의 index는 1부터 시작하고, 각 노드의 순서는
    // 아래와 같다 0에는 * 연산을 할 수 없기 떄문이다.
    for(i = 1; i < MAX_TREE_SIZE - 3; i++ )
    // MAX_TREE_SIZE - 3 은 마지막 뒤의 노드 3개를 넣지 않겠다는 의미이다.
    // 즉 22번 노드까지만 삽입한다는 의미이다. 
        t1.data[i] = 10 + i;
    
    // preorder 순서대로 각 노드들을 출력
    printf("preorder=");
    preorder_tree(&t1, 1);
    printf("\n");

    // inorder 순서대로 노드들을 출력
    printf("inorder=");
    inorder_tree(&t1, 1);
    printf("\n");

    // postorder 순서대로 노드들을 출력
    printf("postorder=");
    postorder_tree(&t1, 1);
    printf("\n");

    return EXIT_SUCCESS;
}