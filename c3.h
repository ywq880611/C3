#ifndef C3_H_
#define C3_H_

#include "disjointSet.h"
#include "maxHeap.h"
#include "global.h"

class C3{
public:
    C3(std::vector<function> fs, std::vector<std::vector<edge>> es);

    void reorder();

    void print_result();

private:
    void clustering();

    void sort_cluster();

    std::vector<function> functions_;
    std::vector<std::vector<edge>> edges_;
    std::vector<int> order_;
    std::vector<int> cluster_size_;
    int clusetr_call_count_[max_nodes][max_nodes];
    std::vector<std::vector<int>> clusters_;
    MaxHeap max_heap_;
    DisjointSet disjoint_set_;
};

#endif