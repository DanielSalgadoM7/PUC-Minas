/*Faça a inserção de alguns registros no final de um vetor e, em seguida, faça algumas pesquisas binárias. A chave primária de pesquisa será o atributo name.
A entrada padrão é composta por duas partes onde a primeira é igual a entrada da primeira questão. As demais linhas correspondem a segunda parte. A segunda parte é composta por
várias linhas. Cada uma possui um elemento que deve ser pesquisado no vetor. A última linha terá a palavra FIM. A saída padrão será composta por várias linhas contendo as palavras
SIM/NAO para indicar se existe cada um dos elementos pesquisados.

Além disso, crie um arquivo de log na pasta corrente com o nome matrícula_sequencial.txt com uma única linha contendo sua matrícula, tempo de execução do seu algoritmo e número
de comparações. Todas as informações do arquivo de log devem ser separadas por uma tabulação '\t'.*/

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
    bool hogwartsStaff;
    bool hogwartsStudent;
    char nomeAtor[tamanho_max];
    bool status;
    char dataNascimento[10];
    int anoNascimento;
    char corOlho[tamanho_max];
    char genero[tamanho_max];
    char hairColour[tamanho_max];
    bool bruxo;
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
            case 7: personagem->hogwartsStaff = false; break;
            case 8: personagem->hogwartsStudent = false; break;
            case 9: strcpy(personagem->nomeAtor, token); break;
            case 10: personagem->status = false; break;
            case 12: strcpy(personagem->dataNascimento, token); break;
            case 13: personagem->anoNascimento = atoi(token); break;
            case 14: strcpy(personagem->corOlho, token); break;
            case 15: strcpy(personagem->genero, token); break;
            case 16: strcpy(personagem->hairColour, token); break;
            case 17: personagem->bruxo = (strcmp(token, "VERDADEIRO") == 0); break;
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
           personagem->hogwartsStaff ? "true" : "false", 
           personagem->hogwartsStudent ? "true" : "false",
           strcmp(personagem->nomeAtor, "-1") != 0 ? personagem->nomeAtor : "", 
           personagem->status ? "true" : "false", 
           strcmp(personagem->dataNascimento, "-1") != 0 ? personagem->dataNascimento : "",
           personagem->anoNascimento, 
           strcmp(personagem->corOlho, "-1") != 0 ? personagem->corOlho : "", 
           strcmp(personagem->genero, "-1") != 0 ? personagem->genero : "", 
           strcmp(personagem->hairColour, "-1") != 0 ? personagem->hairColour : "",
           personagem->bruxo ? "true" : "false");
}

//método de pesquisa binária
int pesquisaBinaria(Personagem *vetor, char *nome, int esq, int dir){
    if(esq > dir){
        return -1;
    }else{
        int meio = (esq + dir) / 2;
        if(strcmp(nome, vetor[meio].nome) == 0){
            return 1;
        }
        else if (strcmp(nome, vetor[meio].nome) > 0)
        {
            return pesquisaBinaria(vetor, nome, meio + 1, dir);
        }
        else
        {
            return pesquisaBinaria(vetor, nome, esq, meio - 1);
        }
    }
}

//método de ordenação
void ordenar(Personagem *vetor, int pos){
    for (int i = 0; i < pos; i++){
        int menor = i;
        for (int j = i + 1; j < pos; j++){
            if(strcmp(vetor[j].nome, vetor[menor].nome) < 0){
                menor = j;
            }
        }
        Personagem temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
    }
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

    ordenar(vetor, pos);

    //chama a pesquisa binária
    scanf(" %[^\r\n]s", nomePesquisa);
    while(strcmp(nomePesquisa, "FIM") != 0){
        printf("%s\n", pesquisaBinaria(vetor, nomePesquisa, 0, pos-1) == 1 ? "SIM" : "NAO");
        scanf(" %[^\r\n]s", nomePesquisa);
    }

    gettimeofday(&fim, NULL); // Marca o fim do tempo

    // Calcula o tempo decorrido em segundos e microssegundos
    tempo_decorrido = (fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1000000.0;
    FILE *arquivo;
    arquivo = fopen("matrícula_binaria.txt","w");
    fprintf(arquivo,"821429\t%f segundos\t%d comparaçoes", tempo_decorrido, count);
    fclose(arquivo);

    return 0;
}
