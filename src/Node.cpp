#include "Node.hpp"
#include "utils.hpp"

Node::Node(int row, int column, int n, int m, NodeType type) {
  this->row = row;
  this->column = column;
  this->longestKnownPath = utils::NEG_INFINITY;
  this->predecessor = nullptr;
  this->type = type;

  if (type == NodeType::DEST)
    this->longestKnownPath = 0;

  setIncomingNeighbors(n, m);
}

void Node::setIncomingNeighbors(int n, int m) {
  if (this->type == NodeType::COMMON) {
    if (this->row == 0) {
        this->incomingNeighbors.push_back(0);
    } else {
      int neighborAbove = (this->row - 1)*m + this->column + 1;
      if (column == 0) {
        this->incomingNeighbors = {neighborAbove, neighborAbove + 1};
      } else if (column == m - 1) {
        this->incomingNeighbors = {neighborAbove - 1, neighborAbove};
      } else {
        this->incomingNeighbors = {neighborAbove - 1, neighborAbove, neighborAbove + 1};
      }
    }
  } else if (this->type == NodeType::DEST) {
    int firstOfLastRow = (n - 1) * m + 1;
    for (int i = 0; i < m; i++)
      this->incomingNeighbors.push_back(firstOfLastRow + i);
  }
}
