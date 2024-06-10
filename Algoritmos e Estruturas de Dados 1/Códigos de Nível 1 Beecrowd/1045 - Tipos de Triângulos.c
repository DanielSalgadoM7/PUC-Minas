/*Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que o lado A representa o maior dos 3 lados. 
A seguir, determine o tipo de triângulo que estes três lados formam, com base nos seguintes casos, sempre escrevendo uma mensagem adequada:
se A ≥ B+C, apresente a mensagem: NAO FORMA TRIANGULO
se A2 = B2 + C2, apresente a mensagem: TRIANGULO RETANGULO
se A2 > B2 + C2, apresente a mensagem: TRIANGULO OBTUSANGULO
se A2 < B2 + C2, apresente a mensagem: TRIANGULO ACUTANGULO
se os três lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO ISOSCELES
Entrada
A entrada contem três valores de ponto flutuante de dupla precisão A (0 < A) , B (0 < B) e C (0 < C).

Saída
Imprima todas as classificações do triângulo especificado na entrada.*/

#include <math.h>
#include <stdio.h>

int main() {
  double valorA, valorB, valorC, temp;

  scanf("%lf %lf %lf", &valorA, &valorB, &valorC);

  if(valorA<valorB){
    temp = valorA;
    valorA = valorB;
    valorB = temp;
  }
  if(valorA<valorC){
    temp = valorA;
    valorA = valorC;
    valorC = temp;
  }
  if(valorB<valorC){
    temp = valorB;
    valorB = valorC;
    valorC = temp;
  }

  if (valorA >= valorB + valorC) {
    printf("NAO FORMA TRIANGULO\n");
  }else if (pow(valorA, 2) < pow(valorB, 2) + pow(valorC, 2)) {
    printf("TRIANGULO ACUTANGULO\n");
  } else if (pow(valorA, 2) > (pow(valorB, 2) + pow(valorC, 2))) {
    printf("TRIANGULO OBTUSANGULO\n");
  } else if (pow(valorA, 2) == pow(valorB, 2) + pow(valorC, 2)) {
    printf("TRIANGULO RETANGULO\n");
  } else {
    printf("a");
  }

  if (valorA == valorB && valorA == valorC) {
    printf("TRIANGULO EQUILATERO\n");
  } else if (valorA == valorB && valorA != valorC ||
             valorA != valorB && valorB == valorC ||
             valorA != valorB && valorA == valorC) {
    printf("TRIANGULO ISOSCELES\n");
  }

  return 0;
}
