#include<iostream>
#include<cstring>
#include"Car.h"
using namespace std;

void Car::init_members(const char* ID, int fuel) {
	strcpy(gamer_id, ID);
	fuel_gauge = fuel;
	cur_speed = 0;
}
void Car::show_var_state() {
	cout << "소유자 ID 	: " << gamer_id << endl;
	cout << "연료량		: " << fuel_gauge << "%" << endl;
	cout << "현재 속도 	: " << cur_speed << "km/h" << endl << endl;
}
void Car::accel() {
	if(fuel_gauge <= 0)	return;
	else	fuel_gauge -= CAR_CONST::FUEL_STEP;

	if((cur_speed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
		cur_speed = CAR_CONST::MAX_SPD;
	else	
		cur_speed += CAR_CONST::ACC_STEP;	
}
void Car::Break() {
	if(cur_speed <= CAR_CONST::BRK_STEP)
		cur_speed = 0;
	else
		cur_speed -= CAR_CONST::BRK_STEP;
}