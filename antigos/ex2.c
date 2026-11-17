#include <stdio.h>

int main(void){
    int x, y;
    printf("Digite o valor de X:\n");
    scanf("%d", &x);

    printf("Digite o valor de y:\n");
    scanf("%d", &y);

    if(x > y){
        printf("x = %d é maior que y = %d\n", x, y);
    }else{
        printf("x = %d é menor que y = %d\n", x, y);
    }
}
