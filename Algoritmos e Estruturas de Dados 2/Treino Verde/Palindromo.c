/*Crie um método iterativo que recebe uma string como parâmetro e retorna true se essa é um palíndromo.

Na saída padrão, para cada linha de entrada, escreva uma linha de saída com SIM/NAO indicando se a linha é um palíndromo.

Destaca-se que uma linha de entrada pode ter caracteres não letras

A entrada termina com a leitura de FIM */

//Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <string.h>

int main(void) {

  char palavra1[1000], palavra2[1000];
  char auxiliar[] = "FIM";

  scanf(" %[^\n\r]", palavra1);
  
  //Loop de repetição pra comparar as palavras enquanto a palavra não for FIM 
  while(strcmp(palavra1, auxiliar) != 0){
    
    //pega uma variável pro tamanho do array
    int tamanho = strlen(palavra1);

    int aux = 0;
    int aux2 = tamanho;
  
  //FOR para inverter a String, mexendo em cada posição do array.
    for(int i = tamanho; i>0; i--){
      palavra2[aux2 - 1] = palavra1[aux];
      aux++;
      aux2--;
    }
    
//Indica que o tamanho da palavra termina no \0, ou seja, quando muda pra próxima palavra
    palavra2[tamanho] = '\0'; 

//IF para comparar se as palavras são iguais
    if(strcmp(palavra1, palavra2) == 0){
      printf("SIM\n");
    }else{
      printf("NAO\n");
    }

    scanf(" %[^\n\r]", palavra1); 
  }

  return 0;
}
