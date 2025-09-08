/*Crie uma classe Personagem seguindo todas as regras apresentadas no slide unidade01g_conceitosBasicos_introducaoOO.pdf.
 Sua classe terá os campos privados id (char[]), name (char[]), alternate_names (Lista), house (char[]), ancestry 
 (char[]), species (char[]), patronus (char[]), hogwartsStaff (Boolean), hogwartsStudent (char[]), actorName (char[]), 
 alive (Boolean), dateOfBirth (DateTime), yearOfBirth (int), eyeColour (char[]), genero (char[]), corCabelo (char[]), 
 bruxo (Boolean). Sua classe também terá pelo menos dois construtores, e os métodos gets, sets, clone, imprimir e ler.

O método imprimir mostra os campos do registro (ver cada linha da saída padrão) e o ler lê os campos de um 
registro. Atenção para o arquivo de entrada, pois em alguns registros faltam valores e esse foi substituído pelo valor 
0 (zero) ou vazio.

A entrada padrão é composta por várias linhas e cada uma contém uma char[] indicando o id do Personagem a ser lido. 
A última linha da entrada contém a palavra FIM. A saída padrão também contém várias linhas, uma para cada registro contido 
em uma linha da entrada padrão.*/

//Daniel Salgado Magalhães - 821429 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>  

typedef struct Personagem{
char* id; 
char* nome; 
char* nomeAlternativo;
char* casa;
char* ancestry; 
char* especie; 
char* patrono; 
bool hogwartsStaff   ;  
bool hogwartsStudent;  
char* nomeAtor; 
bool status;
char* nomeAtorAlternativo; 
char* dataNascimento; 
int anoNascimento; 
char* corOlho; 
char* genero; 
char* corCabelo; 
bool bruxo; 
} Personagem;

// construtores
void newPersonagem ( Personagem* personagem, char* id , char*  nome, char* nomeAlternativo, char* casa, char* ancestry, char*  especie, char* patrono, bool  hogwartsStaff,
                    bool  hogwartsStudent, char* nomeAtor, bool status, char* nomeAtorAlternativo, char*  dataNascimento, int anoNascimento, char* corOlho, 
                    char* genero , char* corCabelo, bool bruxo ){
    if(personagem != NULL){
    personagem->id = id;                             
    personagem->nome = nome;                         
    personagem->nomeAlternativo = nomeAlternativo;                 
    personagem->casa = casa;                           
    personagem->ancestry = ancestry;                     
    personagem->especie = especie;      
    if(strcmp(patrono,"null") == 0){
        personagem->patrono = "";
    }else{
        personagem->patrono= patrono;     
    }                           
    personagem->hogwartsStaff= hogwartsStaff;                   
    personagem->hogwartsStudent= hogwartsStudent ;     
    if(strcmp(nomeAtor,"null") == 0){ 
        personagem->nomeAtor = "";
    }else{
        personagem->nomeAtor = nomeAtor;  
    }                         
    personagem->status= status;                           
    personagem->nomeAtorAlternativo = nomeAtorAlternativo;               
    personagem->dataNascimento = dataNascimento;                   
    personagem->anoNascimento= anoNascimento;                   
    personagem->corOlho = corOlho;                       
    personagem->genero = genero;                         
    personagem->corCabelo = corCabelo;                     
    personagem->bruxo= bruxo;                         
    }
}

Personagem novoPersonagemPesquisado(){
    Personagem novoPersonagem; // instancia o novo personagem pra receber os primeiros valores.
    newPersonagem(&novoPersonagem, "", "", "", "", "", "", "", false, false, "", false, "", "", 0, "", "", "", false);
    return novoPersonagem;
}

// getters
const char* getId(const Personagem *inicial) {
    return inicial->id;
}

const char* getNome(const Personagem *inicial) {
    return inicial->nome;
}

const char* getnNomeAlternativo(const Personagem *inicial) {
    return inicial->nomeAlternativo;
}

const char* getCasa(const Personagem *inicial) {
    return inicial->casa;
}

const char* getAncestry(const Personagem *inicial) {
    return inicial->ancestry;
}

const char* getEspecie(const Personagem *inicial) {
    return inicial->especie;
}

const char* getPatrono(const Personagem *inicial) {
    return inicial->patrono;
}

bool getHogwartsStaff(const Personagem *inicial) {
    return inicial->hogwartsStaff;
}

bool getHogwartsStudent(const Personagem *inicial) {
    return inicial->hogwartsStudent;
}

const char* getNomeAtor(const Personagem *inicial) {
    return inicial->nomeAtor;
}

