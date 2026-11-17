#include <stdio.h>
#define MAX 100
void InsertValores(int x, int vetor[]);
int LeN(void);
int Maior(int x, int vetor[]);

int main(void)
{
    int x, vetor[MAX], maior;
    x = LeN();
    InsertValores(x, vetor);
    maior = Maior(x, vetor);
    printf("Maior eh: %d\n", maior);
    return 0;
}

int LeN(void)
{
    int x;
    do
    {
        printf("Digite o valor de N:\n");
        scanf("%d", &x);
    }while(x < 1 || x > MAX);

    return x;
}

void InsertValores(int x, int vetor[])
{
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

int Maior(int x, int vetor[])
{
    int maior = vetor[0];

    for (int i = 1; i < x; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    return maior;
}

/*3. Exercício 1: maior elemento

Escreva a função int maior(int v[], int n), que devolve o maior valor do vetor., lê os n números e
imprime o maior.
*/
