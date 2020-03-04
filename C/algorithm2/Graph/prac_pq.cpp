// usage of qriority queue, tuple

#include <iostream>
#include <functional>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    // sorted by first components
    priority_queue< tuple<int, int>, vector< tuple<int, int > >,
                            greater< tuple<int, int > > > pq;

    pq.push(make_tuple(1, 1));
    pq.push(make_tuple(1, 1));
    pq.push(make_tuple(1, 1));


    while(!pq.empty()) {
        cout << get<0>(pq.top()) << endl;
        pq.pop();
    }

    return 0;
}
