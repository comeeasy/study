/*
  input   : n ( 1<=n<=100,000 )
            이후에는 n줄에 걸쳐 1이상 n이하의 정수가 n개 주어짐
  output  : 입력된 수열을 만들기 위한 연산을 한 줄에 한 개씩 출력한다.
            push는 +, pop은 -로 불가능한 경우 NO 를 출력한다.
*/
#include <iostream>

#define NUM_MAX 100000
using namespace std;

class Stack {
private :
  int buf[NUM_MAX];
  int peak;
public  :
  Stack() : peak(-1) {}
  bool is_empty() const {
    if( peak != -1 )  return false;
    else              return true;
  }
  void push(int key) { buf[++peak] = key; }
  void pop() { --peak; }
  int top() { return buf[peak]; }
};

class Calculator {
private :
  int input;
  Stack s;
  char log[2*NUM_MAX];
  int log_num;
public  :
  Calculator() : input(1), s(), log_num(0) {}
  bool calculate() {
    int n, get_num;

    cin >> n;
    for(int i=0; i<n; ++i) {
      cin >> get_num;
      if( input <= get_num ) {
        while( input <= get_num ) {
          s.push(input++);
          log[log_num++] = '+';
        }
        s.pop();
        log[log_num++] = '-';
      }
      else {
        if( s.top() == get_num ) {
          s.pop();
          log[log_num++] = '-';
        }
        else {
          ++i;
          while(i < n) {
            cin >> get_num;
            ++i;
          }
          return false;
        }
      }
    }
    return true;
  }
  void show_log() const {
    for(int i=0; i<log_num; ++i)
      cout << log[i] << endl;
  }
};

int main() {
  Calculator cal;

  if (cal.calculate())
    cal.show_log();
  else
    cout << "NO" << endl;

  return 0;
}
