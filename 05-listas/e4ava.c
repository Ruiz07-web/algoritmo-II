#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int valor;
    struct no *prox;
} tNo;

void Empilha(tNo **val, int resto)
{
    tNo *novo;

    novo = (tNo *) malloc(sizeof(tNo));
    novo->valor = resto;
    novo->prox = *val;
    *val = novo;
}

void desimpilha(tNo **val)
{
    tNo *aux;
    printf("Valor binário = ");
    while (*val != NULL)
    {
        aux = *val;
        printf("%d", aux->valor);
        *val = (*val)->prox;

        free(aux);
    }
    printf("\n");
}
int main(void)
{
    tNo *valor = NULL;
    int n, resto; // valor em decimal
    do
    {
        scanf("%d", &n);

    }
    while (n < 1);
    printf("Valor decimal = %d\n", n);
    while(n != 0){
        resto = n % 2;
        n = n / 2;
        Empilha(&valor, resto);
    }

    desimpilha(&valor);
    return 0;
}

/*
Utilizando uma lista linear encadeada do tipo pilha, escreva um programa em C para determinar o
valor binário correspondente a um determinado valor inteiro n > 0 dado como entrada. Sua função main
deverá realizar a chamada à apenas duas funções:

Empilha(): que irá receber o ponteiro para a pilha e o inteiro a ser empilhado
DesempilhaTudo(): função que irá receber o ponteiro para a pilha, realizar a impressão e o
desempilhar dos elementos, a medida que forem sendo impressos
*/
