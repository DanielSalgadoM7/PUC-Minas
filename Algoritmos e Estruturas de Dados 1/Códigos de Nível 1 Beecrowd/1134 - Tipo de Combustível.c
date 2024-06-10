/*Um Posto de combustíveis deseja determinar qual de seus produtos tem a preferência de seus clientes. 
Escreva um algoritmo para ler o tipo de combustível abastecido (codificado da seguinte forma: 1.Álcool 2.Gasolina 3.Diesel 4.Fim). 
Caso o usuário informe um código inválido (fora da faixa de 1 a 4) deve ser solicitado um novo código (até que seja válido). O programa será encerrado quando o código informado for o número 4.

Entrada
A entrada contém apenas valores inteiros e positivos.

Saída
Deve ser escrito a mensagem: "MUITO OBRIGADO" e a quantidade de clientes que abasteceram cada tipo de combustível, conforme exemplo.*/

#include <stdio.h>

int main() {
  int opcao = 0, contAlcool = 0, contGasolina = 0, contDiesel = 0;
  while (opcao != 4) {
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      contAlcool++;
      break;

    case 2:
      contGasolina++;
      break;

    case 3:
      contDiesel++;
      break;

    case 4:
      break;
    }
  }

  printf("MUITO OBRIGADO\n");
  printf("Alcool: %d\n", contAlcool);
  printf("Gasolina: %d\n", contGasolina);
  printf("Diesel: %d\n", contDiesel);

  return 0;
}
