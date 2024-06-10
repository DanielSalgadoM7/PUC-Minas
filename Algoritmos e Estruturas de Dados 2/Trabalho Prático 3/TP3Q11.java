//Refaça a questão 8 deste TP na linguagem Java.

/*Refaça a Questão Quicksort 10 do Trabalho Prático II - com lista duplamente encadeada. O nome do arquivo de log será matrícula_quicksort2.txt.*/

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.util.Date;
import java.io.FileNotFoundException;
import java.text.SimpleDateFormat;
import java.io.FileWriter;
import java.text.ParseException;
import java.io.IOException;

class Celula{
    Personagem perso;
    Celula prox;
    Celula ant;
    int count = 0;
    public Celula(){
        this.perso = null;
        this.prox = null;
        this.ant = null;
    }
    public Celula(Personagem personagem){
        this.perso = personagem;
        this.prox = null;
        this.ant = null;
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
            i.perso.imprimir();
        }
    }
    public void inserirInicio(Personagem personagem) {
        Celula tmp = new Celula(personagem);
        tmp.prox = primeiro.prox;
        tmp.ant = primeiro;
        if (primeiro.prox != null) {
            primeiro.prox.ant = tmp;
        }
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

    void trocar(Celula a, Celula b) {
        Personagem temp = a.perso;
        a.perso = b.perso;
        b.perso = temp;
    }

    Celula obterCelula(int pos) {
        Celula i = primeiro.prox;
        for (int c = 0; c < pos && i != null; i = i.prox, c++);
        return i;
    }

    Celula particionar(Celula low, Celula high) {
        Personagem pivo = high.perso;
        Celula i = low.ant;

        for (Celula j = low; j != high; j = j.prox) {
            if ((j.perso.getcasa().compareTo(pivo.getcasa()) < 0) || ((j.perso.getcasa().compareTo(pivo.getcasa()) == 0) && (j.perso.getnome().compareTo(pivo.getnome()) < 0))) {
                i = (i == null) ? low : i.prox;
                trocar(i, j);
            }
        }
        i = (i == null) ? low : i.prox;
        trocar(i, high);
        return i;
    }
    void ordenar(Celula low, Celula high) {
        if (high != null && low != high && low != high.prox) {
            Celula p = particionar(low, high);
            ordenar(low, p.ant);
            ordenar(p.prox, high);
        }
    }
    Celula obterUltimaCelula() {
        Celula temp = primeiro;
        while (temp.prox != null) {
            temp = temp.prox;
        }
        return temp;
    }
    void quicksort() {
        Celula last = obterUltimaCelula();
        ordenar(primeiro.prox, last);
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
    int compareTo(Personagem other) {
        if(this.casa == other.casa){
            return this.nome.compareTo(other.nome);
        }
        return this.casa.compareTo(other.casa);
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
        System.out.println("["+this.getId()+ " ## "+ this.getnome()+ " ## "+arrayPrintado+ " ## "+this.getcasa()+ " ## "+this.getAncestry()+ " ## "+this.getespecie()+ " ## "+this.getpatrono()+ " ## "+this.getHogwartsStaff()+ " ## "+this.getHogwartsStudent()+ " ## "+this.getnomeAtor()+ " ## "+this.getstatus()+ " ## "+dataFormatada+ " ## "+this.getYear()+ " ## "+this.getcorOlho()+ " ## "+this.getgenero()+ " ## "+this.getcorCabelo()+ " ## "+this.getbruxo()+"]");
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
                int ind = p;
                int end = j;



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
public class TP3Q11 {

    public static boolean checkEnd(String entrada){
        boolean check = true;
        if(entrada.charAt(0) == 'F' && entrada.charAt(1) == 'I' && entrada.charAt(2) == 'M'){
            check = false;
        }
        return check;
    }

    public static boolean igual(String s1, String s2){
        boolean check = false;
        int count = 0;
        if (s1.length() == s2.length()) {
            for(int i = 0; i<s1.length();i++){
                if(s1.charAt(i) == s2.charAt(i)){
                    count++;
                }
            }
        }
        if(count == s1.length()){
            check = true;
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

    public static void sequencial(Personagem[] p1, String nome){
        boolean found = false;
        for(int i = 0; i< p1.length && found == false; i++){
            if(p1[i].getnomeAtor().compareTo(nome) == 0){
                found = true;
                System.out.println("SIM");
            }
        }
        if(!found){
            System.out.println("NAO");
        }
    }

    public static void swap(Personagem[] registros,int i, int j){
        Personagem aux = registros[i];
        registros[i] = registros[j];
        registros[j] = aux;
    }

    public static void insercao(Personagem[] registros) {
        try{
            FileWriter writer = new FileWriter("808238_insercao.txt",true);
            float startTime = System.nanoTime();
            int comp = 0;
            int mov = 0;
            int n = registros.length;
            for (int i = 1; i < n; i++) {
                //declaração de variavel temporaria para comparar com j
                Personagem tmp = registros[i]; 
                int j = i - 1;
                //comparação de tmp com seus antecessores
                while (j >= 0 && (registros[j].getDate().compareTo(tmp.getDate()) > 0 || (registros[j].getDate().compareTo(tmp.getDate()) == 0 && registros[j].getnome().compareTo(tmp.getnome()) > 0))) {
                    comp +=2;
                    registros[j + 1] = registros[j];
                    mov++;
                    j--;
                }
                comp +=4;
                registros[j + 1] = tmp; 
                mov++;
            }
            float endTime = System.nanoTime();
            float duration = (endTime-startTime)/1000000;
            writer.write("808238"+ "\t" + duration + "\t" + comp + "\t"+ mov + "\t");
            writer.close();
    }catch(IOException e){
        e.printStackTrace();
    }
    }

    public static void mergesort(Personagem[] array, int esq, int dir) {
        if (esq < dir) {
            int meio = (esq + dir) / 2;
            mergesort(array, esq, meio);
            mergesort(array, meio + 1, dir);
            intercalar(array, esq, meio, dir);
        }
    }
    
    public static void intercalar(Personagem[] array, int esq, int meio, int dir) {
        try{
        FileWriter writer = new FileWriter("808238_mergesort.txt",true);
        float startTime = System.nanoTime();
        int comp = 0;
        int mov = 0;
        // Definir tamanho dos dois subarrays
        int nEsq = meio - esq + 1;
        int nDir = dir - meio;
    
        Personagem[] arrayEsq = new Personagem[nEsq + 1];
        Personagem[] arrayDir = new Personagem[nDir + 1];
    
        // Inicializar primeiro subarray
        for (int i = 0; i < nEsq; i++) {
            arrayEsq[i] = array[esq + i];
        }
    
        // Inicializar segundo subarray
        for (int i = 0; i < nDir; i++) {
            arrayDir[i] = array[meio + 1 + i];
        }
    
        // Sentinelas no final dos dois arrays
        Personagem sentinela = new Personagem(); // Supondo que você tenha um construtor que defina nome para algo muito grande
        sentinela.setnomeAtor("\uFFFF"); // Caractere de alto valor Unicode
        sentinela.setnome("\uFFFF");
        arrayEsq[nEsq] = arrayDir[nDir] = sentinela;
    
        // Intercalação propriamente dita
        int iEsq = 0, iDir = 0;
        for (int i = esq; i <= dir; i++) {
            int compareResult = arrayEsq[iEsq].getnomeAtor().compareTo(arrayDir[iDir].getnomeAtor());
            comp++;
            if (compareResult < 0 || (compareResult == 0 && arrayEsq[iEsq].getnome().compareTo(arrayDir[iDir].getnome()) <= 0)) {
                comp+=2;
                array[i] = arrayEsq[iEsq++];
                mov++;
            } else {
                array[i] = arrayDir[iDir++];
                mov++;
            }
        }
        float endTime = System.nanoTime();
        float duration = (endTime-startTime)/1000000;
        writer.write("808238"+ "\t" + duration + "\t" + comp + "\t" + mov + "\t");
        writer.close();
        }catch(IOException e){
            e.printStackTrace();;
        }
    }

    public static void selecao(Personagem[] registros){
        try{
        FileWriter writer = new FileWriter("808238_selecao.txt",true);
        float startTime = System.nanoTime();
        int n = registros.length;
        int k = 10;
        int comp = 0;
        for(int i = 0; i<k;i++){
            int menor = i;
            for(int j = i; j<n;j++){
                if(registros[menor].getnome().compareTo(registros[j].getnome()) > 0){
                    comp++;
                    menor = j;
                }
            }
            swap(registros,menor,i);


        }
        float endTime = System.nanoTime();
        float duration = (endTime-startTime)/1000000;
        writer.write("808238"+ "\t" + duration + "\t" + comp + "\t");
        writer.close();
        }catch(IOException e){
            e.printStackTrace();;
        }
    }
    static String parseOption(String s) {
        StringBuilder aux = new StringBuilder();
        for (int i = 0; i < 1; i++) {
            aux.append(s.charAt(i));
        }
        return aux.toString();
    }
    
    static String parseID(String s){
        StringBuilder aux = new StringBuilder();
        for(int i = 2; i<s.length(); i++){
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
        while(checkEnd(id)){
            Personagem teste = new Personagem();
            teste.ler(id);
            registros = aumentarArray(registros,teste);
            newLista.inserirInicio(teste);
            n++;
            id = sc.nextLine();
        }
        newLista.quicksort();
        newLista.printar();

        sc.close();

    }

    
}