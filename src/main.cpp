#include <iostream>
#include <vector>
#include "utils.hpp"
#include "Node.hpp"

int main(int argc, char const *argv[]) {
  int rows, columns;

  std::cin >> rows >> columns;
  int** weightMatrix = new int*[rows];
  for (int i = 0; i < rows; i++) 
    weightMatrix[i] = new int[columns];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cin >> weightMatrix[i][j];
    }
  }

  std::vector<Node*> nodeList = utils::buildNodeList(rows, columns);

  utils::longestPath(rows, columns, weightMatrix, &nodeList);

  Node* sourceNode = nodeList[0];

  int largestPath = sourceNode->longestKnownPath;
  std::cout << largestPath << std::endl;

  Node* predecessor = sourceNode->predecessor;
  while (predecessor != nullptr) {
    if (predecessor->column < columns)
      std::cout << predecessor->column << " ";
    predecessor = predecessor->predecessor;
  }
  std::cout << std::endl;
  
  for (Node* node : nodeList)
    delete node;

  for (int i = 0; i < rows; i++) 
    delete[] weightMatrix[i];
  delete[] weightMatrix;

  return 0;
}
