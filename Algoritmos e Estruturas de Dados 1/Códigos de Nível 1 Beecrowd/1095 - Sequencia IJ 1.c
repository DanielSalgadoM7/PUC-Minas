/*Você deve fazer um programa que apresente a sequencia conforme o exemplo abaixo.

Entrada
Não há nenhuma entrada neste problema.

Saída
Imprima a sequencia conforme exemplo abaixo*/

#include <stdio.h>

int main() {
    int i = 1, j = 60;

    for(j = 60;j>=0;){
        printf("I=%d J=%d\n", i, j);
        i+=3;
        j-=5;
    }
    return 0;
}
