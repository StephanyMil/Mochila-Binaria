#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void backtrackingMochilaBinaria(int i, int peso, int val, int *max_val, int pesos[], int valores[], int qtdItems, int pesoMaximo) {
    if (i == qtdItems || peso == pesoMaximo) {
        *max_val = max(*max_val, val);
        return;
    }
    if (peso + pesos[i] <= pesoMaximo) {
        backtrackingMochilaBinaria(i + 1, peso + pesos[i], val + valores[i], max_val, pesos, valores, qtdItems, pesoMaximo);
    }
    backtrackingMochilaBinaria(i + 1, peso, val, max_val, pesos, valores, qtdItems, pesoMaximo);
}

int main() {
int m, max_val = 0, valores[5] = {60, 100, 120, 130, 150}, pesos[5] = {10, 20, 30, 40, 50};
n = sizeof(valores) / sizeof(valores[0]);

    backtrackingMochilaBinaria(0, 0, 0, &max_val, pesos, valores, n, 50);
    printf("Valor maximo possivel: %d\n", max_val);
    return 0;
}
