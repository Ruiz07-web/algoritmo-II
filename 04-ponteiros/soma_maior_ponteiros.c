#include <stdio.h>
#define MAX 30
void LeN(int *n);
void LeVetor(int n, int *v);
int Soma(int *v, int n);
int Maior(int *v, int n);
int main(void)
{
    int n, v[MAX], soma, maior;
    LeN(&n);
    LeVetor(n, v);
    soma = Soma(v, n);
    maior = Maior(v, n);
    printf("A soma dos numero eh: %d\n", soma);
    printf("O maior número eh %d\n", maior);
    return 0;
}

void LeN(int *n)
{
    do
    {
        scanf("%d", n);
    }
    while (*n < 1 || *n > 30);
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
