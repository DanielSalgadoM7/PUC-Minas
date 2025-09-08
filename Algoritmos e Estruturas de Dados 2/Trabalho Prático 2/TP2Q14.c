/*Repita a questão de Ordenação por Seleção, contudo, usando o algoritmo Radixsort, fazendo com que a chave de pesquisa seja o atributo id. 
O nome do arquivo de log será matrícula_radixsort.txt*/

// Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>

#define tamanho_max 200

// Contagem de comparações
int comp = 0;
// Contagem de movimentações
int mov = 0;

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
        if (str[i] == ';' && str[i + 1] == ';') {
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
            case 0:
                strcpy(personagem->id, token);
                break;
            case 1:
                strcpy(personagem->nome, token);
                break;
            case 2:
                strcpy(personagem->nomeAlternativo, token);
                break;
            case 3:
                strcpy(personagem->casa, token);
                break;
            case 4:
                strcpy(personagem->ancestry, token);
                break;
            case 5:
                strcpy(personagem->especie, token);
                break;
            case 6:
                strcpy(personagem->patrono, token);
                break;
            case 7:
                strcpy(personagem->hogwartsStaff, token);
                break;
            case 8:
                strcpy(personagem->hogwartsStudent, token);
                break;
            case 9:
                strcpy(personagem->nomeAtor, token);
                break;
            case 10:
                strcpy(personagem->status, token);
                break;
            case 12:
                strcpy(personagem->dataNascimento, token);
                break;
            case 13:
                personagem->anoNascimento = atoi(token);
                break;
            case 14:
                strcpy(personagem->corOlho, token);
                break;
            case 15:
                strcpy(personagem->genero, token);
                break;
            case 16:
                strcpy(personagem->corCabelo, token);
                break;
            case 17:
                strcpy(personagem->bruxo, token);
                break;
            default:
                break;
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

// Método de troca
void swap(Personagem *a, Personagem *b) {
    Personagem tmp = *a;
    *a = *b;
    *b = tmp;
}

int getMax(Personagem vetor[], int n) {
    int maior = strlen(vetor[0].id);

    for (int i = 1; i < n; i++) {
        if (strcmp(vetor[i].id, vetor[maior].id) > 0) {
            maior = i;
            comp++;
        }
        comp++;
    }
    return maior;
}

void radcountingSort(Personagem vetor[], int pos, int exp) {
    int count[256] = {0};
    Personagem output[pos];

    // Contar o número de ocorrências de cada elemento
    for (int i = 0; i < pos; i++) {
        int index = (strlen(vetor[i].id) - exp >= 0) ? (vetor[i].id[strlen(vetor[i].id) - exp]) : 0;
        count[index]++;
    }

    // Agora, count[i] contém o número de elementos menores ou iguais a i
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Ordenar
    for (int i = pos - 1; i >= 0; i--) {
        int index = (strlen(vetor[i].id) - exp >= 0) ? (vetor[i].id[strlen(vetor[i].id) - exp]) : 0;
        output[count[index] - 1] = vetor[i];
        count[index]--;
    }

    // Copiar para o vetor original
    for (int i = 0; i < pos; i++) {
        vetor[i] = output[i];
        mov++;
    }
}

void radixsort(Personagem vetor[], int pos) {
    // Encontrar o tamanho da string mais longa
    int max = getMax(vetor, pos);

    // Chamada do radix sort para cada caractere
    for (int exp = 1; exp <= max; exp++) {
        radcountingSort(vetor, pos, exp);
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
        printf("Arquivo não encontrado\n");
        return 0;
    }

    // Leitura do CSV
    char search[300];
    fgets(search, sizeof(search), arq);
    int i = 0;
    while (fgets(search, sizeof(search), arq)) {
        ler(&csv[i], search);
        i++;
    }
    fclose(arq);

    // Preencher o vetor
    scanf("%s", nomePesquisa);
    while (strcmp(nomePesquisa, "FIM") != 0) {
        for (int i = 0; i < 406; i++) {
            if (strcmp(csv[i].id, nomePesquisa) == 0) {
                vetor[pos] = csv[i];
                pos++;
                break;
            }
        }
        scanf("%s", nomePesquisa);
    }

    // Chamando a ordenação
    radixsort(vetor, pos);

    // Chamado para imprimir
    for (int i = 0; i < pos; i++) {
        imprimir(&vetor[i]);
    }

    gettimeofday(&fim, NULL); // Marca o fim do tempo

    // Calcula o tempo decorrido em segundos e microssegundos
    tempo_decorrido = (fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1000000.0;
    FILE *arquivo;
    arquivo = fopen("matrícula_radixsort.txt", "w");
    fprintf(arquivo, "821429\t%d comparacoes\t%d movimentacoes\t%f segundos", comp, mov, tempo_decorrido);
    fclose(arquivo);

    return 0;
}
