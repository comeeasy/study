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
      cout << log[i] << endl;
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
    cout << "NO" << endl;

  return 0;
}
