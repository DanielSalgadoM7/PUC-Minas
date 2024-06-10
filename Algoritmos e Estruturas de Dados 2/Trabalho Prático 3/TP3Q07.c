#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>  
#include <math.h>

#define MAX 5

typedef struct s_Personagem
{
char* id; 
char* nome; 
char* nomeAlternativo;
char* casa; 
char* ancestry; 
char* especie; 
char* patrono; 
bool hogwartsStaff;  
bool hogwartsStudent;  
char* nomeAtor; 
bool alive;
char* alternateActors; 
char* dateOfBirth; 
int yearOfBirth; 
char* eyeColour; 
char* gender; 
char* hairColour; 
bool wizard; 
} Personagem;

// construtor
void newPersonagem ( Personagem* personagem, char* id , char*  nome, char* nomeAlternativo, char* casa,char* ancestry, char*  especie, char* patrono,bool  hogwartsStaff,bool  hogwartsStudent, char* nomeAtor, bool alive, char* alternateActors, char*  dateOfBirth, int yearOfBirth, char*eyeColour, char* gender , char* hairColour, bool wizard ){
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
    personagem->alive= alive  ;                           
    personagem->alternateActors= alternateActors;               
    personagem->dateOfBirth  = dateOfBirth  ;                   
    personagem->yearOfBirth = yearOfBirth ;                   
    personagem->eyeColour = eyeColour;                       
    personagem->gender = gender ;                         
    personagem->hairColour  = hairColour ;                     
    personagem->wizard  = wizard ;                         
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

void setPersonagemAlive(Personagem *p, bool alive) {
    p->alive = alive;
}

void setPersonagemAlternateActors(Personagem *p,  char *alternateActors) {
    if (p->alternateActors != NULL) free(p->alternateActors);
    p->alternateActors = strdup(alternateActors);
}

void setPersonagemDateOfBirth(Personagem *p,  char *dateOfBirth) {
    if (p->dateOfBirth != NULL) free(p->dateOfBirth);
    p->dateOfBirth = strdup(dateOfBirth);
}

void setPersonagemYearOfBirth(Personagem *p, int yearOfBirth) {
    p->yearOfBirth = yearOfBirth;
}

void setPersonagemEyeColour(Personagem *p,  char *eyeColour) {
    if (p->eyeColour != NULL) free(p->eyeColour);
    p->eyeColour = strdup(eyeColour);
}

void setPersonagemGender(Personagem *p,  char *gender) {
    if (p->gender != NULL) free(p->gender);
    p->gender = strdup(gender);
}

void setPersonagemHairColour(Personagem *p,  char *hairColour) {
    if (p->hairColour != NULL) free(p->hairColour);
    p->hairColour = strdup(hairColour);
}

void setPersonagemWizard(Personagem *p, bool wizard) {
    p->wizard = wizard;
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

bool getPersonagemAlive( Personagem *p) {
    return p->alive;
}

 char* getPersonagemAlternateActors( Personagem *p) {
    return p->alternateActors;
}

 char* getPersonagemDateOfBirth( Personagem *p) {
    return p->dateOfBirth;
}

int getPersonagemYearOfBirth( Personagem *p) {
    return p->yearOfBirth;
}
 char* getPersonagemEyeColour( Personagem *p) {
    return p->eyeColour;
}

 char* getPersonagemGender( Personagem *p) {
    return p->gender;
}

 char* getPersonagemHairColour( Personagem *p) {
    return p->hairColour;
}

bool getPersonagemWizard( Personagem *p) {
    return p->wizard;
}

//imprimir personagem

void imprimir ( Personagem* personagem ){
    //adequando ao layout do canvas
    //printf("ESTUDANTE: %s\n",personagem->hogwartsStudent);
    if (personagem->dateOfBirth && strlen(personagem->dateOfBirth) < 10) {
        char *aux = calloc(11, sizeof(char));  // espaço para "dd-mm-yyyy\0"
        int dia, mes, ano;
        
        // parse da data presumindo formatos "d-m-yyyy" ou "dd-m-yyyy" etc.
        if (sscanf(personagem->dateOfBirth, "%d-%d-%d", &dia, &mes, &ano) == 3) {
            sprintf(aux, "%02d-%02d-%d", dia, mes, ano);  // formata com zeros à esquerda para dia e mês
            free(personagem->dateOfBirth);  // libera a memória antiga
            personagem->dateOfBirth = aux;  // atribui a nova string formatada
        } else {
            free(aux);  // libera aux se não for usada
        }
    }
    printf( " ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",personagem->id,personagem->nome,personagem->nomeAlternativo,personagem->casa,personagem->ancestry,personagem->especie,personagem->patrono,personagem->hogwartsStaff ? "true" : "false",personagem->hogwartsStudent ? "true" : "false",personagem->nomeAtor,personagem->alive ? "true" : "false",personagem->dateOfBirth,personagem->yearOfBirth,personagem->eyeColour,personagem->gender,personagem->hairColour,personagem->wizard ? "true" : "false" ); 
}

//ler arquivo e colocar as caracteristicas daquele ID no personagem

Personagem clone(Personagem* p1){

    Personagem* aux = (Personagem*)malloc(1*sizeof(Personagem));
    newPersonagem ( aux,getPersonagemId(p1),getPersonagemnome(p1),getPersonagemnomeAlternativo(p1),getPersonagemcasa(p1),getPersonagemAncestry(p1),getPersonagemespecie(p1),getPersonagempatrono(p1),getPersonagemHogwartsStaff(p1),getPersonagemHogwartsStudent(p1),getPersonagemnomeAtor(p1),getPersonagemAlive(p1),getPersonagemAlternateActors(p1),getPersonagemDateOfBirth(p1),getPersonagemYearOfBirth(p1),getPersonagemEyeColour(p1),getPersonagemGender(p1),getPersonagemHairColour(p1),getPersonagemWizard(p1) );
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

typedef struct {
    Personagem* personagens[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void inicializarFila(FilaCircular* fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

bool filaVazia(FilaCircular* fila) {
    return (fila->tamanho == 0);
}

bool filaCheia(FilaCircular* fila) {
    return (fila->tamanho == MAX);
}

void inserirFila(FilaCircular* fila, Personagem* p) {
    if (filaCheia(fila)) {
        Personagem* removido = fila->personagens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % MAX;
        fila->tamanho--;
        free(removido->id);
        free(removido->nome);
        free(removido);
    }
    fila->personagens[fila->fim] = p;
    fila->fim = (fila->fim + 1) % MAX;
    fila->tamanho++;
    int soma = 0;
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + i) % MAX;
        soma += fila->personagens[index]->yearOfBirth;
    }
    printf(">> Year Birthday Average: %d\n", (int)round((double)soma / fila->tamanho));
}


void imprimirFila(FilaCircular* fila) {
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + i) % MAX;
        printf("%s\n", fila->personagens[index]->nome);
    }
}
Personagem* removerFila(FilaCircular* fila) {
    if (filaVazia(fila)) {
        return NULL;
    }
    Personagem* removido = fila->personagens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->tamanho--;
    return removido;
}
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
    FilaCircular fila;
    inicializarFila(&fila);

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
        inserirFila(&fila, personagem);
        numPersonagens++;

        // ler id novo
        scanf("%s", id);
        getchar();
    }

    int numComandos;
    scanf("%d", &numComandos);

    for (int i = 0; i < numComandos; i++) {
        char comando[10];
        scanf("%s", comando);
        if (strcmp(comando, "I") == 0) {
            scanf("%s", id);
            Personagem* p = inicializarPersonagem(id);
            inserirFila(&fila, p);
        } else if (strcmp(comando, "R") == 0) {
            Personagem* p = removerFila(&fila);
            if (p != NULL) {
                printf("(R) %s %d\n", p->nome, p->yearOfBirth);
                free(p->id);
                free(p->nome);
                free(p);
            }
        }
    }

    printf("[ Head ]\n");
    imprimirFila(&fila);
    printf("[ Tail ]\n");

    // Liberar memória alocada para o array de personagens
    for (int i = 0; i < numPersonagens; i++) {
        free(personagens[i].id);
        free(personagens[i].nome);
    }
    free(personagens);

    return 0;
}