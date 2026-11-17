#include <stdio.h>
#include <string.h>
#define MAX 41
#define MAX_N 50

typedef struct
{
    int codigo;
    char titulo[MAX];
    int ano;
} tLivro;

void LeN(int *n);
void LeLivros(int n, tLivro livros[]);
void Ordenalivro(int n, tLivro livros[]);
void ImprimeLivros(int n, tLivro livros[]);
void LivroAntigo(int n, tLivro livros[]);
void LeValor(int *valor);
int BuscaBinaria(int n, tLivro livros[], int valor);
int main(void)
{
    // valor é a variavel a ser buscada
    int n, valor, pos;
    tLivro livros[MAX_N];
    LeN(&n);
    LeLivros(n, livros);
    Ordenalivro(n, livros);
    ImprimeLivros(n, livros);
    LivroAntigo(n, livros);
    LeValor(&valor);
    while (valor != 0)
    {

        pos = BuscaBinaria(n, livros, valor);

        if (pos == -1)
        {
            printf("Código não existe no vetor\n");
        }
        else
        {
            printf("%s %d\n", livros[pos].titulo, livros[pos].ano );
        }
        LeValor(&valor);
    }
    return 0;
}

void LeN(int *n)
{
    do
    {
        printf("Digite a quantidade de livros:");
        scanf("%d", n);
    }
    while (*n < 1 || *n > MAX_N);
}

void LeLivros(int n, tLivro livros[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite o codigo %d do livro:\n", i + 1);
        scanf("%d", &livros[i].codigo);

        printf("Digite o titulo %d do livro:\n", i + 1);
        scanf("%s", livros[i].titulo);

        printf("Digite o ano %d do livro:\n", i + 1);
        scanf("%d", &livros[i].ano);
    }
}

void Ordenalivro(int n, tLivro livros[])
{
    tLivro aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (livros[j].codigo > livros[j + 1].codigo)
            {
                aux = livros[j];
                livros[j] = livros[j + 1];
                livros[j + 1] = aux;
            }
        }
    }
}

void ImprimeLivros(int n, tLivro livros[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  %s  %d\n", livros[i].codigo, livros[i].titulo, livros[i].ano);
    }
}

void LivroAntigo(int n, tLivro livros[])
{
    int menor = livros[0].ano;
    int indice = 0;
    for (int i = 1; i < n; i++)
    {
        if (livros[i].ano < menor)
        {
            menor = livros[i].ano;
            indice = i;
        }
    }
    printf("Mais antigo: %s\n", livros[indice].titulo);
}

void LeValor(int *valor)
{
    printf("Digite o codigo do livro que deseja buscar\n");
    scanf("%d", valor);
}

int BuscaBinaria(int n, tLivro livros[], int valor)
{
    int ini, meio, fim;
    ini = 0;
    fim = n - 1; // tamanho do livrosor - 1

    while (ini <= fim)
    {
        meio = ini + (fim - ini) / 2;
        if (valor == livros[meio].codigo)
        {
            return meio;
        }
        else if (valor > livros[meio].codigo)
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
