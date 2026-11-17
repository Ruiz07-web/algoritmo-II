#include <stdio.h>
#include <string.h>
#define MAX 100

void LerPalavras(char palavra[]);
int main(void)
{
    char palavra[MAX];
    LerPalavras(palavra);
    return 0;
}

void LerPalavras(char palavra[])
{
    int cont = 0;
    char maior[MAX];
    maior[0] = '\0';
    printf("Digite aqui a palavra:\n");
    scanf("%s", palavra);
    while (strcmp(palavra, "nono") != 0)
    {

        cont += 1;
        if (strlen(palavra) > strlen(maior))
        {
            strcpy(maior, palavra);
        }
        printf("Digite aqui a palavra:\n");
        scanf("%s", palavra);
    }
    printf("Qtd de palavras: %d\n", cont);
    printf("%s\n", maior);
}
