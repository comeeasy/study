/* 
	void init_members(int x, int y, int r);
	void set_coordinate(int x, int y);
	void set_radius(int r);
	Point get_coordinate() const;
	int get_radius() const;
	void show_info() const;
*/

#include<iostream>
#include"Circle.h"
using namespace std;

void Circle::set_coordinate(int x, int y) {
	coordinate.set_x(x);
	coordinate.set_y(y);
}
void Circle::set_radius(int r) {
	if( r < 0 )	cout << "radius must be loger than 0" << endl;
	else		radius = (double)r;
}
void Circle::init_members(int x, int y, int r) {
	set_coordinate(x, y);
	set_radius(r);
}
Point Circle::get_coordinate() const {return coordinate;}
double Circle::get_radius() const {return radius;}
void Circle::show_info() const {
	cout << "coordinate: ";
	coordinate.show_info();
	cout << "radius: " << get_radius() << endl;
}