bool getStatus(const Personagem *inicial) {
    return inicial->status;
}

const char* getNomeAtorAlternativo(const Personagem *inicial) {
    return inicial->nomeAtorAlternativo;
}

const char* getDataNascimento(const Personagem *inicial) {
    return inicial->dataNascimento;
}

int getAnoNascimento(const Personagem *inicial) {
    return inicial->anoNascimento;
}

const char* getCorOlho(const Personagem *inicial) {
    return inicial->corOlho;
}

const char* getGenero(const Personagem *inicial) {
    return inicial->genero;
}

const char* getCorCabelo(const Personagem *inicial) {
    return inicial->corCabelo;
}

bool getBruxo(const Personagem *inicial) {
    return inicial->bruxo;
}

//setters
void setId(Personagem *inicial, const char *id) {
    if (inicial->id != NULL) free(inicial->id);
    inicial->id = strdup(id);
}

void setNome(Personagem *inicial, const char *nome) {
    if (inicial->nome != NULL) free(inicial->nome);
    inicial->nome = strdup(nome);
}

void setNomeAlternativo(Personagem *inicial, const char *nomeAlternativo) {
    if (inicial->nomeAlternativo != NULL) free(inicial->nomeAlternativo);
    inicial->nomeAlternativo = strdup(nomeAlternativo);
}

void setCasa(Personagem *inicial, const char *casa) {
    if (inicial->casa != NULL) free(inicial->casa);
    inicial->casa = strdup(casa);
}

void setAncestry(Personagem *inicial, const char *ancestry) {
    if (inicial->ancestry != NULL) free(inicial->ancestry);
    inicial->ancestry = strdup(ancestry);
}

void setEspecie(Personagem *inicial, const char *especie) {
    if (inicial->especie != NULL) free(inicial->especie);
    inicial->especie = strdup(especie);
}

void setPatrono(Personagem *inicial, const char *patrono) {
    if (inicial->patrono != NULL) free(inicial->patrono);
    inicial->patrono = strdup(patrono);
}

void setHogwartsStaff(Personagem *inicial, bool hogwartsStaff) {
    inicial->hogwartsStaff = hogwartsStaff;
}

void setHogwartsStudent(Personagem *inicial, bool hogwartsStudent) {
    inicial->hogwartsStudent = hogwartsStudent;
}

void setNomeAtor(Personagem *inicial, const char *nomeAtor) {
    if (inicial->nomeAtor != NULL) free(inicial->nomeAtor);
    inicial->nomeAtor = strdup(nomeAtor);
}

void setStatus(Personagem *inicial, bool status) {
    inicial->status = status;
}

void setNomeAtorAlternativo(Personagem *inicial, const char *nomeAtorAlternativo) {
    if (inicial->nomeAtorAlternativo != NULL) free(inicial->nomeAtorAlternativo);
    inicial->nomeAtorAlternativo = strdup(nomeAtorAlternativo);
}

void setDataNascimento(Personagem *inicial, const char *dataNascimento) {
    if (inicial->dataNascimento != NULL) free(inicial->dataNascimento);
    inicial->dataNascimento = strdup(dataNascimento);
}

void setAnoNascimento(Personagem *inicial, int anoNascimento) {
    inicial->anoNascimento = anoNascimento;
}

void setCorOlho(Personagem *inicial, const char *corOlho) {
    if (inicial->corOlho!= NULL) free(inicial->corOlho);
    inicial->corOlho = strdup(corOlho);
}

void setGenero(Personagem *inicial, const char *genero) {
    if (inicial->genero != NULL) free(inicial->genero);
    inicial->genero = strdup(genero);
}

void setCorCabelo(Personagem *inicial, const char *corCabelo) {
    if (inicial->corCabelo != NULL) free(inicial->corCabelo);
    inicial->corCabelo = strdup(corCabelo);
}

void setBruxo(Personagem *inicial, bool bruxo) {
    inicial->bruxo = bruxo;
}

