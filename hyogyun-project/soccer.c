#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_select() {
    char c;

    printf("==============================================\n");
    printf("    Welcome to Penalty Shootout!!\n");
    printf("==============================================\n\n");
    while(1) {
        printf("게임 설명(e), 게임 Start(s), 게임 End(q) 입력: ");
        c = getchar();

        if(c == 'e' && c =='s' && c == 'q') return c;
    }
}

void print_score(int my_score, int com_score) {
    printf("======================\n");
    printf("    Score\n");
    printf("======================\n\n");
    printf("나의 점수   :   컴퓨터 점수\n");
    printf("        %-4d:%+4d\n\n", my_score, com_score);
}

void attack(int ran, int* my_score, int* com_score) {
    int dir;

    printf("<<골 차기 방향 선택>>");
    printf("왼쪽 아래(1) 왼쪽 위(2)\n");
    printf("가운데 아래(3) 가운데 위(4)\n");
    printf("오른쪽 아래(5) 오른쪽 위(6) : \n");
    scanf("%d", &dir);

    if(dir == ran) {
        printf("No goal!! 상대가 막았습니다. ㅠㅠ\n\n");
    }
    else if(dir < 1 && dir > 7) {
        printf("골이 골대를 벗어났습니다. ㅠㅠ\n\n");
    }
    else {
        printf("Wow Goal!!\n\n");
        (*my_score)++;
    }
}

void defence(int ran, int* my_score, int* com_score) {

}

void game_start() {
    int ran;
    int my_score, com_score;
    int result;

    printf("======================\n");
    printf("    Let's Start!!\n");
    printf("======================\n\n");

    srand(time(NULL));
    while(1) {
        ran = rand()%7 + 1;

        attack(ran);
    }
}

void game_explanation() {
    int select;

    printf("======================\n");
    printf("    <<게임 설명>>\n");
    printf("======================\n\n");
    printf("* 홀수 번쨰는 내가 키커(상대가 골키퍼), 짝수 번쨰는 내가 골키퍼(생대가 키커\n");
    printf("* 각자 5번씩 총 10번 수행\n");
    printf("* 게임을 시작하려면(2), 메인 화면으로 돌아가려면(1) 누르세요 : ");

    scanf("%d", &select);
    if(select == 1) game_start();
}

void game() {
    char select;

    while(1) {
        select = get_select();

        switch(select) {
            case 'e' : game_explanation(); break;
            case 's' : game_start(); break;
            case 'q' : return;
        }
    }
}


int main() {

}
