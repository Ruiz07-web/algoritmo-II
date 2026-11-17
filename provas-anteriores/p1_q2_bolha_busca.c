#include <stdio.h>
#define MAX_N 30

void LeInteiro(int *n);
void LeVetor(int n, int vet[]);
void OrdenaBolha(int n, int vet[]);
void Imprime(int n, int vet[]);
void LeValor(int *valor);
int BuscaBinaria(int n, int vet[], int valor);
int main(void)
{

    int n, vet[MAX_N], valor, pos;
    LeInteiro(&n);
    LeVetor(n, vet);
    OrdenaBolha(n, vet);
    Imprime(n, vet);
    LeValor(&valor);
    while (valor != -1)
    {


        pos = BuscaBinaria(n, vet, valor);

        if (pos == -1)
        {
            printf("Valor não existe no vetor\n");
        }
        else
        {
            printf("O %d esta na posicão %d\n", valor, pos);
        }
        LeValor(&valor);
    }

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
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vet[j] < vet[j + 1])
            {
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
    printf("\nmaior : %d\n", vet[0]);
    printf("menor : %d\n", vet[n - 1]);
    printf("\n");
}


void LeValor(int *valor){
    printf("Digite o valor a ser buscado:\n");
    scanf("%d", valor);
}

int BuscaBinaria(int n, int vet[], int valor)
{
    int ini, meio, fim;
    ini = 0;
    fim = n - 1; // tamanho do vetor - 1

    while (ini <= fim)
    {
        meio = ini + (fim - ini) / 2;
        if (valor == vet[meio])
        {
            return meio;
        }
        else if (valor < vet[meio])
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
