/*
    목표물 갯수(n)입력
    목표물 정보 n회 입력
    폭탄 정보 입력
    점수 출력
   
    목표물은 x, y좌표, 강도, 점수 정보를 입력받음
    폭탄은 x, y좌표ㅡ 강도 정보를 입력받음
    목표물의 위치는 겹칠 수 있음
    폭탄이 터질 때, 강도에 따라 다음범위에 있는 목표물에 영향을 끼침
    폭탄에 영향 받는 목표물 중 강도가 폭탄보다 작은 목표물만 점수를 받을 수 있음
   
    x, y 좌표는 0 - 9
    목표물 강도는 0 - 4
    폭탄 강도는  1 - 5
    목표물 개수(n)는 1 - 100
    점수는 1 - 100000
   
    해당 범위에서 벗어난 입력은 고려하지 않는다
   
    - 목표물의 정보를 구조체로 생성
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>

typedef struct _targer    {
   
    int x;
    int y;
    int power;
    int score;
} target;

typedef struct _bomb    {
   
    int x;
    int y;
    int power;
} bomb;

void gotoxy( int x, int y )    {
    COORD pos = {x, y};
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), pos );
}

void wait( float seconds )    {
    clock_t endwait;
    endwait = clock() + (float)seconds*CLOCKS_PER_SEC;
    while( clock() < endwait );
}

//목표물에 폭탄이 영향을 미쳤는지
int is_boom( target t, bomb b )    {
   
    int distance = abs( t.x - b.x ) + abs( t.y - b.y );
   
    if( distance <= b.power )    {    
        if( t.power < b.power )    {          
            return 1;
        }
        else    {          
            return 0;
        }
    }     
    else
        return 0;
   
}

void play_game( target* t, bomb b, int n )    {
   
    int distance;
   
    gotoxy(2,1);
    printf("bomb game!");    //y=1 에는 bomb game! 출력
   
    //map
    for( int i=0; i<10; ++i )    {
       
        for( int j=0; j<10; ++j )    {
           
            gotoxy(i+2, j+3);
            printf("#");
        }
    }
   
    //input info
    gotoxy( 2, 17 );        //y=17 에는 목표물 정보 n회 입력
    printf("number of targets :  %d", n);
    gotoxy(2,19);
    printf("info of bomb: location: ( %d, %d ) power: %d", b.x, b.y, b.power);    //y=19에는 폭탄 정보
    for( int i=0; i<n; ++i )    {
       
        //밑으로는 목표물 정보
        gotoxy(2,21+i);
        printf("target #%d : location: ( %d, %d ) power: %d score: %d", i+1, t[i].x, t[i].y, t[i].power, t[i].score );
    }
   
    //playing game
    for( int i=0; i<n; ++i )    {
       
        gotoxy( t[i].x+2, t[i].y+3 );
        printf("%d", i+1);
        wait(0.3);
    }
    wait(1);
   
    gotoxy(1, 14);
    printf("-------!!!!bomb is coming!!!!!----------");
    gotoxy(1, 15);
    printf("5");
    wait(1);
    gotoxy(1, 14);
    printf("-------!!!!bomb is coming!!!!!----------");
    gotoxy(1, 15);
    printf("4");
    wait(1);
    gotoxy(1, 14);
    printf("-------!!!!bomb is coming!!!!!----------");
    gotoxy(1, 15);
    printf("3");
    wait(1);
    gotoxy(1, 14);
    printf("-------!!!!bomb is coming!!!!!----------");
    gotoxy(1, 15);
    printf("2");
    wait(1);
    gotoxy(1, 14);
    printf("-------!!!!bomb is coming!!!!!----------");
    gotoxy(1, 15);
    printf("1");
    wait(1);
   
    for( int i=0; i<b.power; ++i )    {
       
        for( int j=0; j<10; ++j )    {           
            for( int k=0; k<10; ++k )    {               
                distance = abs( b.x - j ) + abs( b.y - k );
               
                if( distance <= i  )    {
                    gotoxy(j+2, k+3);
                    printf("*");
                }                                       
            }
        }
       
        wait(0.5);
    }
}

void clean_con()    {
   
    for( int i=0; i<40; ++i )
        for( int j=0; j<30; ++j )    {
            gotoxy(i,j);
            printf(" ");
        }
           
}

int main()    {
   
    int n;
    int total_score = 0, dest[100];
    bomb b;
   
    //목표물 갯수(n) 입력
    scanf("%d", &n);
   
    //목표물 정보 n회 입력
    target t[n];
    for( int i=0; i<n; ++i )    {
       
        scanf("%d, %d, %d, %d", &t[i].x, &t[i].y, &t[i].power, &t[i].score);
    }
   
    //폭탄 정보 입력
    scanf("%d, %d, %d", &b.x, &b.y, &b.power);
   
    clean_con();
    play_game( t, b, n );

    gotoxy(1, 21+n);
    printf("score is");
    wait(0.3);
    printf(".");
    wait(0.3);
    printf(".");
    wait(0.3);
    printf(".");
    wait(0.3);
    printf(".");
    //점수 출력
    for( int i=0; i<n; ++i )    {
       
        if( is_boom( t[i], b ) )    {
           
            total_score += t[i].score;
        }       
    }
    printf("  %d", total_score);
   
    return 0;
}