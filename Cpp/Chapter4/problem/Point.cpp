#include<iostream>
#include"Point.h"
using namespace std;

bool Point::init_members(int xpos, int ypos) {
	x = xpos;
	y = ypos;
	return true;
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
void Point::show_info() const {
	cout << '<' << get_x() << ", " << get_y() << '>' << endl;
}