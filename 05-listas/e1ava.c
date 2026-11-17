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
            printf("- -> ");
        }
    }
    printf("\n");
}

void remover(int k, tNo **lst)
{
    tNo *p, *q;

    p = NULL;
    q = *lst;

    while (q != NULL && q->valor != k)
    {
        p = q;
        q = q->prox;
    }
    if (q == NULL)
    {
        printf("Elemento %d nao encontrado!\n", k);
    }
    else
    {
        if (p == NULL)
        {
            *lst = q->prox;
        }
        else
        {
            p->prox = q->prox;
        }
        free(q);
    }
}
void apagar(tNo **lst)
{
    tNo *aux;

    while (*lst != NULL)
    {
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
    }
}
int main(void)
{
    tNo *lista = NULL;
    int x, k; // x são os valores da saquencia
    LeX(&x, &lista);
    scanf("%d", &k);
    imprime(lista);
    remover(k, &lista);
    printf("Lista após a remoção\n");
    imprime(lista);
    apagar(&lista);
    return 0;
}

/**

 por fim, leia um inteiro k e remova a primeira ocorrência
deste elemento na lista, caso exista (essa tarefa deve ser realizada por uma função void).

Não se
esqueça de liberar toda a memória alocada para a lista antes do término do seu programa.

Atenção: o valor 0 é apenas a condição de parada da leitura dos dados de entrada, logo não deve ser
armazenado na lista
 */
