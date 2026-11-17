#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} tNo;

void LeX(int *x, tNo **lst)
{
    tNo *novo, *p;
    do
    {
        scanf("%d", x);

        if (*x == 0)
            break;

        novo = (tNo *) malloc(sizeof(tNo));
        novo->valor = *x;
        novo->prox = NULL;

        if (*lst == NULL)
        {
            *lst = novo;
        }
        else
        {
            p = *lst;
            while (p->prox != NULL)
            {
                p = p->prox;
            }
            p->prox = novo;
        }
    }
    while (*x != 0); // n é o numero que libera do loop
}

void imprime(tNo *lista)
{
    tNo *p;

    if (lista == NULL)
    {
        printf("Lista Vazia\n");
    }
    for (p = lista; p != NULL; p = p->prox)
    {
        printf("%d ", p->valor);

        if (p->prox != NULL)
        {
            printf("--> ");
        }
    }
    printf("\n");
}

void Ponteiros_Para_Remocao(tNo **lst, int k, tNo **p, tNo **q)
{

    *p = NULL;
    *q = *lst;

    while (*q != NULL && (*q)->valor != k)
    {
        *p = *q;
        *q = (*q)->prox;
    }
}

void apagar(tNo **lst){
    tNo* aux;

    while(*lst!=NULL){
        aux = *lst;
        *lst = (*lst) ->prox;
        free(aux);
    }
}



int main(void)
{
    tNo *lista = NULL, *p, *q;
    int x, k; // x são os valores da saquencia
    LeX(&x, &lista);
    scanf("%d", &k);
    imprime(lista);
    Ponteiros_Para_Remocao(&lista, k, &p, &q);
    if (q == NULL)
    {
        printf("\n%d não existe na lista\n", k);
    }else if(p == NULL){
        printf("\nO nó a ser removido é o primeiro da lista\n");
    }
    else
    {
        printf("\nO nó cuja chave é %d precede o nó a ser removido\n", p->valor);
    }

    apagar(&lista);
    return 0;
}
