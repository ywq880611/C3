#include "disjointSet.h"

DisjointSet::DisjointSet(int size){
    size_ = size;
    for(int i = 0; i < size_; i ++){
        fa_[i] = i;
    }
}

int DisjointSet::find(int idx){
    if(idx == fa_[idx]) return idx;
    return find(fa_[idx]);
}

void DisjointSet::merge(int par, int chi){
    int par_idx = find(par);
    int chi_idx = find(chi);
    fa_[chi_idx] = par_idx;
}
