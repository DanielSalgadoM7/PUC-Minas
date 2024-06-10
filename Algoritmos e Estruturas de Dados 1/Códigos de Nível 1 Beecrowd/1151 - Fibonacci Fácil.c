/*A seguinte sequência de números 0 1 1 2 3 5 8 13 21... é conhecida como série de Fibonacci. Nessa sequência, cada número, depois dos 2 primeiros, é igual à soma dos 2 anteriores. 
Escreva um algoritmo que leia um inteiro N (N < 46) e mostre os N primeiros números dessa série.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 46).

Saída
Os valores devem ser mostrados na mesma linha, separados por um espaço em branco. Não deve haver espaço após o último valor.*/

#include <stdio.h>

int main() {
  int i = 0, valorN = 0;
  scanf("%d", &valorN);

  for (i = 0; i < valorN; i++) {
    if (i == 0) {
      printf("0 ");
    }else if(i==1){
      printf("1 ");
    }else if(i == valorN-1){
      printf("%d", (i-1) + (i-2));
    } else {
      printf("%d ",(i-1) + (i-2));
    }
  }
  return 0;
}
