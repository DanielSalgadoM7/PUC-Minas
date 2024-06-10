/*Crie um método iterativo que recebe uma string como parâmetro e retorna true se essa é um Palíndromo.

Na saída padrão, para cada linha de entrada, escreva uma linha de saída com SIM/NÃO indicando  
se a linha é um palíndromo. Destaca-se que uma linha de entrada pode ter caracteres não letras.*/

//Daniel Salgado Magalhães - 821429

class TP1Q01 {

    //função para comparar os caracteres da string normal e invertida
    public static boolean EhPalindromo(String entrada) {
        int esquerda = 0, direita = entrada.length()-1;
        while(esquerda<direita){
            if(entrada.charAt(esquerda) != entrada.charAt(direita)){
                return false;
            }
            esquerda++;
            direita--;
        }
        return true;
    }

    //função para determinar o FIM
    public static boolean isFim(String entrada) {
        return (entrada.length() == 3 && entrada.charAt(0) == 'F' && entrada.charAt(1) == 'I'
                && entrada.charAt(2) == 'M');
    }

    public static void main(String[] args) {
        String entrada;

        while(true) {
            entrada = MyIO.readLine();
            //sai do while caso a entrada seja FIM
            if(entrada.equals("FIM")){
                break;
            }
            if (EhPalindromo(entrada) == true) {
                MyIO.println("SIM");
            } else {
                MyIO.println("NAO");
            }
        } 

    }
}
