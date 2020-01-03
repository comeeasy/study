// 입력 : n ( 1 <= n <= 1,000,000,000 )
// 출력 : 입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나쳐 가는지? 

#include<stdio.h>

int solution( int n ) {
	// n >= 1
	int sub = 0, tmp = n, cnt = 0;

	tmp -= 1;
	if(tmp <= 0)	return 1;

	while( tmp > 0 ) {
		tmp -= sub;
		++cnt;
		sub += 6;
	}

	return cnt;
}

int main() {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", solution(n));
	
	return 0;
}