#include "global.h"

// instance format: edge length, (start node, end node)
using edge = std::pair<int, std::pair<int, int>>;

class MaxHeap
{    
public:
    MaxHeap(std::vector<edge> edges);

    void insert(edge e);

    edge top();

    edge pop();

    bool empty();

private:
    void swap(int n1, int n2);

    void up(int idx);

    void down(int idx);

    int edge_len(int idx);

    edge heap_[max_nodes * max_nodes * 2];
    int size_;
};
