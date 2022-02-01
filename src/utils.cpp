#include <iostream>
#include "utils.hpp"

std::map<NodeId, Node*> utils::buildNodeMap(int rows, int columns) {
  std::map<NodeId, Node*> nodeMap;

  Node* source = new Node(-1, 0, rows, columns, NodeType::SOURCE);
  Node* dest = new Node(rows, columns, rows, columns, NodeType::DEST);
  nodeMap.insert(std::pair<NodeId, Node*>(source->id, source));
  nodeMap.insert(std::pair<NodeId, Node*>(dest->id, dest));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      Node* node = new Node(i, j, rows, columns, NodeType::COMMON);
      nodeMap.insert(std::pair<NodeId, Node*>(node->id, node));
    }
  }

  return nodeMap;
}

void utils::bellmanFordMoore(int rows, int columns, int** weights, std::map<NodeId, Node*>* nodeMap) {  
  bool updatedAny; 

  for (int i = 0; i < (rows*columns) - 1; i++) {
    updatedAny = false;

    for (auto it : *nodeMap) {
      if (!it.second->wasUpdatedLast) continue;

      for (NodeId neighbor : it.second->incomingNeighbors) {
        Node* node = (*nodeMap)[neighbor];
        int edgeWeight = 0;
        if (node->type == NodeType::COMMON)
          edgeWeight = weights[neighbor.first][neighbor.second];

        if (node->shortestKnownPath > it.second->shortestKnownPath + edgeWeight && it.second->shortestKnownPath != INFINITY) {
          node->shortestKnownPath = it.second->shortestKnownPath + edgeWeight;
          node->successor = it.second;
          node->wasUpdated = true;
          updatedAny = true;
        }
      }
    }

    for (auto it : *nodeMap) {
      it.second->wasUpdatedLast = it.second->wasUpdated;
      it.second->wasUpdated = false;
    }

    if (!updatedAny) break;
  }
}
