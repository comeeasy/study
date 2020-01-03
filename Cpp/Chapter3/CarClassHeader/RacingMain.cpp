#include"Car.h"

int main() {
	Car run99;

	run99.init_members("run99", 100);
	run99.accel();
	run99.accel();
	run99.accel();
	run99.show_var_state();
	run99.Break();
	run99.show_var_state();

	return 0;
}