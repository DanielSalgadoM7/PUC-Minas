/*Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .*/

#include <stdio.h>

int main() {
  int horaInicial, minutoInicial, horaFinal, minutoFinal;

  scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);

  if (horaInicial == minutoInicial && horaInicial == horaFinal &&
      horaInicial == minutoFinal) {
    printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
  } else if (horaInicial < horaFinal && minutoInicial < minutoFinal) {
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horaFinal - horaInicial,
           minutoFinal - minutoInicial);
  } else if (horaFinal - horaInicial == 1 || horaFinal - horaInicial == 0) {
    printf("O JOGO DUROU 0 HORA(S) E %d MINUTO(S)\n",
           minutoFinal - minutoInicial);
  } else {
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",
           (horaFinal + 23) - horaInicial, (minutoFinal + 60) - minutoInicial);
  }
  return 0;
}
