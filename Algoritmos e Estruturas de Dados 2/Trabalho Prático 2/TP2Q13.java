/*Repita a questão de Ordenação por Seleção, contudo, usando o algoritmo Counting Sort, 
fazendo com que a chave de pesquisa seja o atributo yearOfBirth. 
O nome do arquivo de log será matrícula_countingsort.txt.*/

//Daniel Salgado Magalhães - 821429

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class TP2Q13 {
    static int mov = 0;
    static int comp = 0;

    public static void main(String args[]) throws Exception {

        long startTime = System.currentTimeMillis();
        Personagem[] vetor = new Personagem[100];
        int pos = 0;

        for (int i = 0; i < 27; i++) {
            String search = MyIO.readLine(); // search procura pelo CSV todo
            if (search.equals("FIM")) {
                break;
            }

            vetor[pos] = new Personagem();
            vetor[pos].setId(search);
            try {
                vetor[pos++].ler();
            } catch (Exception e) {
                System.err.println(e.getMessage());
            }
        }

        // ordenando pela primeira vez
        merge(vetor, pos);

        //ordenado pela segunda vez
        for(int i=1;i<pos;i++){
            ordenarNome(vetor, pos);
        }

        // imprime as informações ordenadas
        for (int i = 0; i < pos; i++) {
            vetor[i].imprimir();
        }

        long endTime = System.currentTimeMillis();
        long elapsedTime = endTime - startTime;
        double seconds = (double) elapsedTime / 1000.0;

        // informações do arquivo de log
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("matricula_mergesort.txt"))) {
            bw.write("821429\t" + comp + " comparações\t" + mov + " movimentações\t" + seconds + " segundos");
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void merge(Personagem vetor[], int pos) {
        mergeSort(vetor, 0, pos - 1);
    }

    public static void mergeSort(Personagem[] vetor, int esq, int dir) {
        if (esq < dir) {
            int meio = (esq + dir) / 2;
            mergeSort(vetor, esq, meio);
            mergeSort(vetor, meio + 1, dir);
            intercalar(vetor, esq, meio, dir);
        }
    }

    public static void intercalar(Personagem[] vetor, int esq, int meio, int dir) {
        // Definir tamanho dos dois subvetores
        int nEsq = (meio + 1) - esq;
        int nDir = dir - meio;

        Personagem[] vetorEsq = new Personagem[nEsq+1];
        Personagem[] vetorDir = new Personagem[nDir+1];

        // Sentinela no final dos dois vetores
        vetorEsq[nEsq] = vetorDir[nDir];

        int iEsq, iDir, i = 0;

        // Inicializar o primeiro subvetor
        for (iEsq = 0; iEsq < nEsq; iEsq++) {
            vetorEsq[iEsq] = vetor[esq + iEsq];
        }

        // Inicializar o segundo subvetor
        for (iDir = 0; iDir < nDir; iDir++) {
            vetorDir[iDir] = vetor[(meio + 1) + iDir];
        }

        // Intercalação propriamente dita
        int j = 0;
        int k = esq;
        while (i < nEsq && j < nDir) {
            if (vetorEsq[i].getNomeAtor().compareTo(vetorDir[j].getNomeAtor()) <= 0) {
                vetor[k] = vetorEsq[i];
                i++;
            } else {
                vetor[k] = vetorDir[j];
                j++;
            }
            k++;
        }

        // Copiar elementos restantes do subvetor esquerdo, se houver
        while (i < nEsq) {
            vetor[k] = vetorEsq[i];
            i++;
            k++;
        }

        // Copiar elementos restantes do subvetor direito, se houver
        while (j < nDir) {
            vetor[k] = vetorDir[j];
            j++;
            k++;
        }
    }

    //metódo para realizar a segunda ordenação(por nome)
    private static Personagem[] ordenarNome(Personagem[] vetor, int pos){
        for(int i = 1; i < pos; i++){
            Personagem temp = vetor[i];
            int j = i - 1;
            if(vetor[j].getNome().compareTo(temp.getNome()) > 0)
            {
                comp++;
                while((j >= 0) && (vetor[j].getNomeAtor() == temp.getNomeAtor()) && vetor[j].getNome().compareTo(temp.getNome()) > 0){
                    comp++;
                    vetor[j + 1] = vetor[j];
                    mov++;
                    j--;
                }
            }
            vetor[j + 1] = temp;
          mov++;
        }
        return vetor;
    }
}

