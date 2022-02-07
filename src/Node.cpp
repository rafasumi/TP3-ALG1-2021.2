#include "Node.hpp"
#include "utils.hpp"

Node::Node(int row, int column, int n, int m, NodeType type) {
  this->row = row;
  this->column = column;
  this->longestKnownPath = utils::NEG_INFINITY;
  this->successor = nullptr;
  this->type = type;

  if (type == NodeType::DEST)
    this->longestKnownPath = 0;

  setIncomingNeighbors(n, m);
}

void Node::setIncomingNeighbors(int n, int m) {
  // Existem dois casos possíveis para definir os vizinhos: quando é um nó comum e quando é um nó de destino, já que
  // quando é um nó de origem, não há arestas incidentes

  // Quando é um nó comum, os nó de onde partem arestas incidentes são aqueles que estão na fileira de acima do nó em questão
  // e que estão à esquerda, à direita ou na mesma coluna que ele. Além disso, é preciso considerar os casos em que o nó está
  // na primeira ou na última coluna, já que assim ele terá apenas dois vizinhos, e quando ele está na primeira fileira, já que
  // nesse caso o único vizinho é o nó de origem
  if (this->type == NodeType::COMMON) {
    if (this->row == 0) {
        // Caso em que o nó está na primeira fileira
        this->incomingNeighbors.push_back(0);
    } else {
      // Obtém o índice do vizinho imediatamente acima do nó em questão. Para obter o índice de um nó a partir de sua fileira e
      // coluna, foi considerada a seguinte fórmula: fileira*m + coluna + 1, onde m é o número total de colunas. O +1 se deve ao
      // fato de que o primeiro elemento da lista é o nó de origem, que não está dentro do grid que possui as macieiras.
      int neighborAbove = (this->row - 1)*m + this->column + 1;
      if (column == 0) {
        // Caso em que o nó está na primeira coluna
        this->incomingNeighbors = {neighborAbove, neighborAbove + 1};
      } else if (column == m - 1) {
        // Caso em que o nó está na última coluna
        this->incomingNeighbors = {neighborAbove - 1, neighborAbove};
      } else {
        // Caso em que o nó está entre a primeira e a última coluna
        this->incomingNeighbors = {neighborAbove - 1, neighborAbove, neighborAbove + 1};
      }
    }
  } else if (this->type == NodeType::DEST) {
    // Quando é um nó de destino, os vizinhos são todos os nós da fileira acima, que é a última do grid das macieiras.
    // Obtém o primeiro nó da última fileira, usando a mesma fórmula de antes
    int firstOfLastRow = (n - 1) * m + 1;
    // Adiciona os nós da última fileira de fórmula iterativa
    for (int i = 0; i < m; i++)
      this->incomingNeighbors.push_back(firstOfLastRow + i);
  }
}
