/*
  input     : T : testcase
              각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다.
              하나의 괄호 문자열의 길이는 2 이상 50 이하이다.
  output    : 문자열이 올바른 문자열이라면 "YES", 아니라면 "NO" 를 한 줄 씩 출력
*/

#include <iostream>
#include <cstring>

#define CHAR_MAX  50
#define STACK_MAX 50
using namespace std;

class Stack {
private :
  int buf[STACK_MAX];
  int peak;
public  :
  Stack() : peak(-1) {}
  bool is_empty() const {
    if( peak != -1 )  return false;
    else              return true;
  }
  void push(int key) { buf[++peak] = key; }
  int pop() {
    int tmp = buf[peak--];
    return tmp;
  }
};

class Checker {
public  :
  char str[CHAR_MAX];
  Stack s;
public  :
  void push_str() {
    char tmp_str[CHAR_MAX];

    cin >> tmp_str;
    strcpy(str, tmp_str);
  }
  bool is_valid() {
    for(int i=0; i<strlen(str); ++i) {
      if( str[i] == '(' ) { s.push(1); }
      else if( str[i] == ')' ){
        if( s.is_empty() )  return false;
        else              s.pop();
      }
    }
    if( s.is_empty() ) return true;
    else               return false;
  }
};

int main() {
  int T;

  cin >> T;
  for(int i=0; i<T; ++i) {
    Checker ch;

    ch.push_str();
    if( ch.is_valid() ) cout << "YES" << endl;
    else                cout << "NO" << endl;
  }

  return 0;
}
