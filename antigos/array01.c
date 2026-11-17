#include <stdio.h>
#include <string.h>
int main(void){
    int notas[3], soma;
    for(int i = 0; i < 3 ; i++){
        scanf("%d", &notas[i]);

    }
     soma = 0;
    for(int j = 0; j < 3; j++){
        soma = soma + notas[j];
    }
    printf("media eh: %.2f \n", (float)((float) soma/3) );

}