// método de imprimir
void imprimir ( Personagem* personagem ){
    // comparação para verificar se a data tá no modelo dd-MM-yyyy
    if (personagem->dataNascimento && strlen(personagem->dataNascimento) < 10) {
        char *aux = calloc(11, sizeof(char));
        int dia, mes, ano;
        
        if (sscanf(personagem->dataNascimento, "%d-%d-%d", &dia, &mes, &ano) == 3) {
            sprintf(aux, "%02d-%02d-%d", dia, mes, ano);  // coloca um zero a esquerda se não tiver
            free(personagem->dataNascimento);  
            personagem->dataNascimento = aux; 
        } else {
            free(aux);
        }
    }
    printf( "[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",personagem->id, personagem->nome, personagem->nomeAlternativo, 
            personagem->casa, personagem->ancestry, personagem->especie, personagem->patrono, personagem->hogwartsStaff ? "true" : "false",
            personagem->hogwartsStudent ? "true" : "false", personagem->nomeAtor, personagem->status ? "true" : "false", personagem->dataNascimento ,personagem->anoNascimento,
            personagem->corOlho, personagem->genero, personagem->corCabelo,(personagem->bruxo == "true" ? "true" : "false") ); 
}

// método de leitura
Personagem* ler(Personagem* personagem, char* arquivo, char* searchID) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("\nArquivo não encontrado.\n");
    } else {
        char linha[500]; // tamanho máximo da linha
        bool search = false; // controle o while

        // pula a primeira linha
        fgets(linha, sizeof(linha), file);
        
        int na = 0;// ler o resto das linhas

        while (scanf("%s", linha) != NULL && !search) {
            char *campos[18];
            char linha_auxiliar[500] = {0};
            int col = 0;
            int t = 0;
            int k = 0;
            int index = 0;
            //cria um token pra armezanar cada variável da quebra de linha
            char *token = strtok(linha, ";");
            int contador = 0;
            na++;
            int debug= 0;
            // lê até que o token seja null
            while (token != NULL) {
                debug++;
                contador++;
                campos[index++] = strdup(token);
                token = strtok(NULL, ";");
            }
            
        // "método" pra trocar [] por {}
        char aux[500] = {0};
        int j = 0;
        for (int i = 0; i < strlen(campos[2]); i++) {
            if (campos[2][i] == '[') {
                aux[j] = '{';
            } else if (campos[2][i] == ']') {
                aux[j] = '}';
            } else if (campos[2][i] == '\'') {
                continue; 
            } else {
                aux[j] = campos[2][i];
            }
            j++; 
        }
        aux[j] = '\0'; 

        free(campos[2]); 
        campos[2] = strdup(aux);
            // verifica se o atributo 0 é o ID pesquisado
            if (strcmp(campos[0], searchID) == 0) {
                //recebe os campos e coloca eles em ordem
                if(contador < 18){
                    if(contador>16){
                    newPersonagem(personagem,campos[0], campos[1], campos[2], campos[3],campos[4], campos[5], "null" ,strcmp(campos[6], "true") == 0,
                    strcmp(campos[7], "true") == 0,campos[8], strcmp(campos[9], "true") == 0,campos[10], campos[11],atoi(campos[12]), campos[13], campos[14],
                    campos[15], (strcmp(campos[16], "true") == 0) ? "true" : "false");
                    } else{
                    newPersonagem(personagem,campos[0], campos[1], campos[2], campos[3],campos[4], campos[5], "null" ,strcmp(campos[6], "true") == 0,
                    strcmp(campos[7], "true") == 0,"null", strcmp(campos[8], "true") == 0,campos[9], campos[10],atoi(campos[11]), campos[12], campos[13],
                    campos[14], (strcmp(campos[15], "true")) == 0 ? "true" : "false");
                    }
                }else{
                    newPersonagem(personagem,campos[0], campos[1], campos[2], campos[3],campos[4], campos[5], campos[6],strcmp(campos[7], "true") == 0,
                    strcmp(campos[8], "true") == 0,campos[9], strcmp(campos[10], "true") == 0,campos[11], campos[12],atoi(campos[13]), campos[14], campos[15],
                    campos[16], (strcmp(campos[17], "true") == 0) ? "true" : "false");
                }
                search = true;
                
                return personagem; // retorna o personagem encontrado
            }

            // liberar memoria pra receber novos personagens
            for (int x = 0; x < index; x++) {
                free(campos[x]);
            }
        }
        fclose(file); // fecha o arquivo
    }
}

int main(){
    //alocando local de memoria para o personagem
    Personagem* personagem = (Personagem*) malloc ( 1 * sizeof(Personagem) );
    char* caminho = "/tmp/characters.csv"; 
    char id[81];
    //ler id novo
    scanf("%s",id ); 
    //limpar buffer
    getchar( );
    while( strcmp( id,"FIM" ) != 0 ){
        personagem = ler( personagem, caminho, id );
        imprimir( personagem );
        //ler id novo
        scanf( "%s", id ); 
        //limpar buffer
        getchar( );
    } 
    //liberar memoria alocada
    free( personagem );
   personagem = NULL;
    return 0;
}
