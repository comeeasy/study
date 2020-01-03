/*
	앞서 상속관계에 놓여있는 클래스의 생성자 정의 및 호출방식에 대해 설명하였다. 이 내용을 바탕으로
	다음 클래에 적절한 생성자를 삽입해보자. 그리고 이의 확인을 위한 main함수를 적절히 정의 헤보자.
*/

#include<iostream>
using namespace std;

class Car { //기본 연료 자동차
private	:
	int gasoline_gauge;
public	:
	Car() : gasoline_gauge(100) {}
	Car(int n) : gasoline_gauge(n) {}
	int get_gas_gauge() { return gasoline_gauge; }
};

class Hybrid_car : public Car {
private	:
	int electicity_gauge;
public	:
	Hybrid_car() : electicity_gauge(100) {}
	Hybrid_car(int n) : electicity_gauge(n) {}
	Hybrid_car(int n1, int n2) : Car(n1), electicity_gauge(n2) {}
	int get_elec_gauge() { return electicity_gauge; }
};

class Hybrid_water_car : public Hybrid_car { // 하이브리드 워터카
private :
	int water_gauge;
public	:
	Hybrid_water_car() : water_gauge(100) {}
	Hybrid_water_car(int n) : water_gauge(n) {}
	Hybrid_water_car(int n1, int n2, int n3) : Hybrid_car(n1 ,n2), water_gauge(n3) {}
	void show_current_gauge() {
		cout << "gasoline 	: " << get_gas_gauge() << endl;
		cout << "electicity	: " << get_elec_gauge() << endl;
		cout << "water 		: " << water_gauge << endl;
	}
};

int main() {
	Hybrid_water_car c1;
	c1.show_current_gauge();
	Hybrid_water_car c2(10);
	c2.show_current_gauge();
	Hybrid_water_car c3(10, 20, 30);
	c3.show_current_gauge();
	return 0;
}