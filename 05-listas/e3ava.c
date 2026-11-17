#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 100
typedef struct no
{
    char name[MAX_STR];
    char adress[MAX_STR];
    struct no *prox;
} tNo;

void LeSite(tNo **lst)
{
    char name[MAX_STR], adress[MAX_STR];
    tNo *novo, *p;

    scanf("%s", name);

    while (strcmp(name, "0") != 0)
    {
        scanf("%s", adress);

        novo = (tNo *) malloc(sizeof(tNo));
        strcpy(novo->name, name);
        strcpy(novo->adress, adress);

        novo->prox = NULL;

        if (*lst == NULL)
        {
            *lst = novo;
        }
        else
        {
            p = *lst;
            while (p->prox != NULL)
            {
                p = p->prox;
            }
            p->prox = novo;
        }
        scanf("%s", name);
    }
}

void imprime(tNo *lista)
{
    tNo *p;
    p = lista;
    for (p = lista; p != NULL; p = p->prox)
    {
        printf("%s %s\n", p->name, p->adress);
    }
}

void LeBusca(char busca[])
{
    scanf("%s", busca);
}

void Busca(tNo **lst, char busca[])
{

    printf("\nChave de Busca\n");
    printf("%s\n", busca);
    tNo *p, *q;

    p = NULL;
    q = *lst;

    while (q != NULL && strcmp(busca, q->name))
    {
        p = q;
        q = q->prox;
    }

    if (q == NULL)
    {
        printf("\nSite nao encontrado!\n");
    }
    else
    {
       printf("\nEndereço Buscado\n%s\n", q->adress);
       if(p != NULL){
            p ->prox = q ->prox;
            q -> prox = *lst;
            *lst = q;
       }
    }
}

void apagar(tNo ** lst){
    tNo * aux;

    while(*lst != NULL){
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
    }
}
int main(void)
{
    tNo *lista;
    char busca[MAX_STR];
    lista = NULL;
    LeSite(&lista);
    LeBusca(busca);
    printf("Lista armazenada antes da busca\n");
    imprime(lista);
    Busca(&lista, busca);
    printf("\nLista armazenada depois da busca\n");
    imprime(lista);
    apagar(&lista);
    return 0;
}

/*Considere uma coleção de nomes de sites da web e seus respectivos links na Internet armazenados
através de uma lista simplesmente encadeada sem cabeça com inserção no final da lista. Note que cada
nó da lista terá trê campos: nome, endereços web e ponteiro para o próximo nó da lista.

Escreva um código em C para realizar as operações de insere, imprime e busca na lista, sendo que ao
realizar a busca, dado o nome de um site, apresente ao usuário o seu link correspondente e, em
seguida mova o nó que contém o nome buscado para o início da lista, de forma que ele possa ser
encontrado mais rapidamente na próxima vez que for buscado.

A entrada dos dados é composta dos nomes dos websites e seus respectivos links, até ler o nome de
website "0". Em seguida, um nome do site a ser buscado é informado. A saída deve ser apresentada
conforme nos exemplos dados.

Google www.google.com
Facebook www.facebook.com
YouTube www.youtube.com
Wikipedia www.wikipedia.org
GitHub github.com
0
Wikipedia

*/
