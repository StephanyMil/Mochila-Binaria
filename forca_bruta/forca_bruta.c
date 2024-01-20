#include <stdio.h>

// Função para calcular o máximo de dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Força Bruta com Iteração
void mochila_binaria_forca_bruta(int valores[], int pesos[], int capacidade, int n, int combinacao_atual[]) {
    int melhor_valor = 0;
    int melhor_combinacao[n];
    
    for (int i = 0; i < (1 << n); i++) {
        int peso_total = 0;
        int valor_total = 0;

        for (int j = 0; j < n; j++) {
            combinacao_atual[j] = (i >> j) & 1;  // Obtém o bit j da representação binária de i
            peso_total += combinacao_atual[j] * pesos[j];
            valor_total += combinacao_atual[j] * valores[j];
        }

        if (peso_total <= capacidade && valor_total > melhor_valor) {
            melhor_valor = valor_total;
            for (int j = 0; j < n; j++) {
                melhor_combinacao[j] = combinacao_atual[j];
            }
        }
    }

    // Exibir resultados
    printf("Força Bruta com Iteração:\n");
    printf("Melhor valor: %d\n", melhor_valor);
    printf("Melhor combinação de itens: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", melhor_combinacao[i]);
    }
    printf("\n");
}

int main() {
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int capacidade = 50;
    int n = sizeof(valores) / sizeof(valores[0]);
    
    int combinacao_atual[n];


    // Força Bruta com Iteração
    mochila_binaria_forca_bruta(valores, pesos, capacidade, n, combinacao_atual);
    printf("\n");

    return 0;
}
