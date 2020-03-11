#include "./header/my_heap.h"

int main() {
    heap h1(MAX_HEAP);
    heap h2(MIN_HEAP);
    
    h1.push(10);
    h1.push(100);
    h1.push(1000);
    h1.show_heap();

    cout << "get out of MIN_HEAP\n";
    h1.pop();
    h1.show_heap();
    cout << "get out of MIN_HEAP\n";
    h1.pop();
    h1.show_heap();

    h2.push(10);
    h2.push(100);
    h2.push(1000);
    h2.show_heap();

    cout << "get out of MAX_HEAP\n";
    h2.pop();
    h2.show_heap();
    cout << "get out of MAX_HEAP\n";
    h2.pop();
    h2.show_heap();

    return 0;
}


/*
int main() {
    heap h;

    h.push(1);
    h.push(5);
    h.push(4);
    h.push(10);
    h.push(12);
    h.push(8);
    h.push(2);
    h.push(3);
    h.push(0);
    h.push(-23);
    h.push(6);
    h.push(200);

    h.show_heap();

    return 0;
}
*/