class Personagem {

    // Atributos
    private String id;
    private String nome;
    private String nomeAlternativo;
    private String casa;
    private String ancestry;
    private String especie;
    private String patrono;
    private String hogwartsStaff;
    private String hogwartsStudent;
    private String nomeAtor;
    private String status;
    private String nomeAtorAlternativo;
    private LocalDate dataNascimento;
    private int anoNascimento;
    private String corOlho;
    private String genero;
    private String corCabelo;
    private String bruxo;

    // Construtores
    Personagem() {
        this("", "", "", "", "", "", "", "", "", "", "", "", LocalDate.of(1, 1, 1), 0, "", "", "", "");
    }

    Personagem(String id, String nome, String nomeAlternativo, String casa, String ancestry, String especie,
            String patrono, String hogwartsStaff,
            String hogwartsStudent, String nomeAtor, String status, String nomeAtorAlternativo,
            LocalDate dataNascimento, int anoNascimento, String corOlho,
            String genero, String corCabelo, String bruxo) {
        this.id = id;
        this.nome = nome;
        this.nomeAlternativo = nomeAlternativo;
        this.casa = casa;
        this.ancestry = ancestry;
        this.especie = especie;
        this.patrono = patrono;
        this.hogwartsStaff = hogwartsStaff;
        this.hogwartsStudent = hogwartsStudent;
        this.nomeAtor = nomeAtor;
        this.status = status;
        this.nomeAtorAlternativo = nomeAtorAlternativo;
        this.dataNascimento = dataNascimento;
        this.anoNascimento = anoNascimento;
        this.corOlho = corOlho;
        this.genero = genero;
        this.corCabelo = corCabelo;
        this.bruxo = bruxo;
    }

    // getters
    public String getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public String getNomeAlternativo() {
        return nomeAlternativo;
    }

    public String getCasa() {
        return casa;
    }

    public String getAncestry() {
        return ancestry;
    }

    public String getEspecie() {
        return especie;
    }

    public String getPatrono() {
        return patrono;
    }

    public String getHogwartsStaff() {
        return hogwartsStaff;
    }

    public String getHogwartsStudent() {
        return hogwartsStudent;
    }

    public String getNomeAtor() {
        return nomeAtor;
    }

    public String getStatus() {
        return status;
    }

    public String getNomeAtorAlternativo() {
        return nomeAtorAlternativo;
    }

    public LocalDate getDataNascimento() {
        return dataNascimento;
    }

    public int getAnoNascimento() {
        return anoNascimento;
    }

    public String getCorOlho() {
        return corOlho;
    }

    public String getGenero() {
        return genero;
    }

    public String getCorCabelo() {
        return corCabelo;
    }

    public String getBruxo() {
        return bruxo;
    }

