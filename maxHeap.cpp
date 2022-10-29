#include "maxHeap.h"

void MaxHeap::swap(int idx1, int idx2){
    edge tmp = heap_[idx1];
    heap_[idx1] = heap_[idx2];
    heap_[idx2] = tmp;
}

int MaxHeap::edge_len(int idx){
    return heap_[idx].first;
}

void MaxHeap::up(int idx){
    int predecessor_idx = idx / 2 - 1;
    if(edge_len(predecessor_idx) < edge_len(idx)){
        swap(idx, predecessor_idx);
        up(predecessor_idx);
    }
}

void MaxHeap::down(int idx){
    int left_idx = idx * 2 + 1;
    int right_idx = idx * 2 + 2;
    int len = edge_len(idx);
    int left_len = edge_len(left_idx);
    int right_len = edge_len(right_idx);
    if(left_len > right_len && left_len > len){
        swap(left_idx, idx);
        return down(left_idx);
    }
    else if(right_len > left_len && right_len > len){
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