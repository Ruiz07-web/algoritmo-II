#include <stdio.h>
#include <string.h>
#define MAX 31
#define MAX_CAD 100
typedef struct
{
    int cod;
    char nome[MAX];
    float price;
} tProduto;

void LeN(int *n);
void LeProdutos( tProduto produtos[], int n);
int IndiceMaisCaro(tProduto produtos[], int n);
int main(void)
{
    int n, maior;
    tProduto produtos[MAX_CAD];
    LeN(&n);
    LeProdutos(produtos, n);
    maior = IndiceMaisCaro( produtos,  n);
    printf("Indice do maior eh: %d\ncódigo: %d\nproduto: %s\npreço: %.2f\n", maior, produtos[maior].cod,  produtos[maior].nome,  produtos[maior].price);
    return 0;
}

void LeN(int *n)
{
    do
    {
        printf("Digite a quantidade de produtos:\n");
        scanf("%d", n);
    }
    while (*n < 1 || *n > MAX_CAD);
}

void LeProdutos( tProduto produtos[], int n){
    for(int i = 0; i < n; i++){
        printf("digite o código %d:\n", i);
        scanf("%d", &produtos[i].cod);
        printf("Digite o nome %d:\n", i);
        scanf("%s", produtos[i].nome);
        printf("Digite o preço %d:\n", i);
        scanf("%f", &produtos[i].price);
    }
}


int IndiceMaisCaro(tProduto produtos[], int n){
    int  ind;
    ind = 0;

    for(int i = 1; i < n; i++){
        if(produtos[i].price > produtos[ind].price){
            ind = i;
        }
    }
    return ind;
}
