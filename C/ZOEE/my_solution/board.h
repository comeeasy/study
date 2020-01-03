#ifndef __BOARD_H__
#define __BOARD_H__

#include<iostream>
#include"location.h"
#include"snake.h"

#define APPLE_MAX	100
#define BOARD_MAX  	100
#define TIME_MAX	10000
#define TURN_MAX	100

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////
class Board {
private	:
	int time;
	int board_size;
	int num_of_apple;
	int move_of_snake;

	char move[TIME_MAX];
	Location apple[APPLE_MAX];
	Snake my_snake;
public	:
	Board();
	void get_init_info();
	int game_start();
	void show_status();
};
///////////////////////////////////////////////////////////////////////////////////////
Board::Board() : time(0), my_snake() {
		for(int i=0; i<APPLE_MAX; ++i) {
			apple[i].set_x(0);
			apple[i].set_y(0);
		}
		for(int i=0; i<TIME_MAX; ++i)  move[i] = 'N';
	}
void Board::get_init_info() {
	int x, y;
	int time;

	cin >> board_size;
	cin >> num_of_apple;
	for(int i=0; i<num_of_apple; ++i) {
		cin >> x; cin >> y;
		apple[i].set_x(x);
		apple[i].set_y(y);
	}
	cin >> move_of_snake;
	for(int i=0; i<move_of_snake; ++i) {
		cin >> time;
		cin >> move[time];
	}
}
int Board::game_start() {
	// 뱀이 앞을 조사
		// 벽이거나 자신의 몸통이 있다면
		// return time;
		
		// 벽이 아니라면 사과가 있는지 없는지 조사 후 is_apple로 return
		// set_location( is_apple )
	Location front;
	bool is_apple;
	while(1) {
		show_status();
		++time;	

		front = my_snake.front();
		// wall search
		if( my_snake.get_location(HEAD).get_x() < 1 || my_snake.get_location(HEAD).get_x() > board_size 
			|| my_snake.get_location(HEAD).get_y() < 1 || my_snake.get_location(HEAD).get_y() > board_size ) {
			return time-1;
		}
		// snake body search
		for(int i=HEAD+1; i<my_snake.get_length(); ++i) {
			if( my_snake.get_location(HEAD).get_x() == my_snake.get_location(i).get_x() 
				&& my_snake.get_location(HEAD).get_y() == my_snake.get_location(i).get_y() )
				return time-1;
		}
		// apple search
		is_apple = 0;
		for(int i=0; i<num_of_apple; ++i) 
			if(front.get_x() == apple[i].get_x() && front.get_y() == apple[i].get_y()) {
				is_apple = 1;
				break;	
			}			
		// there is no apple
		my_snake.set_location(is_apple);

		// select next direction
		my_snake.set_dir(move[time+1]);
	}
}
void Board::show_status() {
	char map[board_size+2][board_size+2];

	for(int i=0; i<=board_size+1; ++i) {
		for(int j=0; j<=board_size+1; ++j) {
			if(i<1 || i>board_size || j<1 || j>board_size) map[i][j] = '#';
			else	map[i][j] = '.';
		}
	}
	for(int i=0; i<num_of_apple; ++i) {
	map[apple[i].get_x()][apple[i].get_y()] = 'a';
	}
	for(int i=HEAD; i<my_snake.get_length(); ++i) {
		map[my_snake.get_location(i).get_x()][my_snake.get_location(i).get_y()] = 's';
	}

	cout << "------------------------------------------------------------------" << endl;
	cout << "time: " << time << endl;
	cout << "------------------------------------------------------------------" << endl;
	for(int i=0; i<=board_size+1; ++i) {
		for(int j=0; j<=board_size+1; ++j) {
			cout << map[j][i];
		}
		cout << endl;
	} 
}

#endif