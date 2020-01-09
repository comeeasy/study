// input	: 세 변의 길이가 공백을 사이로 주어지고 마지막은 0 0 0 이 입력되고,
//			  입력됐다면 프로그램 종료
// output	: 주어진 세 변으로 삼각형을 만들었을 때 직각삼각형이라면 
//			  "right", 틀렸다면, "wrong" 출력			  			  

#include <iostream>
using namespace std;

typedef long long unsigned llu;

// 빗변이 될 길이 찾기
llu* longest(llu* x, llu* y, llu* z) {
	if( *x > *y ) {
		if( *x > *z ) return x;
		else		return z;
	}
	else {
		if( *y > *z )	return y;
		else		return z;
	}
}

int main() {
	llu x, y, z;
	llu* hypo; // 빗변

	while(1) {
		cin >> x >> y >> z;
		if(x == 0 && y == 0 && z == 0) break;

		hypo = longest(&x, &y, &z);
		// a^2 + b^2 = c^2 은 a^2 + b^2 + c^2 = 2*c^2 이다.
		if( 2*(*hypo)*(*hypo) == x*x + y*y + z*z )
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	
	return 0;
}