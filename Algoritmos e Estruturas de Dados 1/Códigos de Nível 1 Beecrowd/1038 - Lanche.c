/*Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. A seguir, calcule e mostre o valor da conta a pagar.

Codigo     Lanche               Preco
1          Cachorro quente      4.0
2          x-salada             4.5  
3          x-bacon              5.0
4          torrada simples      2.0
5          refrigerante         1.5
  
Entrada
O arquivo de entrada contém dois valores inteiros correspondentes ao código e à quantidade de um item conforme tabela acima.

Saída
O arquivo de saída deve conter a mensagem "Total: R$ " seguido pelo valor a ser pago, com 2 casas após o ponto decimal.*/

#include <stdio.h>

int main() {
    double array[6] = {0.0, 4.0, 4.5, 5.0, 2.0, 1.5};
    int codigo, qnt;
    double valor;
  
    scanf("%d %d", &codigo, &qnt);

    valor = array[codigo] * qnt;

    printf("Total: R$ %.2lf\n", valor);
    return 0;
}
