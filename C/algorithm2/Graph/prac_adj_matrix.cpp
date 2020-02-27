#include "./header/adj_matrix.h"

int main() {
    matrixGraph g;

    g.get_adj_matrix("./source/graph.txt");
    g.show_graph();

    g.dfs_adj_matrix_nonrecur();

    return 0;
}
