/*
은행계좌의 입출금을 관리하는 프로그램을 작성하시오

(계좌 잔고를 저장하는 전역 변수 balance를 선언하고, 초기 금액으로 계좌에 1000원이 있다고 하자
정적 지역 변수 amount를 사용하여 총 출금액과 총 입금액을 관리한다.
입금하는 save() 함수와 출금하는 withdraw() 함수를 구현한다.

이 두 함수는 한 개의 int형 매개변수를 사용하여 매개변수 값을 입력한 금액으로 입출금을 구현하도록 한다

void save( int money )
void withdraw( int money )

save(10000), withdraw(5000), save(50000), withdraw(30000) 순서대로 호출할 때의 실행결과를 출력해보세요


입금액    출금액    총입금액 총출금액    잔고
                    1000
10000        10000            11000
    5000         -5000        6000
50000        60000            56000
    30000        -35000        26000
----------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>

int balance = 1000;

void print_account( int key, int _money )    {
   
    static int total_save = 0;
    static int total_withdraw = 0;   
   
    if( key == 1 )    {
       
        total_save += _money;
        printf("%-8d        %-10d          %-8d\n", _money, total_save, balance );
    }
    else if( key == 2 )    {
       
        total_withdraw -= _money;
        printf("        %-8d          %-10d%-8d\n", _money, total_withdraw, balance );
    }
}

void save( int money )    {
   
    int key = 1;
   
    balance += money;
    print_account( 1, money );
}

void withdraw( int money )    {
   
    int key = 2;
   
    balance -= money;
    print_account( 2, money );
}

int main()    {
   
    int money;
   
    printf("입금액  출금액  총입금액  총출금액  잔고\n");
    save(10000);
    withdraw(5000);
    save(50000);
    withdraw(30000);
           
    return 0;
}
 
