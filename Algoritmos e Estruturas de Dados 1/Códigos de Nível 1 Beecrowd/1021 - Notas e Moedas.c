/*Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. 
A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. 
As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre a relação de notas necessárias.
 
Entrada
O arquivo de entrada contém um valor de ponto flutuante N (0 ≤ N ≤ 1000000.00).

Saída
Imprima a quantidade mínima de notas e moedas necessárias para trocar o valor inicial, conforme exemplo fornecido.

Obs: Utilize ponto (.) para separar a parte decimal.*/

#include <stdio.h>

int main() {
  double valorMonetario;
  int integerN;

  //recebe o valor em ponto flutuante
  scanf("%lf", &valorMonetario);
  //transforma esse valor em int multiplicando por 100, para que o número quebrado pelos centavos vire inteiro para as divisões 
  integerN = valorMonetario * 100;

  printf("NOTAS:\n");
  //printa o resultado dividindo por 10000(notas de 100)
  printf("%d nota(s) de R$ 100.00\n", integerN / 10000);
  //depois de printar, pega o módulo do numero, para continuar com as outras notas
  integerN = integerN % 10000;

  //processo repetido pelas outras notas e moedas
  printf("%d nota(s) de R$ 50.00\n", integerN / 5000);
  integerN = integerN % 5000;

  printf("%d nota(s) de R$ 20.00\n", integerN / 2000);
  integerN = integerN % 2000;

  printf("%d nota(s) de R$ 10.00\n", integerN / 1000);
  integerN = integerN % 1000;

  printf("%d nota(s) de R$ 5.00\n", integerN / 500);
  integerN = integerN % 500;

  printf("%d nota(s) de R$ 2.00\n", integerN / 200);
  integerN = integerN % 200;

  printf("MOEDAS:\n");
  printf("%d moeda(s) de R$ 1.00\n", integerN / 100);
  integerN = integerN % 100;
  printf("%d moeda(s) de R$ 0.50\n", integerN / 50);
  integerN = integerN % 50;
  printf("%d moeda(s) de R$ 0.25\n", integerN / 25);
  integerN = integerN % 25;
  printf("%d moeda(s) de R$ 0.10\n", integerN / 10);
  integerN = integerN % 10;
  printf("%d moeda(s) de R$ 0.05\n", integerN / 5);
  integerN = integerN % 5;
  printf("%d moeda(s) de R$ 0.01\n", integerN / 1);
  integerN = integerN % 1;
  return 0;
}
