/*Desde que foi lançado oficialmente o Pomekon no Brasil, Dabriel está tentando realizar seu maior sonho: Ser um Mestre Pomekon. Sua meta é conquistar os 151 Pomekons disponíveis. Ele já conseguiu capturar muitos monstrinhos, porém em sua cidade aparecem muitos Pomekons repetidos, fazendo com que ele capture diversas vezes o mesmo Pomekon.

Vendo que sua mochila está bem cheia, Dabriel pediu para que você fizesse um programa de computador que informasse a ele quantos Pomekons faltam para completar a coleção.

Entrada
A primeira linha do caso de teste consiste de um inteiro N (1 ≤ N ≤ 10³), representando a quantidade de Pomekons que Dabriel já capturou.
As próximas N linhas consistem de uma string S (1 ≤ |S| ≤ 10³), representando o nome de cada Pomekons. O nome de cada Pomekons consiste apenas de letras maiúsculas e minúsculas.

Saída
Você deverá imprimir: "Falta(m) X pomekon(s).", onde X representa a quantidade Pomekons não capturados. */

//Daniel Salgado Magalhães - 821429

public class ColecaoPomekon {
    public static void main(String[] args){
        int qnt =  0, contador = 0;
        qnt = MyIO.readInt();

        String[] entrada = new String[qnt];

        for(int i=0;i<qnt;i++){
            entrada[i] = MyIO.readLine();
        }

        for(int i=0;i<qnt;i++){
            for(int j=i+1;j<qnt;j++){
                if(entrada[i].equals(entrada[j])){
                    contador++;
                    break;
                }
            }
        }
        int pomekonFaltando = 151 - (qnt - contador);
        MyIO.print("Falta(m) " + pomekonFaltando + " pomekon(s).");
    }
}
