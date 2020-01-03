// k광년 이동한 후에는 k-1, k, k+1 광년 이동 할 수 있음
// 이론상 0처음에는 -1, 0, 1광년을 이동할 수는 있으나 의미가 없으므로 처음에는 1광년을 이동한다.

// input  : x, y ( 0 <= x < y < 2^31 )
// output : 각 testCase 에 대하여 x->y로 도달하는데 최소한의 횟수로 이동한 횟수를 출력

#include<iostream>
using namespace std;

void sol(int x, int y) {
	int distance = y-x;
	int sub = 1, cnt = 0;

	while( distance > 0 ) {

		if( distance - sub > 0 ) {
			distance -= sub;
			++cnt;
		}
		else {
			++cnt;
			break;
		}				

		if( distance - sub > 0 ) {
			distance -= sub;
			++cnt;
			++sub;
		}
		else {
			++cnt;
			break;
		}	
	}

	cout << cnt << endl;
}

int main() {
	int t, x, y;


	cin >> t;
	for(int i=0; i<t; ++i) {
		cin >> x >> y;
		sol(x, y);
	}
	return 0;
}