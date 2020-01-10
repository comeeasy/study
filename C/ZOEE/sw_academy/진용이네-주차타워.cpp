/*
	1 - n 까지 번호가 매겨진 주차공간이 있음
	- 차가 주차장에 도착하면, 진용이는 비어있는 주차 공간이 있는지 검사
	- 비어있는 공간이 없다면, 빈 공간이 생길때 까지 대기
	- 빈 주차 공간이 있으면, 주차 가능한 공간 중 번호가 가장 작은 주차장에 주차시킨다.

	- 주차요금은 차량의 무게와 주차 공간마다 따로 책정된 단위 무게당 금액을 곱한 가격
	- 진용이는 오늘 주차장을 이용할 m대의 차량들이 들어오고 나가는 순서를 알고 있다.

	- 진용이의 주차장이 오늘 하루 벌어들을 총 수입을 계산하는 프로그램을 작성해

	- input	: 	TC
				n m ( 1<= n  <= 100, 1<= m <= 2,000)
				n개의 줄에 i번째 주차 공간의 단위 무게당 요금 Ri ( 1 <= Ri <= 100 )
				m개의 줄에 차량i의 무게 Wi가 정수로 주어진다. ( 1 <= Wi <= 10,000 )
				2m개의 줄에 차량들의 주차장 출입순서가 하나의 정수 x 로 주어짐
				- 주어진 정수가 양수면, x번 차가 주차장에 들어옴을 뜻함
				  주어진 정수가 음수면, -x번 차가 나감을 뜻함.
	- output:	각 TC마다 "#t " (t는 1부터 시작)을 출력하고, 진용이가 하룻동안 벌어들일 수
				입을 출력해
*/
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
	void show_info() const { 
		cout << "---------------- waiting_list...-----------------" << endl;
		for(int i=head; i<tail; ++i) {
			cout << q[i] << " ";
		}
		cout << endl << "-------------------------------------------------" << endl;
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
	void show_info() const { 
		cout << "---------------- car info ---------------------------" << endl;
		cout << "number: " << number << endl;
		cout << "weight: " << weight << endl;
		cout << "-----------------------------------------------------" << endl;
	}
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
		show_info();
	}
	int get_income();
	void show_info() {
		cout << "------------- show info ---------------------------------------------" << endl;

		cout << "park_space_num: " << park_space_num << endl;
		cout << "car_num: " << car_num << endl;
		cout << "inout list.." << endl;
		for(int i=0; i<car_num*2; ++i) {
			cout << inout_list[i] << endl;
		}
		cout << "-----------------------------------------------------------------" << endl << endl;
	}
	void show_park_info() {
		Car* tmp;

		cout << "--------------- park station --------------------" << endl;
		for(int i=0; i<park_space_num; ++i) cout << i << " "; cout << endl;
		for(int i=0; i<park_space_num; ++i) {
			if( (tmp = park_space[i].get_car()) != NULL )
				cout << park_space[i].get_car()->get_number() << " ";
			else
				cout << "  ";
		}
		cout << endl;
		cout << "-------------------------------------------------" << endl;
	}
};

int Parking_station::get_income() {
	Car* tmp;

	// inout list 순서대로 처리
	//cout << "inout list 순서대로 처리" << endl;
	for(int i=0; i<car_num*2; ++i) {
		show_park_info();

		cout << i << "번째 inout list는" << inout_list[i] << "입니다." << endl;

		// 들어올 차량이 있다면
		//cout << "들어올 차량이 있다면" << endl;
		if( inout_list[i] > 0 ) {
			// waiting list에 먼저 등록
			//cout << "waiting list에 먼저 등록" << endl;
			waiting_list.wait(inout_list[i]);
			waiting_list.show_info();

			// 가장 번호가 작은 순으로 주차공간에 자리가 있는지 조사
			//cout << "가장 번호가 작은 순으로 주차공간에 자리가 있는지 조사" << endl;
			for(int j=0; j<park_space_num; ++j) {
				if( park_space[j].is_empty() != 0 ) {
					park_space[j].park(cars[waiting_list.top()]);

					cout << waiting_list.top() << " 차 주차하였습니다." << endl;

					waiting_list.park();
					break;
				}
			} 
		}
		// 나가는 차량이 있다면
		else {
			//cout << "나가는 차량이 있다면" << endl;

			// 나가는 차량이 몇번 주차공간에 있는지 조사
			//cout << "나가는 차량이 몇번 주차공간에 있는지 조사" << endl;
			for(int j=0; j<park_space_num; ++j) {
				if( ( tmp = park_space[j].get_car()) != NULL ) {
					//tmp->show_info();

					if( tmp->get_number() == -inout_list[i] ) {
						cout << "rate  : " << park_space[j].get_rate() << endl;
						cout << "weight: " << tmp->get_weight() << endl;
						cout << "요금은 : " << (park_space[j].get_rate())*(park_space[j].get_car()->get_weight()) << "입니다." << endl;
						cout << -inout_list[i] << " 차 계산하였습니다." << endl;
						income += (park_space[j].get_rate())*(park_space[j].get_car()->get_weight());

						cout << "수입: " << income << endl;
						park_space[j].park_out();

						for(int j=0; j<park_space_num; ++j) {
							if( park_space[j].is_empty() != 0 ) {
								if( waiting_list.top() != -1 ) {
									park_space[j].park(cars[waiting_list.top()]);

									cout << waiting_list.top() << " 차 주차하였습니다." << endl;

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