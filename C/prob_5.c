/*
	음수를 입력하여
	-8645 를 입력하면 5468- 이 출력되게하는 프로그램을 짜세요
*/

#include<stdio.h>
#include<string.h>
#define MAX_CHAR 10000

int main() {
	char string[MAX_CHAR];
	char tmp;

	int i=0;
	while( (tmp = getchar()) != '\n' ) {
		string[MAX_CHAR-i] = tmp;
		++i;
	}

	for(int j=i-1; j>=0; --j) {
		putchar(string[MAX_CHAR-j]);
	}
	printf("\n");
	return 0;
}