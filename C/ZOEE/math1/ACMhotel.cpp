// 입력 : 1: T(testcase) 2: H, W, N (1<=H,W<=99), (1<=N<=H*W)
// 출력 : T개만큼의 배정되어햐하는 방 번호 출력

#include<iostream>
using namespace std;

void sol(int H, int W, int N) {
	int room_number;

	if((N%H) == 0)	room_number = ((N/H)) + H*100;
	else			room_number = ((N/H) + 1) + (N%H)*100;
	cout << room_number << endl;
}

int main() {
	int T, H, W, N;

	cin >> T;
	for(int i=0; i<T; ++i) {
		cin >> H >> W >> N;
		sol(H, W, N);
	}
	
	return 0;
}