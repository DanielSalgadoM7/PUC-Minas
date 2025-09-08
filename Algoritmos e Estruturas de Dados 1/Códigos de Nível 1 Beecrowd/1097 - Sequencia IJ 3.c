/*Você deve fazer um programa que apresente a sequencia conforme o exemplo abaixo.

Entrada
Não há nenhuma entrada neste problema.

Saída
Imprima a sequencia conforme exemplo abaixo.*/

#include <stdio.h>

int main() {
    int i = 1, j = 7;

    while(i<10){
        printf("I=%d J=%d\n", i, j);
        j--;
        printf("I=%d J=%d\n", i, j);
        j--;
        printf("I=%d J=%d\n", i, j);
        j+=4;
        i+=2;
    }
    return 0;
}
