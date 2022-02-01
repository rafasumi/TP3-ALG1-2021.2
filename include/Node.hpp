#ifndef NODE_H
#define NODE_H

#include <vector>

enum NodeType {
  COMMON,
  SOURCE,
  DEST
};

using NodeId = std::pair<int, int>;

class Node {
  public:
    Node(int row, int column, int n, int m, NodeType type);

    NodeId id;
    int shortestKnownPath;
    Node* successor;
    std::vector<NodeId> incomingNeighbors;
    NodeType type;
    bool wasUpdatedLast;
    bool wasUpdated;

  private:
    void setIncomingNeighbors(int n, int m);
    bool isValidNode(int row, int column, int n, int m);
};

#endif
