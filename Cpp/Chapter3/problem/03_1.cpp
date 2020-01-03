#include<iostream>
using namespace std;

struct point {
	int x, y;

	void move_pos(int _x, int _y) {		// 점의 좌표 이동
		x += _x;
		y += _y;
	}
	void add_point(const point &pos) {	// 점의 좌표 증가
		x += pos.x;
		y += pos.y;
	}
	void show_pos() {					// 현재 x, y 좌표정보 출력
		cout << "[" << x << ", " << y << "]" << endl;
	}
};

int main() {
	point pos1 = {12, 4};
	point pos2 = {20, 30};

	pos1.move_pos(-7, 10);
	pos1.show_pos();

	pos1.add_point(pos2);
	pos1.show_pos();

	return 0;
}

