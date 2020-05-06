#include<stdio.h>

int clap(int i) {
    int r;

    while(i != 0) {
        r = i%10;
        i /= 10;
        //printf("r = %d\n", r);
        if(r == 3 || r == 6 || r == 9) return 1;
    }

    return 0;
}

int main() {
    int number, a, b, c, d;

    printf("1000이하의 자연수를 입력하십시오 : ");
    scanf("%d", &number);

    if(number < 1 || number > 1000) {
        printf("1부터 1000이하의 자연수를 입력하세요.\n");
    }
    for(int i=1; i<=number && i<1000; ++i) {
        if(clap(i)) printf("  *  ");
        else printf("  %d  ", i);
        if(i%10 == 0) printf("\n");
    }
    
    printf("\n\n");
    return 0;
}