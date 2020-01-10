#include <iostream>

#define PARK_MAX 	100
#define CAR_MAX  	2000
#define EXIST		1
#define EMPTY 		0
using namespace std;

class Queue {
private :
	int head;
	int tail;
	int q[CAR_MAX];
public	:
	Queue() : head(0), tail(0) {}
	void wait(int x) { q[tail++] = x; }
	int park() { 
		if( head == tail ) return -1;
		else {
			return q[head++];
		}
	}
	int top() const {
		if( head != tail ) 	return q[head];
		else				return -1;
	}	
};

class Car {
private	:
	int number;
	int weight;
public	:
	Car() : weight(0), number(0) {}
	Car(int _number) : weight(0), number(_number) {}
	int get_weight() const { return weight; }
	void set_weight(int _weight) { weight = _weight; }
	int get_number() const { return number; }
	void set_number(int i) { this->number = i; }
};

class Park_space {
private	:
	bool is_car;
	Car* car;
	int rate; // 무게당 요금
public	:
	Park_space(int _rate) : is_car(EMPTY), car(0), rate(_rate) {} 
	Park_space() : is_car(EMPTY), car(0), rate(0) {} 

	int get_rate() const { return rate; }
	void set_rate(int _rate) { rate = _rate; }
	bool is_empty() const { return !is_car; }
	void park(Car& c) {
		is_car = EXIST;
		car = &c;
	}
	void park_out() {
		is_car = EMPTY;
		car = NULL;
	}
	Car* get_car() { return car; }
};

class Parking_station {
private	:
	int park_space_num;
	int car_num;

	Park_space park_space[PARK_MAX];
	int inout_list[2*CAR_MAX];
	Car cars[CAR_MAX+1];
	Queue waiting_list;

	int income;
public	:
	Parking_station() {
		int rate, weight, x;

		cin >> park_space_num;
		cin >> car_num;
		for(int i=0; i<park_space_num; ++i) {
			cin >> rate;
			park_space[i].set_rate(rate);
		}
		for(int i=1; i<=car_num; ++i) {
			cin >> weight;
			cars[i].set_weight(weight);
			cars[i].set_number(i);
		}
		for(int i=0; i<2*car_num; ++i) {
			cin >> x;
			inout_list[i] = x;
		}

		this->income = 0;
	}
	int get_income();
};

int Parking_station::get_income() {
	Car* tmp;

	for(int i=0; i<car_num*2; ++i) {
		if( inout_list[i] > 0 ) {
			waiting_list.wait(inout_list[i]);
			for(int j=0; j<park_space_num; ++j) {
				if( park_space[j].is_empty() != 0 ) {
					park_space[j].park(cars[waiting_list.top()]);
					waiting_list.park();
					break;
				}
			} 
		}
		else {
			for(int j=0; j<park_space_num; ++j) {
				if( ( tmp = park_space[j].get_car()) != NULL ) {
					if( tmp->get_number() == -inout_list[i] ) {
						income += (park_space[j].get_rate())*(park_space[j].get_car()->get_weight());
						park_space[j].park_out();
						for(int j=0; j<park_space_num; ++j) {
							if( park_space[j].is_empty() != 0 ) {
								if( waiting_list.top() != -1 ) {
									park_space[j].park(cars[waiting_list.top()]);
									waiting_list.park();
								}
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
	return income;
}

int main() {
	int TC;

	cin >> TC;
	for(int i=1; i<=TC; ++i) {
		Parking_station ps;
		cout << "#" << i << " " << ps.get_income() << endl; 
	}

	return 0;
}