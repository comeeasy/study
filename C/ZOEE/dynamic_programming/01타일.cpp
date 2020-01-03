/*
	input  : n ( 0 <= n <= 1,000,000 )
	output : 00 타일과 1 타일을 가지고 만들 수 있는 가지 수를 15746 으로 나눈 수를 출력
*/
#include<iostream>

#define DIVIDER 15746
#define N_MAX 1000000
using namespace std;

int com[N_MAX+1];
inline void mk_com() {
	com[1] = 1;
	for(int i=2; i<N_MAX+1; ++i) {
		com[i] = ( (i*com[i-1]) % DIVIDER );
	}
}

int solution(int n) {
	int sum = 0;

	for(int i=0; n-2*i >= 0; ++i) {
		sum += ( com[n-i] / (com[n-2*i]*com[i]) );
		sum %= DIVIDER;
	}
}

int main() {
	int n;
	cin >> n;
	mk_com();

	cout << solution(n) << endl;

	return 0;
}	