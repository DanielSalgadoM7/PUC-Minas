/*Complete o código da classe matriz dinâmica visto na sala de aula. A primeira tarefa consiste em, no construtor da classe Matriz, dados os números de linha e coluna, 
fazer as devidas alocações de células. As demais tarefas são as implementações dos métodos Matriz soma(Matriz), Matriz multiplicacao(Matriz), void mostrarDiagonalPrincipal() 
e void mostrarDiagonalSecundaria(). A entrada padrão é composta por vários casos de teste sendo que o número de casos é um inteiro contido na primeira linha da entrada.
Em seguida, temos cada um dos casos de teste. Cada caso é composto por duas matrizes. Para cada caso de teste, temos que suas duas primeiras linhas contêm um número inteiro 
cada representando os números de linhas e de colunas da primeira matriz, respectivamente. Em seguida, temos os elementos da primeira matriz que estão representados nas próximas 
l linhas onde l é o número de linhas dessa matriz. Cada uma dessas linhas têm c colunas onde c é o número de colunas dessa matriz. Nas duas linhas seguintes, 
temos os números de linhas e colunas da segunda matriz do caso de teste. As l2 linhas seguintes têm c2 colunas contendo os elementos da segunda matriz. l2 e c2 correspondem aos 
números de linhas e colunas da segunda matriz do caso de teste, respectivamente.



A saída padrão contém várias linhas para cada caso de teste. As duas primeiras linhas de saída de um caso de teste correspondem às diagonais principal e secundaria da primeira 
matriz, respectivamente. As demais ls linhas de um caso de teste correspondem as linhas matriz obtida pela soma das duas matrizes do caso de teste sendo que essas linhas contêm 
cs colunas referentes às colunas da matriz de soma. Da mesma forma, as linhas seguintes do caso teste contêm lm linhas com cm colunas representando os elementos da matriz de 
multiplicação onde lm e cm são os números de linhas e colunas da matriz de multiplicação. */

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.util.Date;
import java.io.FileNotFoundException;
import java.text.SimpleDateFormat;
import java.text.ParseException;

class Celula{
    public int elemento;
    public Celula dir;
    public Celula esq;
    public Celula sup;
    public Celula inf;

    
    public Celula(){
        this.elemento = 0;
        this.dir = null;
        this.esq = null;
        this.sup = null;
        this.inf = null;
    }
    public Celula(int x){
        this.elemento = x;
        this.dir = null;
        this.esq = null;
        this.sup = null;
        this.inf = null;
    }
}

class MatrizFlexivel{
    private Celula inicio;
    private int linha,coluna;
    public MatrizFlexivel(){
        this(3,3);
    }
    public MatrizFlexivel(int linhas, int colunas){
       inicio = new Celula(0);
       this.linha = linhas;
       this.coluna = colunas;
       Celula i = inicio;
       for(int j = 1; j< this.coluna; j++){
        Celula nova = new Celula(0);
        i.dir = nova;
        nova.esq = i;
        i = nova;
       }

       Celula linhaAnterior = inicio;
       for(int k = 1; k<this.linha; k++){
        Celula novaLinha = new Celula(0);
        linhaAnterior.inf = novaLinha;
        novaLinha.sup = linhaAnterior;

        Celula celulaAtualLinha = novaLinha;
        Celula celulaAcima = linhaAnterior;
        for(int j = 1; j<this.coluna; j++){
            Celula novaCelula = new Celula(0);
            celulaAtualLinha.dir = novaCelula;
            novaCelula.esq = celulaAtualLinha;

            celulaAcima = celulaAcima.dir;
            celulaAcima.inf = novaCelula;
            novaCelula.sup = celulaAcima;

            celulaAtualLinha=novaCelula;
        }
        linhaAnterior = novaLinha;
       }
    

    }

    public void printar(){
        Celula i = inicio;
        Celula sentinela = inicio;
        for(int j = 0; j<linha;j++){
            for(int k = 0;k<coluna;k++){
                System.out.print(i.elemento+ " ");
                i = i.dir;
            }
            sentinela = sentinela.inf;
            i = sentinela;
            System.out.println();
        }
    }

    public void diagPrincipal(){
        Celula j = inicio;
        while(j.dir!= null){
            System.out.print(j.elemento+" ");
            j = j.inf;
            j = j.dir;
        }
        System.out.print(j.elemento+" ");
    }

