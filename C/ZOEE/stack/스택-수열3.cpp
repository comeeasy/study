#include <iostream>
#include <cassert>

#define NUM_MAX 100001
using namespace std;

class Stack {
private :
  int buf[NUM_MAX];
  int peak;
public  :
  Stack() : peak(-1) {}
  bool is_empty() const {
    if( peak <= -1 ) {
      assert(peak < -1);
      return true;
    }
    else              return false;
  }
  void push(int key) { buf[++peak] = key; }
  int pop() {
    if(peak==-1) { return -1; }
    else { return buf[peak--]; }
  }
  int top() {
    if(peak==-1) { return -1; }
    else { return buf[peak]; }
  }
};

class Calculator {
private :
  int input;
  Stack s;
  // +, - 의 log를 저장할 저장소
  char log[2*NUM_MAX];
  // log의 길이를 저장
  int log_num;
public  :
  Calculator() :input(1), s(), log_num(0) {}
  bool calculate(int n, int* number) {
    for(int i=0; i<n; ++i) {
      if( input <= number[i] ) {
        while( input <= number[i] ) {
          s.push(input++);
          log[log_num++] = '+';
        }
        s.pop();
        log[log_num++] = '-';
      }
      else {
        if( s.top() == number[i] ) {
          s.pop();
          log[log_num++] = '-';
        }
        else {
          return false;
        }
      }
    }
    return true;
  }
  void show_log() const {
    for(int i=0; i<log_num; ++i)
      cout << log[i] << "\n";
  }
};

int main() {
  int number[NUM_MAX], n;
  Calculator cal;

  cin >> n;
  for(int i=0; i<n; ++i) {
    cin >> number[i];
  }

  if (cal.calculate(n, number))
    cal.show_log();
  else
    cout << "NO\n";

  return 0;
}
