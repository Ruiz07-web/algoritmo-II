#include <stdio.h>
#include <string.h>
#define MAX_STR 31
#define MAX_Al 100

typedef struct
{
    int matricula;
    char nome[MAX_STR];
    char curso[MAX_STR];
} tAluno;

void LeDados(tAluno alunos[], int *qtd_alunos);
void Busca(tAluno alunos[], int qtd_alunos);

int main(void)
{
    int qtd_alunos;
    tAluno alunos[MAX_Al];
    LeDados(alunos, &qtd_alunos);
    Busca(alunos, qtd_alunos);
    return 0;
}

void LeDados(tAluno alunos[], int *qtd_alunos)
{

    scanf("%d", qtd_alunos);

    while (*qtd_alunos > MAX_Al || *qtd_alunos < 1)
    {

        scanf("%d", qtd_alunos);
    }

    for (int i = 0; i < *qtd_alunos; i++)
    {
        printf("digite o código %d:\n", i);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome %d:\n", i);
        scanf("%s", alunos[i].nome);
        printf("Digite curso %d:\n", i);
        scanf("%s", alunos[i].curso);
    }
}

void Busca(tAluno alunos[], int qtd_alunos)
{
    char nbusca[MAX_STR];
    scanf("%s", nbusca);
    int cont = 0;
    while (strcmp(nbusca, "nono")!= 0)
    {
        for (int i = 0; i < qtd_alunos; i++)
        {
            if (strcmp(alunos[i].curso, nbusca) == 0)
            {
                printf("matricula :%d\n", alunos[i].matricula);
                printf("nome :%s\n", alunos[i].nome);
                cont++;
            }
        }
        if(cont == 0){
            printf("Não existe aluno matriculado neste curso\n");
        }else{
            cont = 0;
        }
        scanf("%s", nbusca);
    }
}

