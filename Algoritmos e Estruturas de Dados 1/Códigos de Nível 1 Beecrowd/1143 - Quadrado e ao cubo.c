/*Escreva um programa que leia um valor inteiro N (1 < N < 1000). Este N é a quantidade de linhas de saída que serão apresentadas na execução do programa.

Entrada
O arquivo de entrada contém um número inteiro positivo N.

Saída
Imprima a saída conforme o exemplo fornecido.*/

#include <stdio.h>
 
int main() {
    int valor = 0;
    scanf("%d", &valor);
    
    for(int i=1;i<=valor;i++){
        printf("%d %d %d\n", i, (i*i), (i*i*i));
    }
    return 0;
}
