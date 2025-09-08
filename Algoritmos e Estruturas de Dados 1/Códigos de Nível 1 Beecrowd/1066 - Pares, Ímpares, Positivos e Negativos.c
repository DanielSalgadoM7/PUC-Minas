/*Leia 5 valores Inteiros. A seguir mostre quantos valores digitados foram pares, quantos valores digitados foram ímpares, quantos valores digitados foram positivos e quantos valores digitados foram negativos.

Entrada
O arquivo de entrada contém 5 valores inteiros quaisquer.

Saída
Imprima a mensagem conforme o exemplo fornecido, uma mensagem por linha, não esquecendo o final de linha após cada uma.*/

#include <stdio.h>

int main() {
  int valor = 0, positivo = 0, negativo = 0, par = 0, impar = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &valor);

    if (valor > 0 && valor % 2 == 0) {
      positivo++;
      par++;
    } else if (valor == 0) {
      par++;
    } else if (valor >= 0 && valor % 2 != 0) {
      positivo++;
      impar++;
    } else if (valor < 0 && valor % 2 == 0) {
      negativo++;
      par++;
    } else {
      negativo++;
      impar++;
    }
  }

  printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) "
         "positivo(s)\n%d valor(es) negativo(s)\n",
         par, impar, positivo, negativo);

  return 0;
}
