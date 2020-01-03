#include<iostream>
#include"Circle.h"
using namespace std;

class Ring {
private	:
	Circle inner_circle;
	Circle outer_circle;
	double radius;
public	:
	void init_members(int x, int y, int r, int thickness) {
		inner_circle.set_coordinate(x, y);
		outer_circle.set_coordinate(x, y);
		if( r < (float)thickness/2 )	cout << "wrong input" << endl;
		else	radius = r;
		inner_circle.set_radius(radius - (double)thickness/2);
		outer_circle.set_radius(radius + (double)thickness/2);
	}
	void show_info() {
		cout << "inner circle: ";
		inner_circle.show_info();
		cout << "outer circle: ";
		outer_circle.show_info();
	}
};

int main() {
	Ring ring;
	ring.init_members(0, 0, 10, 2);
	ring.show_info();
	return 0;
}