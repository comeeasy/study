#include<stdio.h>

int clap(int i) {
    int r, cnt=0;

    while(i != 0) {
        r = i%10;
        i /= 10;
        //printf("r = %d\n", r);
        if(r == 3 || r == 6 || r == 9) {
            ++cnt;
        }
    }

    return cnt;
}

int main() {
    int number, a, b, c, d;
    int cnt;

    printf("1000이하의 자연수를 입력하십시오 : ");
    scanf("%d", &number);

    if(number < 1 || number > 1000) {
        printf("1부터 1000이하의 자연수를 입력하세요.\n");
        return 0;
    }
    for(int i=1; i<=number && i<1000; ++i) {
        if(cnt = clap(i)) {
            printf("  ");
            for(int j=0; j<cnt; ++j) printf("*");
            printf("  ");
        }
        else printf("  %d  ", i);
        if(i%10 == 0) printf("\n");
    }
    
    printf("\n\n");
    return 0;
}