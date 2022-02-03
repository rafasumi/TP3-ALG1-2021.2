#include "utils.hpp"

std::vector<Node*> utils::buildNodeList(int rows, int columns) {
  std::vector<Node*> nodeList;

  Node* source = new Node(-1, 0, rows, columns, NodeType::SOURCE);
  nodeList.push_back(source);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      Node* node = new Node(i, j, rows, columns, NodeType::COMMON);
      nodeList.push_back(node);
    }
  }

  Node* dest = new Node(rows, columns, rows, columns, NodeType::DEST);
  nodeList.push_back(dest);

  return nodeList;
}

void utils::longestPath(int rows, int columns, int** weights, std::vector<Node*>* nodeList) {  
  for (int j = nodeList->size() - 1; j >= 0; j--) {
    Node* node = nodeList->at(j);

    for (int neighbor : node->incomingNeighbors) {
      Node* neighborNode = nodeList->at(neighbor);

      int edgeWeight = 0;
      if (node->type == NodeType::COMMON)
        edgeWeight = weights[node->row][node->column];

      if (node->longestKnownPath + edgeWeight >= neighborNode->longestKnownPath) {
        neighborNode->longestKnownPath = node->longestKnownPath + edgeWeight;
        neighborNode->predecessor = node;
      }
    }
  }
}