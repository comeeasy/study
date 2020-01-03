#ifndef __CRICLE_H__
#define __CRICLE_H__

#include"Point.h"

class Circle {
private	:
	Point coordinate;
	double radius;
public	:
	void init_members(int x, int y, int r);

	void set_coordinate(int x, int y);
	void set_radius(int r);
	Point get_coordinate() const;
	double get_radius() const;
	void show_info() const;
};

#endif