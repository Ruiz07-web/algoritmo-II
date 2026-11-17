#include <stdio.h>
#include <stdlib.h>
#define MAX 31
typedef struct
{
    int codigo;
    char nome[MAX];
    float price;
} tProduto;

void LeN(int *n);
void LeProdutos(int n, tProduto *produtos);
void LeVlimite(float *limite);
void ImprimeAcima(int n, tProduto *produtos, float limite);
int main(void)
{
    int n;
    float limite;
    tProduto *produtos;
    LeN(&n);

    produtos = malloc(n * (sizeof(tProduto)));

    if (produtos == NULL)
    {
        printf("Erro ao alocar memory\n");
        return -1;
    }
    LeProdutos(n, produtos);
    LeVlimite(&limite);
    ImprimeAcima(n, produtos, limite);
    free(produtos);
    return 0;
}

void LeN(int *n)
{
    do
    {
        scanf("%d", n);
    }
    while (*n < 1);
}

void LeProdutos(int n, tProduto *produtos)
{
    tProduto *p;
    for (p = produtos; p < n + produtos; p++)
    {
        scanf("%d", &p->codigo);
        scanf("%s", p->nome);
        scanf("%f", &p->price);
    }
}

void LeVlimite(float *limite)
{
    do
    {
        scanf("%f", limite);
    }
    while (*limite < 0);
}

void ImprimeAcima(int n, tProduto *produtos, float limite)
{
    tProduto *p;
    for (p = produtos; p < n + produtos; p++)
    {
        if (p->price > limite)
        {
            printf("%d %s %.2f\n", p->codigo, p->nome, p->price);
        }
    }
}
