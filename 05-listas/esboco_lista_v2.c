#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int chave;
    struct cel *prox;
} celula;

void apagar(celula **lst) {
    celula *aux;

    while(*lst != NULL){
        aux = *lst;
        *lst = (*lst) -> prox;
        free(aux);
    }
}

void inserir_fim(int n, celula **lst)
{
    celula *novo, *p;

    novo = (celula *) malloc(sizeof(celula));
    novo->chave = n;
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

void remover(int x, celula **lst) {
    celula *p, *q;

    p = NULL;
    q = *lst;

    while(q != NULL && q->chave != x){
        p = q;
        q = q -> prox;
    }
    if(q == NULL){
        printf("\nElemento nao existe\n");
    }
    else{
        if(p != NULL){
            p -> prox = q -> prox;
        }else{
            *lst = q -> prox;
        }
        free(q);
    }
}

void imprimir(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL; p = p->prox)
    {
        printf("%d ", p->chave);
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
