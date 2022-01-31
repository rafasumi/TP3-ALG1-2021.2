#include "Node.hpp"
#include "utils.hpp"

Node::Node(int row, int column, int n, int m, NodeType type) {
  this->id = NodeId(row, column);
  this->shortestKnownPath = INFINITY;
  this->successor = nullptr;
  this->type = type;

  if (type == NodeType::DEST) {
    this->shortestKnownPath = 0;
  }

  setIncomingNeighbors(n, m);
}

void Node::setIncomingNeighbors(int n, int m) {
  if (this->type == NodeType::COMMON) {
    if (this->id.first == 0) {
        this->incomingNeighbors.push_back(NodeId(-1, 0));
    } else {
      for (int i = -1; i <= 1; i++) {
        if (isValidNode(this->id.first - 1, this->id.second + i, n, m))
          this->incomingNeighbors.push_back(NodeId(this->id.first - 1, this->id.second + i));
      }
    }
  } else if (this->type == NodeType::DEST) {
    for (int i = 0; i < m; i++)
      this->incomingNeighbors.push_back(NodeId(this->id.first - 1, i));
  }
}

bool Node::isValidNode(int row, int column, int n, int m) {
  return ((row >= 0) && (row < n) && (column >= 0) && (column < m));
}
