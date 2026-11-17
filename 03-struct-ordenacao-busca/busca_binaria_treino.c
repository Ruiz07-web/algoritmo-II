#include <stdio.h>

int BuscaBinaria(int n, int v[], int valor);

int main(void)
{
    int v[7] = {2, 4, 6, 8, 10, 12, 14};

    for (int x = 1; x <= 15; x++)
    {
        printf("%d -> %d\n", x, BuscaBinaria(7, v, x));
    }
    return 0;
}

int BuscaBinaria(int n, int v[], int valor)
{
    int ini = 0;
    int fim = n - 1;
    int meio;

    while (ini <= fim)
    {
        meio = ini + (fim - ini) / 2;
        if (valor == v[meio])
        {
            return meio;
        }

        else if (valor > v[meio])
        {
            ini = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}
