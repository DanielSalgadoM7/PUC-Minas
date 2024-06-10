/*O Imperador Júlio César foi um dos principais nomes do Império Romano. Entre suas contribuições, temos um algoritmo de criptografia chamado Ciframento de César. 
Segundo os historiadores, César utilizava esse algoritmo para criptografar as mensagens que enviava aos seus generais durante as batalhas. 
A ideia básica é um simples deslocamento de caracteres.


Assim, por exemplo, se a chave utilizada para criptografar as mensagens for 3, todas as ocorrências do caractere a são substituídas pelo caractere d, as do b por e, e assim sucessivamente.


Crie um método ITERATIVO que recebe uma string como parâmetro e retorna outra contendo a entrada de forma cifrada. Neste exercício, suponha a chave de ciframento três.
Na saída padrão, para cada linha de entrada, escreva uma linha com a mensagem criptografada.*/ 

//Daniel Salgado Magalhães = 821429

public class TP1Q03 {
    public static void main(String[] args) {
        String entrada;

        while(true){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }
            MyIO.println(ciframento(entrada));
        }

    }   

    //função de ciframento
    public static String ciframento(String entrada){
        String entradaCif = "";
        for(int i=0;i<entrada.length();i++){
            //transforma a letra de cada posição em um número para adicionar + 3
            int posicao = (int)entrada.charAt(i)+3;
            //volta o número da letra para a letra em si
            entradaCif += (char)posicao; 
        }
        return entradaCif;
    }
}
