#include <iostream>
using namespace std;

class Point {
private	:
	int x, y;
public	:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	void show_position() const {
		cout << "<" << x << ", " << y << ">" << endl;
	}

	// private 영역에 접근하기 위해 friend 선언하였다.
	friend Point operator+(const Point& pos1, const Point& pos2);
};

Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.x + pos2.x, pos1.y + pos2.y);
	return pos;
}

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.show_position();
	pos2.show_position();
	pos3.show_position();

	return 0;
}