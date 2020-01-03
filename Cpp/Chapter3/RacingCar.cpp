#include<iostream>
using namespace std;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car {
	char gamer_id[ID_LEN];
	int fuel_gauge;
	int cur_speed;
};

void show_car_state(const Car &car) {
	cout << "소유자 ID 	: " << car.gamer_id << endl;
	cout << "연료량		: " << car.fuel_gauge << endl;
	cout << "현재 속도	: " << car.cur_speed << endl;
}

void accel(Car &car) {
	if(car.fuel_gauge <= 0)	return;
	else					car.fuel_gauge -= FUEL_STEP;

	if(car.cur_speed + ACC_STEP >= MAX_SPD)	{
		car.cur_speed = MAX_SPD;
		return;
	}
	else	
		car.cur_speed += ACC_STEP;
}

void Break(Car &car) {
	if(car.cur_speed < BRK_STEP) {
		car.cur_speed = 0;
		return;
	}
	else
		car.cur_speed -= BRK_STEP;
}

int main() {
	Car run99 = {"run99", 100, 0};
	accel(run99);
	accel(run99);
	show_car_state(run99);
	Break(run99);
	show_car_state(run99);

	Car run77 = {"run77", 100, 0};
	accel(run77);
	Break(run77);
	show_car_state(run77);

	return 0;
}