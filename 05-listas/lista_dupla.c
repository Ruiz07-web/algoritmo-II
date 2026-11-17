#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int chave;
    struct cel *ant;
    struct cel *prox;
} celula;

void inserir_inicio_dup(int x, celula **lst)
{
    celula *novo;

    novo = (celula *)calloc(1, sizeof(celula));
    novo->chave = x;

    novo->ant = NULL;
    novo->prox = *lst;

    if (*lst != NULL)
    {
        (*lst)->ant = novo;
    }
    *lst = novo;
}

void imprimir(celula *lista)
{
    celula *p;

    for (p = lista; p != NULL; p = p->prox)
    {
        printf("%d ", p->chave);
    }
    printf("\n");
}

int main(void)
{
    celula *lista = NULL;
    inserir_inicio_dup(30, &lista);
    inserir_inicio_dup(20, &lista);
    inserir_inicio_dup(10, &lista);
    imprimir(lista);
    return 0;
}