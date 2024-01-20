#include <stdio.h>

typedef struct
{
    int valor;
    int peso;
    float razao;
} Item;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

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

int Metodo_Guloso(int peso[], int valor[], int M, int n, int solucao[])
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

    return valorTotal;
}

void Mochila_Aproximacao(int p[], int u[], int M, int n)
{
    int maior = u[0]; // Assume que o primeiro elemento é o maior inicialmente
    int maior_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (u[i] > maior)
        {
            maior = u[i]; // Atualiza o maior valor se encontrar um valor maior
            maior_index = i;
        }
    }

    int solucao[n];
    int maximo_valor = max(maior, Metodo_Guloso(p, u, M, n, solucao));

    if (maximo_valor == maior)
    {
        printf("Itens selecionados: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", i == maior_index ? 1 : 0);
        }
        printf("\n");
    }
    else
    {
        printf("Itens selecionados: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", solucao[i]);
        }
        printf("\n");
        printf("\n");
    }

    printf("Valor total dos itens selecionados = %d\n", maximo_valor); // Imprime o valor máximo obtido
}

int main()
{
    int p[] = {10, 20, 30};           // Pesos dos itens
    int u[] = {60, 100, 120};         // Valores dos itens
    int M = 50;                       // Capacidade da mochila
    int n = sizeof(p) / sizeof(p[0]); // Número de itens

    Mochila_Aproximacao(p, u, M, n);

    return 0;
}