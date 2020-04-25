#include <stdio.h>

int function1(int* n0, int* n1) {
    int tmp, num0, num1;

    while(1) {
        printf("첫번째 수를 입력하시오 : ");
        scanf("%d", n0);
        printf("두번째 수를 입력하시오 : ");
        scanf("%d", n1);

        if(*n0 > 0 && *n1 > 0) {
            num0 = *n0;
            num1 = *n1;
            break;
        }
    }

    do {
        //printf("n0: %d,   n1: %d\n", num0, num1);

        // 둘이 같다면 최대공약수는 그들 자신
        if(num0 == num1) break;
        if(num0 < num1) {
            tmp = num0;
            num0 = num1;
            num1 = tmp;
        }

        num0 = num0 % num1;
    } while(!(num0 == 0));

    printf("최대 공약수는 %d입니다.\n", num1);
    return num1;
}

void function2(int n0, int n1, int g) {
    int result = (n0*n1)/g;

    printf("최소 공배수는 %d입니다.\n", result);
}

int main() {
    int n0, n1, g;

    g = function1(&n0, &n1);
    function2(n0, n1, g);
    return 0;
}
