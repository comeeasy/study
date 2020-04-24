/*
    project #
    학번 :
    이름 :
*/

/*
    사용해서 구현해야함
    void print_main()
    int check_triple(int num1, int num2, int num3)
    int check_double(int num1, int num2, int num3)
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

enum {INSERT_COIN = 1, SELECT_GAME, RESULT, EXIT};

int slot_num_game, slot_num_double, slot_num_triple;
int roll_num_game, roll_num_win;

int main() {
    int select;
    int coin = 0;

    void insert_coin(int*);
    void print_menu();
    void select_game(int*);
    void result(int*);

    while(1) {
        print_menu();
        scanf("%d", &select);

        if(select >= 1 && select <= 4) {
            // game continue
            switch(select) {
                case INSERT_COIN : insert_coin(&coin); break;
                case SELECT_GAME : select_game(&coin); break;
                case RESULT      : result(&coin); break;
                case EXIT        : return 0;
            }
        }
        else { // validation
            printf("잘못된 메뉴 선택입니다.\n\n");
        }
    }
}

int check_double(int num1, int num2, int num3) {
    if(num1 == num2)        return 1;
    else if(num1 == num3)   return 1;
    else if(num2 == num3)   return 1;
    else                    return 0;
}

int check_triple(int num1, int num2, int num3) {
    if(num1 == num2 && num2 == num3) return 1;
    else return 0;
}

void print_menu() {
    printf("---------------------------------\n");
    printf("1. 코인 입력\n");
    printf("2. 게임 선택\n");
    printf("3. 결과 확인\n");
    printf("4. 게임 종료\n");
    printf("---------------------------------\n");
}

void insert_coin(int* coin) {
    int tmp;

    printf("코인을 입력하세요(최소 : 500) : ");
    scanf("%d", &tmp);

    if(tmp >= 500 && tmp <= INT_MAX) {
        printf("%d코인 충전하였습니다.\n", tmp);
        *coin = tmp;
    }
    else {
        printf("500이상의 코인을 입력하세요.\n\n");
    }
}

void slot_machine(int* coin) {
    int num[3], select;
    int check_double(int num1, int num2, int num3);
    int check_triple(int num1, int num2, int num3);

    printf("Welcome to Slot Machine!\n\n");

    while(1) {
        if(*coin < 40) {
            printf("입장료가 부족합니다.\n");
            return;
        }

        for(int i=0; i<3; ++i) num[i] = rand()%10;
        printf("Your numbers are %d %d %d. ", num[0], num[1], num[2]);

        slot_num_game++;
        if(check_double(num[0], num[1], num[2])) {
            slot_num_double++;
            *coin += 40;
            printf("!!DOUBLE!!\ncoin : %d        ", *coin);
        }
        else if(check_triple(num[0], num[1], num[2])) {
            slot_num_triple++;
            *coin += 80;
            printf("!!!Triple!!!\ncoin : %d        ", *coin);
        }
        else {
            *coin -= 40;
            printf("TRY AGAIN\n coin : %d        ", *coin);
        }

        while(1) {
            printf("Continue Slot Machine? (1 : Y / 0 : N) ");
            scanf("%d", &select);
            if(select >= 0 && select <= 1) {
                if(!select) return;
                else break;
            }
            else {
                printf("잘못된 입력입니다. \n\n");
            }
        }
        printf("\n");
    }
}

void rolling_dice(int* coin) {
    int n[3], answer, select, i=1;

    printf("Welcome to Rolling Dice!\n\n");

    while(1) {
        if(*coin < 40) {
            printf("입장료가 부족합니다.\n");
            return;
        }

        for(int i=0; i<3; ++i) n[i] = rand()%10;

        printf("세 주사위의 합을 맞춰보세요 => ");
        scanf("%d", &answer);

        roll_num_game++;
        if( (n[0]+n[1]+n[2]) == answer) {
            roll_num_win++;
            *coin += i*answer;
            ++i;

            printf("Wow!!    \n");
            printf("The answer was %d\n", n[0]+n[1]+n[2]);
            printf("coin : %d        ", *coin);
        }
        else {
            i=1;
            *coin -= 40;

            printf("Try Again T^T    \n");
            printf("The answer was %d\n", n[0]+n[1]+n[2]);
            printf("coin : %d        ", *coin);
        }

        while(1) {
            printf("Continue Rolling Dice? (1 : Y / 0 : N) ");
            scanf("%d", &select);

            if(select >= 0 && select <= 1) {
                if(!select) return;
                else break;
            }
            else {
                printf("잘못된 입력입니다.\n");
            }
        }
    }
}

// sng : slot_num_game
// snw : slow_num_win
// rng : roll_num_game
// rnw : roll_num_win
void select_game(int* coin) {
    int select;

    void slot_machine(int*);
    void rollint_dice(int*);

    while(1) {
        printf("1. slot machine\n");
        printf("2. rolling dice\n");
        scanf("%d", &select);
        printf("your choice is : %d\n\n", select);

        if(select >= 1 && select <= 2) {
            // continue game
            switch(select) {
                case 1 : slot_machine(coin); break;
                case 2 : rolling_dice(coin); break;
            }
            return;
        }
        else {
            printf("올바른 입력이 아닙니다.\n\n");
        }
    }
}

void result(int* coin) {
    float rate;

    printf("잔여 코인 : %d\n", *coin);
    printf("1. SLOT MACHINE\n");
    if(slot_num_game == 0) {
        printf("    0 triples out of 0 games  [0%%]\n");
        printf("    0 doubles out of 0 games  [0%%]\n");
    }
    else {
        rate = slot_num_triple/(float)slot_num_game;
        printf("    %d triples out of %d games  [%d%%]\n", slot_num_triple, slot_num_game, (int)(rate*100));
        rate = slot_num_double/(float)slot_num_game;
        printf("    %d doubles out of %d games  [%d%%]\n", slot_num_double, slot_num_game, (int)(rate*100));
    }

    printf("2. ROLLING DICE\n");
    if(roll_num_game == 0) {
        printf("    0 answers out of 0 games [0%%]\n");
    }
    else {
        rate = roll_num_win/(float)roll_num_game;
        printf("    %d answers out of %d games [%d%%]\n", roll_num_win, roll_num_game, (int)(rate*100));
    }
}
