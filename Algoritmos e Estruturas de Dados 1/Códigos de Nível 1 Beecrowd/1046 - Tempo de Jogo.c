/*Leia a hora inicial e a hora final de um jogo. A seguir calcule a duração do jogo, sabendo que o mesmo pode começar em um dia e terminar em outro, tendo uma duração mínima de 1 hora e máxima de 24 horas.

Entrada
A entrada contém dois valores inteiros representando a hora de início e a hora de fim do jogo.

Saída
Apresente a duração do jogo conforme exemplo abaixo.*/

#include <stdio.h>
 
int main() {
    int valorA, valorB;
    
    scanf("%d %d", &valorA, &valorB);

  //if de 1 um dia
    if(valorA == valorB){
        printf("O JOGO DUROU 24 HORA(S)\n");
    }//se o valorB é maior, significa que terminou no mesmo dia, por isso, é apenas a diferença
    else if(valorB > valorA){
        printf("O JOGO DUROU %d HORA(S)\n", valorB - valorA);
    }//se o valorB é menor, adiciona 24 horas, para entrar no mesmo caso do segundo if
    else{
        printf("O JOGO DUROU %d HORA(S)\n", (valorB+24) - valorA);
    }
    return 0;
}
