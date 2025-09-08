/*A empresa ABC resolveu conceder um aumento de salários a seus funcionários de acordo com a tabela abaixo:


Salário	Percentual de Reajuste
0 - 400.00
400.01 - 800.00
800.01 - 1200.00
1200.01 - 2000.00
Acima de 2000.00

15%
12%
10%
7%
4%

Leia o salário do funcionário e calcule e mostre o novo salário, bem como o valor de reajuste ganho e o índice reajustado, em percentual.

Entrada
A entrada contém apenas um valor de ponto flutuante, com duas casas decimais.

Saída
Imprima 3 linhas na saída: o novo salário, o valor ganho de reajuste (ambos devem ser apresentados com 2 casas decimais) e o percentual de reajuste ganho, conforme exemplo abaixo.*/

#include <stdio.h>
 
int main() {
    double salario= 0.0, reajuste, novoSalario;
    
    scanf("%lf", &salario);
    
    if(salario <= 400.00){
        novoSalario = salario + (salario * 0.15);
        printf("Novo salario: %.2lf\n", novoSalario);
        printf("Reajuste ganho: %.2lf\n", novoSalario - salario);
        printf("Em percentual: 15 %\n");
    }else if(salario > 400.00 && salario <= 800.00){
        novoSalario = salario + (salario * 0.12);
        printf("Novo salario: %.2lf\n", novoSalario);
        printf("Reajuste ganho: %.2lf\n", novoSalario - salario);
        printf("Em percentual: 12 %\n");
    }else if(salario > 800.00 && salario <= 1200.00){
        novoSalario = salario + (salario * 0.10);
        printf("Novo salario: %.2lf\n", novoSalario);
        printf("Reajuste ganho: %.2lf\n", novoSalario - salario);
        printf("Em percentual: 10 %\n");
    }else if(salario > 1200.00 && salario <= 2000.00){
        novoSalario = salario + (salario * 0.07);
        printf("Novo salario: %.2lf\n", novoSalario);
        printf("Reajuste ganho: %.2lf\n", novoSalario - salario);
        printf("Em percentual: 7 %\n");
    }else{
        novoSalario = salario + (salario * 0.04);
        printf("Novo salario: %.2lf\n", novoSalario);
        printf("Reajuste ganho: %.2lf\n", novoSalario - salario);
        printf("Em percentual: 4 %\n");
    }
    return 0;
}
