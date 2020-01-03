// 입력 : 1: T, 2: k, 3: n (1 <=k, n <= 14
// 출력 : T에 대한 해당 집 거주민 수 (k층 n호)

#include<iostream>
#define MAX 14
using namespace std;
// index 순으로 층, 호수
int registers[MAX+1][MAX+1];

void mk_apartment() {
	// initialization
		// 0층에 대한 거주민 (0층 i호에는 i명이 산다.)
	for(int i=1; i<=MAX; ++i)	registers[0][i] = i;
		// 각 층의 1호는 1명이 삼
	for(int i=1; i<=MAX; ++i)	registers[i][1] = 1;

	// 1층부터, 2호부터 아랫집과 같은 층 i-1호에 사는 사람의 수를 더한게 i호에 사는 사람 수
	for(int i=1; i<=MAX; ++i) {
		for(int j=2; j<=MAX; ++j) {
			registers[i][j] = registers[i-1][j] + registers[i][j-1];
		}
	}
}

int main() {
	int T, k, n;

	mk_apartment();
	cin >> T;
	for(int i=0; i<T; ++i) {
		cin >> k >> n;
		cout << registers[k][n] << endl;
	}
	return 0;
}