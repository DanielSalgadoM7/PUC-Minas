/*Você está digitando um texto longo com um teclado quebrado. Bem, não tão quebrado. 
O único problema com o teclado é que às vezes a tecla "home" ou a tecla "end" é automaticamente pressionada (internamente). 
Você não está ciente deste problema, já que você está focado no texto e nem sequer ligou o monitor! 
Depois que você terminar de digitar, você pode ver um texto na tela (se você ligar o monitor). Em chinês, podemos chamar este texto de Beiju. 
Sua tarefa é encontrar o texto Beiju.

Entrada
Há diversos casos de teste. Cada teste é uma única linha que contém pelo menos uma e, no máximo, 100.000 letras, underscores e dois caracteres 
especiais '[' e ']'. '[' Significa que a tecla "Home" é pressionada internamente, e ']' significa que a tecla "End" é pressionada internamente. 
A entrada é terminada por fim de arquivo (EOF). O tamanho do arquivo de entrada não excede 5MB.

Saída
Para cada caso, imprimir o texto Beiju na tela.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAM 100000

//função para acrescentar as letras
void escreverFim(char string[], char c) {
    int len = strlen(string);
    string[len] = c;
    string[len + 1] = '\0';
}

//função para limpar a string
void clearString(char string[]) {
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        string[i] = '\0';
    }
}

//função para solucionar o problema
void tecladoQuebrado(char string[]) {
    char resultado[MAX_TAM] = "\0";
    char auxiliar[MAX_TAM] = "\0";

    bool escreverNoFim = true;

    int len = strlen(string);
                                         
    for (int i = 0; i < len; i++) { 
                                    
        //entrando aqui acontece a mudança do texto BEIJU para o começo
        if (string[i] == '[') escreverNoFim = false;
        else if (string[i] == ']') {
            escreverNoFim = true;
            strcat(auxiliar, resultado);
            strcpy(resultado, auxiliar);
            clearString(auxiliar);
        }

        //adiciona as palavras no lugar enquanto não chega no '[' ou ']'
        if (string[i] != '[' && string[i] != ']') 
        {
            if (escreverNoFim) 
            {
                escreverFim(resultado, string[i]);
            }

            else {
                escreverFim(auxiliar, string[i]);
            }
        }
    }

    strcpy(string, resultado);
}

void main() 
{

    char string[MAX_TAM];
    //colocando o scanf como condição de parada o programa vai parar assim que acabar as operações com a palavra lida
    while (scanf("%s", string) != EOF) 
    {
        tecladoQuebrado(string);
        printf("%s\n", string);
    }
}
