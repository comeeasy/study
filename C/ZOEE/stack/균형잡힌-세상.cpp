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
  int top() {
    int tmp = buf[peak];
    return tmp;
  }
};

class Checker {
public  :
  char str[CHAR_MAX+1];
  Stack s;
public  :
  void push_str(char* tmp_str) {
    strcpy(str, tmp_str);
  }
  bool is_valid() {
    for(int i=0; i<strlen(str); ++i) {
      if( str[i] == '(' ) { s.push(1); }
      else if( str[i] == ')' ) {
        if( s.is_empty() || ( s.top() != 1 ) ) { return false; }
        else                { s.pop(); }
      }
      else if( str[i] == '[' ) { s.push(2); }
      else if( str[i] == ']' ) {
        if( s.is_empty() || ( s.top() != 2 ) ) { return false; }
        else                { s.pop(); }
      }
    }

    if( s.is_empty() )  return true;
    else                                  return false;
  }
};

void get_string(char* tmp_str) {
  char ch;
  int i=0;

  while(1) {
    ch = getchar();

    if( ch == '\n' ) continue;
    if( ch == '.' ) {
      tmp_str[i] = '\0';
      break;
    }
    tmp_str[i++] = ch;
  }
}

int main() {
  char tmp_str[CHAR_MAX];

  while(1) {
    get_string(tmp_str);

    if( tmp_str[0] == '\0' ) break;

    Checker ch;
    ch.push_str(tmp_str);
    if( ch.is_valid() ) cout << "yes" << endl;
    else                cout << "no" << endl;
  }

  return 0;
}
