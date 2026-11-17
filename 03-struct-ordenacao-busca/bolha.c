#include <stdio.h>
#define MAX_N 30

void LeInteiro(int *n);
void LeVetor(int n, int vet[]);
void OrdenaBolha(int n, int vet[]);
void Imprime(int n, int vet[]);
int main(void)
{
    int n, vet[MAX_N];
    LeInteiro(&n);
    LeVetor(n, vet);
    OrdenaBolha(n, vet);
    Imprime(n, vet);
    return 0;
}

void LeInteiro(int *n)
{
    do
    {
        printf("Digite o valor de n:");
        scanf("%d", n);
    }
    while (*n < 1 || *n > MAX_N);
}

void LeVetor(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
}

void OrdenaBolha(int n, int vet[])
{
    int aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i ; j++)
        {
            if(vet[j] > vet[j + 1] ){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;

            }
        }
    }
}

void Imprime(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
