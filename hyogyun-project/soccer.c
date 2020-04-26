#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////////////////////////////////

char get_select();
int get_ran(int range);
void print_score(int my_score, int com_score);
void attack(int* my_score, int* com_score);
void defence(int* my_score, int* com_score);
void game_start();
void game_explanation();
void game();

////////////////////////////////////////////////////////////////////////

int main() {
    srand(time(NULL));
    game();
    return 0;
}

/////////////////////////////////////////////////////////////////////////

char get_select() {
    char c;

    printf("==============================================\n");
    printf("    Welcome to Penalty Shootout!!\n");
    printf("==============================================\n\n");
    while(1) {
        printf("게임 설명(e), 게임 Start(s), 게임 End(q) 입력: ");
        c = getchar();

        if(c == 'e' || c =='s' || c == 'q') return c;
    }
}

// range 1 - n
int get_ran(int range) {
    return rand()%range+1;
}

void print_score(int my_score, int com_score) {
    printf("======================\n");
    printf("    Score\n");
    printf("======================\n\n");
    printf("나의 점수   :   컴퓨터 점수\n");
    printf("        %-4d:%4d\n\n", my_score, com_score);
}

void attack(int* my_score, int* com_score) {
    int dir, ran;

    ran = get_ran(6);
    printf("<<골 차기 방향 선택>>\n");
    printf("왼쪽 아래(1) 왼쪽 위(2)\n");
    printf("가운데 아래(3) 가운데 위(4)\n");
    printf("오른쪽 아래(5) 오른쪽 위(6) : \n");
    scanf("%d", &dir);
    getchar();

    if(dir == ran) {
        printf("No goal!! 상대가 막았습니다. ㅠㅠ\n\n");
    }
    else if(dir < 1 || dir > 6) {
        printf("골이 골대를 벗어났습니다. ㅠㅠ\n\n");
    }
    else {
        printf("Wow Goal!!\n\n");
        (*my_score)++;
    }
}

void defence(int* my_score, int* com_score) {
    int dir, ran;

    ran = get_ran(7);
    printf("<<수비 차기 방향 선택>>\n");
    printf("왼쪽 아래(1) 왼쪽 위(2)\n");
    printf("가운데 아래(3) 가운데 위(4)\n");
    printf("오른쪽 아래(5) 오른쪽 위(6) : \n");
    scanf("%d", &dir);
    getchar();

    if(dir == ran) {
        printf("방어 성공!!\n\n");
    }
    else if(ran == 7) {
        printf("No goal!! 골이 골대를 벗어났습니다.\n\n");
    }
    else {
        printf("상대편 Goal!!!!!\n\n");
        (*com_score)++;
    }
}

void game_start() {
    int my_score=0, com_score=0;
    int play_time=0;

    printf("======================\n");
    printf("    Let's Start!!\n");
    printf("======================\n\n");

    while(1) {
        ++play_time;

        attack(&my_score, &com_score);
        print_score(my_score, com_score);
        defence(&my_score, &com_score);
        print_score(my_score, com_score);

        if(play_time == 10) {
            if(my_score > com_score) {
                printf("You Win!! 축하합니다!!\n\n");
                printf("계속하려면 아무 키나 누르십시오...\n\n");
                getchar();
                return;
            }
            else if(my_score < com_score) {
                printf("You lose 다음 기회에..\n\n");
                printf("계속하려면 아무 키나 누르십시오...\n\n");
                getchar();
                return;
            }
            else {
                --play_time;
            }
        }
    }
}

void game_explanation() {
    int select;

    printf("======================\n");
    printf("    <<게임 설명>>\n");
    printf("======================\n\n");
    printf("* 홀수 번쨰는 내가 키커(상대가 골키퍼), 짝수 번쨰는 내가 골키퍼(생대가 키커\n");
    printf("* 각자 5번씩 총 10번 수행\n");
    printf("* 게임을 시작하려면(1), 메인 화면으로 돌아가려면(2) 누르세요 : ");

    scanf("%d", &select);
    getchar();
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
