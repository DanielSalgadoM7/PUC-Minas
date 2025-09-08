/*Escreva um algoritmo que leia 2 valores inteiros X e Y calcule a soma dos números que não são múltiplos de 13 entre X e Y, incluindo ambos.

Entrada
O arquivo de entrada contém 2 valores inteiros quaisquer, não necessariamente em ordem crescente.

Saída
Imprima a soma de todos os valores não divisíveis por 13 entre os dois valores lidos na entrada, inclusive ambos se for o caso.*/

#include <stdio.h>

int main() {
  int valorX = 0, valorY = 0, soma = 0, maior = 0, menor = 0;
  scanf("%d %d", &valorX, &valorY);

  if (valorX > valorY) {
    maior = valorX;
    menor = valorY;
  } else {
    maior = valorY;
    menor = valorX;
  }
  for (int i = menor; i <= maior; i++) {
    if (i % 13 != 0) {
      soma += i;
    }
  }

  printf("%d\n", soma);
  return 0;
}
