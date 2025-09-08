//Daniel Salgado - 821429

import java.util.Scanner;

class Palindromo {

    //função para inverter a string recebida
    public static int inverteString(String palavra) {

        String palavraInvertida = new StringBuilder(palavra).reverse().toString();

        if (palavra.equals(palavraInvertida)) {
            return 1;
        } else {
            return 0;
        }
    }

    //função para determinar o FIM
    public static boolean isFim(String palavra) {
        return (palavra.length() == 3 && palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I'
                && palavra.charAt(2) == 'M');
    }

    public static void main(String[] args) {

        Scanner sc;
        sc = new Scanner(System.in);

        String palavra;

        do {
            palavra = sc.nextLine();
            if(palavra.equals("FIM")){
                break;
            }
            if (inverteString(palavra) == 1) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        } while (isFim(palavra) == false);

        sc.close();
    }
}
