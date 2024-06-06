/* Grupo de Arquitetura de Computadores 1

Trabalho extra - Conversor Fracionário

  Professor: Cláudio Campos
  Aluno: Caio Gomes - 763989
  Aluno: Daniel Salgado - 821429
  Aluno: Gabriel Henrique Vieira - 775799

Link no replit: https://replit.com/@DanielSalgadoM7/Teste-Claudio#main.c

*/

#include <stdio.h>
#include <math.h>

void decimalParaBinario(int numeroDecimal) {
    int numeroBinario[32];
    int indice = 0;

    while (numeroDecimal > 0) {
        numeroBinario[indice] = numeroDecimal % 2;
        numeroDecimal /= 2;
        indice++;
    }

  //for que vai printar a ordem certinha dos números do hexadecimal
    printf("O número decimal em binário é: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", numeroBinario[i]);
    }
    printf("\n");
}

int binarioParaDecimal(int binario) {
    int decimal = 0, expoente = 0, digito;

    while (binario != 0) {
        digito = binario % 10;

        decimal += digito * pow(2, expoente);

        binario /= 10;
        expoente++;
    }

    return decimal;
}

void decimalParaHexadecimal(int numeroDecimal) {
    char numeroHexadecimal[20];
    int indice = 0;

    while (numeroDecimal != 0) {
        int resto = 0;
        resto = numeroDecimal % 16;

        if (resto < 10) {
            numeroHexadecimal[indice] = resto + 48; 
        } else {
            numeroHexadecimal[indice] = resto + 55; 
        }

        indice++;
        numeroDecimal /= 16;
    }

  //for que vai printar a ordem certinha dos números do hexadecimal
    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", numeroHexadecimal[i]);
    }
    printf("\n");
}

int main() {
  int aux;
  int choice;

  printf("\nBem vindo ao nosso\n\n");
  printf("-------------CONVERSOR FRACIONÁRIO------------------ \n\n");

  do {
    printf("\n1. Converter de decimal para binário\n");
    printf("2. Converter de decimal para hexadecimal\n");
    printf("3. Converter de binário para decimal\n");
    printf("4. Sair\n");
    printf("\nEscolha uma das opções acima: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("\nDigite um valor em decimal: ");
      scanf("%d", &aux);
      printf("\nO número %d em binário é: ", aux);
      decimalParaBinario(aux);
      break;

    case 2:
      printf("\nDigite um valor em decimal: ");
      scanf("%d", &aux);
      printf("\nO número %d em hexadecimal é: ", aux);
      decimalParaHexadecimal(aux);
      break;

    case 3:
      printf("\nDigite um valor em binário: ");
      scanf("%d", &aux);
      printf("\nO número binário %d em decimal é %d\n", aux, binarioParaDecimal(aux));
      break;

    case 4:
      printf("\nSaindo do programa. Até mais!\n");
    break;

    default:
      printf("\nOpção inválida. Tente novamente.\n");
    }

  } while (choice != 4);

  return 0;
}
