/*Faça um programa que leia um número inteiro n indicando o número de valores
 * reais que devem ser lidos e salvos sequencialmente em um arquivo texto. Após
 * a leitura dos valores, devemos fechar o arquivo. Em seguida, reabri-lo e
 * fazer a leitura de trás para frente usando os métodos getFilePointer e seek
 * da classe RandomAccessFile e mostre todos os valores lidos na tela. Nessa
 * questão, você não pode usar, arrays, strings ou qualquer estrutura de dados.
 * A entrada padrão é composta por um número inteiro n e mais n números reais. A
 * saída padrão corresponde a n números reais mostrados um por linha de saída.*/

// Daniel Salgado Magalhães - 821429

#include <stdio.h>

void ler_arquivo_reverso(FILE *arq, float valorLido) {

  // Ler um número do arquivo
  if (fscanf(arq, "%g", &valorLido) != EOF) {
    // Fica chamando o método de forma recursiva pra ler os números de trás pra frente
    ler_arquivo_reverso(arq, valorLido);

    // Imprimi o número depois de chamar a função
    printf("%g\n", valorLido);
  }
}

int main() {
  int valorN = 0;
  float valorLido = 0;
  scanf("%d", &valorN);

  // abertura do arquivo para escrita
  FILE *arq = fopen("arq.txt", "w+");

  for (int i = 0; i < valorN; i++) {
    scanf("%f", &valorLido);
    fprintf(arq, "%f\n", valorLido);
  }

  // fechamento inicial do arquivo
  fclose(arq);

  //abertura do arquivo para leitura
  fopen("arq.txt", "r");

  //função que inverte o arquivo pra ler de trás pra frente
  ler_arquivo_reverso(arq, valorLido);

  //fechamento final do arquivo
  fclose(arq);
  return 0;
}
