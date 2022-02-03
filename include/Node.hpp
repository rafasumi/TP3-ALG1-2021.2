#ifndef NODE_H
#define NODE_H

#include <vector>

enum NodeType {
  COMMON,
  SOURCE,
  DEST
};

class Node {
  public:
    Node(int row, int column, int n, int m, NodeType type);

    int row, column;
    int longestKnownPath;
    Node* predecessor;
    std::vector<int> incomingNeighbors;
    NodeType type;

  private:
    void setIncomingNeighbors(int n, int m);
};

#endif
