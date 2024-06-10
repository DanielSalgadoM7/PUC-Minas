/*
* Arthur Martinho Medeiros Oliveira - 813168
* Caio Gomes Alcantara Gloria - 763989
* Daniel Salgado Magalhães - 821429
* Gabriel Henrique Vieira de Oliveira - 775799
*/

import java.io.*;

public class EP4 {
    public static void main(String[] args) throws Exception {
        
        // inicialização das variaveis 
        char X = ' ', Y = ' ';

        //abre o arquivo para leitura
        String arquivo = "testeula.ula";
        String arquivoSaida = "testeula.hex";

        try (BufferedReader br = new BufferedReader(new FileReader(arquivo));
        BufferedWriter bw = new BufferedWriter(new FileWriter(arquivoSaida))) {

            String linha; // linha de comando que vai ser lida

            // loop que vai começar a interpretar o arquivo apenas quando inicio: for digitado
            while (!((linha = br.readLine()).equals("inicio:"))) {
            }

            // Lê cada linha do arquivo até atingir o final
            while (!((linha = br.readLine()).equals("fim."))) {
               
                if(linha.charAt(0) == 'X'){ 
                    // Se o primeiro caractere da string for 'X' atribui o caractere da terceira posição
                    X = linha.charAt(2);
                }
                if(linha.charAt(0) == 'Y'){
                    // Se o primeiro caractere da string for 'Y' atribui o caractere da terceira posição
                    Y = linha.charAt(2);
                }
                if(linha.charAt(0) == 'W'){
                    // Se o primeiro caractere da string for 'W' atribui tudo que esta entre '=' e ';'
                    String S = extrairParteSelecionada(linha);
                    // Apos extrair o mineminico converte para o valor em Hexa de acordo com a tabela
                    char SHexa = conversorS(S);
                    String operacao = "";// Comando que vai ser escrito no arquivo
                    // Adiciona ao comando X, Y e S respectivamente
                    operacao+=X;
                    operacao+=Y;
                    operacao+=SHexa;
                    bw.write(operacao);// Escreve a operação no .hex
                    bw.newLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //função para obter valor de S;
    public static String extrairParteSelecionada(String entrada) {
        int indiceInicial = entrada.indexOf("="); // Encontra o índice do caractere "="
        int indiceFinal = entrada.indexOf(";"); // Encontra o índice do caractere ";"

        // Verifica se ambos os caracteres foram encontrados
        if (indiceInicial != -1 && indiceFinal != -1) {
            // Adiciona 1 ao índice inicial para ignorar o caractere "="
            // Retorna a parte selecionada da string
            return entrada.substring(indiceInicial + 1, indiceFinal);
        } else {
            // Retorna uma string vazia se os caracteres não forem encontrados
            return "";
        }
    }

    //método de conversão
    public static char conversorS(String S){
        char SHexa = 'z';

        if(S.equals("nB")){
            SHexa = '0';
            return SHexa;
        }
        if(S.equals("nAeBn")){
            SHexa = '1';
            return SHexa;
        }
        if(S.equals("nAeB")){
            SHexa = '2';
            return SHexa;
        }
        if(S.equals("Lzero")){
            SHexa = '3';
            return SHexa;
        }
        if(S.equals("AeBn")){
            SHexa = '4';
            return SHexa;
        }
        if(S.equals("nA")){
            SHexa = '5';
            return SHexa;
        }
        if(S.equals("AXB")){
            SHexa = '6';
            return SHexa;
        }
        if(S.equals("AenB")){
            SHexa = '7';
            return SHexa;
        }
        if(S.equals("nAonB")){
            SHexa = '8';
            return SHexa;
        }
        if(S.equals("nAXnB")){
            SHexa = '9';
            return SHexa;
        }
        if(S.equals("Bcopia")){
            SHexa = 'A';
            return SHexa;
        }
        if(S.equals("AeB")){
            SHexa = 'B';
            return SHexa;
        }
        if(S.equals("Lum")){
            SHexa = 'C';
            return SHexa;
        }
        if(S.equals("AonB")){
            SHexa = 'D';
            return SHexa;
        }
        if(S.equals("AoB")){
            SHexa = 'E';
            return SHexa;
        }
        if(S.equals("Acopia")){
            SHexa = 'F';
            return SHexa;
        }

        return SHexa;
    }
}