/*Depois de um belo dia de aula é função das vans levarem os estudantes para suas respectivas casas. 
Mas o que muitos não sabem é que além dos gastos e manutenção da van o motorista precisa ter uma rota para entregar os passageiros em suas casas. 
Como você é o menino(a) da informática, ele pediu sua ajuda para desenvolver essa rota ordenando os alunos pela distância (da menor para a maior), 
pela região (em ordem alfabética) e por último pelo nome.


Entrada
Ele te dá a quantidade Q de alunos que não faltaram, o nome do aluno A e uma sigla para a região onde ele mora S ("L" Leste, "N" Norte, "O" Oeste, "S" Sul), 
e C que representa o custo da entrada da cidade até sua casa. A saída dos casos será (EOF).

Saída
A saída será uma lista das pessoas na ordem em que devem ser entregues.*/

#include <stdio.h>
typedef struct Aluno{
    char nomeAluno[100];
    char siglaRegiao;
    int entrada;
}Aluno;

int main(){
    int qnt;

    scanf("%d", &qnt);

    Aluno alunos[qnt];
    for(int i=0;i<qnt;i++){
        scanf(" %s", alunos[i].nomeAluno);
        scanf(" %c", &alunos[i].siglaRegiao);
        scanf("%d", &alunos[i].entrada);
    }

    for (int k = 0; k < qnt - 1; k++) {
        for (int l = k + 1; l < qnt; l++) {
            if (alunos[k].entrada == alunos[l].entrada) {
                if (strcmp(alunos[k].nomeAluno, alunos[l].nomeAluno) > 0) {
                    // Trocar os alunos de lugar
                    Aluno temp = alunos[k];
                    alunos[k] = alunos[l];
                    alunos[l] = temp;
                }
            }
        }
    }

    for(int j = 0; j<qnt; j++){
        printf("%s\n", alunos[j].nomeAluno);
    }
    return 0;
}