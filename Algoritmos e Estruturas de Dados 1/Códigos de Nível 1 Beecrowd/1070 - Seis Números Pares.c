/*Leia um valor inteiro X. Em seguida apresente os 6 valores ímpares consecutivos a partir de X, um valor por linha, inclusive o X ser for o caso.

Entrada
A entrada será um valor inteiro positivo.

Saída
A saída será uma sequência de seis números ímpares.*/

#include <stdio.h>

int main() {
    int valor = 0, impar = 0;

    scanf("%d", &valor);

    if(valor%2==0){
        impar = valor+1;
    }else{
      impar = valor;
    }

    for(int i=0;i<6;i++){
        printf("%d\n", impar);
        impar += 2;
    }
    return 0;
}
