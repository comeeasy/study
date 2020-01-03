#include<iostream>
using namespace std;

class Fruit_seller {
private	:
	int APPLE_PRICE;
	int num_of_apples;
	int money;
public	:
	void init_members(int price, int num, int _money) {
		APPLE_PRICE = price;
		num_of_apples = num;
		money = _money;
	}
	int sale_apples(int _money) {
		int num = _money / APPLE_PRICE;
		num_of_apples -= num;
		money += _money;
		return num;
	}
	void show_sales_result() {
		cout << "남은 사과: " << num_of_apples << endl;
		cout << "판매 수익: " << money << endl;
	}	
};

class Fruit_buyer {
private	:
	int my_money;
	int num_of_apples;
public	:
	void init_members(int money) {
		my_money = money;
		num_of_apples = 0;
	}
	void buy_apples(Fruit_seller &seller, int money) {
		num_of_apples += seller.sale_apples(money);
		my_money -= money;
	}
	void show_buy_result() {
		cout << "현재 잔액: " << my_money << endl;
		cout << "사과 개수: " << num_of_apples << endl << endl;
	}
};

int main() {
	Fruit_seller seller;
	seller.init_members(1000, 20, 0);

	Fruit_buyer buyer;
	buyer.init_members(5000);
	buyer.buy_apples(seller, 2000);

	seller.show_sales_result();
	buyer.show_buy_result();

	return 0;
}