#include <iostream>
using namespace std;

class Point {
private	:
	int x, y;
public	:
	Point(int _x, int _y) : x(_x), y(_y) {}
	void show_info() const { cout << "<" << x << ", " << y << ">" << endl; }
	// 전위 증가
	Point& operator++() {
		++x;
		++y;
		return *this;
	}
	// 후위 증가
	const Point& operator++(int) {
		const Point retobj(x, y);
		++x;
		++y;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

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
	Point pos(3, 5);
	Point cpy;

	cpy = pos--;
	cpy.show_info();
	pos.show_info();

	cpy = pos++;
	cpy.show_info();
	pos.show_info();

	return 0;
}