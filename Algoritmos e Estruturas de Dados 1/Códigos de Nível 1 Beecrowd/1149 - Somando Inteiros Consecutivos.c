/*Faça um algoritmo para ler um valor A e um valor N. Imprimir a soma de A + i para cada i com os valores (0 <= i <= N-1). 
Enquanto N for negativo ou ZERO, um novo N(apenas N) deve ser lido.

Entrada
A entrada contém somente valores inteiros, podendo ser positivos ou negativos. Todos os valores estão na mesma linha.

Saída
A saída contém apenas um valor inteiro.*/

#include <stdio.h>

int main() {
    int valorA = 0, valorN = 0, soma = 0;
    scanf("%d %d", &valorA, &valorN);
    while(valorN <= 0){
        scanf("%d", &valorN);
    }

    for(int i = 0;i<=valorN-1;i++){
        soma += valorA + i;
    }
    printf("%d\n", soma);
    return 0;
}
