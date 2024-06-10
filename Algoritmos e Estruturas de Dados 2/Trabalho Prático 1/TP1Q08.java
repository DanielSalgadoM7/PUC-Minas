/*Faça um programa que leia um número inteiro n indicando o número de valores
 * reais que devem ser lidos e salvos sequencialmente em um arquivo texto. Após
 * a leitura dos valores, devemos fechar o arquivo. Em seguida, reabri-lo e
 * fazer a leitura de trás para frente usando os métodos getFilePointer e seek
 * da classe RandomAccessFile e mostre todos os valores lidos na tela. Nessa
 * questão, você não pode usar, arrays, strings ou qualquer estrutura de dados.
 * A entrada padrão é composta por um número inteiro n e mais n números reais. A
 * saída padrão corresponde a n números reais mostrados um por linha de saída.*/

// Daniel Salgado Magalhães - 821429

import java.io.*;

public class TP1Q08 {
    public static void main(String[] args) {
        int valorN;
        valorN = MyIO.readInt();
        
        try {
            // Cria o arquivo
            RandomAccessFile arq = new RandomAccessFile("arquivo.txt", "rw");

            // Escreve números no arquivo
            for (int i = 0; i < valorN; i++) {
                double valorNum = MyIO.readDouble();
                arq.writeDouble(valorNum);
            }

            // Fecha o arquivo
            arq.close();

            // Reabre o arquivo para leitura de trás para frente
            arq = new RandomAccessFile("arquivo.txt", "r");

            // Obtém o tamanho do arquivo
            long tamanho = arq.length();

            // Lê e mostra os valores de trás para frente
            for (long pos = tamanho - 8; pos >= 0; pos -= 8) {
                arq.seek(pos);
                double valorLido = arq.readDouble();
                if (valorLido == (int) valorLido) {
                    // Se o valor for um número inteiro, imprime como inteiro
                    MyIO.println((int) valorLido);
                } else {
                    // Se tiver ponto, vai imprimir como double
                    MyIO.println(valorLido);
                }
            }

            // Fecha o arquivo novamente
            arq.close();
        } catch (IOException e) {
            System.err.println("Erro de E/S: " + e.getMessage());
        }
    }
}
