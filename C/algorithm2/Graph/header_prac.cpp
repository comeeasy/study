#include "./header/adj_matrix.h"

int main() {
    matrixGraph g;

    g.get_adj_matrix("graph.txt");
    g.show_graph();

    return 0;
}
