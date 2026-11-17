#include <stdio.h>
void olaMundo(void);
int main(void){

    for(int i = 0; i < 10; i++){
         olaMundo();
    }


    return 0;
}
void olaMundo(void){
    printf("Olá mundo!\n");
}
