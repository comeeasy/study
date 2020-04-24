#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#include <stdio.h>

int insert_arr(int arr[MAX], int num, int i);
int delete_arr(int arr[MAX], int i);
void print_arr(int arr[MAX], int i);

int main() 
{    
    int n, num;
    int top = -1; 
    int arr[MAX];   
    while( 1 )
    {
        printf("[  삽입(1), 삭제(2), 출력(3), 종료(4)  ] "); 
        scanf("%d", &n);    
        switch (n)
        {        
        case 1: printf("삽입할 숫자를 입력하세요 ");
                scanf("%d", &num);
                top = insert_arr(arr, num, top);
                printf("-----------------배열출력-----------------\n");
                print_arr(arr, top);
                printf("\n----------------------------------------\n");
                break;
        case 2: top = delete_arr(arr, top);
                printf("-----------------배열출력-----------------\n");
                print_arr(arr, top);
                printf("\n----------------------------------------\n");
                break;        
        case 3: printf("-----------------배열출력-----------------\n");
                print_arr(arr, top);
                printf("\n----------------------------------------\n");
                break;
        case 4: printf("Exit program.\n");
                return 0;
        default:printf("entered undefined.\n");
                break;
        }
        puts("");
    } 
    return 0;
}

/* 삽입 함수 구현 */
int insert_arr(int arr[MAX], int num, int i)
{     
    if( i >= MAX-1 )    
    {    
        printf("\nArray is full\n");
        return i;
    }
    else    
    {    
        arr[++i] = num;
        return i;    
    }
}

int delete_arr(int arr[MAX], int i)
{   
    if( i <= -1 )    
    {    
    printf("Array is empty.\n");
    return i;
    }
    else    
        return (--i);
}

/* 출력 함수 */
void print_arr(int arr[MAX], int i)
{    
    int j;
    for( j = 0; j <= i; ++j )        
        printf("%d ", arr[j]);
} 