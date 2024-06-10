/*No ano de 2020 o Papai Noel não poderá sair de casa para entregar presentes por conta da pandemia do Coronavirus. 
Então ele ordenou que seus duendes fossem entregar no lugar dele no dia do natal. 
Como eles são bastante inexperientes, irão se dividir em vários times compostos de três membros: 
Um líder, um entregador e um piloto de trenó. O plano do Papai Noel é que os líderes das equipes seja sempre os duendes 
mais velhos, por esse motivo ele pediu para todos escreverem seus nomes e idades em uma lista. 
Como você é um duende programador, resolveu ajudar o Papai Noel a organizar a lista e montar os times a partir dela.

Segue abaixo algumas regras e fatos:

A lista deve ser organizada em ordem descendente de idade;
Caso dois duendes possuírem a mesma idade, deve se organizar por ordem ascendente de nome;
Não existe dois duendes de mesmo nome;
Nenhum duende tem mais de 20 caracteres em seu nome;
Os duendes da lista tem idade entre 10 e 100 anos;
Os primeiros 1/3 dos duendes (os mais velhos), serão os líderes dos times;
A ordem dos duendes entregadores e pilotos seguem a mesma lógica dos líderes. Ex) 
Se há 6 duendes na lista, haverá dois times, onde o duende mais velho é líder do time 1, e o segundo mais velho é líder 
do time 2. O terceiro mais velho é entregador do time 1 e o quarto mais velho é entregador do time 2. 
O quinto é piloto de trenó do time 1 e o último é piloto do time 2;

Entrada
A entrada é composta de um número inteiro N (3 <= N <= 30), onde N é múltiplo de 3, que representa a quantidade de 
duedes na lista. Em seguida as próximas N linhas contém o nome e a idade de cada duende.

Saída
A saída é composta de 4 linhas por time. A primeira linha deve seguir o formato "Time X", onde X é o número do time. 
A segunda, terceira e quarta linha contém, respectivamente, o nome e idade do duende líder, entregador e piloto de trenó.
 Depois de cada time, deverá haver uma linha em branco, inclusive após o último time.*/

 //Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** s1, char** s2){
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main(){
    int n;
    scanf("%d",&n);
    int idade;
    char nome[20];
    int arrayIdade[n];
    char** arrayNomes = (char*)malloc(sizeof(char)*n);

    for(int i = 0; i<n; i++){
        scanf("%s %d",nome,&idade);
        arrayNomes[i] = (char*)malloc(sizeof(char)*strlen(nome)+1);
        strcpy(arrayNomes[i],nome);
        arrayIdade[i] = idade;
    }

    for(int j = 0; j<n-1; j++){
        int menor = j;
        for(int i = j+1; i<n; i++){
            if(arrayIdade[menor]>arrayIdade[i]){
                menor = i;
            }
        }
        int temp = arrayIdade[menor];
        arrayIdade[menor] = arrayIdade[j];
        arrayIdade[j] = temp;
        swap(&arrayNomes[menor],&arrayNomes[j]); 
    }
    int index = n-1;
    int count = 1;
    for(int i = n; i>0; i/=3){
        printf("Time %d\n",count++);
        for(int j = index;j>= 0;j -= 2){
            printf("%s %d\n",arrayNomes[j],arrayIdade[j]);
            
        }
        printf("\n");
        index--;
    }


}
