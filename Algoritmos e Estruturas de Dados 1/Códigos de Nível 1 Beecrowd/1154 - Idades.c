/*Faça um algoritmo para ler um número indeterminado de dados, contendo cada um, a idade de um indivíduo. O último dado, que não entrará nos cálculos, contém o valor de idade negativa. 
Calcular e imprimir a idade média deste grupo de indivíduos.

Entrada
A entrada contém um número indeterminado de inteiros. A entrada será encerrada quando um valor negativo for lido.

Saída
A saída contém um valor correspondente à média de idade dos indivíduos.

A média deve ser impressa com dois dígitos após o ponto decimal.*/

#include <stdio.h>

int main(void) {
  int idade = 0, soma = 0, contador = 0;
  float media = 0.0;

  while (1) {
    scanf("%d", &idade);
    if (idade < 0) {
      break;
    }
    soma += idade;
    contador++;
  }

  media = (float)soma / contador;
  printf("%.2f\n", media);

  return 0;
}
