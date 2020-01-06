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
	Point operator+(const Point &ref) {
		Point pos(x+ref.x, y+ref.y);
		return pos;
	}
};

int main() {
	Point pos1(3, 4);
	Point pos2(10,20);
	Point pos3 = pos1.operator+(pos2);

	pos1.show_position();
	pos2.show_position();
	pos3.show_position();

	return 0;
}