#include <stdio.h>
#define MAX 100

int LeX(void);
void LeValores(int x, int vet[]);
int ContaPrimos(int x, int vet[]);
int EhPrimo(int i);
int main(void)
{
    int x, vet[MAX], soma;
    x = LeX();
    LeValores(x, vet);
    soma = ContaPrimos(x, vet);
    printf("Quantidade de primos %d \n", soma);

    return 0;
}

int LeX(void)
{
    int x;
    do
    {
        printf("Digite o valor de X:\n");
        scanf("%d", &x);
    }
    while (x < 1 || x > 100);

    return x;
}

void LeValores(int x, int vet[])
{
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &vet[i]);
    }
}

int ContaPrimos(int x, int vet[])
{
    int soma = 0;
    for (int i = 0; i < x; i++)
    {
        soma += EhPrimo(vet[i]);
    }
    return soma;
}

int EhPrimo(int i)
{

    // passo 1: menor que 2 não é primo
    if ( i < 2)
        return 0;

    // passo 2: procura um divisor de 2 até x-1
    for (int d = 2 ; d < i ; d++)
    {
        if (i % d == 0){
            return 0;
        }

    }

    return 1;
}
