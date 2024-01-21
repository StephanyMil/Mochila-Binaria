#include <stdio.h>

// Função para calcular o máximo de dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila_divisao_conquista(int valores[], int pesos[], int capacidade, int inicio, int fim) {
    if (inicio > fim) {
        return 0;
    }
    int meio = (inicio + fim) / 2;

    int inclui_meio = (capacidade >= pesos[meio]) ?
        valores[meio] + mochila_divisao_conquista(valores, pesos, capacidade - pesos[meio], inicio, meio - 1) +
        mochila_divisao_conquista(valores, pesos, capacidade - pesos[meio], meio + 1, fim) : 0;

    int exclui_meio = mochila_divisao_conquista(valores, pesos, capacidade, inicio, meio - 1) +
                     mochila_divisao_conquista(valores, pesos, capacidade, meio + 1, fim);

    return max(inclui_meio, exclui_meio);
}

int main() {
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int capacidade = 50;
    int n = sizeof(valores) / sizeof(valores[0]);

    int resultado = mochila_divisao_conquista(valores, pesos, capacidade, 0, n - 1);

    printf("Resultado da mochila: %d\n", resultado);

    return 0;
}
