#include "./header/adj_list.h"

int main() {
    listGraph g;

    g.input_adj_list("./source/graph.txt");
    cout << "read source successflly\n";


    g.show_graph();

    return 0;
}
