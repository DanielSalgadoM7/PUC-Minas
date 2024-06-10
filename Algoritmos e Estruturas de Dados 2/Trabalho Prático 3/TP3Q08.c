/*Refaça a Questão Quicksort 10 do Trabalho Prático II - com lista duplamente encadeada. O nome do arquivo de log será matrícula_quicksort2.txt.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>  


typedef struct s_Personagem
{
char*   id; 
char* nome; 
char* nomeAlternativo;
char* casa; 
char* ancestry; 
char* especie; 
char* patrono; 
bool hogwartsStaff;  
bool hogwartsStudent;  
char* nomeAtor; 
bool status;
char* atorAlternativo; 
char* dataNascimento; 
int anoNascimento; 
char* corOlho; 
char* genero; 
char* corCabelo; 
bool bruxo; 
} Personagem;

// construtor
void newPersonagem ( Personagem* personagem, char* id , char*  nome, char* nomeAlternativo, char* casa,char* ancestry, char*  especie, char* patrono,bool  hogwartsStaff,bool  hogwartsStudent, char* nomeAtor, bool status, char* atorAlternativo, char*  dataNascimento, int anoNascimento, char*corOlho, char* genero , char* corCabelo, bool bruxo ){
    if(personagem != NULL){
    personagem->id = id;                             
    personagem->nome = nome;                         
    personagem->nomeAlternativo = nomeAlternativo;                 
    personagem->casa = casa;                           
    personagem->ancestry = ancestry;                     
    personagem->especie = especie;      
    if(strcmp(patrono,"null") == 0){
        personagem -> patrono = "";
    }else{
        personagem->patrono= patrono;     
    }                           
    personagem->hogwartsStaff= hogwartsStaff;                   
    personagem->hogwartsStudent= hogwartsStudent ;     
    if(strcmp(nomeAtor,"null") == 0){ 
        personagem -> nomeAtor = "";
    }else{
        personagem->nomeAtor= nomeAtor;  
    }                         
    personagem->status= status  ;                           
    personagem->atorAlternativo= atorAlternativo;               
    personagem->dataNascimento  = dataNascimento  ;                   
    personagem->anoNascimento = anoNascimento ;                   
    personagem->corOlho = corOlho;                       
    personagem->genero = genero ;                         
    personagem->corCabelo  = corCabelo ;                     
    personagem->bruxo  = bruxo ;                         
    }
}

//setters

void setPersonagemId(Personagem *p,  char *id) {
    if (p->id != NULL) free(p->id);
    p->id = strdup(id);
}

void setPersonagemnome(Personagem *p,  char *nome) {
    if (p->nome != NULL) free(p->nome);
    p->nome = strdup(nome);
}

void setPersonagemnomeAlternativo(Personagem *p,  char *nomeAlternativo) {
    if (p->nomeAlternativo != NULL) free(p->nomeAlternativo);
    p->nomeAlternativo = strdup(nomeAlternativo);
}

void setPersonagemcasa(Personagem *p,  char *casa) {
    if (p->casa != NULL) free(p->casa);
    p->casa = strdup(casa);
}

void setPersonagemAncestry(Personagem *p,  char *ancestry) {
    if (p->ancestry != NULL) free(p->ancestry);
    p->ancestry = strdup(ancestry);
}

void setPersonagemespecie(Personagem *p,  char *especie) {
    if (p->especie != NULL) free(p->especie);
    p->especie = strdup(especie);
}

void setPersonagempatrono(Personagem *p,  char *patrono) {
    if (p->patrono != NULL) free(p->patrono);
    p->patrono = strdup(patrono);
}

void setPersonagemHogwartsStaff(Personagem *p, bool hogwartsStaff) {
    p->hogwartsStaff = hogwartsStaff;
}

void setPersonagemHogwartsStudent(Personagem *p, bool hogwartsStudent) {
    p->hogwartsStudent = hogwartsStudent;
}

void setPersonagemnomeAtor(Personagem *p,  char *nomeAtor) {
    if (p->nomeAtor != NULL) free(p->nomeAtor);
    p->nomeAtor = strdup(nomeAtor);
}

void setPersonagemstatus(Personagem *p, bool status) {
    p->status = status;
}

void setPersonagematorAlternativo(Personagem *p,  char *atorAlternativo) {
    if (p->atorAlternativo != NULL) free(p->atorAlternativo);
    p->atorAlternativo = strdup(atorAlternativo);
}

void setPersonagemdataNascimento(Personagem *p,  char *dataNascimento) {
    if (p->dataNascimento != NULL) free(p->dataNascimento);
    p->dataNascimento = strdup(dataNascimento);
}

void setPersonagemanoNascimento(Personagem *p, int anoNascimento) {
    p->anoNascimento = anoNascimento;
}

void setPersonagemcorOlho(Personagem *p,  char *corOlho) {
    if (p->corOlho != NULL) free(p->corOlho);
    p->corOlho = strdup(corOlho);
}

void setPersonagemgenero(Personagem *p,  char *genero) {
    if (p->genero != NULL) free(p->genero);
    p->genero = strdup(genero);
}

void setPersonagemcorCabelo(Personagem *p,  char *corCabelo) {
    if (p->corCabelo != NULL) free(p->corCabelo);
    p->corCabelo = strdup(corCabelo);
}

void setPersonagembruxo(Personagem *p, bool bruxo) {
    p->bruxo = bruxo;
}

// getters
 char* getPersonagemId( Personagem *p) {
    return p->id;
}

 char* getPersonagemnome( Personagem *p) {
    return p->nome;
}

 char* getPersonagemnomeAlternativo( Personagem *p) {
    return p->nomeAlternativo;
}

 char* getPersonagemcasa( Personagem *p) {
    return p->casa;
}

 char* getPersonagemAncestry( Personagem *p) {
    return p->ancestry;
}

 char* getPersonagemespecie( Personagem *p) {
    return p->especie;
}

 char* getPersonagempatrono( Personagem *p) {
    return p->patrono;
}

bool getPersonagemHogwartsStaff( Personagem *p) {
    return p->hogwartsStaff;
}

bool getPersonagemHogwartsStudent( Personagem *p) {
    return p->hogwartsStudent;
}

 char* getPersonagemnomeAtor( Personagem *p) {
    return p->nomeAtor;
}

bool getPersonagemstatus( Personagem *p) {
    return p->status;
}

 char* getPersonagematorAlternativo( Personagem *p) {
    return p->atorAlternativo;
}

 char* getPersonagemdataNascimento( Personagem *p) {
    return p->dataNascimento;
}

int getPersonagemanoNascimento( Personagem *p) {
    return p->anoNascimento;
}
 char* getPersonagemcorOlho( Personagem *p) {
    return p->corOlho;
}

 char* getPersonagemgenero( Personagem *p) {
    return p->genero;
}

 char* getPersonagemcorCabelo( Personagem *p) {
    return p->corCabelo;
}

bool getPersonagembruxo( Personagem *p) {
    return p->bruxo;
}

//imprimir personagem

void imprimir ( Personagem* personagem ){
    //adequando ao layout do canvas
    //printf("ESTUDANTE: %s\n",personagem->hogwartsStudent);
    if (personagem->dataNascimento && strlen(personagem->dataNascimento) < 10) {
        char *aux = calloc(11, sizeof(char));  // espaço para "dd-mm-yyyy\0"
        int dia, mes, ano;
        
        // parse da data presumindo formatos "d-m-yyyy" ou "dd-m-yyyy" etc.
        if (sscanf(personagem->dataNascimento, "%d-%d-%d", &dia, &mes, &ano) == 3) {
            sprintf(aux, "%02d-%02d-%d", dia, mes, ano);  // formata com zeros à esquerda para dia e mês
            free(personagem->dataNascimento);  // libera a memória antiga
            personagem->dataNascimento = aux;  // atribui a nova string formatada
        } else {
            free(aux);  // libera aux se não for usada
        }
    }
    printf( " [%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",personagem->id,personagem->nome,personagem->nomeAlternativo,personagem->casa,personagem->ancestry,personagem->especie,personagem->patrono,personagem->hogwartsStaff ? "true" : "false",personagem->hogwartsStudent ? "true" : "false",personagem->nomeAtor,personagem->status ? "true" : "false",personagem->dataNascimento,personagem->anoNascimento,personagem->corOlho,personagem->genero,personagem->corCabelo,personagem->bruxo ? "true" : "false" ); 
}

//ler arquivo e colocar as caracteristicas daquele ID no personagem

Personagem clone(Personagem* p1){

    Personagem* aux = (Personagem*)malloc(1*sizeof(Personagem));
    newPersonagem ( aux,getPersonagemId(p1),getPersonagemnome(p1),getPersonagemnomeAlternativo(p1),getPersonagemcasa(p1),getPersonagemAncestry(p1),getPersonagemespecie(p1),getPersonagempatrono(p1),getPersonagemHogwartsStaff(p1),getPersonagemHogwartsStudent(p1),getPersonagemnomeAtor(p1),getPersonagemstatus(p1),getPersonagematorAlternativo(p1),getPersonagemdataNascimento(p1),getPersonagemanoNascimento(p1),getPersonagemcorOlho(p1),getPersonagemgenero(p1),getPersonagemcorCabelo(p1),getPersonagembruxo(p1) );
}

Personagem* ler(Personagem* personagem, char* filenome, char* id_procurado) {
    //leitura do arquivo
    FILE* file = fopen(filenome, "r");
    if (file == NULL) {
        printf("\nERROR: File Not Found.\n");
    } else {
        char line[500];
        //variavel para controlar o while
        bool idFound = false;

        // pular cabeçalho
        fgets(line, sizeof(line), file);
        // ler o resto das linhas
        int na = 0;
        //a cada fgets é uma quebra de linha
        while (fgets(line, sizeof(line), file) != NULL && !idFound) {
            char *atributos[18];
            char auxline[500] = {0};
            int col = 0;
            int t = 0;
            int k = 0;
            int index = 0;
            //faz a mesma coisa que o split, armazena nessa variavel as palavras separadas com ;
            char *token = strtok(line, ";");
            int execvar = 0;
            na++;
            int debug= 0;
            while (token != NULL) {
                //nesse caso a lógica é que esse ponteiro de strings "token" vai ser repartido e seu valor vai para aquele indice em atributos
                debug++;
                execvar++;
                atributos[index++] = strdup(token);
                token = strtok(NULL, ";");
            }
        //variavel auxiliar para trocar o [] por {}
        char aux[500] = {0};
        int j = 0;
        for (int i = 0; i < strlen(atributos[2]); i++) {
            if (atributos[2][i] == '[') {
                aux[j] = '{';
            } else if (atributos[2][i] == ']') {
                aux[j] = '}';
            } else if (atributos[2][i] == '\'') {
                continue; 
            } else {
                aux[j] = atributos[2][i];
            }
            j++; 
        }
        aux[j] = '\0'; 

        free(atributos[2]); 
        atributos[2] = strdup(aux);
            //comparação entre a primeira coluna e o id colocado pelo usuario
            if (strcmp(atributos[0], id_procurado) == 0) {
                //atribuição dos valores das colunas para um personagem
                bool aux = "false";

                if(execvar < 18){
                    if(execvar>16){
                    if(strlen(atributos[16]) >= 11){
                        aux = "true";
                    }else{
                        aux = 0;
                    }
                    newPersonagem(personagem,atributos[0], atributos[1], atributos[2], atributos[3],atributos[4], atributos[5], "null" ,strcmp(atributos[6], "VERDADEIRO") == 0,strcmp(atributos[7], "VERDADEIRO") == 0,atributos[8], strcmp(atributos[9], "VERDADEIRO") == 0,atributos[10], atributos[11],atoi(atributos[12]), atributos[13], atributos[14],atributos[15], aux);
                    } else{
                    if(strlen(atributos[15]) >= 11){
                        aux = "true";
                    } else{
                        aux = 0;
                    }
                    newPersonagem(personagem,atributos[0], atributos[1], atributos[2], atributos[3],atributos[4], atributos[5], "null" ,strcmp(atributos[6], "VERDADEIRO") == 0,strcmp(atributos[7], "VERDADEIRO") == 0,"null", strcmp(atributos[8], "VERDADEIRO") == 0,atributos[9], atributos[10],atoi(atributos[11]), atributos[12], atributos[13],atributos[14], aux);
                    }
                }else{
                    if(strlen(atributos[17]) >= 11){
                        aux = "true";
                    }else{
                        aux = 0;
                    }
                    newPersonagem(personagem,atributos[0], atributos[1], atributos[2], atributos[3],atributos[4], atributos[5], atributos[6],strcmp(atributos[7], "VERDADEIRO") == 0,strcmp(atributos[8], "VERDADEIRO") == 0,atributos[9], strcmp(atributos[10], "VERDADEIRO") == 0,atributos[11], atributos[12],atoi(atributos[13]), atributos[14], atributos[15],atributos[16], aux);
                }
                idFound = true;
                //retorna o personagem com essas caracteristicas
                return personagem;
            }

            // liberar memoria
            for (int x = 0; x < index; x++) {
                free(atributos[x]);
            }
        }
        //fechar arquivo
        fclose(file);
    }
}

typedef struct Celula {
    Personagem data;
    struct Celula* prox;
    struct Celula* ant;
} Celula;
typedef struct Lista {
    Celula* primeiro;
    Celula* ultimo;
} Lista;

void initList(Lista* list) {
    list->primeiro = NULL;
    list->ultimo = NULL;
}

// Função para criar um novo nó
Celula* createCelula(Personagem data) {
    Celula* newCelula = (Celula*)malloc(sizeof(Celula));
    newCelula->data = data;
    newCelula->prox = NULL;
    newCelula->ant = NULL;
    return newCelula;
}

// Função para adicionar um nó ao final da lista
void append(Lista* list, Personagem data) {
    Celula* newCelula = createCelula(data);
    if (list->ultimo == NULL) {
        list->primeiro = newCelula;
        list->ultimo = newCelula;
    } else {
        list->ultimo->prox = newCelula;
        newCelula->ant = list->ultimo;
        list->ultimo = newCelula;
    }
}

// Função para imprimir a lista
void printList(Lista* list) {
    Celula* temp = list->primeiro;
    while (temp != NULL) {
        imprimir(&temp->data);
        temp = temp->prox;
    }
    printf("\n");
}

// Função de partição para o Quicksort
Celula* partition(Celula* low, Celula* high) {
    char pivocasa[100];
    char pivonome[100];
    strcpy(pivocasa, high->data.casa);
    strcpy(pivonome, high->data.nome);

    Celula* i = low->ant;
    for (Celula* j = low; j != high; j = j->prox) {
        if (strcmp(j->data.casa, pivocasa) < 0 || 
            (strcmp(j->data.casa, pivocasa) == 0 && strcmp(j->data.nome, pivonome) < 0)) {
            i = (i == NULL) ? low : i->prox;
            Personagem temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    i = (i == NULL) ? low : i->prox;
    Personagem temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

// Função recursiva do Quicksort
void quickSort(Celula* low, Celula* high) {
    if (high != NULL && low != high && low != high->prox) {
        Celula* p = partition(low, high);
        quickSort(low, p->ant);
        quickSort(p->prox, high);
    }
}

// Função para encontrar o último nó
Celula* getUltimo(Celula* primeiro) {
    while (primeiro != NULL && primeiro->prox != NULL) {
        primeiro = primeiro->prox;
    }
    return primeiro;
}

// Função principal
Personagem* inicializarPersonagem(char* id) {
    Personagem* p = (Personagem*)malloc(sizeof(Personagem));
    char* path = "/tmp/characters.csv";
    ler(p, path, id);
    return p;
}

int main() {
    Personagem* personagens = NULL;
    Personagem* personagem = NULL;
    int numPersonagens = 0;
    char* path = "/tmp/characters.csv";
    char id[81];
    Lista lista;
    initList(&lista);
    // ler id novo
    scanf("%s", id);
    getchar();

    while (strcmp(id, "FIM") != 0) {
        personagem = (Personagem*)malloc(sizeof(Personagem));
        // alocar espaço para um novo personagem no array
        personagens = (Personagem*) realloc(personagens, (numPersonagens + 1) * sizeof(Personagem));

        if (personagens == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            return 1;
        }

        // ler o personagem do arquivo
        ler(&personagens[numPersonagens], path, id);
        ler(personagem, path, id);
        append(&lista,personagens[numPersonagens]);
        numPersonagens++;

        // ler id novo
        scanf("%s", id);
        getchar();
    }
    quickSort(lista.primeiro,lista.ultimo);
    printList(&lista);
    free(personagens);
    personagens = NULL;

    return 0;
}