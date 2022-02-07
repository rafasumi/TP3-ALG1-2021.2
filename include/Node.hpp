#ifndef NODE_H
#define NODE_H

#include <vector>

// Enum que representa os possíveis tipos de vértices: origem, destino ou comum.
// Os nós comuns são aqueles que representam as macieiras, de forma que estão dispostos em
// fileiras e colunas.
// O nó de origem se encontra antes dos nós que representam a primeira fileira de macieiras.
// O nó de destino se encontra após os nós que representam a última fileira de macieiras.
enum NodeType {
  COMMON,
  SOURCE,
  DEST
};

// Classe que representa um nó no grafo modelado para o problema. Cada nó representa uma macieira na plantação
class Node {
  public:
    Node(int row, int column, int n, int m, NodeType type);

    // Indica a fileira na qual se encontra a macieira que o nó representa. É -1 para os nós de origem e destino
    int row;
    // Indica a coluna na qual se encontra a macieira que o nó representa. É -1 para os nós de origem e destino
    int column;
    // Maior caminho conhecido do nó em questão ao nó de destino. De início, é -inf para todo nó
    // exceto para o de destino, que é 0.
    int longestKnownPath;
    // Sucessor do nó em questão no maior caminho até o nó de destino
    Node* successor;
    // Vetor com os índices dos nós vizinhos que possuem uma aresta que leva até o nó da classe
    std::vector<int> incomingNeighbors;
    // Tipo do nó
    NodeType type;

  private:
    // Instancia o vetor incomingNeighbors para um determinado nó considerando o tamanho a quantidade de fileiras e colunas
    // de macieiras
    void setIncomingNeighbors(int n, int m);
};

#endif
