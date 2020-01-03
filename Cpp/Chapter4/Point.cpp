#include<iostream>
#include"Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos) {
	x = xpos;
	y = ypos;
}

int Point::get_x() const {return x;}
int Point::get_y() const {return y;}
bool Point::set_x(int xpos) {
	x = xpos;
	return true;
}
bool Point::set_y(int ypos) {
	y = ypos;
	return true;
}
void Point::show_info() {
	cout << '<' << get_x() << ", " << get_y() << '>' << endl;
}