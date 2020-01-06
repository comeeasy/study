#include <iostream>
using namespace std;

class Point {
private	:
	int x, y;
public	:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	void show_info() const { cout << "<" << x << ", " << y << ">" << endl; }
	bool operator==(const Point& pos) {
		if( pos.x == x && pos.y == y ) 	return 1;
		else							return 0;
	}
	bool operator!=(const Point& pos) {
		if( *this == pos )	return 0;
		else				return 1;
	}
};

int main() {
	Point pos1(1, 1);
	Point pos2(2, 2);
	Point pos3(1, 1);

	cout << pos1 == pos2 << endl;
	cout << pos1 == pos3 << endl;
	cout << pos2 == pos3 << endl;

	cout << pos1 != pos2 << endl;
	cout << pos1 != pos3 << endl;
	cout << pos2 != pos3 << endl;	

	return 0;
}