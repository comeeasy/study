/*
  input   : 첫 째 줄에 K( 1 <= K <= 100,000 )
          이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며
          정수가 "0" 일 경우는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.

          정수가 "0"일 경우에는 지울 수 있는 수가 있음을 보장할 수 있다.
  output  : 재민이가 최종적으로 적어 낸 수의 합을 출력한다.
*/
#include <iostream>

#define STACK_MAX 100000
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
  // stack이 넘치지 않을 것을 보장하기 때문에 예외처리 하지 않겠다.
  void push(int key) { buf[++peak] = key; }
  // stack이 비어 있지 않았다는 것을 문제에서 보장하였음.
  int pop() {
    int tmp = buf[peak--];
    return tmp;
  }
  int sum() const {
    int sum=0;

    for(int i=0; i<=peak; ++i) sum += buf[i];
    return sum;
  }
};

int main() {
  int K, tmp, sum=0;
  Stack s;

  cin >> K;
  for(int i=0; i<K; ++i) {
    cin >> tmp;
    if(tmp) { s.push(tmp); }
    else    { s.pop(); }
  }

  if( s.is_empty() ) cout << "0" << endl;
  else               cout << s.sum() << endl;

  return 0;
}
