#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <limits>
#include "Node.hpp"

namespace utils {
  const int NEG_INFINITY = std::numeric_limits<int>::min();;

  std::vector<Node*> buildNodeList(int rows, int columns);
  void longestPath(int rows, int columns, int** weights, std::vector<Node*>* nodeList);
}

#endif
