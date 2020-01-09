// 세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한
// 네 번째 점을 찾는 프로그램 작성

// input	: 세점의 좌표가 한 줄에 하나씩 주어짐, 
//			  좌표는 1 이상, 1000 이하의 정수
// output	: 직사각형의 네 번째 점의 좌표를 출력한다.
#include <iostream>
using namespace std;

// 입력받은 좌표중 하나씩만 있됨는 x, y좌표를 출력하면 
int find_one(int* base) {
	int a, cnt;
	for(int i=0; i<3; ++i) {
		cnt = 0;
		for(int j=0; j<3; ++j) {
			if(base[i] ==base[j]) ++cnt;
		}
		if(cnt == 1) return base[i];
	}
}

int main() {
	int x[3], y[3];
	for(int i=0; i<3; ++i) 
		cin >> x[i] >> y[i];

	cout << find_one(x) << ' ' << find_one(y) << endl;
	return 0;
}

