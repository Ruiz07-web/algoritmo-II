#include <stdio.h>

int validar(void);
void imprime(int height);

int main(void)
{
    int height;
    height = validar();
    imprime(height);

    return 0;
}

void imprime(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // laço dos espaços
        for (int k = 1; k <= height - i; k++)
        {
            printf(" ");
        }
        // laço que imprime a primeira estrutura
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        // laço que imprime a primeira estrutura
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");

    }
}


// função pra validar o numero
int validar(void)
{
    int x;
    do
    {
        printf("Digite o valor da altura:\n");
        scanf("%d", &x);
    }
    while (x < 1 || x > 8);

    return x;
}
