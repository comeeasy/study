#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/*
    빈 집합을 생성하여 return 함
*/
SET* create() {
    SET* s;

    s = malloc(sizeof(SET));
    s->n = 0;

    return s;
}
/*
    집합  set에 element가 포함되어 있으면 TRUE, 그렇지
    않으면 FALSE return defined by macro
*/
int member(SET* set, int element) {
    for(int i=0; i<set->n; ++i) {
        if(set->elem[i] == element)
            return TRUE;
    }
    return FALSE;
}
/*
    return num of element
*/
int length(SET* set) {
    return set->n;
}
/*
    set에 원소 element를 추가한 후 그 집합을 return함
    주의 할 점은 중복되는 원소를 허용하지 않는다는 점이다.
*/
SET* insert(SET* set, int element) {
    int n = set->n;

    // 처음부터 끝까지 탐색하여 중복되는 원소가 있다면 그대로 return
    for(int i=0; i<n; ++i) {
        if(set->elem[i] == element) return set;
    }

    // for문을 탈출하지 못했으므로 중복되는 원소가 존재하지 않는다.
    // 원래 크기보다 1큰 인덱스에 저장함
    if(n < MAX-1) {
        set->elem[n] = element;
        (set->n)++;
    }
    else {
        printf("\n-------- array is full. cannot insert -----------\n");
    }

    // 배열의 최대 크기보다 원래 크기가 더 작았다면 삽입, 아니라면 경고 후 return
    return set;
}
/*
    set에 element를 제거한 후 그 집합을 return함
*/
SET* delete(SET* set, int element) {
    if((set->n) == 0) {
        printf("\n---------- array is empty ------------\n");
    }
    else {
        for(int i=0; i<set->n; ++i) {
            if(set->elem[i] == element) {
                (set->n)--;
                for(int j=i; j<set->n; ++j) {
                    set->elem[j] = set->elem[j+1];
                }
                break;
            }
        }
    }

    return set;
}
/*
    set1, set2의 교집합 return
*/
SET* intersection(SET* set1, SET* set2) {
    SET* set = create();

    for(int i=0; i<set1->n; ++i) {
        for(int j=0; j<set2->n; ++j) {
            if(set1->elem[i] == set2->elem[j])
                set = insert(set, set1->elem[i]);
        }
    }

    return set;
}
/*
    집합 set1, set2의 합집합을 return함
*/
SET* sunion(SET* set1, SET* set2) {
    SET* set = create();

    for(int i=0; i<set1->n; ++i) set = insert(set, set1->elem[i]);
    for(int i=0; i<set2->n; ++i) set = insert(set, set2->elem[i]);

    return set;
}
/*
    set1, set2의 차집합 return
*/
SET* difference(SET* set1, SET* set2) {
    SET* set;
    SET* inter_set;

    set = sunion(set1, set1);
    inter_set = intersection(set1, set2);

    for(int i=0; i<inter_set->n; ++i)
        set = delete(set, inter_set->elem[i]);

    free(inter_set);
    return set;
}
/*
    집합의 모든 우너소를 한 줄에 출력함.
    이 때 집합 기호 {, } 를 출력하고 각 원소 사이에
    (,)를 출력
*/
void print(SET* set) {
    printf("{%d", set->elem[0]);
    for(int i=1; i<set->n; ++i)
        printf(", %d", set->elem[i]);
    printf("}\n");
}

int main() {
    SET *s1, *s2, *s3, *s4, *s5, *s6;

    // s1
    s1 = create();
    s1 = insert(s1, -10);
    s1 = insert(s1, 30);
    s1 = insert(s1, -20);
    s1 = insert(s1, 5);
    s1 = insert(s1, -20);
    s1 = insert(s1, 90);
    s1 = insert(s1, -70);
    printf("s1=");
    print(s1);

    // s2
    s2 = create();
    s2 = insert(s2, 5);
    s2 = insert(s2, -15);
    s2 = insert(s2, -20);
    s2 = insert(s2, -50);
    s2 = insert(s2, 15);
    s2 = insert(s2, -70);
    s2 = insert(s2, 90);
    s2 = insert(s2, -3);

    printf("s2=");
    print(s2);

    // member
    if (member(s1, 30) == TRUE)
        printf("member(s1,30)=TRUE\n");
    else if (member(s1, 30) == FALSE)
        printf("member(s1,30)=FALSE\n");
    else
        printf("member(s1,30)=???\n");

    if (member(s2, -90) == TRUE)
        printf("member(s2,-90)=TRUE\n");
    else if (member(s2, -90) == FALSE)
        printf("member(s2,-90)=FALSE\n");
    else
        printf("member(s2,-90)=???\n");

     // length
     printf("length(s1)=%d\n", length(s1));
     printf("length(s2)=%d\n", length(s2));

     // s3 = s1 U s2
     s3 = sunion(s1, s2);
     printf("s1Us2=");
     print(s3);

     // s4 = s1 ^ s2
     s4 = intersection(s1, s2);
     printf("s1^s2=");
     print(s4);

     // s5 = s1 - s2
     s5 = difference(s1, s2);
     printf("s1-s2=");
     print(s5);

     // s6 = s2 - s1
     s6 = difference(s2, s1);
     printf("s2-s1=");
     print(s6);

     return EXIT_SUCCESS;

}
