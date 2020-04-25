#include <stdio.h>

int score[5];

void input_score() {
    printf("점수를 입력 받습니다. ");
    for(int i=0; i<5; ++i) {
        printf("%d 회차의 점수를 입력하세요.\n", i+1);
        scanf("%d", score+i);
    }
}

void printf_score() {
    int sum=0;

    printf("점수를 출력합니다.\n");
    for(int i=0; i<5; ++i) {
        printf("%d회차 : %d\n", i+1, score[i]);
        sum+=score[i];
    }
    printf("합계 : %d\n", sum);
}

void fix_score() {
    int n;

    printf("점수를 수정합니다.\n");
    printf("몇회차 점수를 수정할까요?\n");
    scanf("%d", &n);
    printf("점수는 몇점입니까?\n");
    scanf("%d", score+n-1);
}

int choose_function() {
    printf("========================================\n");
    printf("기능을 선택하세요. 1: 입력, 2:출력, 3.수정\n");
    int num;
    scanf("%d", &num);
    switch(num) {
        case 1:
            input_score(); break;
        case 2:
            printf_score(); break;
        case 3:
            fix_score(); break;
    }

    return 0;
}

int main() {
    while(1) {
        choose_function();
    }
}
