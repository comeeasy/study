#include <stdio.h>

#define MAX 200000
int prime[MAX];

void init_prime() {
    for(int i=0; i<MAX; ++i) prime[i] = i;
    // 0 is not prime num
    prime[1] = 0;
    
    // 에라토스테네스의 체
    for(int i=2; i<MAX-1; ++i) {
        if(prime[i]) {
            for(int j=i; j<MAX; j+=i) {
                prime[j] = 0;
            }
        }
    }
}

int main() {
    int row = 18;
    int out = 0;
    int sum = 0;

    printf("몇번째 줄(row)까지 출력할 것인지 입력하세요 : ");
    scanf_s("%d", &row);

    init_prime();
    for(int i=0; i<row; ++i) {
        for(int j=0; j<(row/2 + 1); ++row) {
            printf("   ");
        }
        for(int j=0; j<row; ++j) {
            while(!prime[out++])
            printf("%3d   ", prime[out]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("출력한 소수의 총 합은 %d 입니다.  \n\n", sum);
    return 0;
}
