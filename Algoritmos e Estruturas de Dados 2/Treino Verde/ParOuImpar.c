// Ler números até encontrar 0. 

// Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <math.h>

int main(){
    int num;

    do{
        scanf("%d", &num);
        if (num == 0){
            break;
        }else if (num % 2 == 0){
            printf("P\n");
        }
        else{
            printf("I\n");
        }
    }while (num != 0);
}
