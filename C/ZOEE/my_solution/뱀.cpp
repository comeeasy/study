#include <iostream>
#include "board.h"
using namespace std;

int main() {
	Board board;

	board.get_init_info();
	cout << board.game_start() << endl;
	return 0;
}