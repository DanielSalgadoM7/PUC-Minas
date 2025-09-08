/*Crie um método recursivo que recebe uma string como parâmetro e retorna true se essa é um Palíndromo.

Na saída padrão, para cada linha de entrada, escreva uma linha de saída com SIM/NÃO indicando se a linha é um palíndromo. 
Destaca-se que uma linha de entrada pode ter caracteres não letras.*/

//Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindromoRecursivo(char entrada[], int pos){
  //tamanho da string para comparar com as posições
  int tamanho = strlen(entrada);
  if(pos > tamanho/2){
    return true;//retorna verdadeiro caso seja igual
  }else if(entrada[pos] == entrada[tamanho-pos-1]){
    return palindromoRecursivo(entrada, pos+1);//adiciona +1 a posição para percorrer a palavra 
  }else{
    return false;// retorna falso caso não seja igual
  }
}

int main(){
  char entrada[10000];

  while(1){
    scanf(" %[^\n]", entrada);
    if(strcmp(entrada,"FIM")==0){
      break;
    }
    printf(palindromoRecursivo(entrada, 0)?"SIM\n":"NAO\n");
  }
}
