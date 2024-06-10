//Refazer a Questão 1 - Lista com Alocação Sequencial usando lista dinâmica simples em Java.

/*Crie uma Lista de registros baseada na de inteiros vista na sala de aula. Sua lista deve conter todos os atributos e métodos existentes na lista de inteiros, 
contudo, adaptados para a classe Personagem. Lembre-se que, na verdade, temos uma lista de ponteiros (ou referências) e cada um deles aponta para um registo. 
Neste exercício, faremos inserções, remoções e mostraremos os elementos de nossa lista.


Os métodos de inserir e remover devem operar conforme descrito a seguir, respeitando parâmetros e retornos. Primeiro, o void inserirInicio(Personagem personagem) 
insere um registro na primeira posição da Lista e remaneja os demais. Segundo, o void inserir(Personagem personagem, int posição) insere um registro na posição p da Lista, 
onde p < n e n é o número de registros cadastrados. Em seguida, esse método remaneja os demais registros. O void inserirFim(Personagem personagem) insere um registro na última 
posição da Lista. O Personagem removerInicio() remove e retorna o primeiro registro cadastrado na Lista e remaneja os demais. O Personagem remover(int posição) remove e 
retorna o registro cadastrado na p-ésima posição da Lista e remaneja os demais. O Personagem removerFim() remove e retorna o último registro cadastrado na lista.


A entrada padrão é composta por duas partes. A primeira é igual a entrada da primeira questão. As demais linhas correspondem a segunda parte. 
A primeira linha da segunda parte tem um número inteiro $n$ indicando a quantidade de registros a serem inseridos/removidos. Nas próximas n linhas, tem-se n comandos de 
inserção/remoção a serem processados neste exercício. Cada uma dessas linhas tem uma palavra de comando: II inserir no início, I* inserir em qualquer posição, IF inserir no fim, 
RI remover no início, R* remover em qualquer posição e RF remover no fim. No caso dos comandos de inserir, temos também o nome do arquivo que contém o registro a ser inserido. 
No caso dos comandos de em qualquer posição, temos também esse nome. No Inserir, a posição fica imediatamente após a palavra de comando. 
A saída padrão tem uma linha para cada registro removido sendo que essa informação será constituída pela palavra (R) e o atributo name. 
No final, a saída mostra os atributos relativos a cada registro cadastrado na lista após as operações de inserção e remoção. */

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.util.Date;
import java.io.FileNotFoundException;
import java.text.SimpleDateFormat;
import java.text.ParseException;

class Celula{
    Personagem perso;
    Celula prox;
    int count = 0;
    public Celula(){
        this.perso = null;
        this.prox = null;
    }
    public Celula(Personagem personagem){
        this.perso = personagem;
        this.prox = null;
    }
}


class Lista {
    Celula primeiro, ultimo;
    int count = 0;
    public Lista() {
        primeiro = new Celula();
        ultimo = primeiro;
    }

    void printar() {
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.print("["+ count++ + " ");
            i.perso.imprimir();
        }
    }

    void inserirInicio(Personagem personagem) {
        Celula tmp = new Celula(personagem);
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if (primeiro == ultimo) {
            ultimo = tmp;
        }
    }

    void inserir(Personagem personagem, int pos) throws Exception {
        Celula i = primeiro;
        for (int c = 0; c < pos; i = i.prox, c++);
        Celula tmp = new Celula(personagem);
        tmp.prox = i.prox;
        i.prox = tmp;
        if (tmp.prox == null) {
            ultimo = tmp;
        }
    }

    void inserirFim(Personagem personagem) {
        Celula tmp = new Celula(personagem);
        ultimo.prox = tmp;
        ultimo = tmp;
    }

    Personagem removerInicio() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro! Lista vazia.");
        }
        Celula tmp = primeiro.prox;
        primeiro.prox = tmp.prox;
        if (primeiro.prox == null) {
            ultimo = primeiro;
        }
        return tmp.perso;
    }

    Personagem remover(int pos) throws Exception {
        Celula tmp = new Celula();
        Celula i = primeiro;
        for (int c = 0; c < pos; i = i.prox, c++);
        tmp = i.prox;
        i.prox = tmp.prox;
        if (tmp == ultimo) {
            ultimo = i;
        }
        return tmp.perso;
    }

    Personagem removerFim() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro! Lista vazia.");
        }
        Celula i = primeiro;
        while (i.prox != ultimo) {
            i = i.prox;
        }
        Celula tmp = ultimo;
        ultimo = i;
        ultimo.prox = null;
        return tmp.perso;
    }

    int tamanho() {
        int tamanho = 0;
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            tamanho++;
        }
        return tamanho;
    }
}

