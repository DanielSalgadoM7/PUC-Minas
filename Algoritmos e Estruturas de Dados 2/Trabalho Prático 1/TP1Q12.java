/*O Imperador Júlio César foi um dos principais nomes do Império Romano. Entre suas contribuições, temos um algoritmo de criptografia chamado Ciframento de César. 
Segundo os historiadores, César utilizava esse algoritmo para criptografar as mensagens que enviava aos seus generais durante as batalhas. 
A ideia básica é um simples deslocamento de caracteres.

Assim, por exemplo, se a chave utilizada para criptografar as mensagens for 3, todas as ocorrências do caractere a são substituídas pelo caractere d, as do b por e, e assim sucessivamente.

Crie um método ITERATIVO que recebe uma string como parâmetro e retorna outra contendo a entrada de forma cifrada. Neste exercício, suponha a chave de ciframento três.
Na saída padrão, para cada linha de entrada, escreva uma linha com a mensagem criptografada.*/ 

//Daniel Salgado Magalhães = 821429

public class TP1Q12 {
    public static void main(String[] args) {
        String entrada;

        while(true){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }
            MyIO.println(ciframentoRecursivo(entrada));
        }
    }

    //inicializa e fica chamando o método
    static String ciframentoRecursivo(String entrada){
        return ciframentoRecursivo(entrada, 0,"");
    }

    //função recursiva do ciframento
    static String ciframentoRecursivo(String entrada, int pos, String entradaCif){
        if(pos == entrada.length()){
            return entradaCif;//quando a posição atingir o tamanho final da entrada, ele retorna a entrada cifrada
        }else{
            entradaCif += (char) ((int)entrada.charAt(pos)+3);
            return ciframentoRecursivo(entrada, pos + 1, entradaCif); // vai incrementando cada letra na palavra cifrada
        }
    }
}
