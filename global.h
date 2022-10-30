#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <utility>
#include <vector>
#include <stdlib.h>
#include <string>

#define max_nodes 5000
#define cluster_threshold 4096
extern bool print_verbose;

// instance format: call count, (start node, end node)
using edge = std::pair<int, std::pair<int, int>>;

// format: function name, function size
using function = std::pair<std::string, int>;

#endif