#include <stdio.h>
#include <string.h>
#define MAX 20

void inserirNome(char nome[]);
int tamNome(char nome[]);
int main(void){
    char nome[MAX + 1];
    int tam;
    inserirNome(nome);
    tam = tamNome(nome);
    printf("%d ", tam);


    return 0;
}


void inserirNome(char nome[]){
    printf("Digite seu nome:\n");
    scanf("%s", nome);
}

int tamNome(char nome[]){
    int x = 0;
    for(int i = 0; i != ; i++){
     if(nome[i] != '\0'){
        x++;
     }
    }
    return x;
}
