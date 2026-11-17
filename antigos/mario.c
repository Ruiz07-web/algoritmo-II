#include <stdio.h>

int validarAltura(void);
void montarTorre(int altura);

int main(void)
{
    int altura;
    altura = validarAltura();
    montarTorre(altura);

    return 0;
}

void montarTorre(int altura)
{
    for (int i = 1; i <= altura; i++)
    {
        for(int k = 1; k <= altura - i; k++){
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

// função pra validar o tamanho da torre.
int validarAltura(void)
{
    int x;
    do
    {
        printf("Digite o tamanho da torre:\n");
        scanf("%d", &x);
    }
    while (x < 1 || x > 8);

    return x;
}