class Personagem{
    //Elementos

    private String id,nome,casa,ancestry,especie,patrono,nomeAtor,corOlho,corCabelo,genero;
    private ArrayList<String> nomeAlternativo;
    private boolean hogwartsStudent,hogwartsStaff,status,bruxo;
    private Date dataNascimento;
    private int anoNascimento;

    //Construtores
    public Personagem() {
        this.id = "";
        this.nome = "";
        this.ancestry = "";
        this.especie = "";
        this.patrono = "";
        this.nomeAtor = "";
        this.corOlho = "";
        this.corCabelo = "";
        this.genero = "";
        this.casa = "";
        this.anoNascimento = 0;
        this.nomeAlternativo = new ArrayList<String>();
    }

    public Personagem(String id, String nome, String casa, String ancestry, String especie,
                      String patrono, String nomeAtor, String corOlho, String corCabelo,
                      String genero, ArrayList<String> nomeAlternativo, boolean hogwartsStudent,
                      boolean hogwartsStaff, boolean status, boolean bruxo, Date dataNascimento,
                      int anoNascimento) {
        this.id = id;
        this.nome = nome;
        this.casa = casa;
        this.ancestry = ancestry;
        this.especie = especie;
        this.patrono = patrono;
        this.nomeAtor = nomeAtor;
        this.corOlho = corOlho;
        this.corCabelo = corCabelo;
        this.genero = genero;
        this.nomeAlternativo = nomeAlternativo;
        this.hogwartsStudent = hogwartsStudent;
        this.hogwartsStaff = hogwartsStaff;
        this.status = status;
        this.bruxo = bruxo;
        this.dataNascimento = dataNascimento;
        this.anoNascimento = anoNascimento;
    }
    //Métodos Get
    public String getId(){
        return this.id;
    }
    public String getnome(){
        return this.nome;
    }
    public String getcasa(){
        return this.casa;
    }
    public String getAncestry(){
        return this.ancestry;
    }
    public String getespecie(){
        return this.especie;
    }
    public String getpatrono(){
        return this.patrono;
    }
    public String getnomeAtor(){
        return this.nomeAtor;
    }
    public String getcorOlho(){
        return this.corOlho;
    }
    public String getcorCabelo(){
        return this.corCabelo;
    }
    public String getgenero(){
        return this.genero;
    }
    public ArrayList<String> getAlternatenomes(){
        return this.nomeAlternativo;
    }
    public boolean getHogwartsStudent(){
        return this.hogwartsStudent;
    }
    public boolean getHogwartsStaff(){
        return this.hogwartsStaff;
    }
    public boolean getstatus(){
        return this.status;
    }
    public boolean getbruxo(){
        return this.bruxo;
    }
    public int getYear(){
        return this.anoNascimento;
    }
    public Date getDate(){
        return this.dataNascimento;
    }

    //Métodos Set
    public void setId(String id){
        this.id = id;
    }
    public void setnome(String nome){
        this.nome = nome;
    }
    public void setcasa(String casanome){
        this.casa=casanome;
    }
    public void setAncestry(String ancestry){
        this.ancestry = ancestry;
    }
    public void setespecie(String especie){
        this.especie = especie;
    }
    public void setpatrono(String patrono){
        this.patrono = patrono;
    }
    public void setnomeAtor(String nome){
        this.nomeAtor = nome;
    }
    public void setEyeColor(String color){
        this.corOlho = color;
    }
    public void setcorCabelo(String color){
        this.corCabelo = color;
    }
    public void setgenero(String genero){
        this.genero = genero;
    }
    public void setAlternatenomes(ArrayList<String> nomes){
        this.nomeAlternativo = nomes;
    }
    public void setHogwartsStudent(boolean isStudent){
        this.hogwartsStudent = isStudent;
    }
    public void setHogwartsStaff(boolean haveStaff){
        this.hogwartsStaff = haveStaff;
    }
    public void setstatus(boolean isstatus){
        this.status = isstatus;
    }
    public void setbruxo(boolean isbruxo){
        this.bruxo = isbruxo;
    }
    public void setYear(int newYear){
        this.anoNascimento = newYear;
    }
    public void setDate(Date newDate){

        this.dataNascimento = newDate;
    }

