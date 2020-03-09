#include "./header/my_heap.h"

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
