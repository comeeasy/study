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
            for(int j=i+i; j<MAX; j+=i) {
                prime[j] = 0;
            }
        }
    }

    //for(int i=0; i<100; ++i) printf("%d ", prime[i]);
}

int main() {
    int row = 18;
    int out = 0;
    int sum = 0;

    printf("몇번째 줄(row)까지 출력할 것인지 입력하세요 : ");
    scanf("%d", &row);

    init_prime();

    for(int i=1; i<=row; ++i) {
        for(int j=0; j<(row-i); ++j) {
            printf("   ");
        }
        for(int j=1; j<=i; ++j) {
            while(prime[out++]==0 && out < MAX); 
            printf("%3d   ", prime[out-1]);
            sum += prime[out-1];
        }
            printf("\n");
    }
    
    printf("\n\n");
    printf("출력한 소수의 총 합은 %d 입니다.  \n\n", sum);
    return 0;
}