    public void insert(int x){
        Celula j = inicio;
        Celula acompanharInicio = inicio;
        while(j.elemento!= 0){
            j = j.dir;
            if(j==null){
                acompanharInicio = acompanharInicio.inf;
                j = acompanharInicio;
                if(j == null && acompanharInicio == null){
                    System.out.println("LISTA CHEIA");
                    break;
                }
            }
        }
        j.elemento = x;
    }
    public void diagSecundaria(){
        System.out.println();
        Celula j = inicio;
        int count = 0;
        while(j.dir!= null){
            j = j.dir;
        }
        while(j.esq!= null){
            System.out.print(j.elemento + " ");
            j = j.inf;
            j = j.esq;
        }
        System.out.println(j.elemento);


    }    
    public MatrizFlexivel somarComOutraMatriz(MatrizFlexivel outra){
        MatrizFlexivel soma = new MatrizFlexivel(this.linha, this.coluna);
        Celula percorreSoma = soma.inicio;
        Celula percorreMatriz= this.inicio;
        Celula percorreOutra = outra.inicio;
        Celula percorreLinhaMatriz = this.inicio;
        Celula percorreLinhaSoma = soma.inicio;
        Celula percorreLinhaOutra = outra.inicio;
        for(int i = 0; i< this.linha; i++){
            for(int j = 0; j<this.coluna;j++){
                percorreSoma.elemento = percorreMatriz.elemento+percorreOutra.elemento;
                percorreSoma = percorreSoma.dir;
                percorreOutra = percorreOutra.dir;
                percorreMatriz = percorreMatriz.dir;
            }
            percorreLinhaMatriz = percorreLinhaMatriz.inf;
            percorreLinhaOutra = percorreLinhaOutra.inf;
            percorreLinhaSoma = percorreLinhaSoma.inf;
            percorreSoma=percorreLinhaSoma;
            percorreOutra = percorreLinhaOutra;
            percorreMatriz = percorreLinhaMatriz;
        }
        return soma;
    }
    public MatrizFlexivel multiplicarComOutraMatriz(MatrizFlexivel outra) {
        if (this.coluna != outra.linha) {
            throw new IllegalArgumentException("As matrizes não podem ser multiplicadas");
        }
    
        MatrizFlexivel produto = new MatrizFlexivel(this.linha, outra.coluna);
    
        Celula percorreProdutoLinha = produto.inicio;
        Celula percorreMatrizLinha = this.inicio;
        Celula OutraSentinela = outra.inicio;
    
        for (int i = 0; i < this.linha; i++) {
            Celula percorreProdutoColuna = percorreProdutoLinha;
            for (int j = 0; j < outra.coluna; j++) {
                int soma = 0;
                Celula percorreMatriz = percorreMatrizLinha;
                Celula percorreOutra = OutraSentinela;
    
                for (int k = 0; k < this.coluna; k++) {
                    soma += percorreMatriz.elemento * percorreOutra.elemento;
                    percorreMatriz = percorreMatriz.dir;
                    percorreOutra = percorreOutra.inf;
                }
    
                percorreProdutoColuna.elemento = soma;
                percorreProdutoColuna = percorreProdutoColuna.dir;
                OutraSentinela = OutraSentinela.dir; 
            }
    
            percorreMatrizLinha = percorreMatrizLinha.inf; 
            OutraSentinela = outra.inicio; 
            percorreProdutoLinha = percorreProdutoLinha.inf;
        }
    
        return produto;
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
        String path = "tmp/characters.csv";
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


    //Outros métodos para verificar o nome
    public void addnome(String nome){
        this.nomeAlternativo.add(nome);
    }
    
}
public class TP3Q09 {

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
        int input = sc.nextInt();
        for(int i = 0; i<input; i++){
            int linhaMatriz1 = sc.nextInt();
            int colunaMatriz1 = sc.nextInt();
            sc.nextLine();
            MatrizFlexivel Matriz1= new MatrizFlexivel(linhaMatriz1,colunaMatriz1);
            for(int j = 0; j<linhaMatriz1; j++){
                String elementosPorLinha = sc.nextLine();
                String[] elementos = elementosPorLinha.split(" ");
                for(String elemento : elementos){
                    Matriz1.insert(Integer.parseInt(elemento));
                }
            }
            int linhaMatriz2 = sc.nextInt();
            int colunaMatriz2 = sc.nextInt();
            sc.nextLine();
            MatrizFlexivel Matriz2= new MatrizFlexivel(linhaMatriz2,colunaMatriz2);
            for(int j = 0;j<linhaMatriz2; j++){
                String elementosPorLinha = sc.nextLine();
                String[] elementos = elementosPorLinha.split(" ");
                for(String elemento : elementos){
                    Matriz2.insert(Integer.parseInt(elemento));
                }
            }
            Matriz1.diagPrincipal();
            Matriz1.diagSecundaria();
            MatrizFlexivel somaDasMatrizes = Matriz1.somarComOutraMatriz(Matriz2);
            somaDasMatrizes.printar();
            MatrizFlexivel multiplicarMatrizes = Matriz1.multiplicarComOutraMatriz(Matriz2);
            multiplicarMatrizes.printar();

        }

        sc.close();

    }

}