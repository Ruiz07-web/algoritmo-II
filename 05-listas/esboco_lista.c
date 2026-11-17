#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int chave;
    struct cel *prox;
} celula;

/* ===== funções que você já fez ===== */
void apagar(celula **lst);
void inserir_fim(int n, celula **lst);
void remover(int x, celula **lst);
void imprimir(celula *lst);

/* ===== funções novas ===== */
void remover_primeiro(celula **lst);
void remover_ultimo(celula **lst);
void inserir_inicio(int x, celula **lst);
void inserir_posicao(int x, int i, celula **lst);
int contar(int x, celula *lst);
int crescente(celula *lst);
int decrescente(celula *lst);
celula *busca_S(int x, celula *lst);
celula *buscaR_S(int x, celula *lst);
void inserir_ordenado(int x, celula **lst);

int main()
{
    celula *lista = NULL; /* lista sem cabeca vazia */
    int num, op, pos;

    do
    {
        printf("\n\n1 - Inserir numero no fim");
        printf("\n2 - Remover um numero");
        printf("\n3 - Imprimir lista");
        printf("\n5 - Remover o primeiro");
        printf("\n6 - Remover o ultimo");
        printf("\n7 - Inserir no inicio");
        printf("\n8 - Inserir na posicao i");
        printf("\n9 - Contar ocorrencias de x");
        printf("\n10 - Verificar se esta em ordem crescente");
        printf("\n11 - Verificar se esta em ordem decrescente");
        printf("\n12 - Busca Iterativa");
        printf("\n13 - Busca Recursiva");
        printf("\n14 - Inserir em ordem");
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
            imprimir(lista);
        else if (op == 5)
            remover_primeiro(&lista);
        else if (op == 6)
            remover_ultimo(&lista);
        else if (op == 7)
        {
            scanf("%d", &num);
            inserir_inicio(num, &lista);
        }
        else if (op == 8)
        {
            scanf("%d %d", &num, &pos);
            inserir_posicao(num, pos, &lista);
        }
        else if (op == 9)
        {
            scanf("%d", &num);
            printf("\n%d aparece %d vez(es)", num, contar(num, lista));
        }

        else if (op == 10)
            printf(crescente(lista) ? "\nEsta em ordem crescente"
                                    : "\nNao esta em ordem crescente");
        else if (op == 11)
            printf(decrescente(lista) ? "\nEsta em ordem decrescente"
                                      : "\nNao esta em ordem decrescente");
        else if (op == 12)
        {
            scanf("%d", &num);
            if (busca_S(num, lista) != NULL)
                printf("\n%d esta na lista", num);
            else
                printf("\n%d nao esta na lista", num);
        }
        else if (op == 13)
        {
            scanf("%d", &num);
            if (buscaR_S(num, lista) != NULL)
                printf("\n%d esta na lista", num);
            else
                printf("\n%d nao esta na lista", num);
        }
        else if (op == 14)
        {
            scanf("%d", &num);
            inserir_ordenado(num, &lista);
        }
    }
    while (op != 4);

    apagar(&lista);
    return 0;
}

/* ===================== funções que você já fez ===================== */

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
    celula *novo, *p;

    novo = (celula *) malloc(sizeof(celula));
    novo->chave = n;
    novo->prox = NULL;

    if (*lst == NULL)
        *lst = novo;
    else
    {
        p = *lst;
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
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
        printf("\nElemento nao existe");
    else
    {
        if (p != NULL)
            p->prox = q->prox;
        else
            *lst = q->prox;
        free(q);
    }
}

void imprimir(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL; p = p->prox)
        printf("%d ", p->chave);
    printf("\n");
}

/* ===================== funções novas: é com você ===================== */

void remover_primeiro(celula **lst)
{
    celula *aux;
    if (*lst == NULL)
    {
        printf("\nLista Vazia\n");
    }
    else
    {
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
    }
}

void remover_ultimo(celula **lst)
{
    celula *p, *q;

    p = NULL;
    q = *lst;

    if (q == NULL)
    {
        printf("\nLista Vazia\n");
    }
    else
    {

        while (q->prox != NULL)
        {
            p = q;
            q = q->prox;
        }
        if (p != NULL)
        {
            p->prox = q->prox;
        }
        else
        {
            *lst = q->prox;
        }
        free(q);
    }
}

void inserir_inicio(int x, celula **lst)
{
    celula *novo;

    novo = (celula *) malloc(sizeof(celula));

    novo->chave = x;
    novo->prox = *lst;

    *lst = novo;
}

void inserir_posicao(int x, int i, celula **lst)
{
    int pos;
    celula *novo, *p;
    novo = (celula *) malloc(sizeof(celula));
    novo->chave = x;
    p = *lst;
    if (i == 1)
    {
        novo->prox = *lst;
        *lst = novo;
        return;
    }
    if (i < 1)
    {
        printf("\nPosicao invalida");
        free(novo);
        return;
    }
    pos = 1;

    while (p != NULL && pos < i - 1)
    {
        p = p->prox;
        pos++;
    }
    if (p == NULL)
    {
        printf("Posição Invalida\n");
        free(novo);
        return;
    }

    novo->prox = p->prox;
    p->prox = novo;
}

int contar(int x, celula *lst)
{
    int cont = 0;
    celula *p;
    for (p = lst; p != NULL; p = p->prox)
    {
        if (p->chave == x)
        {
            cont++;
        }
    }
    return cont;
}

int crescente(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL && p->prox != NULL; p = p->prox)
    {
        if (p->chave > p->prox->chave)
        {
            return 0;
        }
    }
    return 1;
}

int decrescente(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL && p->prox != NULL; p = p->prox)
    {
        if (p->chave < p->prox->chave)
        {
            return 0;
        }
    }
    return 1;
}

celula *busca_S(int x, celula *lst)
{
    celula *p;

    p = lst;
    while (p != NULL && p->chave != x)
    {
        p = p->prox;
    }

    return p;
}

celula *buscaR_S(int x, celula *lst)
{

    if (lst == NULL)
    {
        return NULL;
    }
    if (x == lst->chave)
    {
        return lst;
    }
    else
    {
        return buscaR_S(x, lst->prox);
    }
}

void inserir_ordenado(int x, celula **lst)
{
    celula *novo, *p, *q;

    novo = (celula *)  malloc(sizeof(celula));
    novo->chave = x;

    p = NULL;
    q = *lst;

    while(q != NULL && q-> chave < x){
        p = q;
        q = q->prox;
    }

    novo -> prox = q;
    if(p==NULL){
        *lst = novo;

    }else{
        p -> prox = novo;
    }
}
