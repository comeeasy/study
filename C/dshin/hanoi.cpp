#include <iostream>

#define MAX 1024

#define FROM    0
#define TMP     1
#define TO      2
using namespace std;

class Stack {
private :
    int buf[MAX];
    int peak;
public  :
    Stack() : peak(0) {for(int i=0; i<MAX; ++i) buf[i] = 0;}
    int is_empty() {return ((peak == -1) ? 1 : 0);}
    void push(int key) {buf[++peak] = key;}
    int top() {return buf[peak];}
    void pop() {
        if(peak == -1) {
            cout << "Stack is empty! by in_empty\n";
        }
        else {
            --peak;
        }
    }
    int get_n() const {return peak+1;}
};

class Hanoi {
private :
    Stack table[3];
    int n;
public  :
    Hanoi(int num) : n(num) {
        for(int i=1; i<=n; ++i) {
            table[FROM].push(i);
        }
    }

    void go(int from, int to) {
        int tmp;

        if(!table[from].is_empty()) {
            tmp = table[from].top();
            table[from].pop();
            table[to].push(tmp);

            cout << "disk go " << from << " --> " << to << endl;
        }
        else {
            cout << "stack is empty! by go\n";
        }
    }

    void solve(int from, int tmp, int to, int n) {
        if(n == 1) {
            go(from, to);
        }
        else {
            solve(from, to, tmp, n-1);
            go(from, to);
        }
    }
};

int main() {
    Hanoi h(2);

    h.solve(FROM, TMP, TO, 2);
    return 0;
}
