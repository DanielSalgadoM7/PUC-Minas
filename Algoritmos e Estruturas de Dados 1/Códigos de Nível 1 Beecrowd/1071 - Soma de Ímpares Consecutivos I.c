/*Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números impares entre eles.

Entrada
O arquivo de entrada contém dois valores inteiros.

Saída
O programa deve imprimir um valor inteiro. Este valor é a soma dos valores ímpares que estão entre os valores fornecidos na entrada que deverá caber em um inteiro.*/

#include <stdio.h>

int main() {
    int valorX = 0, valorY = 0, soma = 0;

    scanf("%d %d", &valorX, &valorY);

    for(int i=valorX-1; i>valorY;i--){
        if(i < valorX && i > valorY && i % 2 != 0){
            soma += i;
        }
    }

  printf("%d\n", soma);
    return 0;
}
