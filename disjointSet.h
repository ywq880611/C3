#ifndef DISJOINT_SET_
#define DISJOINT_SET_

#include "global.h"

class DisjointSet
{
public:
    DisjointSet(int size);

    int find(int idx);

    void merge(int par, int chi);

private:
    int fa_[max_nodes];
    int size_;
};

#endif