    //Método clone
    public void clone(Personagem newClone){
        newClone.setYear(this.getYear());
        newClone.setDate(this.getDate());   
        newClone.setHogwartsStaff(this.getHogwartsStaff());
        newClone.setstatus(this.getstatus());
        newClone.setbruxo(this.getbruxo());
        newClone.setgenero(this.getgenero());
        newClone.setAlternatenomes(this.getAlternatenomes());
        newClone.setgenero(this.getgenero());
        newClone.setHogwartsStudent(this.getHogwartsStudent());
        newClone.setcorCabelo(this.getcorCabelo());
        newClone.setEyeColor(this.getcorOlho());
        newClone.setpatrono(this.getpatrono());
        newClone.setespecie(this.getespecie());
        newClone.setAncestry(this.getAncestry());
        newClone.setcasa(this.getcasa());
        newClone.setnome(this.getnome());
        newClone.setId(this.getId());

    }

    //Método de imprimir
    public void imprimir(){
        String arrayPrintado = "{";
        if(!this.getAlternatenomes().isEmpty()){
            for(int i = 0; i<this.getAlternatenomes().size(); i++){
                arrayPrintado+=this.getAlternatenomes().get(i);
                if (i < this.getAlternatenomes().size()- 1) {
                    arrayPrintado += ", ";
                }
            }
        }

        arrayPrintado+= "}";
        SimpleDateFormat formato = new SimpleDateFormat("dd-MM-yyyy");
        String dataFormatada = "";
        if (this.getDate() != null) {
            dataFormatada = formato.format(this.getDate());
        } else {
            dataFormatada = "Data não disponível";
        }
        System.out.println("## "+this.getId()+ " ## "+ this.getnome()+ " ## "+arrayPrintado+ " ## "+this.getcasa()+ " ## "+this.getAncestry()+ " ## "+this.getespecie()+ " ## "+this.getpatrono()+ " ## "+this.getHogwartsStaff()+ " ## "+this.getHogwartsStudent()+ " ## "+this.getnomeAtor()+ " ## "+this.getstatus()+ " ## "+dataFormatada+ " ## "+this.getYear()+ " ## "+this.getcorOlho()+ " ## "+this.getgenero()+ " ## "+this.getcorCabelo()+ " ## "+this.getbruxo()+"]");
    }


    //Método de Ler
    public void ler(String id){
        String path = "/tmp/characters.csv";
        try{
            File dados = new File(path);
            Scanner sc = new Scanner(dados);

            if(sc.hasNextLine()){
                sc.nextLine();
            }
            
            while(sc.hasNextLine()){
                String linha = sc.nextLine();
                int p = 0;
                while(linha.charAt(p) != '['){
                    p++;
                }
                int j = p;
                while(linha.charAt(j) != ']'){
                    j++;
                }

                String[] colunas = linha.split(";");

                if(colunas.length>0 && colunas[0].equals(id)){
                    this.setId(colunas[0]);
                    this.setnome(colunas[1]);
                    this.setcasa(colunas[3]);
                    this.setAncestry(colunas[4]);
                    this.setespecie(colunas[5]);
                    this.setpatrono(colunas[6]);
                    if(colunas[7].compareTo("VERDADEIRO") == 0){
                        this.setHogwartsStaff(true);
                    }else{
                        this.setHogwartsStaff(false);
                    }
                    if(colunas[8].compareTo("VERDADEIRO") == 0){
                        this.setHogwartsStudent(true);
                    } else{
                        this.setHogwartsStudent(false);
                    }
                    this.setnomeAtor(colunas[9]);
                    if(colunas[10].compareTo("VERDADEIRO") == 0){
                        this.setstatus(true);
                    }else{
                        this.setstatus(false);
                    }
                    SimpleDateFormat formato = new SimpleDateFormat("dd-MM-yyyy");
                    try {
                        this.setDate(formato.parse(colunas[12]));
                    } catch (ParseException e) {
                        System.err.println("Formato de data inválido.");
                    }
                    this.setYear(Integer.parseInt(colunas[13]));
                    this.setEyeColor(colunas[14]);
                    this.setgenero(colunas[15]);
                    this.setcorCabelo(colunas[16]);
                    this.setbruxo("VERDADEIRO".equals(colunas[17]));
                    String nomesAlternativos = colunas[2];
                    String nomes[] = nomesAlternativos.split(",");
                    //padronizar

                    for(int n = 0; n< nomes.length; n++){
                        if(nomes[n].length() > 0){
                            if(nomes[n].charAt(0) == ' '){
                                String aux = "";
                                for(int x = 0; x<nomes[n].length()-1; x++){
                                    aux += nomes[n].charAt(x+1);
                                }
                                nomes[n] = aux;
                            }
                            if(nomes[n].charAt(0) == '['){
                                String aux = "";
                                for(int x = 0; x<nomes[n].length()-1; x++){
                                    aux += nomes[n].charAt(x+1);
                                }
                                nomes[n] = aux;
                            }
                            if(nomes[n].charAt(nomes[n].length()-1) == ']'){
                                String aux = "";
                                for(int x = 0; x<nomes[n].length()-1; x++){
                                    aux += nomes[n].charAt(x);
                                }
                                nomes[n] = aux;
                            }
                            if(nomes[n].length() > 0 && nomes[n].charAt(0) == '\''){
                                String aux = "";
                                for(int x = 0; x<nomes[n].length()-1; x++){
                                    aux += nomes[n].charAt(x+1);
                                }
                                nomes[n] = aux;
                            }
                            if(nomes[n].length() > 0 && nomes[n].charAt(nomes[n].length()-1) == '\''){
                                String aux = "";
                                for(int x = 0; x<nomes[n].length()-1; x++){
                                    aux += nomes[n].charAt(x);
                                }
                                nomes[n] = aux;
                            }
                        }
                    }
                    
                    ArrayList<String> Alternativos = new ArrayList<String>();
                    for(int i = 0; i<nomes.length; i++){
                        Alternativos.add(nomes[i]);
                    }
                    this.setAlternatenomes(Alternativos);
                }
            }
            sc.close();
        }catch(FileNotFoundException erro){
            erro.printStackTrace();
        }
    }


