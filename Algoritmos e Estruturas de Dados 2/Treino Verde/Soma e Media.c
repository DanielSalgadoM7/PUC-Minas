/*Escreva um programa que leia as notas inteiras de 5 disciplinas que o aluno está matriculado (n1, n2, n3, n4 e n5). 
Depois o seu programa deverá mostrar a soma das notas (inteiro) e a média arredondada para cima (inteiro).

Entrada: 5 inteiros

Saída: uma soma (inteira) e uma média arredondada (inteira).*/

//Daniel Salgado Magalhães - 821429

#include <stdio.h>

int main(){
  int nota1 = 0, nota2 = 0, nota3 = 0, nota4 = 0, nota5 = 0;
  scanf(" %d %d %d %d %d", &nota1, &nota2, &nota3, &nota4, &nota5);

  int soma = nota1 + nota2 + nota3 + nota4 + nota5;
  int media = soma/5;
  printf("%d\n%d\n", soma, media);
}
