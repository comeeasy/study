#include <iostream>
#include <cstdio>
using namespace std;

void get_string(char* tmp_str) {
  char ch;
  int i=0;

  while(1) {
    ch = getchar();
    if( ch == '\n' ) {
      tmp_str[i] = '\0';
      break;
    }

    cout << ch << endl;
    tmp_str[i++] = ch;
  }
  cout << tmp_str << endl;
}

int main() {
  char name[50];

  get_string(name);
  return 0;
}
