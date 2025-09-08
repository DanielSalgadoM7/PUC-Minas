/*Ler um número inteiro N e calcular todos os seus divisores.

Entrada
O arquivo de entrada contém um valor inteiro.

Saída
Escreva todos os divisores positivos de N, um valor por linha.*/

#include <stdio.h>

int main(void) {
  int numLido = 0;
  scanf("%d", &numLido);

  for (int i = 1; i <= numLido; i++) {
    if ((numLido % i) == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}
