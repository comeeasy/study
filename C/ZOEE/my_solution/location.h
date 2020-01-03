#ifndef __LOCATION_H__
#define __LOCATION_H__

class Location {
private	:
	int x, y;
public	:
	Location() : x(1), y(1) {}
	Location(int _x, int _y) : x(_x), y(_y) {}
	void set_location(int x, int y);
	Location& get_location();
	void set_x(int x);
	int get_x();
	void set_y(int y);
	int get_y();
};

void Location::set_location(int x, int y) {
	this->x = x;
	this->y = y;
}
Location& Location::get_location() {
	return *this;
}
void Location::set_x(int x) { this->x = x; }
int Location::get_x() { return this->x; }
void Location::set_y(int y) { this->y = y; }
int Location::get_y() { return this->y; }

#endif