/*Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, uma linha em branco e em seguida, os valores na sequência como foram lidos.

Entrada
A entrada contem três números inteiros.

Saída
Imprima a saída conforme foi especificado.*/

#include <stdio.h>

int main() {
  int A, B, C;

  scanf("%d %d %d", &A, &B, &C);

  if(A<B && B<C){
    printf("%d\n%d\n%d\n", A, B, C);
  }else if(B<A && A<C){
    printf("%d\n%d\n%d\n", B, A, C);
  }else if(C<A && A<B){
    printf("%d\n%d\n%d\n", C, A, B);
  }else if(C<B && B<A){
    printf("%d\n%d\n%d\n", C, B, A);
  }else if(B<C && C<A){
    printf("%d\n%d\n%d\n", B, C, A);
  }else{
    printf("%d\n%d\n%d\n", A, C, B);
  }
  printf("\n%d\n%d\n%d\n", A, B, C);
  return 0;
}
