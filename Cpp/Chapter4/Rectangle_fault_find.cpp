#include<iostream>
#include"Point.h"
#include"Rectangle.h"
using namespace std;

int main() {
	Point pos1;
	if( !pos1.init_members(-2, 4) )	cout << "false to initialize" << endl;
	if( !pos1.init_members( 2, 4) )	cout << "false to initialize" << endl;

	Point pos2;
	if( !pos2.init_members(5, 9) )	cout << "false to initialize" << endl;

	Rectangle rec;
	if( !rec.init_members(pos2, pos1) )	cout << "false to initialize rectangle" << endl;
	if( !rec.init_members(pos1, pos2) )	cout << "false to initialize rectangle" << endl;

	rec.show_rec_info();
	return 0;
}