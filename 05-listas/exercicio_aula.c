#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int chave;
    struct cel *prox;
} celula;

void apagar(celula **lst)
{
    celula *aux;

    while (*lst != NULL)
    {
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
    }
}

void inserir_fim(int n, celula **lst)
{
    celula *novo, *percorre; /* declara o novo nó e o ponteiro de percurso */

    /* prepara o nó */
    novo = (celula *) malloc(sizeof(celula));
    novo->chave = n;
    novo->prox = NULL;

    if (*lst == NULL) /* lista vazia */
    {
        *lst = novo; /* o novo vira o primeiro */
    }
    else
    {
        percorre = *lst;               /* começa no primeiro nó */
        while (percorre->prox != NULL) /* enquanto NÃO estiver no último */
            percorre = percorre->prox;
        percorre->prox = novo; /* o último passa a apontar para o novo */
    }
}

void remover(int x, celula **lst)
{
    celula *p, *q;

    p = NULL;
    q = *lst;

    while (q != NULL && q->chave != x)
    {
        p = q;
        q = q->prox;
    }
    if (q == NULL)
    {
        printf("\nElemento não existe.");
    }
    else
    {
        if (p != NULL)
        {
            p->prox = q->prox; // na duvida
        }
        else
        {
            *lst = q->prox; // na duvida
        }
        free(q);
    }
}

void imprimir(celula *lst)
{
    celula *percorre; // ponteiro que percorre a lista

    for (percorre = lst; percorre != NULL; percorre = percorre->prox)
    {
        printf("%d ", percorre->chave);
    }
    printf("\n");
}

int main()
{
    celula *lista = NULL; /* lista sem cabeca vazia */
    int num, op;

    do
    {
        printf("\n\n1 - Inserir numero na lista");
        printf("\n2 - Remover da lista");
        printf("\n3 - Imprimir lista");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &num);
            inserir_fim(num, &lista);
        }
        else if (op == 2)
        {
            scanf("%d", &num);
            remover(num, &lista);
        }
        else if (op == 3)
        {
            imprimir(lista);
        }
    }
    while (op != 4);

    apagar(&lista);
    return 0;
}
