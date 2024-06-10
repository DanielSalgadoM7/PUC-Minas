/*Escreva um algoritmo para calcular e escrever o valor de S, sendo S dado pela fórmula:
S = 1 + 1/2 + 1/3 + … + 1/100

Entrada
Não há nenhuma entrada neste problema.

Saída
A saída contém um valor correspondente ao valor de S.
O valor deve ser impresso com dois dígitos após o ponto decimal.*/

#include <stdio.h>

int main(void) {
  float S = 0.0;
  for (int i = 1; i <= 100; i++) {
    S = S + 1.0 / i;
  }

  printf("%.2lf\n", S);
  return 0;
}
