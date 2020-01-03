#include<stdio.h>
#include<stdlib.h>

int main() {

	char c;

	scanf("%c", &c);
	// ab\n 입력
	printf("c: %c\n", c);

	fflush(stdin);

	scanf("%c", &c);
	// b\n 입력
	printf("c: %c\n",c );

	return 0;
}