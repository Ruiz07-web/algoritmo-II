#include <stdio.h>
#include <stdlib.h>
void LeN(int *n);
void LeVetor(int n, int *v);
int Soma(int *v, int n);
int Maior(int *v, int n);
int main(void)
{
    int n, *v, soma, maior;
    LeN(&n);

    v = malloc(n * sizeof(int));
    if (v == NULL)
    {
        printf("Erro de memoria\n");
        return -1;
    }

    LeVetor(n, v);
    soma = Soma(v, n);
    maior = Maior(v, n);
    printf("A soma dos numero eh: %d\n", soma);
    printf("O maior número eh %d\n", maior);
    free(v);
    return 0;
}

void LeN(int *n)
{
    do
    {
        scanf("%d", n);
    }
    while (*n < 1);
}

void LeVetor(int n, int *v)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", v + i);
    }
}

int Soma(int *v, int n)
{
    int soma = 0;
    int *p;
    for (p = v; p < v + n; p++)
    {
        soma += *p;
    }
    return soma;
}

int Maior(int *v, int n)
{
    int maior = *(v + 0);
    for (int i = 0; i < n; i++)
    {
        if (*(v + i) > maior)
        {
            maior = *(v + i);
        }
    }
    return maior;
}
