/*
  input   : 하나 또는 여러줄에 걸쳐서 문자열이 주어진다.
            각 문자열은 영문 알파벳, 공백, 소괄호, 대괄호 등으로 이루어져 있다.
            길이는 100글자보다 작거나 같다.
  output  : 각 죽마다 해당 문자열이 균형을 이루고 있으면, "yes", 아니면 "no"
            를 출력한다.
*/

#include <iostream>
#include <cstring>

#define CHAR_MAX  100
#define STACK_MAX 100
using namespace std;

class Stack {
private :
  int buf[STACK_MAX+1];
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
  char str[CHAR_MAX+1];
  Stack s1;
  Stack s2;
public  :
  void push_str(char* tmp_str) {
    strcpy(str, tmp_str);
  }
  bool is_valid() {
    for(int i=0; i<strlen(str); ++i) {
      // 소괄호는 s1, 대괄호는 s2

      if( str[i] == '(' ) { s1.push(1); }
      else if( str[i] == ')' ) {
        if( s1.is_empty() ) { return false; }
        else                { s1.pop(); }
      }
      else if( str[i] == '[' ) { s2.push(1); }
      else if( str[i] == ']' ) {
        if( s2.is_empty() ) { return false; }
        else                { s2.pop(); }
      }
    }

    if( s1.is_empty() && s2.is_empty() )  return true;
    else                                  return false;
  }
};

void get_string(char* tmp_str) {
  char ch;
  int i=0;

  do {
    ch = getchar();
    tmp_str[i++];
  } while( ch != '.' );

  tmp_str[i] = '\0';
}

int main() {
  char tmp_str[CHAR_MAX];

  while(1) {
    get_string(tmp_str);

    printf("%s", tmp_str);
    if( !strcmp(".", tmp_str) ) break;

    Checker ch;

    ch.push_str(tmp_str);
    if( ch.is_valid() ) cout << "yes" << endl;
    else                cout << "no" << endl;
  }

  return 0;
}
