/*
    덧셈과 뺄셈, 곱셈, 나눗셈 중에 원하는 연산을 입력하여 계산하고,
    각 연산의 수행 쵯수를 출력하는 계산기 프로그램 작성
    
    (각 연산을 지원하는 함수들은 해당 연산을 수행하고, 정적 지역변수를 사용하여
    해당 연산의 수행 횟수를 기억하고 출력하도록 구한다.)
    총 5번의 연산을 입력받고, 입력한 연산의 수행 횟수와 결과를 출력하도록 한다.
*/
#include<stdio.h>

void cal( int num1, int num2, int key )    {
    
    static int add_num = 0;
    static int sub_num = 0;
    static int mult_num = 0;
    static int div_num = 0;
    
    switch( key )    {
        
        case 1 :
            ++add_num;
            printf("덧셈 횟수 : %d\n", add_num);
            printf("결과 : %d\n", num1 + num2);
            break;
        case 2 :
            ++sub_num;
            printf("뺄셈 횟수 : %d\n", sub_num);
            printf("결과 : %d\n", num1 - num2);
            break;
        case 3 :
            ++mult_num;
            printf("곱셈 횟수 : %d\n", mult_num);
            printf("결과 : %d\n", num1 * num2);    
            break;
        case 4 :
            ++div_num;
            printf("나눗셈 횟수 : %d\n", div_num);
            printf("결과 : %.2g\n", (float)num1 / num2);
            break;
    }
}

int main()    {
    
    int num1, num2;
    int key;
    char tmp;
    
    for( int i=0; i<5; ++i )    {
        
        printf("연산을 입력하세요( 예 1+2 ) : ");
        scanf("%d%c%d", &num1, &tmp, &num2 );
        
        if( tmp == '+' )
            key = 1;
        else if( tmp == '-' )
            key = 2;
        else if( tmp == '*' )
            key = 3;
        else if( tmp == '/' )
            key = 4;
                
        cal( num1, num2, key );
    }    
    
    return 0;
}