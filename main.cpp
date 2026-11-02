#include "graph.h"

simple_graph my_graph;

int main(void) {
    my_graph.init();
    my_graph.run(1);
    my_graph.end();
    return 0;
}