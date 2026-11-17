#include <stdio.h>
#include <string.h> /*strlen*/
int main()
{
    char palavra[10] = "Ola!";
    int n;
    n = 0;
    while (palavra[n] != '\0')
        n++;
    printf("O comprimento da palavra é %d\n", n);
    printf("O comprimento da palavra é %lu\n", strlen(palavra));
    return 0;
}
