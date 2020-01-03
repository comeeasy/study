#include<iostream>
#include"Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
	// member initializer
	// 객체 up_left의 생성과정에서 x1, y1을 인자로 전달 받는 생성자를 호출하라
	// 객체 low_right의 생성과정에서 x1, y2를 인자로 전달받는 생성자를 호출하라 라는 의미.
	: up_left(x1, y1), low_right(x2, y2) {}

void Rectangle::show_info() const {
	cout << "좌 상단: " << '[' << up_left.get_x() << ", ";
	cout << up_left.get_y() << ']' << endl;
	cout << "우 하단: " << '[' << low_right.get_x() << ", ";
	cout << low_right.get_y() << ']' << endl << endl;
}