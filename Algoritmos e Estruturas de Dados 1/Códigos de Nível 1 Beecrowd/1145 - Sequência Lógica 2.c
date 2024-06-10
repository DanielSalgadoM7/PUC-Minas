/*Escreva um programa que leia dois valores X e Y. A seguir, mostre uma sequência de 1 até Y, passando para a próxima linha a cada X números.

Entrada
O arquivo de entrada contém dois valores inteiros, (1 < X < 20) e (X < Y < 100000).

Saída
Cada sequência deve ser impressa em uma linha apenas, com 1 espaço em branco entre cada número, conforme exemplo abaixo. Não deve haver espaço em branco após o último valor da linha.*/

#include <stdio.h>
int main() {
  int valorX, valorY, i = 1, j = 0;
  scanf("%d %d", &valorX, &valorY);

  while (i <= valorY) {
    for (j = 0; j < valorX; j++) {
      if (i > valorY)
        break;
      if (j == 0) {
        printf("%d", i++);
      } else {
        printf(" %d", i++);
      }
    }
    printf("\n");
  }
  return 0;
}
