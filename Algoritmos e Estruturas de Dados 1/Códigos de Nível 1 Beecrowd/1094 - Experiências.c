/*Maria acabou de iniciar seu curso de graduação na faculdade de medicina e precisa de sua ajuda para organizar os experimentos de um laboratório o qual ela é responsável. 
Ela quer saber no final do ano, quantas cobaias foram utilizadas no laboratório e o percentual de cada tipo de cobaia utilizada.

Este laboratório em especial utiliza três tipos de cobaias: sapos, ratos e coelhos. 
Para obter estas informações, ela sabe exatamente o número de experimentos que foram realizados, o tipo de cobaia utilizada e a quantidade de cobaias utilizadas em cada experimento.

Entrada
A primeira linha de entrada contém um valor inteiro N que indica os vários casos de teste que vem a seguir. 
Cada caso de teste contém um inteiro Quantia (1 ≤ Quantia ≤ 15) que representa a quantidade de cobaias utilizadas e um caractere Tipo ('C', 'R' ou 'S'), indicando o tipo de cobaia 
(R:Rato S:Sapo C:Coelho).

Saída
Apresente o total de cobaias utilizadas, o total de cada tipo de cobaia utilizada e o percentual de cada uma em relação ao total de cobaias utilizadas, 
sendo que o percentual deve ser apresentado com dois dígitos após o ponto.*/

#include <stdio.h>

int main() {
    int valor = 0, qnt = 0, contCoelho = 0, contSapo = 0, contRato = 0, contTotal = 0;
    char tipo;

    scanf("%d", &valor);

    for(int i=0;i<valor;i++){
        scanf("%d %c", &qnt, &tipo);

        if(tipo == 'R'){
            contRato += qnt;
            contTotal += qnt;
        }else if(tipo == 'C'){
            contCoelho += qnt;
            contTotal += qnt;
        }else{
            contSapo += qnt;
            contTotal += qnt;
        }
    }

    printf("Total: %d cobaias\n", contTotal);
    printf("Total de coelhos: %d\n", contCoelho);
    printf("Total de ratos: %d\n", contRato);
    printf("Total de sapos: %d\n", contSapo);
    printf("Percentual de coelhos: %.2lf %\n", (contCoelho*100.0)/contTotal);
    printf("Percentual de ratos: %.2lf %\n", (contRato*100.0)/contTotal);
    printf("Percentual de sapos: %.2lf %\n", (contSapo*100.0)/contTotal);


    return 0;
}
