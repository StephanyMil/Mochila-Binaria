#include <iostream>
#include <vector>
#include <chrono> // Incluindo a biblioteca chrono para medir o tempo
using namespace std;
using namespace std::chrono;

int mochilaRecursiva(vector< vector<int> > tabela, int lucros[], int tamanhoLucros, int pesos[], int capacidade, int indiceAtual) {
     // Verificando se o peso não ultrapassa a capacidade
    if (capacidade <= 0 || indiceAtual >= tamanhoLucros || indiceAtual < 0)
      return 0;

    // Se o problema já estiver resolvido, retorne o resultado da tabela
    if (tabela[indiceAtual][capacidade] != 0)
      return tabela[indiceAtual][capacidade];

    // Chamada recursiva após escolher o elemento no índiceAtual
    // Se o peso do elemento no índiceAtual ultrapassar a capacidade, não processaremos isso
    int lucro1 = 0;
    if (pesos[indiceAtual] <= capacidade)
      lucro1 = lucros[indiceAtual] + mochilaRecursiva(tabela, lucros, tamanhoLucros, pesos,
        capacidade - pesos[indiceAtual], indiceAtual + 1);

    // Chamada recursiva após excluir o elemento no índiceAtual
    int lucro2 = mochilaRecursiva(tabela, lucros, tamanhoLucros, pesos, capacidade, indiceAtual + 1);

    tabela[indiceAtual][capacidade] = max(lucro1, lucro2);
    return tabela[indiceAtual][capacidade];
  }

int mochila(int lucros[], int tamanhoLucros, int pesos[], int capacidade) {
  vector< vector<int> > tabela(tamanhoLucros, std::vector<int>(capacidade + 1, 0));

  // Início da medição do tempo
  auto start_time = high_resolution_clock::now();

  int resultado = mochilaRecursiva(tabela, lucros, tamanhoLucros, pesos, capacidade, 0);

  // Fim da medição do tempo
  auto end_time = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end_time - start_time);

  cout << "Tempo de execução = " << duration.count() << " ms" << endl;
  
  cout << "Lucro total da mochila = ";

  return resultado;
}

int main() {
  int lucros[] = {60, 100, 120, 130, 150};
  int pesos[] = {10, 20, 30, 40, 50};

  cout << mochila(lucros, 4, pesos, 50) << endl;
  return 0;
}
