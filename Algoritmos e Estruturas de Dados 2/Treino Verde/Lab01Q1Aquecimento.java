/*Crie um método ITERATIVO em Java que receba como parâmetro uma string e retorne seu número de caracteres maiúsculos. 
Em seguida, teste o método anterior usando redirecionamento de entrada e saída. 
A entrada padrão é composta por várias linhas sendo que a última contém a palavra FIM.  
A saída padrão contém um número inteiro para cada linha de entrada.*/

//Daniel Salgado Magalhães - 821429

import java.util.Scanner;

class Lab01Q1Aquecimento {

    // função para determinar o FIM
    public static boolean isFim(String palavra) {
        return (palavra.length() == 3 && palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I'
                && palavra.charAt(2) == 'M');
    }

    // função para determinar se a letra é maiúscula
    public static boolean isMaiscula(char letra) {
        if(letra >= 'A' && letra <= 'Z'){
            return true;
        } 
        return false;
    }

    // função para contar as letras maiúsculas, percorre cada letra da palavra, chamando a função isMaiscula
    public static int contMaiuscula(String entrada) {
        int cont = 0;

        for (int i = 0; i < entrada.length(); i++) {
            if (isMaiscula(entrada.charAt(i)) == true) {
                cont++;
            }
        }
        return cont;
    }

    public static void main(String[] args) {

        String[] palavra = new String[1000];
        int numEntrada = 0;

        Scanner sc = new Scanner(System.in);

        // leitura padrão até condição de parada
        do {
            palavra[numEntrada] = sc.nextLine();
        } while (isFim(palavra[numEntrada++]) == false);

        //como estava contando a quantidade de letras do FIM, adicionei -1 no for, tirando a contagem dele
        for (int i = 0; i < numEntrada - 1 ; i++) {
            System.out.println(contMaiuscula(palavra[i]));
        }

        sc.close();
    }
}
