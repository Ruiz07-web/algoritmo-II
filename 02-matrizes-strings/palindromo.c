#include <stdio.h>
#include <string.h>
#define MAX 100
int EhPalindromo(char s[]);
int main(void)
{
    char s[MAX];
    int r;

    printf("Digite a palavra:\n");
    scanf("%s", s);
    r = EhPalindromo(s);
    if (r == 1)
    {
        printf("Eh palindromo\n");
    }
    else
    {
        printf("No eh palindromo\n");
    }
    return 0;
}

int EhPalindromo(char s[])
{


    int t = strlen(s);

    printf("%d\n", t);

    for (int i = 0; i < t; i++)
    {
        if (s[i] != s[t - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}
