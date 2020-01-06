// Point class 를 기반으로
// +=, -= 연산자를 overloading 하고, return 을 Point의 reference로 하자.

#include <iostream>
using namespace std;

class Point {
private	:
	int x, y;
public	:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	void show_info() const { cout << "<" << x << ", " << y << ">" << endl; }
	Point& operator+=(const Point& pos) {
		x += pos.x;
		y += pos.y;
	}
	Point& operator-=(const Point& pos) {
		x -= pos.x;
		y -= pos.y;
	}
};

int main() {
	Point pos1(3, 4);
	Point pos2(1, 2);

	pos1 += pos2;
	pos1.show_info();

	pos1 += pos1;
	pos1.show_info();

	return 0;
}

