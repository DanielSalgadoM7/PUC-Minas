/*Faça um programa que mostre os números pares entre 1 e 100, inclusive.

Entrada
Neste problema extremamente simples de repetição não há entrada.

Saída
Imprima todos os números pares entre 1 e 100, inclusive se for o caso, um em cada linha.*/

#include <stdio.h>

int main() {

    for(int i=2; i<=100;){
        printf("%d\n", i);
        i+=2;
    }

    return 0;
}
