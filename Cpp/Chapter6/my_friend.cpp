#include<iostream>
#include<string>
using namespace std;

class Girl;
class Boy {
private	:
	int height;
friend class Girl;
public	:
	Boy(int len) : height(len) {}
	void show_friend_info(Girl& frn);
};

class Girl {
private	:
	string ph_num;
public	:
	Girl(string num) : ph_num(num) {}
	void show_friend_info(Boy& frn);
friend class Boy;
};

void Boy::show_friend_info(Girl& frn) {
	cout << "Her phone num is: " << frn.ph_num << endl;
}
void Girl::show_friend_info(Boy& frn) {
	cout << "His heigt is: " << frn.height << endl;
}

int main() {
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.show_friend_info(girl);
	girl.show_friend_info(boy);
	return 0;

}