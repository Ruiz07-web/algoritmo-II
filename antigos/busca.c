#include <stdio.h>
#define MAX 20
int main(void){
    int numbers[MAX], x, temp;
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        scanf("%d", & numbers[i]);
    }

    scanf("%d", &temp);

    for(int k = 0; k < x; k++){
        if(numbers[k]== temp){
            printf("found/encontrada\n");
        }
        printf("Not found\n");
    }
    return 0;
}
