/*Crie um método iterativo que recebe uma string e retorna true se a mesma é composta somente por vogais. 
Crie outro método iterativo} que recebe uma string e retorna true se a mesma é composta somente por consoantes. 
Crie um terceiro método iterativo que recebe uma string e retorna true se a mesma corresponde a um número inteiro. 
Crie um quarto método iterativo que recebe uma string e retorna true se a mesma corresponde a um número real. 
Na saída padrão, para cada linha de entrada, escreva outra de saída da seguinte forma X1 X2 X3 X4 onde cada Xi é um 
booleano indicando se a é entrada é: composta somente por vogais (X1); composta somente somente por consoantes (X2); 
um número inteiro (X3); um número real (X4). Se Xi for verdadeiro, seu valor será SIM, caso contrário, NÃO.*/

//Daniel Salgado Magalhães - 821429

public class TP1Q06{
    public static void main(String[] args){
        String entrada;

        while(true){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }

            MyIO.print(isVogal(entrada)?"SIM":"NAO");
            MyIO.print(isConsoante(entrada)?" SIM":" NAO");
            MyIO.print(isInteiro(entrada)?" SIM":" NAO");
            MyIO.println(isReal(entrada)?" SIM":" NAO");
        }
    }

    //função para verificação de palavras com apenas vogais
    public static boolean isVogal(String entrada){
        entrada = entrada.toLowerCase();
        for(int i = 0;i<entrada.length();i++){
            if(entrada.charAt(i) !='a' && entrada.charAt(i) != 'e' && entrada.charAt(i) != 'i' && entrada.charAt(i) != 'o' && entrada.charAt(i) != 'u'){
                return false;
            }
        }
        return true;
    }

    //função para verificação de palavras com apenas consoantes
    public static boolean isConsoante(String entrada){
        entrada = entrada.toLowerCase();
        for(int i=0;i<entrada.length();i++){
            if(entrada.charAt(i) == 'a' || entrada.charAt(i) == 'e' || entrada.charAt(i) == 'i' || entrada.charAt(i) == 'o' || entrada.charAt(i) == 'u' || entrada.charAt(i)>=48 && entrada.charAt(i)<=57){
                return false;
            }
        }
        return true;
    }

    //função para verificação de palavras com apenas números inteiros
    public static boolean isInteiro(String entrada){
        for(int i=0;i<entrada.length();i++){
            if(!(entrada.charAt(i)>=48 && entrada.charAt(i)<=57)){
                return false;
            }
        }
        return true;
    }
    
    //função para verificação de palavras com apenas números reais
    public static boolean isReal(String entrada){
        int cont = 0;
        for(int i=0;i<entrada.length();i++){
            if(!((entrada.charAt(i)>=48 && entrada.charAt(i)<=57) || entrada.charAt(i) == ',' || entrada.charAt(i) == '.'))
                return false;
            //após a verificação de que é um número de 0 a 9 ou '.' ou ',', ele confere se é um dos dos pontos e realiza o contador
            if(entrada.charAt(i) == ',' || entrada.charAt(i) == '.')
                cont++;

        }

        //caso o contador seja maior que 1, a pontuação está errada no número, e ele não é real
        if (cont <= 1)
            return true;
        else
            return false;
    }   

}
