#include <stdio.h>

void LeN(int *n);
int SomaImpares(int n);
int main(void)
{
    int n, soma;
    LeN(&n);
    soma = SomaImpares(n);
    printf("Soma: %d\n", soma);

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

int SomaImpares(int n)
{
    int  soma = 0;
    while (n > 0)
    {

        if (n % 2 != 0)
        {
            soma += n % 10;
        }
        n = n / 10;
    }
    return soma;
}
