#include<stdio.h>
#include<stdlib.h>

typedef struct s_node	{

	int key;
	struct s_node* next;

} node;

typedef struct stack	{

	node* peek;
	int size;

} STACK;

node* create_node( int key )	{

	node* new_node = (node*)malloc(sizeof(node));
	new_node->key = key;
	new_node->next = NULL;

	return new_node;
}

void delete_node( node* del_node )	{

	free( del_node );
}

STACK* create_stack( )	{

	STACK* new_stack = (STACK*)malloc(sizeof(STACK));
	new_stack->peek = NULL;
	new_stack->size = 0;

	return new_stack;
}

void delete_stack ( STACK* del_stack )	{

	node* tmp;

	//stack->peek이 NULL이 아닐때까지 ( peek이 NULL을 가리킨다면 탈출 )
	while ( del_stack->peek )	{

		tmp = del_stack->peek;
		del_stack->peek = del_stack->peek->next;
		delete_node ( tmp );
	}

	free( del_stack );
}

void push ( STACK* stack, int x )	{

	node* tmp;

	//stack의 size가 0이라면
	if ( stack->size == 0 )	{

		stack->peek = create_node( x );
		stack->size++;
	}
	//stack이 차있으면
	else	{

		tmp = create_node( x );
		tmp->next = stack->peek;
		stack->peek = tmp;
		stack->size++;
	}
}

void pop( STACK* stack ) 	{

	int _pop;
	node* tmp;

	if( stack->size == 0 )	{
		printf("\nstack is empty!!!!\n\n");
	}

	tmp = stack->peek;
	stack->peek = stack->peek->next;
	stack->size--;

	delete_node( tmp );
}


int main()	{

	int test_case;
	//scanf("%d", &test_case);
	test_case = 100000;

	int ary[test_case];
	char pupo[1000000];
	int end_of_ary=0;

	STACK* stack = create_stack();

	//for( int i=0; i<test_case; ++i)	{
	//	scanf("%d", &ary[i]);
	//}
	for(int i=1; i<=100000; ++i) {
		ary[i-1] = 100000-(i-1);
	}

	int j=0;
	for( int i=1; i<=test_case; ++i )	{

		//다음 수열을 위해 필요한 숫자를 파악함
		//1. i가 현재 필요한 숫자보다 큰지
		//2. top에 있는 숫자가 무엇인지

		if ( i < ary[j] )	{

			push( stack, i );
			pupo[end_of_ary] = '+';
			++end_of_ary;

		}
		// 원하는 숫자를 위에서 찾았다면
		else if ( i == ary[j] )	{

			push( stack, i);
			pupo[end_of_ary] = '+';
			++end_of_ary;

			pop( stack );
			pupo[end_of_ary] = '-';
			++end_of_ary;
			++j;

		}
		//( i < ary[j] ) 적어도 위에는 없을떄 즉 top이 원하는 숫자가 아니라면 주어진 수열은 못만듬
		else if ( i > ary[j] )	{

			//근데 top에 원하는 수가 있다면 pop해서 수열에 껴넣으면 됨
			if ( stack->peek->key == ary[j] )	{

				pop( stack );
				pupo[end_of_ary] = '-';
				++end_of_ary;

				--i;
				++j;
			}
			//그렇지도 않다면 이 수열은 글러먹음
			else if ( stack->peek->key != ary[j] )	{

				printf("NO\n");
				return 0;
			}
		}

	}

	//스택에 수가 남아있는 경우
	if ( stack->size != 0 )	{

		//스택에 있는 수가 다음 수열에 오지말아야할 경우
		if ( ary[j] != stack->peek->key )	{

			//종료
			printf("NO\n");
			return 0;
		}
		//스택에 있는 수가 다음 수열에 와야할 경우
		else

			//반복해주기 위함 , stack의 size가 0이 될때까지
			while ( ary[j] == stack->peek->key ) {

				pop( stack );
				pupo[end_of_ary] = '-';
				++end_of_ary;
				++j;

				if ( stack->size == 0 )
					break;

			}
	}

	for ( int i=0; i<end_of_ary; ++i )	{

		printf("%c\n", pupo[i]);
	}

	delete_stack( stack );
	return 0;
}
