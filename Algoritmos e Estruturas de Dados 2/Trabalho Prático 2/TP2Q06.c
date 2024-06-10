/*Repita a questão anterior, contudo, usando a Seleção Recursiva. 
A entrada e a saída padrão serão iguais as da questão anterior. O nome do arquivo de log será matrícula_selecaoRecursiva.txt.*/

//Atributo para ordenação = nome

// Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define tamanho_max 200

// Contagem de comparações
int count = 0;

typedef struct {
    char id[tamanho_max];
    char nome[tamanho_max];
    char nomeAlternativo[tamanho_max];
    char casa[tamanho_max];
    char ancestry[tamanho_max];
    char especie[tamanho_max];
    char patrono[tamanho_max];
    char hogwartsStaff[tamanho_max];
    char hogwartsStudent[tamanho_max];
    char nomeAtor[tamanho_max];
    char status[tamanho_max];
    char dataNascimento[10];
    int anoNascimento;
    char corOlho[tamanho_max];
    char genero[tamanho_max];
    char corCabelo[tamanho_max];
    char bruxo[tamanho_max];
} Personagem;

void consertoVirgula(char *str) {
    int tamanho = strlen(str);
    char tmp[3 * tamanho];
    int j = 0; 

    for (int i = 0; i < tamanho; i++) {
        if (str[i] == ';' && str[i+1] == ';') {
            tmp[j++] = ';'; 
            tmp[j++] = '-';
            tmp[j++] = '1';
            tmp[j++] = ';';
            
            i++;
        } else {
            tmp[j++] = str[i];
        }
        
    }
    tmp[j] = '\0';
    strcpy(str, tmp);
}

void ler(Personagem *personagem, char *str) {
    consertoVirgula(str);
    char *token = strtok(str, ";");
    int fieldIndex = 0;

    while (token != NULL) {
        switch (fieldIndex) {
            case 0: strcpy(personagem->id, token); break;
            case 1: strcpy(personagem->nome, token); break;
            case 2: strcpy(personagem->nomeAlternativo, token); break;
            case 3: strcpy(personagem->casa, token); break;
            case 4: strcpy(personagem->ancestry, token); break;
            case 5: strcpy(personagem->especie, token); break;
            case 6: strcpy(personagem->patrono, token); break;
            case 7: strcpy(personagem->hogwartsStaff, token); break;
            case 8: strcpy(personagem->hogwartsStudent, token); break;
            case 9: strcpy(personagem->nomeAtor, token); break;
            case 10: strcpy(personagem->status, token); break;
            case 12: strcpy(personagem->dataNascimento, token); break;
            case 13: personagem->anoNascimento = atoi(token); break;
            case 14: strcpy(personagem->corOlho, token); break;
            case 15: strcpy(personagem->genero, token); break;
            case 16: strcpy(personagem->corCabelo, token); break;
            case 17: strcpy(personagem->bruxo, token); break;
            default: break;
        }
        fieldIndex++;
        token = strtok(NULL, ";");
    }
}

void imprimir(Personagem *personagem) {
    int len = strlen(personagem->nomeAlternativo);
    for (int i = 0; i < len; i++) {
        if (personagem->nomeAlternativo[i] == '[') {
            personagem->nomeAlternativo[i] = '{';
        } else if (personagem->nomeAlternativo[i] == ']') {
            personagem->nomeAlternativo[i] = '}';
        } else if (personagem->nomeAlternativo[i] == '\'') {
            memmove(&personagem->nomeAlternativo[i], &personagem->nomeAlternativo[i + 1], strlen(personagem->nomeAlternativo) - i);
            i--;
        }
    }

    printf("[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
           strcmp(personagem->id, "-1") != 0 ? personagem->id : "", 
           strcmp(personagem->nome, "-1") != 0 ? personagem->nome : "", 
           strcmp(personagem->nomeAlternativo, "-1") != 0 ? personagem->nomeAlternativo : "", 
           strcmp(personagem->casa, "-1") != 0 ? personagem->casa : "",
           strcmp(personagem->ancestry, "-1") != 0 ? personagem->ancestry : "", 
           strcmp(personagem->especie, "-1") != 0 ? personagem->especie : "", 
           strcmp(personagem->patrono, "-1") != 0 ? personagem->patrono : "",
           strcmp(personagem->hogwartsStaff, "VERDADEIRO") != 0 ? "false" : "true", 
           strcmp(personagem->hogwartsStudent, "VERDADEIRO") != 0 ? "false" : "true",
           strcmp(personagem->nomeAtor, "-1") != 0 ? personagem->nomeAtor : "", 
           strcmp(personagem->status, "VERDADEIRO") != 0 ? "false" : "true", 
           strcmp(personagem->dataNascimento, "-1") != 0 ? personagem->dataNascimento : "",
           personagem->anoNascimento, 
           strcmp(personagem->corOlho, "-1") != 0 ? personagem->corOlho : "", 
           strcmp(personagem->genero, "-1") != 0 ? personagem->genero : "", 
           strcmp(personagem->corCabelo, "-1") != 0 ? personagem->corCabelo : "",
           strcmp(personagem->bruxo, "VERDADEIRO") != 0 ? "true" : "false");
}

//método de ordenação por seleção
void selecao(Personagem vetor[],int pos, int tam){
    count++;
    if(pos>=tam-1){
        return;
    }

    int menor = pos;

    for(int i=pos+1; i<tam; i++){
        count++;
        if(strcmp(vetor[menor].nome,vetor[i].nome) > 0)
            menor = i;
    }

    Personagem temp = vetor[pos];
    vetor[pos] = vetor[menor];
    vetor[menor] = temp;

    selecao(vetor,pos+1,tam);
}

//chamando recursivamente a seleção
void selecao1(Personagem vetor[], int tam){
    selecao(vetor,0, tam);
}

int main() {
    struct timeval inicio, fim;
    double tempo_decorrido;
    gettimeofday(&inicio, NULL); // Marca o início do tempo

    Personagem csv[406];
    Personagem vetor[30];
    int pos = 0;
    char nomePesquisa[50];

    FILE *arq = fopen("/tmp/characters.csv", "r");
    if (arq == NULL) {
        printf("File not found\n");
        return 0;
    }

    char search[300];
    fgets(search, sizeof(search), arq);
    int i = 0;
    while (fgets(search, sizeof(search), arq)) {
        ler(&csv[i], search);
        i++;
    }

    fclose(arq);
    scanf("%s", nomePesquisa);
    while(strcmp(nomePesquisa, "FIM") != 0){
        for (int i = 0; i < 406; i++) {
            if (strcmp(csv[i].id, nomePesquisa) == 0) {
                vetor[pos] = csv[i];
                pos++;
                break;
            }
        }
        scanf("%s", nomePesquisa);
    }

    selecao1(vetor, pos);

    //chamado para imprimir
    for(int i=0;i<pos;i++){
        imprimir(&vetor[i]);
    }

    gettimeofday(&fim, NULL); // Marca o fim do tempo

    // Calcula o tempo decorrido em segundos e microssegundos
    tempo_decorrido = (fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1000000.0;
    FILE *arquivo;
    arquivo = fopen("matrícula_selecaoRecursiva.txt","w");
    fprintf(arquivo,"821429\t%f segundos\t%d comparaçoes", tempo_decorrido, count);
    fclose(arquivo);

    return 0;
}
