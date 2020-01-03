// Car class의 선언이 담긴다.

// 5, 30 행은 헤더파일의 중복포함문제를 해결하기위한 매크로 선언이다.

#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST {
		enum {
		ID_LEN 		= 20,
		MAX_SPD 	= 200,
		FUEL_STEP	= 2,
		ACC_STEP	= 10,
		BRK_STEP	= 10
	};
}

class Car {
private :
	char gamer_id[CAR_CONST::ID_LEN];
	int fuel_gauge;
	int cur_speed;
public	:
	void init_members(const char* ID, int fuel );
	void show_var_state();
	void accel();
	void Break();
};

#endif