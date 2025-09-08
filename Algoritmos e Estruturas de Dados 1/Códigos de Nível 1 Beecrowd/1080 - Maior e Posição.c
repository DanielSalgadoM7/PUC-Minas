/*Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.

Entrada
O arquivo de entrada contém 100 números inteiros, positivos e distintos.

Saída
Apresente o maior valor lido e a posição de entrada, conforme exemplo abaixo.*/

#include <stdio.h>
 
int main() {
    int valor = 0, maior = 0, pos = 0, num = 0;
    
    for(int i = 1;i<=100;i++){
        scanf("%d", &valor);
        
        if(valor > maior){
            maior = valor;
            pos = i;
        }
    }
    printf("%d\n%d\n", maior, pos);
    return 0;
}
