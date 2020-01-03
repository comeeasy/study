#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <iostream>
#include "location.h"

using namespace std;

#define LENGTH_MAX 	100
#define UP 		1
#define RIGHT 	2
#define DOWN 	4
#define LEFT	8

#define HEAD 	0

///////////////////////////////////////////////////////////////////////////////
class Snake {
private	:
	int length;
	int dir;
	Location _front;
	Location location[LENGTH_MAX];
public	:
	Snake();
	void set_dir(int dir);
	void set_dir(char L_D);
	int get_dir();
	void set_length(int length);
	int get_length();
	Location& front();
	void set_location( bool is_apple );
	Location& get_location(int i);
};
///////////////////////////////////////////////////////////////////////////////
Snake::Snake() : length(1), dir(RIGHT) {
		// init location of head
		location[HEAD] = Location(1, 1);
		for(int i=1; i<LENGTH_MAX; ++i) {
			location[i] = Location(-1, -1);
		}
}
void Snake::set_dir(int dir)	{ 
	this->dir = dir; 
}
void Snake::set_dir(char L_D) 	{
	if( L_D == 'L' ) {
		switch(dir) {
			case UP		: dir = LEFT;	break;
			case RIGHT	: dir = UP;		break;
			case DOWN	: dir = RIGHT;	break;
			case LEFT	: dir = DOWN;	break;
		}
	}
	else if( L_D == 'D' ) {
		switch(dir) {
			case UP		: dir = RIGHT;	break;
			case RIGHT	: dir = DOWN;	break;
			case DOWN	: dir = LEFT;	break;
			case LEFT	: dir = UP;		break;
		}
	}
}
int Snake::get_dir() {			
	return this->dir; 
}
void Snake::set_length(int length) { 
	this->length = length; 
}
int Snake::get_length() { 
	return this->length; 
}
Location& Snake::front() {
	switch(dir) {
		case UP		: this->_front.set_x(this->location[HEAD].get_x());
					  this->_front.set_y(this->location[HEAD].get_y()-1);
					  return this->_front;	
		case RIGHT	: this->_front.set_x(this->location[HEAD].get_x()+1);
					  this->_front.set_y(this->location[HEAD].get_y());
					  return this->_front;
		case DOWN	: this->_front.set_x(this->location[HEAD].get_x());
					  this->_front.set_y(this->location[HEAD].get_y()+1);
					  return this->_front;
		case LEFT	: this->_front.set_x(this->location[HEAD].get_x());
					  this->_front.set_y(this->location[HEAD].get_y()-1);
					  return this->_front;
	}
}
void Snake::set_location( bool is_apple ) {
	if( is_apple ) {
		for(int i=length-1; i>=HEAD; --i) {
			location[i+1] = location[i];
		}
		location[HEAD] = front();
		++length;
	}
	else	{
		for(int i=1; i<length; ++i) {
			location[i] = location[i-1];
		}
		location[HEAD] = front();
	}

	cout << "direc 	: " << dir << endl;
	cout << "HEAD   : " << "<" << location[HEAD].get_x() << ", " << location[HEAD].get_y() << ">" << endl;
	cout << "front(): " << "<" << front().get_x() << ", " << front().get_y() << ">" << endl;
}
Location& Snake::get_location(int i) {
	return location[i];
}

#endif