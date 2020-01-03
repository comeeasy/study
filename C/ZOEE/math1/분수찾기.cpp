#include<iostream>
using namespace std;

#define UP		1
#define DOWN	0

void solution(int x) {
	int cnt=1, dir=UP;

	while(x-cnt>0) {
		x -= cnt;
		cnt++;
		dir = cnt%2;
	}

	if(dir == UP)	cout << cnt+1-x << '/' << x << endl;
	else			cout << x << '/' << cnt+1-x << endl;
}

int main() {
	int x;

	cout << "분수 찾기" << endl;
	cin >> x;
	solution(x);

	return 0;
}