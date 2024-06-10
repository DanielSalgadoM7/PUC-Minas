/*Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento em uma fábrica, e informe-o expresso no formato horas:minutos:segundos.

Entrada
O arquivo de entrada contém um valor inteiro N.

Saída 
Imprima o tempo lido no arquivo de entrada (segundos), convertido para horas:minutos:segundos, conforme exemplo fornecido.*/

#include <stdio.h>

int main() {
    int tempo, hora = 0, minuto = 0, segundo = 0;

    scanf("%d", &tempo);

    //printa a hora dividindo o tempo(em segundos), por 3600(1 hora)
    hora = tempo/3600;

    //faz com que o tempo seja o resto da divisão anterior, para que ele possa ser dividido pelos minutos
    tempo = tempo%3600;

    //processo repetido com os minutos
    minuto = tempo/60;

    tempo = tempo%60;

    segundo = tempo;

    printf("%d:%d:%d", hora, minuto, segundo);
  
    return 0;
}
