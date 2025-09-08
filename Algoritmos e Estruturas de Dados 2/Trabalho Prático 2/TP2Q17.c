/*Refaça a Questão Heapsort considerando a ordenação parcial com k igual a 10.*/

//Atributo para ordenação - cor do cabelo

// Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define tamanho_max 200

// Contagem de comparacoes
int comp = 0;
// Contagem de movimentacoes
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

void swap(Personagem *a, Personagem *b){
    Personagem tmp = *a;
    *a = *b;
    *b = tmp;
}

void construir(Personagem vetor[], int tamHeap){
    for(int i = tamHeap; i > 1 && (strcmp(vetor[i].corCabelo, vetor[i/2].corCabelo) > 0|| 
        (strcmp(vetor[i].corCabelo, vetor[i/2].corCabelo) == 0 && strcmp(vetor[i].nome,vetor[i/2].nome)>0)); i /= 2){
        swap(&vetor[i], &vetor[i/2]);
    }
}

int getMaiorFilho(Personagem vetor[], int i, int tamHeap){
    int filho;
    if (2*i == tamHeap || strcmp(vetor[2*i].corCabelo, vetor[2*i+1].corCabelo) > 0 || 
        (strcmp(vetor[2*i].corCabelo, vetor[2*i+1].corCabelo) == 0 && strcmp(vetor[2*i].nome,vetor[2*i+1].nome)>0)){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}

void reconstruir(Personagem vetor[], int tamHeap){
    int i = 1;
    while(i <= (tamHeap/2)){
        int filho = getMaiorFilho(vetor, i, tamHeap);
        if(strcmp(vetor[i].corCabelo, vetor[filho].corCabelo) <= 0){
            swap(&vetor[i], &vetor[filho]);
            i = filho;
        }else{
            i = tamHeap;
        }
    }
}

//método de ordenação heapsort parcial
void heapsortParcial(Personagem vetor[], int pos, int k) {
    //Alterar o vetor ignorando a posicao zero
    Personagem vetorTmp[pos+1];
    for(int i = 0; i < pos; i++){
        vetorTmp[i+1] = vetor[i];
    }

    //Contrucao do heap
    for(int tamHeap = 2; tamHeap <= k; tamHeap++){
        construir(vetorTmp, tamHeap);
    }
    
    for(int i=k+1; i<=pos;i++){
        if(strcmp(vetorTmp[i].corCabelo, vetorTmp[1].corCabelo) < 0){
            swap(&vetorTmp[i],&vetorTmp[1]);
            reconstruir(vetorTmp, k);
        }
    }    
    //Ordenacao propriamente dita
    int tamHeap = k;
    while(tamHeap > 1){
        swap(&vetorTmp[1], &vetorTmp[tamHeap--]);
        reconstruir(vetorTmp, tamHeap);
    }

    //Alterar o vetor para voltar a posicao zero
    for(int i = 0; i < pos; i++){
        vetor[i] = vetorTmp[i+1];
    }
}

int main() {
    struct timeval inicio, fim;
    double tempo_decorrido;
    gettimeofday(&inicio, NULL); // Marca o início do tempo

    Personagem csv[406];
    Personagem vetor[30];
    int pos = 0, k=10;
    char nomePesquisa[50];

    FILE *arq = fopen("/tmp/characters.csv", "r");
    if (arq == NULL) {
        printf("Arquivo não encontrado\n");
        return 0;
    }

    //leitura do CSV
    char search[300];
    fgets(search, sizeof(search), arq);
    int i = 0;
    while (fgets(search, sizeof(search), arq)) {
        ler(&csv[i], search);
        i++;
    }
    fclose(arq);

    //preencher o vetor
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

    //chamando a ordenação
    heapsortParcial(vetor, pos, k);

    //chamado para imprimir
    for(int i=0;i<k;i++){
        imprimir(&vetor[i]);
    }

    gettimeofday(&fim, NULL); // Marca o fim do tempo

    // Calcula o tempo decorrido em segundos e microssegundos
    tempo_decorrido = (fim.tv_sec - inicio.tv_sec) + (double)(fim.tv_usec - inicio.tv_usec) / 1000000.0;
    FILE *arquivo;
    arquivo = fopen("matrícula_heapsortParcial.txt","w");
    fprintf(arquivo,"821429\t%d comparacoes\t%d movimentacoes\t%f segundos",  comp, mov, tempo_decorrido);
    fclose(arquivo);

    return 0;
}
