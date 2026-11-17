#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} tNo;

int main(void)
{
    tNo *a, *b, *c;

    a = (tNo*) malloc(sizeof(tNo));
    b = (tNo*) malloc(sizeof(tNo));
    c = (tNo*) malloc(sizeof(tNo));

    if (a == NULL || b == NULL || c == NULL)
    {
        return 1;
    }

    scanf("%d", &a->valor);
    scanf("%d", &b->valor);
    scanf("%d", &c->valor);

    a->prox = b;
    b->prox = c;
    c->prox = NULL;

    tNo *lista = a;

    tNo *p = lista;

    while (p != NULL)
    {
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
    p = lista;
    while (p != NULL)
    {
        tNo *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    return 0;
}
