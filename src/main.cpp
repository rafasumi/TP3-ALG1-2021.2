#include <iostream>
#include <vector>
#include "utils.hpp"
#include "Node.hpp"

// Função main do programa. É responsável pela leitura do arquivo de input, por instanciar objetos e variáveis
// e pela chamada de funções necessárias para realizar o cálculo desejado.
int main(int argc, char const *argv[]) {
  int rows, columns;

  std::cin >> rows >> columns;

  // Instancia uma matriz que contém os valores da entrada. A matriz é utilizada como forma de armazenar os valores
  // de pesos para arestas de um grafo. A ideia da modelagem é que o grafo seja direcionado e tenha nós que representem
  // as macieiras. Assim o número de maçãs em uma macieira é o peso das arestas incidentes no nó que a representa.
  int** weightMatrix = new int*[rows];
  for (int i = 0; i < rows; i++) 
    weightMatrix[i] = new int[columns];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cin >> weightMatrix[i][j];
    }
  }

  // Constrói a lista que contém os nós do grafo modelado
  std::vector<Node*> nodeList = utils::buildNodeList(rows, columns);

  // Computa os maiores caminhos até o nó de origem
  utils::computeLongestPath(weightMatrix, &nodeList);

  // Pega o nó de origem
  Node* sourceNode = nodeList[0];

  // O maior caminho do nó de origem até o nó de destino é equivalente a maior quantidade de maçãs que podem ser colhidas em
  // uma viagem da colheitadeira obedecendo as suas restrições de movimentação
  int largestPath = sourceNode->longestKnownPath;
  std::cout << largestPath << std::endl;

  // Caminha pelos nós que compõem o maior caminho do nó de origem. Nesse caso, o valor que se deseja extrair é a coluna das
  // macieiras que esses nós representam 
  Node* successor = sourceNode->successor;
  while (successor != nullptr && successor->type == NodeType::COMMON) {
    std::cout << successor->column << " ";
    successor = successor->successor;
  }
  std::cout << std::endl;
  
  // Libera a memória alocada dinamicamente no programa
  for (Node* node : nodeList)
    delete node;

  for (int i = 0; i < rows; i++) 
    delete[] weightMatrix[i];
  delete[] weightMatrix;

  return 0;
}
