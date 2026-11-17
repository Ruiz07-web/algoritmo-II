#include <stdio.h>
#define MAX 100
int LeN(void);
int Busca(int n, int vet[], int valor);
void InsertValores(int x, int vetor[]);
int main(void)
{
    int n, vet[MAX], valor, pos;
    n = LeN();
    InsertValores(n, vet);
    printf("Digite o valor a ser buscado:\n");
    scanf("%d", &valor);
    pos = Busca(n, vet, valor);
    if (pos == -1)
    {
        printf("Valor %d não existe no vetor\n", valor);
    }
    else
    {
        printf("índice v[%d]\n", pos);
    }

    return 0;
}

int LeN(void)
{
    int n;
    do
    {
        printf("Digite o valor de N:\n");
        scanf("%d", &n);
    }
    while (n < 1 || n > MAX);

    return n;
}

void InsertValores(int x, int vet[])
{
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &vet[i]);
    }
}

int Busca(int n, int vet[], int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == valor)
            return i;
    }
    return -1;
}
