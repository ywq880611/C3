#include "maxHeap.h"

void MaxHeap::swap(int idx1, int idx2){
    edge tmp = heap_[idx1];
    heap_[idx1] = heap_[idx2];
    heap_[idx2] = tmp;
}

int MaxHeap::edge_count(int idx){
    return heap_[idx].first;
}

void MaxHeap::up(int idx){
    int predecessor_idx = idx / 2 - 1;
    if(edge_count(predecessor_idx) < edge_count(idx)){
        swap(idx, predecessor_idx);
        up(predecessor_idx);
    }
}

void MaxHeap::down(int idx){
    int left_idx = idx * 2 + 1;
    int right_idx = idx * 2 + 2;
    int count = edge_count(idx);
    int left_count = edge_count(left_idx);
    int right_count = edge_count(right_idx);
    if(left_count > right_count && left_count > count){
        swap(left_idx, idx);
        return down(left_idx);
    }
    else if(right_count > left_count && right_count > count){
        swap(right_idx, idx);
        return down(right_idx);
    }
}

void MaxHeap::insert(edge e){
    heap_[size_] = e;
    up(size_);
    size_ ++;
}

edge MaxHeap::top(){
    if(empty()) abort();
    return heap_[0];
}

edge MaxHeap::pop(){
    if(empty()) abort();
    edge t = top();
    size_ --;
    swap(0, size_);
    down(0);
    return t;
}

bool MaxHeap::empty(){
    return size_ <= 0;
}

MaxHeap::MaxHeap(std::vector<edge> edges){
    for(edge e : edges){
        // We could optimize as O(n) by building heap from buttom to top.
        // it's O(nlogn) now, because heap was built from top to buttom.
        insert(e);
    }
}

MaxHeap::MaxHeap(std::vector<std::vector<edge>> func_edges){
    for(std::vector<edge> edges : func_edges){
        for(edge e: edges){
            insert(e);
        }
    }
}