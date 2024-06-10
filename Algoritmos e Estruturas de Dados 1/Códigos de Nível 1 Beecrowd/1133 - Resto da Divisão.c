/*Escreva um programa que leia 2 valores X e Y e que imprima todos os valores entre eles cujo resto da divisão dele por 5 for igual a 2 ou igual a 3.

Entrada
O arquivo de entrada contém 2 valores positivos inteiros quaisquer, não necessariamente em ordem crescente.

Saída
Imprima todos os valores conforme exemplo abaixo, sempre em ordem crescente.*/

#include <stdio.h>

int main() {
    int valorX = 0, valorY = 0, menor = 0, maior = 0;

    scanf("%d %d", &valorX, &valorY);

    if(valorX > valorY){
        maior = valorX;
        menor = valorY;
    }else{
        maior = valorY;
        menor = valorX;
    }

    for(int i = menor+1;i < maior; i++){
        if(i%5==2 || i%5==3){
            printf("%d\n", i);
        }
    }
    return 0;
}
