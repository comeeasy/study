// 정수 n이 주어졌을 떄, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

// input	: 첫째 줄에 testcase T, 둘째 줄에 n ( 1<= n <= 10)
// output	: 각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.

#include<iostream>
using namespace std;

int factorial[11];
void init_factorial() {
	factorial[0] = 1;
	factorial[1] = 1;
	for(int i=2; i<11; ++i)	factorial[i] = i*factoral[i-1];
}


int function(int n) {
	int N = n;

	for(int a=0; a<=3; ++a) {
		if( 3*a > n )	break;
		for(int b=0; b<=5; ++b) {
			
			for(int c=0; c<=10; ++c) {

			}
		}
	}
}


int main() {
	int t, n, ans;

	init_factorial();
	cin >> t;
	for(int i=0; i<t; ++i) {
		ans = 0;
		cin >> n;
		ans += function(n);
	}	

	return 0;
}