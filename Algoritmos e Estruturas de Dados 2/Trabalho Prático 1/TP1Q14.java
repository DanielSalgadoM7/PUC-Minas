/*Crie um método recursivo que recebe uma string contendo uma expressão booleana e o valor de suas entradas e retorna um booleano indicando se a 
expressão é verdadeira ou falsa. Cada string de entrada é composta por um número inteiro n indicando o número de entradas da expressão booleana 
corrente. Em seguida, a string contém n valores binários (um para cada entrada) e a expressão booleana. 
Na saída padrão, para cada linha de entrada, escreva uma linha de saída com SIM / NÃO indicando se a expressão corrente é verdadeira ou falsa. */

//Daniel Salgado Magalhães - 821429

public class TP1Q14 {
    public static void main(String[] args) {
        boolean notFim;
        int quantNumeros;
        String entradaString = new String();
        char[] entradaChar = new char[1000];

        do {
            quantNumeros = MyIO.readInt();
            notFim = notFim(quantNumeros);
            if (notFim) {
                String[] listaValores = lerValores(quantNumeros);
                entradaString = MyIO.readLine();
                str2char(entradaString, entradaChar);
                int tam = entradaString.length();
                tam = removerEspacos(entradaChar, tam);
                trocar(entradaChar, listaValores, tam);
                char resp = algebraBooleana(entradaChar, tam);
                MyIO.println(resp);
            }
        } while (notFim);
    }

    public static boolean notFim(int quantNumeros) {
        return quantNumeros != 0;
    }

    public static void str2char(String entradaString, char[] entradaChar) {
        str2char(entradaString, entradaChar, 0);
    }

    public static void str2char(String entradaString, char[] entradaChar, int pos) {
        if (pos < entradaString.length()) {
            entradaChar[pos] = entradaString.charAt(pos);
            str2char(entradaString, entradaChar, pos + 1);
        }
    }

    public static int removerEspacos(char[] entradaChar, int tam) {
        return removerEspacos(entradaChar, tam, 0);
    }

    public static int removerEspacos(char[] entradaChar, int tam, int pos) {
        if (pos < tam) {
            if (entradaChar[pos] == ' ' || entradaChar[pos] == ',') {
                for (int j = pos; j < tam - 1; j++) {
                    entradaChar[j] = entradaChar[j + 1];
                }
                entradaChar[tam] = '\0';
                return removerEspacos(entradaChar, tam - 1, pos);
            } else {
                return removerEspacos(entradaChar, tam, pos + 1);
            }
        }
        return tam;
    }

    public static void trocar(char[] entradaChar, String[] listaValores, int tam) {
        trocar(entradaChar, listaValores, tam, 0, 0);
    }

    public static void trocar(char[] entradaChar, String[] listaValores, int tam, int pos, int listapos) {
        if (listapos < listaValores.length) {
            if (pos < tam) {
                if ((int) entradaChar[pos] == listapos + 65) {
                    entradaChar[pos] = listaValores[listapos].charAt(0);
                }
                trocar(entradaChar, listaValores, tam, pos + 1, listapos);
            } else {
                trocar(entradaChar, listaValores, tam, 0, listapos + 1);
            }
        }
    }

    public static String[] lerValores(int quantValores) {
        String[] listaValores = new String[quantValores];
        return lerValores(listaValores, quantValores, 0);
    }

    public static String[] lerValores(String[] listaValores, int quantValores, int pos) {
        if (pos < quantValores) {
            listaValores[pos] = MyIO.readString();
            return lerValores(listaValores, quantValores, pos + 1);
        }
        return listaValores;
    }

    public static char algebraBooleana(char[] entradaChar, int tam) {
        char[] valores = new char[10];
        return algebraBooleana(entradaChar, tam, valores, 0, 0);
    }

    public static char algebraBooleana(char[] entradaChar, int tam, char[] valores, int quantValores, int i) {
        if (i < tam) {
            if (entradaChar[i] == ')') {
                int j = i;
                while (j > 0 && entradaChar[j] != '(') {
                    j--;
                }
                char tipo = entradaChar[j - 1];
                if (tipo == 't') {
                    valores[quantValores] = entradaChar[j + 1];
                    return not(valores, quantValores);
                } else if (tipo == 'd') {
                    for (int k = j + 1; k < i; k++) {
                        valores[quantValores] = entradaChar[k];
                        quantValores++;
                    }
                    return and(valores, quantValores);
                } else if (tipo == 'r') {
                    for (int k = j + 1; k < i; k++) {
                        valores[quantValores] = entradaChar[k];
                        quantValores++;
                    }
                    return or(valores, quantValores);
                }
            }
            return algebraBooleana(entradaChar, tam, valores, quantValores, i + 1);
        }
        return entradaChar[0];
    }

    public static char not(char[] valores, int quantValores) {
        return not(valores, quantValores, 0);
    }

    public static char not(char[] valores, int quantValores, int i) {
        if (i < quantValores) {
            if (valores[i] == '1') {
                return '0';
            } else {
                return '1';
            }
        }
        return '1'; // Retorna '1' caso não haja valores
    }

    public static char and(char[] valores, int quantValores) {
        return and(valores, quantValores, 0);
    }

    public static char and(char[] valores, int quantValores, int i) {
        if (i < quantValores) {
            if (valores[i] == '0') {
                return '0';
            }
            return and(valores, quantValores, i + 1);
        }
        return '1'; // Retorna '1' caso todos os valores sejam '1'
    }

    public static char or(char[] valores, int quantValores) {
        return or(valores, quantValores, 0);
    }

    public static char or(char[] valores, int quantValores, int i) {
        if (i < quantValores) {
            if (valores[i] == '1') {
                return '1';
            }
            return or(valores, quantValores, i + 1);
        }
        return '0'; // Retorna '0' caso todos os valores sejam '0'
    }
}