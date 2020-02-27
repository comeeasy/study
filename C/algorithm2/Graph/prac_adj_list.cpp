#include "./header/adj_list.h"

int main() {
    listGraph g;

    g.input_adj_list("./source/graph.txt");
    g.show_graph();

    g.bfs_adj_list_nonrecur();

    return 0;
}
