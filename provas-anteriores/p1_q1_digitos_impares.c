#include <stdio.h>
int LeInteiro();
int SomaImpares(int x);

int main(void){
    int x;
    x = LeInteiro();
    SomaImpares(x);

}


int LeInteiro(void){
    int x;
    do{
        printf("Digite o valor de entrada:\n");
        scanf("%d", &x);
    }while(x < 1);
    return x;
}


int SomaImpares(int x){
    int vtemp, soma = 0;
    vtemp = x;
    for(int i = 0; i < )
}
