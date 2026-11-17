#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int chave;
    struct cel *prox;
} celula;

// funções

void Enfileirar(int x, celula **i, celula **f)
{
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->chave = x;

    nova->prox = NULL;

    if (*i == NULL)
    {
        *i = *f = nova;
    }
    else
    {
        (*f)->prox = nova;
        *f = nova;
    }
}

void Desinfileirar(celula **i, celula **f)
{
    celula *aux;

    while (*i != NULL)
    {

        aux = *i;
        printf("%d ", aux->chave);
        *i = (*i)->prox;
        if (*i == NULL)
        {
            *f = NULL;
        }
        free(aux);
    }
    printf("\n");
}

int main(void)
{
    celula *ini, *fim;
    ini = NULL;
    fim = NULL;
    int x;

    do
    {
        scanf("%d", &x);
          if(x < 1){
        break;
    }
        Enfileirar(x, &ini, &fim);
    }
    while (x > 0);

    Desinfileirar(&ini, &fim);
}
