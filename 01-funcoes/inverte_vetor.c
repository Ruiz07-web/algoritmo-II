#include <stdio.h>
#define MAX 100

void Inverte(int tamVet, int vet[]);
void Imprime(int tamVet, int vet[]);
int main(void)
{
    int tamVet, vet[MAX];
    scanf("%d", &tamVet);
    for (int i = 0; i < tamVet; i++)
    {
        scanf("%d", &vet[i]);
    }



    Imprime(tamVet, vet);
    Inverte(tamVet, vet);
    Imprime(tamVet, vet);
    return 0;
}

void Inverte(int tamVet, int vet[])
{
   for(int i = 0; i < tamVet/2; i++){
        int aux;
       aux =  vet[i];
       vet[i] = vet[tamVet - 1 - i];
       vet[tamVet - 1 - i] = aux;
   }
}

void Imprime(int tamVet, int vet[])
{
    for(int i = 0; i < tamVet; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}
