/*Leia 3 valores reais (A, B e C) e verifique se eles formam ou não um triângulo. Em caso positivo, calcule o perímetro do triângulo e apresente a mensagem:


Perimetro = XX.X


Em caso negativo, calcule a área do trapézio que tem A e B como base e C como altura, mostrando a mensagem


Area = XX.X

Entrada
A entrada contém três valores reais.

Saída
O resultado deve ser apresentado com uma casa decimal.*/

#include <stdio.h>

int main() {
    double valorA, valorB, valorC, perimetro, area;

    scanf("%lf %lf %lf", &valorA, &valorB, &valorC);

    if(valorA<valorB+valorC && valorB<valorA+valorC && valorC<valorA+valorB){
        perimetro = valorA + valorB + valorC;
        printf("Perimetro = %.1lf\n", perimetro);
    }else{
        area = ((valorA + valorB)*valorC)/2.0;
        printf("Area = %.1lf\n", area);
    }
    return 0;
}
