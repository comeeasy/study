#include<stdio.h>

int sol(int a, int b, int v) {
	if(a == v) return 1;

	if( (v-a)%(a-b) == 0 ) 	return ((v-a)/(a-b) + 1);
	else					return ((v-a)/(a-b) + 2);
}

int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d\n", sol(a, b, v));
	return 0;
}