/*Neste problema, você deverá ler 3 palavras que definem o tipo de animal possível segundo o esquema abaixo, da esquerda para a direita.  
Em seguida conclua qual dos animais seguintes foi escolhido, através das três palavras fornecidas.

IMAGEM NO PROBLEMA DO BEECROWD

Entrada
A entrada contém 3 palavras, uma em cada linha, necessárias para identificar o animal segundo a figura acima, com todas as letras minúsculas.

Saída
Imprima o nome do animal correspondente à entrada fornecida.*/

#include <stdio.h>
#include <string.h>

int main() {
    char palavra1[100], palavra2[100], palavra3[100];

    scanf(" %[^\n] %[^\n] %[^\n]", palavra1, palavra2, palavra3);

    if(strcmp(palavra1, "vertebrado")==0){
        //caminho 1 1 1/2
        if(strcmp(palavra2,"ave")==0){
            if(strcmp(palavra3,"carnivoro")==0){
                printf("aguia\n");
            }else{
                printf("pomba\n");
            }
        //caminho 1 2 1/2
        }else{
            if(strcmp(palavra3,"onivoro")==0){
                printf("homem\n");
            }else{
                printf("vaca\n");
            }
        }
    //começo do else para invertebrados
    }else{
        if(strcmp(palavra2,"inseto")==0){
            if(strcmp(palavra3,"hematofago")==0){
                printf("pulga\n");
            }else{
                printf("lagarta\n");
            }
        //caminho 2 1 1/2
        }else{
            if(strcmp(palavra3,"hematofago")==0){
                printf("sanguessuga\n");
            }else{
                printf("minhoca\n");
            }
        }
    }
    return 0;
}