    //Outros métodos
    public void addnome(String nome){
        this.nomeAlternativo.add(nome);
    }
    
}
public class TP3Q05 {

    public static boolean isFim(String entrada){
        boolean check = true;
        if(entrada.charAt(0) == 'F' && entrada.charAt(1) == 'I' && entrada.charAt(2) == 'M'){
            check = false;
        }
        return check;
    }

    public static Personagem[] aumentarArray(Personagem[] array, Personagem novoPersonagem){
        Personagem[] newArray = new Personagem[array.length+1];
        if(array.length != 0){
            for(int i = 0; i<array.length; i++){
                newArray[i] = array[i];
            }
        }
        newArray[array.length] = novoPersonagem;
        return newArray;
    }

    static String parseOption(String s) {
        StringBuilder aux = new StringBuilder();
        for (int i = 0; i < 2; i++) {
            aux.append(s.charAt(i));
        }
        return aux.toString();
    }
    
    static String parseID(String s){
        StringBuilder aux = new StringBuilder();
        for(int i = 3; i<s.length(); i++){
            aux.append(s.charAt(i));
        }
        return aux.toString();
    }
    static Personagem search(Personagem[] registros,int n, String id){
        Personagem tmp = new Personagem();
        for(int i = 0; i< n; i++){
            if(registros[i].getId().compareTo(id) == 0){
                tmp = registros[i];
            }
        }
        return tmp;
    }

    static boolean parseSuccess(String s) {
        try {
            Integer.parseInt(s);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Personagem[] registros = new Personagem[0];
        Personagem[] removidos = new Personagem[0];
        int count = 0;
        Lista newLista = new Lista();
        int n = 0;
        String id = sc.nextLine();
        while(isFim(id)){
            Personagem teste = new Personagem();
            teste.ler(id);
            newLista.inserirFim(teste);
            registros = aumentarArray(registros,teste);
            n++;
            id = sc.nextLine();
        }
        int pos = sc.nextInt();
        sc.nextLine();
        String selection;
        String id2;
        String opt;
        for(int i = 0; i<pos; i++){
            Personagem novoPersonagem = new Personagem();
            selection = sc.nextLine();
            id2 = parseID(selection);
            opt = parseOption(selection);
            novoPersonagem.ler(id2);
            switch(opt){
                case "II": newLista.inserirInicio(novoPersonagem); break;
                case "I*": 
                    opt = parseOption(id2);
                    id2 = parseID(id2);
                    novoPersonagem.ler(id2);
                    newLista.inserir(novoPersonagem, Integer.parseInt(opt));
                    break;
                case "IF": newLista.inserirFim(novoPersonagem);break;
                case "RI": removidos = aumentarArray(removidos, newLista.removerInicio());count++;break;
                case "R*": removidos = aumentarArray(removidos, newLista.remover(Integer.parseInt(id2)));count++;break;
                case "RF": removidos = aumentarArray(removidos, newLista.removerFim());count++;break;
                default: System.out.println("Opção Incorreta"); break;
            }
        }
        for(int i = 0; i<count;i++){
            System.out.println("(R) "+ removidos[i].getnome());
        }
        newLista.printar();

        sc.close();

    } 
}