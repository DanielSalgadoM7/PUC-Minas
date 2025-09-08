/*Escreva um programa que leia um valor inteiro N. Este N é a quantidade de linhas de saída que serão apresentadas na execução do programa.

Entrada
O arquivo de entrada contém um número inteiro positivo N.

Saída
Imprima a saída conforme o exemplo fornecido.*/

#include <stdio.h>

int main() {
  int valor = 0, pum = 1;
  scanf("%d", &valor);

  for (int i = 0; i < valor; i++) {
    printf("%d %d %d PUM\n", pum, (pum + 1), (pum + 2));
    pum += 4;
  }
  return 0;
}
