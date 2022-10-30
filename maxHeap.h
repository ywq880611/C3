#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

#include "global.h"

class MaxHeap
{    
public:
    MaxHeap(std::vector<edge> edges);

    MaxHeap(std::vector<std::vector<edge>> func_edges);

    void insert(edge e);

    edge top();

    edge pop();

    bool empty();

private:
    void swap(int n1, int n2);

    void up(int idx);

    void down(int idx);

    int edge_count(int idx);

    edge heap_[max_nodes * max_nodes * 2];
    int size_;
};

#endif