    // setters
    public void setId(String id) {
        this.id = id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNomeAlternativo(String nomeAlternativo) {
        this.nomeAlternativo = nomeAlternativo;
    }

    public void setCasa(String casa) {
        this.casa = casa;
    }

    public void setAncestry(String ancestry) {
        this.ancestry = ancestry;
    }

    public void setEspecie(String especie) {
        this.especie = especie;
    }

    public void setPatrono(String patrono) {
        this.patrono = patrono;
    }

    public void setHogwartsStaff(String hogwartsStaff) {
        this.hogwartsStaff = hogwartsStaff;
    }

    public void setHogwartsStudent(String hogwartsStudent) {
        this.hogwartsStudent = hogwartsStudent;
    }

    public void setNomeAtor(String nomeAtor) {
        this.nomeAtor = nomeAtor;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public void setNomeAtorAlternativo(String nomeAtorAlternativo) {
        this.nomeAtorAlternativo = nomeAtorAlternativo;
    }

    public void setDataNascimento(LocalDate dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }

    public void setCorOlho(String corOlho) {
        this.corOlho = corOlho;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void setCorCabelo(String corCabelo) {
        this.corCabelo = corCabelo;
    }

    public void setBruxo(String bruxo) {
        this.bruxo = bruxo;
    }

    // método de clonar
    protected Personagem clone() throws CloneNotSupportedException {
        Personagem clone = new Personagem();
        clone.id = this.id;
        clone.nome = this.nome;
        clone.nomeAlternativo = this.nomeAlternativo;
        clone.casa = this.casa;
        clone.ancestry = this.ancestry;
        clone.especie = this.especie;
        clone.patrono = this.patrono;
        clone.hogwartsStaff = this.hogwartsStaff;
        clone.hogwartsStudent = this.hogwartsStudent;
        clone.nomeAtor = this.nomeAtor;
        clone.status = this.status;
        clone.nomeAtorAlternativo = this.nomeAtorAlternativo;
        clone.dataNascimento = this.dataNascimento;
        clone.anoNascimento = this.anoNascimento;
        clone.corOlho = this.corOlho;
        clone.genero = this.genero;
        clone.corCabelo = this.corCabelo;
        clone.bruxo = this.bruxo;
        return clone;
    }

    // método de imprimir
    // usar o date format desse jeito faz com que converta de YYYY-MM-dd para
    // dd-MM-YYYY
    public void imprimir() {
        System.out.println("[" + this.id + " ## " + this.nome + " ## {" + this.nomeAlternativo + "} ## " + this.casa
                + " ## " + this.ancestry + " ## " + this.especie + " ## " + this.patrono + " ## "
                + (this.hogwartsStaff.equals("VERDADEIRO") ? "true" : "false") + " ## "
                + (this.hogwartsStudent.equals("VERDADEIRO") ? "true" : "false") + " ## "
                + this.nomeAtor + " ## " + (this.status.equals("VERDADEIRO") ? "true" : "false") + " ## "
                + this.dataNascimento.format(DateTimeFormatter.ofPattern("dd-MM-yyyy")) + " ## " + this.anoNascimento
                + " ## " + this.corOlho + " ## " + this.genero + " ## " + this.corCabelo + " ## "
                + (this.bruxo.equals("VERDADEIRO") ? "true" : "false") + "]");
    }

    // método de leitura
    // método de leitura
    public void ler() throws IOException {
        // "D:/Daniel/Faculdade/Semestre 3/AEDS2/AEDS-2/TP2/characters.csv"
        // "/tmp/characters.csv"
        try {
            String nomeArquivo = "/tmp/characters.csv";
            FileReader fileReader = new FileReader(nomeArquivo);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String linha;
            boolean primeiraLinha = true; // Flag para controlar a primeira linha

            while ((linha = bufferedReader.readLine()) != null) {
                if (primeiraLinha) {
                    primeiraLinha = false;
                    continue; // Ignora a primeira linha com cabeçalhos
                }

                // separa a linha por campos, tendo como condição de separação o sinal ;
                String[] campos = linha.split(";");
                String id;
                try {
                    id = campos[0]; // id do personagem

                    if (id.equals(this.id)) {// O personagem com o ID desejado foi encontrado

                        this.nome = campos[1]; // Nome do personagem

                        if (campos.length > 2 && campos[2] != null && !campos[2].isEmpty()) {
                            String apelidosArray = campos[2].trim(); // Remove os espaços em branco extras

                            if (apelidosArray.startsWith("[") && apelidosArray.endsWith("]")) {
                                apelidosArray = apelidosArray.substring(1, apelidosArray.length() - 1); // Remove os
                                                                                                        // colchetes
                            }

                            // Verifica se o campo está vazio após remover colchetes
                            if (!apelidosArray.isEmpty()) {
                                StringBuilder nomeAlternativoBuilder = new StringBuilder();
                                String[] apelidosFinal = apelidosArray.split("',\\s*'"); // Isso divide os apelidos com
                                                                                         // base na ',' para tirar as
                                                                                         // aspas simples de cada
                                                                                         // apelido
                                for (String apelido : apelidosFinal) {// faz a string apelido percorrer tudo até
                                                                      // terminar o array apelidosFinal
                                    StringBuilder apelidoSemAspas = new StringBuilder();
                                    for (int i = 0; i < apelido.length(); i++) {
                                        if (apelido.charAt(i) != '\'') { // Adiciona apenas os caracteres que não são
                                                                         // aspas simples
                                            apelidoSemAspas.append(apelido.charAt(i));
                                        }
                                    }
                                    nomeAlternativoBuilder.append(apelidoSemAspas.toString()).append(", "); // Adiciona
                                                                                                            // o apelido
                                                                                                            // sem as
                                                                                                            // aspas à
                                                                                                            // lista
                                }
                                // Remove a vírgula e o espaço extras no final
                                String nomeAlternativo = nomeAlternativoBuilder.toString().trim();
                                nomeAlternativo = nomeAlternativo.substring(0, nomeAlternativo.length() - 1);

                                this.nomeAlternativo = nomeAlternativo; // Apelidos como uma String separada por
                                                                        // vírgulas
                            } else {
                                this.nomeAlternativo = ""; // String vazia se o campo estiver vazio
                            }
                        } else {
                            this.nomeAlternativo = ""; // String vazia se não houver apelidos
                        }

                        this.casa = campos[3]; // casa do personagem

                        this.ancestry = campos[4]; // "passado" do personagem

                        this.especie = campos[5]; // espécie do personagem

                        this.patrono = campos[6]; // patrono do personagem

                        this.hogwartsStaff = campos[7]; // verifica se é funcionário de
                                                        // Hogwarts

                        this.hogwartsStudent = campos[8]; // String que verifica se é estudante de Hogwarts

                        this.nomeAtor = campos[9]; // nome do Ator

                        this.status = campos[10]; // verifica se tá vivo ou morto

                        this.nomeAtorAlternativo = campos[11];

                        DateTimeFormatter[] formatters = {
                                DateTimeFormatter.ofPattern("dd-MM-yyyy"), // Verifica o formato dd-MM-yyyy
                                DateTimeFormatter.ofPattern("dd-M-yyyy") // Verifica o formato dd-M-yyyy (por causa de
                                                                         // erro em uma linha do csv)
                        };

                        for (DateTimeFormatter formatter : formatters) {
                            try {
                                this.dataNascimento = LocalDate.parse(campos[12], formatter);
                                break;// sai do loop se a data tiver no padrão
                            } catch (DateTimeParseException e) {
                                // vai pra outra tentativa se não for no padrão dd-MM-yyyy
                            }
                        }

                        // Se não é nenhuma das duas, vai ser a data padrão nula
                        if (this.dataNascimento == null) {
                            this.dataNascimento = null;
                        }

                        this.anoNascimento = Integer.parseInt(campos[13]); // ano de nascimento do personagemgem

                        this.corOlho = campos[14]; // cor de olho do personagem

                        this.genero = campos[15]; // gênero do personagem

                        this.corCabelo = campos[16]; // cor de cabelo do personagem

                        this.bruxo = campos[17]; // verifica se é bruxo

                        break; // Para de ler o arquivo assim que ler todas as informações do personagem
                    }

                } catch (NumberFormatException e) {
                    System.err.println("Erro ao converter um número: " + e.getMessage()); // erro de conversão de número
                }
            }

            bufferedReader.close(); // fecha o buffer
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }
}
