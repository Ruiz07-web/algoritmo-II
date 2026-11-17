#include <stdio.h>
#define MAX 100
int pegarTamLista(void);
void imprimirLista(int tamLista, int lista[]);
void addValorInLista(int tamLista, int lista[]);



 int main(void){
 int tamLista, lista[MAX];
    tamLista = pegarTamLista();
    addValorInLista(tamLista, lista);
    imprimirLista(tamLista, lista);


    return 0;
}


// função pra pegar o valor que vai ser o tamanho da lista
int pegarTamLista(void){
    int x;
    do{
        printf("Digite o tamanho da Lista:\n");
        scanf("%d", &x);
    }while(x < 1 || x > 100);
    return x;
}


void addValorInLista(int tamLista, int lista[]){
    for(int i = 0; i < tamLista; i++){
        scanf("%d", & lista[i]);
    }
}


void imprimirLista(int tamLista, int lista[]){
    for(int i = 0; i < tamLista; i++){
        printf("%d\n", lista[i]);
    }
}
