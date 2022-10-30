#include "c3.h"

#include <string.h>
#include <iostream>

extern bool print_verbose;

std::vector<function> case1_functions = {
    {"A", 10},
    {"B", 10},
    {"C", 10},
    {"D", 10}
};

std::vector<std::vector<edge>> case1_edges ={
    {
        {100, {0, 1}},
        {40, {0, 2}}
    },
    {
        {30, {1, 2}}
    },
    {
        {90, {2, 3}}
    }
};

int main(int argc, char* argv[]){
    //printf("123\n\n");
    //fflush(stdout);
    std::cout << "123" << std::endl;
    //if(argc == 2 && strcmp(argv[1], "-v")) print_verbose = true;
    //int t = *(int*)(0);
    C3 case1(case1_functions, case1_edges);
    //case1.reorder();
    //case1.print_result();
}