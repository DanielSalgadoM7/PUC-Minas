/*Escreva um algoritmo que leia 2 números e imprima o resultado da divisão do primeiro pelo segundo. 
Caso não for possível mostre a mensagem “divisao impossivel” para os valores em questão.

Entrada
A entrada contém um número inteiro N. Este N será a quantidade de pares de valores inteiros (X e Y) que serão lidos em seguida.

Saída
Para cada caso mostre o resultado da divisão com um dígito após o ponto decimal, ou “divisao impossivel” caso não seja possível efetuar o cálculo.

Obs.: Cuide que a divisão entre dois inteiros em algumas linguagens como o C e C++ gera outro inteiro. Utilize cast :)*/

#include <stdio.h>
 
int main() {
    int entrada = 0, valorX = 0, valorY = 0;
    scanf("%d", &entrada);
    
    for(int i = 0; i<entrada; i++){
        scanf("%d %d", &valorX, &valorY);
        
        if(valorY == 0){
            printf("divisao impossivel\n");
        }else{
            double resultado = (double)valorX/valorY;
            printf("%.1lf\n", resultado);
        }
        
        
    }
    
    
    return 0;
}
