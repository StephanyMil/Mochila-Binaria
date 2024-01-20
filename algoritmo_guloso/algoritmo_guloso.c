#include <stdio.h>

typedef struct
{
    int valor;
    int peso;
    float razao;
} Item;

// Função de partição para o quicksort
int partition(Item arr[], int low, int high)
{
    float pivot = arr[high].razao;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].razao >= pivot)
        {
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
void quicksort(Item arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Função que implementa o algoritmo guloso para o problema da mochila 0/1
void Metodo_Guloso(int valor[], int peso[], int M, int n)
{
    Item itens[n];

    for (int i = 0; i < n; i++)
    {
        itens[i].valor = valor[i];
        itens[i].peso = peso[i];
        itens[i].razao = (float)valor[i] / peso[i];
    }

    quicksort(itens, 0, n - 1);

    int capacidade = M; // Capacidade utilizada da mochila
    int solucao[n];     // Vetor solução
    int valorTotal = 0; // Soma dos valores dos itens selecionados

    // Inicialização do vetor solução
    for (int i = 0; i < n; i++)
    {
        solucao[i] = 0;
    }
    // Loop: colocando cada item na mochila
    int i;

    for (i = 0; i < n; i++)
    {
        if (itens[i].peso <= capacidade)
        {
            solucao[i] = 1;
            capacidade -= itens[i].peso;
            valorTotal += itens[i].valor; // Adiciona o valor do item selecionado ao total
        }
    }
    // Segundo loop: procurando itens restantes para preencher o espaço da mochila
    for (int j = i; j < n; j++)
    {
        if (itens[j].peso <= capacidade)
        {
            solucao[j] = 1;
            capacidade -= itens[j].peso;
            valorTotal += itens[j].valor; // Adiciona o valor do item selecionado ao total
        }
    }
    // Exibindo resultados
    printf("Solucao Gulosa:\n");
    printf("Itens selecionados: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", solucao[i]);
    }
    printf("\n");
    printf("Valor total dos itens selecionados: %d\n", valorTotal); // Imprime o valor total dos itens selecionados
    printf("\n");
}

int main()
{
    // Exemplo de entrada
    int valor[] = {60, 100, 120};
    int peso[] = {10, 20, 30};
    int M = 50;
    int n = sizeof(valor) / sizeof(valor[0]);

    // Chamada do método guloso
    Metodo_Guloso(valor, peso, M, n);

    return 0;
}
