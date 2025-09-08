/*Escreva um programa para ler as coordenadas (X,Y) de uma quantidade indeterminada de pontos no sistema cartesiano. Para cada ponto escrever o quadrante a que ele pertence. 
O algoritmo será encerrado quando pelo menos uma de duas coordenadas for NULA (nesta situação sem escrever mensagem alguma).

Entrada
A entrada contém vários casos de teste. Cada caso de teste contém 2 valores inteiros.

Saída
Para cada caso de teste mostre em qual quadrante do sistema cartesiano se encontra a coordenada lida, conforme o exemplo.*/

#include <stdio.h>

int main() {
  int cordX = 0, cordY = 0;
  scanf("%d %d", &cordX, &cordY);

  while (cordX != 0 || cordY != 0) {
    if (cordX > 0 && cordY > 0) {
      printf("primeiro\n");
    } else if (cordX < 0 && cordY > 0) {
      printf("segundo\n");
    } else if (cordX < 0 && cordY < 0) {
      printf("terceiro\n");
    } else {
      printf("quarto\n");
    }
    scanf("%d %d", &cordX, &cordY);
  }
  return 0;
}
