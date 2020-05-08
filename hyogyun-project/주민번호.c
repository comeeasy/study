#include <stdio.h>

#define MAN 1
#define WOMAN 0

typedef struct id {
    int year;
    int month;
    int day;
    int gender;
    int validation;
} ID;

void validation(ID* id, int id_num_ft, int id_num_bk) {
    int gender_key;
    int yoon_nyun = 0;

    if(1000000 <= id_num_bk && id_num_bk <5000000) {
        gender_key = id_num_bk / 1000000;
    }
    else {
        id->validation = 0;
        return;
    }

    // if 960617
    // year = 96
    id->year = id_num_ft / 10000;
    // month = 6
    id->month = (id_num_ft - 10000*id->year) / 100;
    // day = 17
    id->day = id_num_ft - 10000*id->year - 100*id->month;

    // gender validation check && set gender
    if(id->year >= 0 && id->year <=20) {
        id->year +=2000;

        if(gender_key == 3)         id->gender = MAN;
        else if(gender_key == 4)    id->gender = WOMAN;
        else                        {id->validation = 0;}                          
    }
    else if ( 20 < id->year && id->year <=99 ){
        id->year += 1900;

        if(gender_key == 1)         id->gender = MAN;
        else if(gender_key == 2)    id->gender = WOMAN;
        else {
            id->validation = 0; 
        }        
    }

    // month validatio check
    if(id->month >= 1 && id->month <=12) 
        id->validation = 1;
    else {
        id->validation = 0;
    }
    
    // 윤년 check
    // 4의 배수인 해를 윤년으로 한다. 그러나 100으로 나눌 수 있지만
    // 400으로 나누어 떨어지지 않는 해는 예외로 평년으로 한다.
    if( id->year%4 == 0 ) {
        if(id->year%100 == 0 && id->year%400 != 0) yoon_nyun = 0;
        yoon_nyun = 1;
    }

    if(id->month == 1  && id->day >=1  && id->day <= 31) id->validation = 1;
    if(id->month == 2  && id->day >=1) {
        if(yoon_nyun == 1 && id->day <=29) id->validation = 1;
        else if(id->day <= 28)    id->validation = 1;
    }
    if(id->month == 3  && id->day >=1  && id->day <= 31) id->validation = 1;
    else if(id->month == 4  && id->day >=1  && id->day <= 30) id->validation = 1;
    else if(id->month == 5  && id->day >=1  && id->day <= 31) id->validation = 1;
    else if(id->month == 6  && id->day >=1  && id->day <= 30) id->validation = 1;
    else if(id->month == 7  && id->day >=1  && id->day <= 31) id->validation = 1;
    else if(id->month == 8  && id->day >=1  && id->day <= 31) id->validation = 1;
    else if(id->month == 9  && id->day >=1  && id->day <= 30) id->validation = 1;
    else if(id->month == 10 && id->day >=1  && id->day <= 31) id->validation = 1;
    else if(id->month == 11 && id->day >=1  && id->day <= 30) id->validation = 1;
    else if(id->month == 12 && id->day >=1  && id->day <= 31) id->validation = 1;
    else {
        id->validation = 0;
    }
}

int main() {
    int id_num_ft, id_num_bk;
    ID id;

    printf("주민번호 앞6자리를 입력하세요 : ");
    scanf("%d", &id_num_ft);

    printf("주민번호 뒤6자리를 입력하세요 : ");
    scanf("%d", &id_num_bk);

    validation(&id, id_num_ft, id_num_bk);
    if(id.validation) {
        printf("%d년 %d월 %d일 출생, %d세", id.year, id.month,id.day, 2021-id.year);
        if(id.gender == MAN) printf("남성입니다\n");
        else                 printf("여성입니다\n");
    }
    else {
        printf("잘못된 입력입니다.\n");
    }

    return 0;   
}