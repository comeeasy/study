#define TRUE    1
#define FALSE   0

/*
    정수를 원소로 가지는 집합, 하나의 집합은 최대 1024개까지의 원소를 저장
    구조체 형 SET에 집합의 원소들은 정수 배열 변수로 표현하고, 집합의
    원소의 개수는 정수 변수로 표현함, 하나의 집합은 SET* 로 표현함
typedef sturct set {
    ...
} SET;

SET* create();
int member(SET* set, int element);
int length(SET* set);
SET* inset(SET* set, int element);
SET* delete(SET* set, int element);
SET* sunion(SET* set1, SET* set2);
SET* intersection(SET* set1, SET* set2);
SET* difference(SET* set1, SET* set2);
void print(SET* set);
