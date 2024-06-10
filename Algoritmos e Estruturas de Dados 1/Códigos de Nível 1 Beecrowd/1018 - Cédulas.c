/*Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) no qual o valor pode ser decomposto. 
As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas necessárias.

Entrada 
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).

Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada tipo necessárias, conforme o exemplo fornecido. 
Não esqueça de imprimir o fim de linha após cada linha, caso contrário seu programa apresentará a mensagem: “Presentation Error”.*/

#include <stdio.h>
 
int main() {
    int valorNota;
    
    scanf("%d", &valorNota);
    
    //printa o valor inicial
    printf("%d\n", valorNota);
    
    //cada print é feito com o valor da nota, dividido pelo número desejado
    printf("%d nota(s) de R$ 100,00\n", valorNota/100);
    
    //depois de printar, a gente muda o valor da nota pro módulo da operação
    valorNota = valorNota%100;
    
    //520%100 = 20, sendo assim, valorNota = 20 agora
    printf("%d nota(s) de R$ 50,00\n", valorNota/50);
    valorNota = valorNota%50;
    
    printf("%d nota(s) de R$ 20,00\n", valorNota/20);
    valorNota = valorNota%20;
    
    printf("%d nota(s) de R$ 10,00\n", valorNota/10);
    valorNota = valorNota%10;
    
    printf("%d nota(s) de R$ 5,00\n", valorNota/5);
    valorNota = valorNota%5;
    
    printf("%d nota(s) de R$ 2,00\n", valorNota/2);
    valorNota = valorNota%2;
    
    printf("%d nota(s) de R$ 1,00\n", valorNota);
 
    return 0;
}
