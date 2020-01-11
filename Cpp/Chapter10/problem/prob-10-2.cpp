// 문제1: '-'단항 연산자의 정의, 멤버 함수로 정의 <1,2> -> <-1, -2>
// 문제2: '~'단항 연산자의 정의, 전역 변수로 정의 <1,2> -> <2, 1>

/*
	return *this;
		구문은 실제로 지금 이 클래스의 객체 자체를 전달하는 것이로

	전역변수로 정의된 operator~ 함수는 레퍼런스로 ref 객체를 받아서
	이 객체를 다루고 return 할 때에는 복사 생성자에 의해 완전히 다른 객체를 복사하여
	return 한다. 

	컴파일 후 실행시 나타나는 출력
---------------------------------------------------
	ref add: 0x7ffe4e2a2da0
	<-2, -1>
	pos1 add: 0x7ffe4e2a2da0
	<2, 1>
	pos2 add: 0x7ffe4e2a2da8
	<-2, -1>
	pos3 add: 0x7ffe4e2a2db0
--------------------------------------------------

	pos2가 기존의 pos1의 주소값을 받지 않았다.
*/

#include <iostream>
using namespace std;

class Point {
private	:
	int x, y;
public	:
	Point(int _x, int _y) : x(_x), y(_y) {}
	void show_info() const { cout << "<" << x << ", " << y << ">" << endl; }
	Point& operator-() {
		x = -x;
		y = -y;
		return *this;
	}

	friend Point& operator~(Point& ref);
};

Point& operator~(Point& ref) {
	int tmp = ref.x;
	ref.x = ref.y;
	ref.y = tmp;

	cout << "ref add: " << &ref << endl;

	return ref;
}

int main() {
	Point pos1(1, 2);
	Point pos2 = ~pos1;
	Point pos3 = -pos1;

	pos1.show_info();
	cout << "pos1 add: " << &pos1 << endl; 
	pos2.show_info();
	cout << "pos2 add: " << &pos2 << endl;
	pos3.show_info();
	cout << "pos3 add: " << &pos3 << endl;

	return 0;
}