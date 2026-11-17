#include <stdio.h>
#define MAX 100
int LeN(void);
void LeMatriz(int n, int matriz[][MAX]);
void ImprimeMatriz(int n, int matriz[][MAX]);
int SomaPrincipal(int n, int matriz[][MAX]);
int SomaSecundaria(int n, int matriz[][MAX]);
int main(void)
{
    int n, matriz[MAX][MAX], somap = 0, somas = 0;
    n = LeN();
    LeMatriz(n, matriz);
    ImprimeMatriz(n, matriz);
    somap = SomaPrincipal(n, matriz);
    printf("Principal: %d\n", somap);
    somas = SomaSecundaria(n, matriz);
    printf("Secundaria: %d\n", somas);

    return 0;
}

int LeN(void)
{
    int n;
    do
    {
        scanf("%d", &n);
    }
    while (n < 1 || n > MAX);

    return n;
}

void LeMatriz(int n, int matriz[][MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatriz(int n, int matriz[][MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int SomaPrincipal(int n, int matriz[][MAX])
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += matriz[i][i];
    }
    return soma;
}

int SomaSecundaria(int n, int matriz[][MAX])
{
    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += matriz[i][n -1 - i];
    return soma;
}
