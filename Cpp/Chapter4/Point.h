#ifndef __POINT_H__
#define __POINT_H__

class Point {
private	:
	int x, y;
public	:
	Point(const int &xpos, const int &ypos);
	int get_x() const;
	int get_y() const;
	bool set_x(int xpos);
	bool set_y(int ypos);
	void show_info();
};

#endif