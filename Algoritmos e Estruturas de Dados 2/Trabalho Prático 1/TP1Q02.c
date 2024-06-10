/*Crie um método iterativo que recebe uma string como parâmetro e retorna true
se essa é um Palíndromo.

Na saída padrão, para cada linha de entrada, escreva uma linha de saída com
SIM/NÃO indicando se a linha é um palíndromo. Destaca-se que uma linha de
entrada pode ter caracteres não letras.*/

// Daniel Salgado Magalhães - 821429

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define tamanho_max 10000

// função para comparar os caracteres da string normal e invertida
int EhPalindromo(char entrada[], int tamanho) {
  int esquerda = 0, direita = tamanho - 1;

  while (esquerda < direita) {
    if (entrada[esquerda] != entrada[direita]) {
      return 0;
    }
    esquerda++;
    direita--;
  }

  return 1;
}

int main() {
  char *entrada = (char *)malloc(tamanho_max * sizeof(char));
  int tamanho = 0;

  while (1) {
    scanf(" %[^\n\r]", entrada);

    if (strcmp(entrada, "FIM") == 0) {
      break;
    }

    // tamanho receba a quantidade da palavra
    tamanho = strlen(entrada);

    printf("%s\n", EhPalindromo(entrada, tamanho) ? "SIM" : "NAO");
  }

  free(entrada);
}
