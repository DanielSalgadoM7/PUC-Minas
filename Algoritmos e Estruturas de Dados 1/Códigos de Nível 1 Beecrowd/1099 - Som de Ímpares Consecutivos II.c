/*Leia um valor inteiro N que é a quantidade de casos de teste que vem a seguir. Cada caso de teste consiste de dois inteiros X e Y. 
Você deve apresentar a soma de todos os ímpares existentes entre X e Y.

Entrada
A primeira linha de entrada é um inteiro N que é a quantidade de casos de teste que vem a seguir. Cada caso de teste consiste em uma linha contendo dois inteiros X e Y.

Saída
Imprima a soma de todos valores ímpares entre X e Y.*/

#include <stdio.h>

int main() {
    int valor = 0, X = 0, Y = 0;

    scanf("%d", &valor);

    for(int i=0;i<valor;i++){
        scanf("%d %d", &X, &Y);
        int soma =  0;
        if(X > Y){
            for(int j = Y+1;j<X;j++){
                if(j%2!=0){
                    soma+=j;
                }
            }
            printf("%d\n", soma);
        }else if(X == Y){
            printf("0\n");
        }else{
            for(int j = X+1;j<Y;j++){
                if(j%2!=0){
                    soma+=j;
                }
            }
            printf("%d\n", soma);
        }
    }
    return 0;
}
