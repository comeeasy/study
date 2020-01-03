#include <iostream>

#define ANSWER_MAX 1000
using namespace std;

int solution(int x, int y, int w, int h) {
	int answer = ANSWER_MAX;

	if( w-x < answer ) 	answer = w-x;
	if( x < answer )	answer = x;
	if( h-y < answer )	answer = h-y;
	if( y < answer )	answer = y;

	return answer;
}

int main() {
	int x, y, w, h;
	int answer;

	cin >> x >> y >> w >> h;
	answer = solution(x, y, w, h);
	cout << answer << endl;

	return 0;
}