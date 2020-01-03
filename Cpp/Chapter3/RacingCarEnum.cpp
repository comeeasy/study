#include<iostream>
using namespace std;

namespace CAR_CONST {
	enum {
		ID_LEN		= 20,
		MAX_SPD		= 200,
		FUEL_STEP	= 2,
		ACC_STEP	= 10,
		BRK_STEP	= 10
	};
}

struct Car {
	char gamer_id[CAR_CONST::ID_LEN];
	int fuel_gauge;
	int cur_speed;

	/////////////////////////////////////////////////////////////////////////////////

	void show_car_state() {
		cout << "소유자 ID 	: " << gamer_id << endl;
		cout << "연료량		: " << fuel_gauge << "%" << endl;
		cout << "현재 속도	: " << cur_speed << "km/s" << endl << endl;
	}

	void accel() {
		if(fuel_gauge <= 0)	return;
		else				fuel_gauge -= CAR_CONST::FUEL_STEP;

		if((cur_speed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD )	{
			cur_speed = CAR_CONST::MAX_SPD;
		} else	{
			cur_speed += CAR_CONST::ACC_STEP;
		}
	}

	void Break() {
		if(cur_speed - CAR_CONST::BRK_STEP <= 0)	cur_speed = 0;
		else	cur_speed -= CAR_CONST::BRK_STEP;
	}
};

int main() {
	Car run99 = {"run99", 100, 0};
	run99.accel();
	run99.accel();
	run99.show_car_state();
	run99.Break();
	run99.show_car_state();

	Car spd77 = {"spd77", 100, 0};
	spd77.accel();
	spd77.show_car_state();
	spd77.Break();
	spd77.show_car_state();

	return 0;
}