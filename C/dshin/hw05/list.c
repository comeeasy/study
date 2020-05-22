// ============================================================

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ============================================================

// list에 포함된 data를 순서대로 출력한다.
// 출력형식은 (n: i1, i2, ..., in)이다. 
// 여기서 n은 list에 포함된 node의 개수이고 i1, i2, ..
// in은 각 data이다.
void print_list(NODE* list) {
    NODE* tmp = list;

    printf("(%d:", length_list(list));
    for(int i=0; i<length_list(list)-1; tmp = tmp->link, ++i) {
        printf("%d,", tmp->data);
    }
    printf("%d)\n", tmp->data);
}

// list에 포함된 node의 개수를 return한다.
int length_list(NODE* list) {
    int l = 0;

    for(NODE* p = list; p != NULL; p = p->link) ++l;
    return l;
}

// list의 n번째 (n>=1) node의 주소를 return 한다.
// 오류 발생 시 (return NULL)
NODE* nth_list(NODE* list, int n) {
    NODE* to_return = list;

    for(int i=0; i<n-1; ++i) to_return = to_return->link;
    return to_return;
}

// list의 맨 앞에 item이 저장된 새 node를 생성하여
// 추가한후 수정된 list의 주소를 return한다.
NODE* add_list(NODE* list, int item) {
    NODE* new_node;

    new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = item;
    new_node->link = list;

    return new_node;
}

// list의 맨 앞 node를 제거한 후 수정된 list의 주소를
// return 한다. (return NULL)
NODE* delete_list(NODE* list) {
    NODE* tmp1, tmp2;

    tmp1 = list;
    if(length_list(list) > 0) {
        do {
            tmp2 = tmp1->link;
            free(tmp1);
            tmp1 = tmp2;
        } while(tmp2 != NULL);
    }
    else return NULL;
}

// ============================================================