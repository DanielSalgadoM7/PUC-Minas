/*Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. 
Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.

Entrada 
Leia três valores de ponto flutuante (double) A, B e C.

Saída
Se não houver possibilidade de calcular as raízes, apresente a mensagem "Impossivel calcular". 
Caso contrário, imprima o resultado das raízes com 5 dígitos após o ponto, com uma mensagem correspondente conforme exemplo abaixo. Imprima sempre o final de linha após cada mensagem.*/

#include <stdio.h>
#include <math.h>

int main() {
    double valorA, valorB, valorC, r1, r2, baskara;

    scanf("%lf %lf %lf", &valorA, &valorB, &valorC);
  
    baskara = sqrt(pow(valorB,2) - 4 * valorA * valorC);

    if(valorA == 0.0 || (pow(valorB,2) - 4 * valorA * valorC) < 0 ){
        printf("Impossivel calcular\n");
    }else{
        r1 = (-valorB + baskara)/(2*valorA);
        r2 = (-valorB - baskara)/(2*valorA);
        printf("R1 = %.5lf\n", r1);
        printf("R2 = %.5lf\n", r2);
    }

    return 0;
}
