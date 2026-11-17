#include <stdio.h>
#include <string.h>
#define MAX 100

void LerPalavras(char maior[], int *cont);

int main(void)
{
    int cont = 0;
    char maior[MAX];
    LerPalavras(maior, &cont);
    printf("total de palavras: %d\n", cont);
    printf("maior palavra eh: %s\n", maior);
    return 0;
}

void LerPalavras(char maior[], int *cont)
{
    char palavra[MAX];
    maior[0] = '\0';
    printf("Digite aqui a primeira palavra\n");
    scanf("%s", palavra);

    while (strcmp(palavra, "nono") != 0)
    {
        *cont += 1;

        if (strlen(palavra) > strlen(maior))
        {
            strcpy(maior, palavra);
        }
        printf("Digite aqui a  palavra\n");
        scanf("%s", palavra);
    }
}
