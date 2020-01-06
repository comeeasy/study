// 전역함수 기반으로 오버로딩
// 멤버 별 '-' 연산의 결과를 담은 Point 객체 반환

#include <iostream>
using namespace std;

class Point {
private	:	
	int x, y;
public	:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	void show_info() const { cout << "<" << x << ", " << y << ">" << endl; }

	friend Point operator-(const Point& pos1, const Point& pos2);
};

Point operator-(const Point& pos1, const Point& pos2) {
	Point pos(pos1.x-pos2.x, pos1.y-pos2.y);
	return pos;
}

int main() {
	Point pos1(1, 2);
	Point pos2(3, 4);
	Point pos3 = pos1 - pos2;

	pos1.show_info();
	pos2.show_info();
	pos3.show_info();

	return 0;
}

