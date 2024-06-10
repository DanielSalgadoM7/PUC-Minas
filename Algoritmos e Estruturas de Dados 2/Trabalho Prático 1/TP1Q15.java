/*Crie um método recursivo que recebe uma string e retorna true se a mesma é composta somente por vogais. 
Crie outro método recursivo que recebe uma string e retorna true se a mesma é composta somente por consoantes. 
Crie um terceiro método recursivo que recebe uma string e retorna true se a mesma corresponde a um número inteiro. 
Crie um quarto método recursivo que recebe uma string e retorna true se a mesma corresponde a um número real. 
Na saída padrão, para cada linha de entrada, escreva outra de saída da seguinte forma X1 X2 X3 X4 onde cada Xi é um 
booleano indicando se a é entrada é: composta somente por vogais (X1); composta somente somente por consoantes (X2); 
um número inteiro (X3); um número real (X4). Se Xi for verdadeiro, seu valor será SIM, caso contrário, NÃO.*/

//Daniel Salgado Magalhães - 821429

public class TP1Q15 {
    public static void main(String[] args) {
        String entrada;

        while (true) {
            entrada = MyIO.readLine();
            if (entrada.equals("FIM")) {
                break;
            }
            MyIO.print(isVogal(entrada) ? "SIM " : "NAO ");
            MyIO.print(isConsoante(entrada) ? "SIM " : "NAO ");
            MyIO.print(isInteiro(entrada) ? "SIM " : "NAO ");
            MyIO.println(isReal(entrada) ? "SIM" : "NAO");
        }
    }

    // métodos recursivos para verificar se só tem vogais
    static boolean isVogal(String entrada) {
        return isVogal(entrada, 0);
    }

    static boolean isVogal(String entrada, int pos) {
        entrada = entrada.toLowerCase();
        if (pos >= entrada.length()) {
            return true;
        } else if (entrada.charAt(pos) != 'a' && entrada.charAt(pos) != 'e' && entrada.charAt(pos) != 'i'
                && entrada.charAt(pos) != 'o' && entrada.charAt(pos) != 'u') {
            return false;
        }
        return isVogal(entrada, pos + 1);
    }

    // métodos recursivos para verificar se só tem consoantes
    static boolean isConsoante(String entrada) {
        return isConsoante(entrada, 0);
    }

    static boolean isConsoante(String entrada, int pos) {
        entrada = entrada.toLowerCase();
        if (pos >= entrada.length()) {
            return true;
        } else if ((entrada.charAt(pos) == 'a' || entrada.charAt(pos) == 'e' || entrada.charAt(pos) == 'i'
                || entrada.charAt(pos) == 'o' || entrada.charAt(pos) == 'u'
                || entrada.charAt(pos) >= 48 && entrada.charAt(pos) <= 57)) {
            return false;
        }
        return isConsoante(entrada, pos + 1);
    }

    // métodos recursivos para verificar se só tem números inteiros
    static boolean isInteiro(String entrada) {
        return isInteiro(entrada, 0);
    }

    static boolean isInteiro(String entrada, int pos) {
        entrada = entrada.toLowerCase();
        if (pos >= entrada.length()) {
            return true;
        } else if (!(entrada.charAt(pos) >= 48 && entrada.charAt(pos) <= 57)) {
            return false;
        }
        return isInteiro(entrada, pos + 1);
    }

    // métodos recursivos para verificar se só tem números reais
    static boolean isReal(String entrada) {
        return isReal(entrada, 0, 0);
    }

    static boolean isReal(String entrada, int pos, int cont) {
        entrada = entrada.toLowerCase();
        if (pos >= entrada.length()) {
            return true;
        } else if (cont > 1|| !((entrada.charAt(pos) >= 48 && entrada.charAt(pos) <= 57) || entrada.charAt(pos) == ',' || entrada.charAt(pos) == '.')) {
            return false;//retorna falso se não for uma letra ou ',' ou '.'.
        } else if(entrada.charAt(pos) == ',' || entrada.charAt(pos) == '.'){
            return isReal(entrada, pos+1, cont+1); //se é ',' ou '.', retorna o método incrementando pos e cont
        }else{
            return isReal(entrada, pos + 1, cont); //senão, retorna incrementando apenas a pos
        }
    }
}
