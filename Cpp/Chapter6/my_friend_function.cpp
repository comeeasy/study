#include<iostream>
using namespace std;

class Point;
class Point_op {
private	:
	int opcnt;
public	:
	Point_op() : opcnt(0) {}

	Point Point_add(const Point&, const Point&);
	Point Point_sub(const Point&, const Point&);
	~Point_op() {
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point {
private	:
	int x, y;
public	:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) {}
	friend Point Point_op::Point_add(const Point&, const Point&);
	friend Point Point_op::Point_sub(const Point&, const Point&);
	friend void show_point_pos(const Point&);
};

Point Point_op::Point_add(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}
Point Point_op::Point_sub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main() {
	Point pos1(1, 2);
	Point pos2(2, 4);
	Point_op op;

	show_point_pos(op.Point_add(pos1, pos2));
	show_point_pos(op.Point_sub(pos1, pos2));
	return 0;
}

void show_point_pos(const Point& pos) {
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
 }