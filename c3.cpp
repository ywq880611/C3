#include "c3.h"
#include <string.h>
#include <algorithm>


C3::C3(std::vector<function> fs, std::vector<std::vector<edge>> es): 
        functions_(fs),
        edges_(es),
        max_heap_(es),
        disjoint_set_(functions_.size()),
        clusters_(functions_.size()),
        cluster_size_(functions_.size()) {
    memset(clusetr_call_count_, 0, sizeof(clusetr_call_count_));
    for(int i = 0; i < functions_.size(); i ++){
        cluster_size_[i] = functions_[i].second;
    }
    for(auto edges: es){
        for(auto e: edges){
            int count = e.first;
            int start = e.second.first;
            int end = e.second.second;
            if(start != end) clusetr_call_count_[start][end] = count;
        }
    }
}

void C3::clustering(){
    while(!max_heap_.empty()){
        edge top = max_heap_.pop();
        int count = top.first;
        int start = top.second.first;
        int end = top.second.second;
        if(disjoint_set_.find(start) == start && \
        cluster_size_[start] <= cluster_threshold && \
        disjoint_set_.find(end) == end && \
        cluster_size_[end] <= cluster_threshold){
            disjoint_set_.merge(start, end);
            cluster_size_[start] += cluster_size_[end];

            for(int node: clusters_[start]){
                clusters_[end].push_back(node);
            }
            clusters_.clear();

            // update cluster call count table
            clusetr_call_count_[start][end] = 0;
            clusetr_call_count_[end][start] = 0;
            for(int i = 0; i < functions_.size(); i ++){
                clusetr_call_count_[start][i] += clusetr_call_count_[end][i];
                if(clusetr_call_count_[end][i] != 0){
                    edge new_edge(clusetr_call_count_[start][i], {start, i});
                    max_heap_.insert(new_edge);
                    if(print_verbose) {
                        printf("updating: cluster %d to %d, merge %d to %d, it's %d now.\n", \
                        start, i, end, i, clusetr_call_count_[start][i]);
                    }
                }
                clusetr_call_count_[i][start] += clusetr_call_count_[i][end];
                if(clusetr_call_count_[i][end] != 0){
                    edge new_edge(clusetr_call_count_[i][start], {i, start});
                    max_heap_.insert(new_edge);
                    if(print_verbose) {
                        printf("updating: cluster %d to %d, merge %d to %d, it's %d now.\n", \
                        i, start, i, end, clusetr_call_count_[i][start]);
                    }
                }
                clusetr_call_count_[i][end] = 0;
            }
        }
    }
    if(print_verbose){
        for(int i = 0; i < clusters_.size(); i ++){
            if(!clusters_[i].empty()){
                printf("cluster %d have nodes:", i);
                for(auto j : clusters_[i]){
                    printf(" %d,", j);
                }
                printf("\n");
            }
        }
    }
}

bool cmp(std::pair<int, double> c1, std::pair<int, double> c2){
    return c1.second < c2.second;
}

void C3::sort_cluster(){
    std::vector<std::pair<int, double>> cluster_density;
    for(int i = 0; i < clusters_.size(); i ++){
        if(!clusters_[i].empty()){
            int call_count = 0;
            int cluster_size = 0;
            for(int j = 0; j < functions_.size(); j ++){
                call_count += clusetr_call_count_[j][i];
            }
            for(int j = 0; j < clusters_[i].size(); j ++){
                cluster_size += functions_[j].second;
            }
            cluster_density.push_back({i, call_count / cluster_size});
        }
    }
    sort(cluster_density.begin(), cluster_density.end(), cmp);
    if(print_verbose) printf("cluster order is:");
    for(int i = 0; i < cluster_density.size(); i ++){
        if(print_verbose) printf(" %d, ", cluster_density[i].first);
        for(auto j : clusters_[i]){
            order_.push_back(j);
        }
    }
    if(print_verbose) printf("\n");
}

void C3::reorder(){
    clustering();
    sort_cluster();
}

void C3::print_result(){
    printf("order is :");
    for(auto i : order_){
        printf(" %d", i);
    }
    printf("\n");
}