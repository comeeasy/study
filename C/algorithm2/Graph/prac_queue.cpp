#include <queue>
#include <iostream>

using namespace std;

void show_queue(queue<int> q) {
    for(int i=0; !(q.empty()); ++i) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    show_queue(q);
    q.pop();
    show_queue(q);

    return 0;
}
