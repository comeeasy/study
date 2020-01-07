// M 이상 N 이하의 소수를 모두 출려력하는 프로그램을 작성하세요
// input	: M, N (1 <= M <= N <= 1,000,000)
// output	: 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
#include <iostream>

#define MAX_NUM 1000000
#define TRUE  0
#define FALSE 1
using namespace std;

// 전역변수이므로 TRUE == 0 으로 초기화
bool is_prime[MAX_NUM];
int main() {
	int M, N;
	cin >> M >> N;

	is_prime[0] = FALSE;
	is_prime[1] = FALSE;
	for(int i=2; i<N+1; ++i) {
		if( is_prime[i] == TRUE ) {
			if( i >= M ) cout << i << endl;
			for(int j=i+i; j<N+1; j+=i ) {
				is_prime[j] = FALSE;
			}
		}
	}
	
	return 0;
}