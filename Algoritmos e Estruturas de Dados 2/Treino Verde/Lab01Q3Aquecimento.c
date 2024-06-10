/*Crie um método ITERATIVO em Java que receba como parâmetro uma string e
retorne seu número de caracteres maiúsculos. Em seguida, teste o método anterior
usando redirecionamento de entrada e saída. A entrada padrão é composta por
várias linhas sendo que a última contém a palavra FIM. A saída padrão contém um
número inteiro para cada linha de entrada.*/

// Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <string.h>

//função para contar as letras maiúsculas
int ContarMaiuscula(char palavra[]) {
  int cont = 0;
  for (int i = 0; palavra[i] != '\0'; i++) {
    if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
      cont++;
    }
  }
  return cont;
}

int main() {
  char palavra[1000][100];
  int qntPalavras = 0;

  //loop de repetição até o ponto de parada determinado
  do {
    scanf(" %[^\n]", palavra[qntPalavras]);
    qntPalavras++;
  } while (strcmp(palavra[qntPalavras - 1], "FIM") != 0);

  //impressão de cada contagem de letras maiúsculas em cada palavra
  for (int i = 0; i < qntPalavras - 1; i++) {
    printf("%d\n", ContarMaiuscula(palavra[i]));
  }
  return 0;
} 
