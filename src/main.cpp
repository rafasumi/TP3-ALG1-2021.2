#include <iostream>
#include <map>
#include "utils.hpp"
#include "Node.hpp"

int main(int argc, char const *argv[]) {
  int rows, columns;

  std::cin >> rows >> columns;
  int** weightMatrix = new int*[rows];
  for (int i = 0; i < rows; i++) 
    weightMatrix[i] = new int[columns];

  int weight;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cin >> weight;
      weightMatrix[i][j] = -1*weight;
    }
  }

  std::map<NodeId, Node*> nodeMap = buildNodeMap(rows, columns);

  bellmanFordMoore(rows, columns, weightMatrix, &nodeMap);

  NodeId source = NodeId(-1, 0);
  Node* sourceNode = nodeMap[source];

  int largestPath = -1*sourceNode->shortestKnownPath;
  std::cout << largestPath << std::endl;

  Node* successor = sourceNode->successor;
  while (successor != nullptr) {
    if (successor->id.second < columns)
      std::cout << successor->id.second << " ";
    successor = successor->successor;
  }
  std::cout << std::endl;

  for (auto it : nodeMap)
    delete it.second;

  for (int i = 0; i < rows; i++) 
    delete[] weightMatrix[i];
  delete[] weightMatrix;

  return 0;
}
