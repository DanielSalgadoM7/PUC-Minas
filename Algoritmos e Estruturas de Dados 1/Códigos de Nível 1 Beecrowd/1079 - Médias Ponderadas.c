/*Leia 1 valor inteiro N, que representa o número de casos de teste que vem a seguir. Cada caso de teste consiste de 3 valores reais, cada um deles com uma casa decimal. 
Apresente a média ponderada para cada um destes conjuntos de 3 valores, sendo que o primeiro valor tem peso 2, o segundo valor tem peso 3 e o terceiro valor tem peso 5.

Entrada
O arquivo de entrada contém um valor inteiro N na primeira linha. Cada N linha a seguir contém um caso de teste com três valores com uma casa decimal cada valor.

Saída
Para cada caso de teste, imprima a média ponderada dos 3 valores, conforme exemplo abaixo.*/

#include <stdio.h>

int main() {
    int valor = 0;
    double num1 = 0.0, num2 = 0.0, num3 = 0.0, media = 0.0;

    scanf("%d", &valor);

    for(int i=0;i<valor;i++){

        scanf("%lf %lf %lf", &num1, &num2, &num3);
        media = ((num1*2) + (num2*3) + (num3*5))/10.0;
        printf("%.1lf\n", media);
        
    }


    return 0;
}
