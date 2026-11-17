#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} tNo;

int main(void)
{
    // cria a variavel e ja inicia o malloc
    tNo *x = malloc(sizeof(tNo));
    tNo *y = malloc(sizeof(tNo));
    tNo *z = malloc(sizeof(tNo));
    // se for null para
    if (y == NULL || x == NULL || z == NULL)
    {
        return -1;
    }
    // le os valores pra x, y e z
    scanf("%d", &x->valor);
    scanf("%d", &y->valor);
    scanf("%d", &z->valor);

    // aponta

    x ->proximo = y;
    y ->proximo = z;
    z ->proximo = NULL;

    // cria lista pra armazenar o inicio de tudo?

    tNo *lista = x;

    // criar um ponteiro pra percorrer?

    tNo *seguinte = lista;
    // enquanto ele for diferente de nulo continua, então ele tem que saltar na lista.
    while(seguinte != NULL){
        printf("%d ", seguinte -> valor); // primeiro é o x pq o seguinte recebeu a lista que iniciava em x;
        // agr pra incrementar o seguinte tem que ir pro y, como?
        seguinte = seguinte -> proximo; // nao entendi muito essa parte , tipo tipo ele recebe o proximo de a
    }
    printf("\n");

    // liberar memoria

    // antes de liberar o seguinte tem que voltar pro inicio.

    seguinte = lista;

    while(seguinte != NULL){
        tNo *temp = seguinte -> proximo; // acho que pode ser temp o nome ne, nao precisa ser proximo ne
        free(seguinte);
        seguinte = temp;
    }
    return 0;
}
