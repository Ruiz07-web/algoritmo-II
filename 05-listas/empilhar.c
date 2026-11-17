#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} tNo;

void empilhar(tNo **lst, int *x)
{
    tNo *novo;
    scanf("%d", x);

    while (*x != -1)
    {
        novo = (tNo *) malloc(sizeof(tNo));
        novo->valor = *x;
        novo->prox = *lst;
        *lst = novo;
        scanf("%d", x);
    }
}

void imprimir(tNo *lista){
    tNo *p;
    for(p = lista; p != NULL; p = p->prox){
        printf("%d ", p -> valor);
    }
    printf("\n");

}

void apagar(tNo ** lst){
    tNo *aux;
    while(*lst != NULL){
        aux = *lst;
        printf("%d ", aux ->valor);
        *lst = (*lst)-> prox;
        free(aux);
    }
    printf("\n");
}
int main(void)
{
    tNo *lista = NULL;
    int x;
    empilhar(&lista, &x);
    imprimir(lista);
    apagar(&lista);
    return 0;
}
