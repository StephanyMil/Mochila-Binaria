// Função para calcular o máximo de dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

#include <stdio.h>

typedef struct {
    int valor;
    int peso;
    float razao;
} Item;

// Função de partição para o quicksort
int partition(Item arr[], int low, int high) {
    float pivot = arr[high].razao;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].razao >= pivot) {
            i++;
            // Troca arr[i] e arr[j]
            Item temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Troca arr[i+1] e arr[high]
    Item temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Função de ordenação quicksort
void quicksort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Função que implementa o algoritmo guloso para o problema da mochila 0/1
void Metodo_Guloso(int valor[], int peso[], int M, int n) {
    Item itens[n];

    for(int i=0; i<n; i++){
        itens[i].valor = valor[i];
        itens[i].peso = peso[i];
        itens[i].razao = (float)valor[i]/peso[i];
    }

    quicksort(itens, 0, n-1);

    int capacidade = M;  // Capacidade utilizada da mochila
    int solucao[n];  // Vetor solução

    // Inicialização do vetor solução
    for (int i = 0; i < n; i++) {
        solucao[i] = 0;
    }
    // Loop: colocando cada item na mochila
    for (int i = 0; i<n; i++) {
        if (itens[i].peso <= capacidade) {
            solucao[i] = 1;
            capacidade -= itens[i].peso;
        }
    }
    // Segundo loop: procurando itens restantes para preencher o espaço da mochila
    for (int j = 0; j < n; j++) {
        if (itens[j].peso <= capacidade) {
            solucao[j] = 1;
            capacidade -= itens[j].peso;
        }
    }
    // Exibindo resultados
    printf("Solução Gulosa:\n");
    printf("Itens selecionados: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", solucao[i]);
    }
    printf("\n");
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
    Metodo_Guloso(valores, pesos, capacidade, n);
    printf("\n");

    return 0;
}
