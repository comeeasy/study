#include <iostream>
using namespace std;

class Point {
private	:
	int x, y;
public	:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	void show_info() const { cout << "<" << x << ", " << y << ">" << endl; }
	// 전위 증가
	Point& operator++() {
		++x;
		++y;
		return *this;
	}
	// 후위 증가
	const Point operator++(int) {
		const Point retobj(x, y);
		++x;
		++y;
		return retobj;
	}

	Point operator*(int times) {
		Point pos(x*times, y*times);
		return pos;
	}

	friend Point operator*(int times, Point& ref);
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point operator*(int times, Point& ref) {
	return ref*times;
}

Point& operator--(Point& ref) {
	ref.x -= 1;
	ref.y -= 1;
	return ref;
}
const Point operator--(Point& ref, int) {
	// const object
	const Point retobj(ref);
	ref.x -= 1;
	ref.y -= 1;
	return retobj;
}

int main() {
	Point pos(1, 2);
	Point cpy;

	cpy = 3*pos;
	cpy.show_info();

	cpy = 2*pos*3;
	cpy.show_info();

	return 0;
}