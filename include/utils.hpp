#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <limits>
#include "Node.hpp"

// Namespace que contém funções e dados úteis
namespace utils {
  // Constante que representa -inf. No caso, é o menor valor que um int em C++ pode armazenar
  const int NEG_INFINITY = std::numeric_limits<int>::min();;

  // Função que constrói a lista de nós do grafo que modela o grid de macieiras. Além dos nós que representam macieiras
  // há um nó de destino e um nó de origem
  std::vector<Node*> buildNodeList(int rows, int columns);
  // Função que encontra o maior caminho do nó de origem até o nó de destino
  void computeLongestPath(int** weights, std::vector<Node*>* nodeList);
}

#endif
