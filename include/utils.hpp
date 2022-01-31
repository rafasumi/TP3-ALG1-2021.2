#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <limits>
#include "Node.hpp"

const int INFINITY = 300000;

std::map<NodeId, Node*> buildNodeMap(int rows, int columns);
void bellmanFordMoore(int rows, int columns, int** weights, std::map<NodeId, Node*>* nodeMap);
void shortestPaths(int rows, int columns, int** weights, std::map<NodeId, Node*>* nodeMap);

#endif
