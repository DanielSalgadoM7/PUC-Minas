/*Leia 6 valores. Em seguida, mostre quantos destes valores digitados foram positivos. 
Na próxima linha, deve-se mostrar a média de todos os valores positivos digitados, com um dígito após o ponto decimal.

Entrada
A entrada contém 6 números que podem ser valores inteiros ou de ponto flutuante. Pelo menos um destes números será positivo.

Saída
O primeiro valor de saída é a quantidade de valores positivos. A próxima linha deve mostrar a média dos valores positivos digitados.*/

#include <stdio.h>
 
int main() {
    double num = 0.0, media = 0.0;
    int cont = 0;
    
    for(int i=0;i<6;i++){
        scanf("%lf", &num);
        if(num>0){
            cont++;
            media += num;
        }
    }
    
    media = media/cont;
    
    printf("%d valores positivos\n", cont);
    printf("%.1lf\n", media);
    return 0;
}
