#include "utils.hpp"

std::vector<Node*> utils::buildNodeList(int rows, int columns) {
  std::vector<Node*> nodeList;

  // Insere o nó de origem no início do vetor (posição 0)
  Node* source = new Node(-1, -1, rows, columns, NodeType::SOURCE);
  nodeList.push_back(source);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      // Insere recursivamente os nós comuns (posição i*columns + j + 1)
      Node* node = new Node(i, j, rows, columns, NodeType::COMMON);
      nodeList.push_back(node);
    }
  }

  // Insere o nó de destino ao final do vetor (posição nodeList.size() - 1)
  Node* dest = new Node(-1, -1, rows, columns, NodeType::DEST);
  nodeList.push_back(dest);

  return nodeList;
}

void utils::computeLongestPath(int** weights, std::vector<Node*>* nodeList) {  
  // Itera por todos os nós da lista, partindo do nó de destino
  for (int j = nodeList->size() - 1; j >= 0; j--) {
    Node* node = nodeList->at(j);

    // Pega o peso das arestas incidentes no nó em questão. Se for um nó comum, o peso se encontra na matriz weights na 
    // posição que a macieira do nó ocuparia. Caso contrário, o peso é 0.
    int edgeWeight = 0;
    if (node->type == NodeType::COMMON)
      edgeWeight = weights[node->row][node->column];

    // Itera por todos os vizinhos "incidentes" do nó, ou seja, todos aqueles de ondem partem arestas que incidem no nó
    for (int neighbor : node->incomingNeighbors) {
      Node* neighborNode = nodeList->at(neighbor);

      // Se o maior caminho conhecido de node até o destino mais o peso da aresta incidente for maior ou igual ao maior caminho
      // conhecido do vizinho até o nó de destino, então se considera que o novo maior caminho do nó vizinho passa por node.
      // Os valores de longestKnownPath e successor do vizinho são atualizados
      if (node->longestKnownPath + edgeWeight >= neighborNode->longestKnownPath) {
        neighborNode->longestKnownPath = node->longestKnownPath + edgeWeight;
        neighborNode->successor = node;
      }
    }
  }
}