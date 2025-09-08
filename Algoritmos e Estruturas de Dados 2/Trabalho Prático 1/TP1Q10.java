/*Crie um método recursivo que recebe uma string como parâmetro e retorna true se essa é um Palíndromo.

Na saída padrão, para cada linha de entrada, escreva uma linha de saída com SIM/NÃO indicando se a linha é um palíndromo. 
Destaca-se que uma linha de entrada pode ter caracteres não letras.*/

//Daniel Salgado Magalhães - 821429

public class TP1Q10{
    public static void main(String[] args){
        String entrada;

        while(true){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }
            MyIO.println(palindromoRecursivo(entrada)?"SIM":"NAO");
        }
    }

    //fica chamando o método
    public static boolean palindromoRecursivo(String entrada){
        return palindromoRecursivo(entrada,0);
    }

    //realiza a verificação do palindromo
    public static boolean palindromoRecursivo(String entrada, int pos){
        if(pos > entrada.length()/2){
            return true; //retorna verdadeiro caso seja igual
        }else if(entrada.charAt(pos) == entrada.charAt(entrada.length()-pos-1)){
            return palindromoRecursivo(entrada, pos+1); //adiciona +1 a posição para percorrer a palavra    
        }else{
            return false; // retorna falso caso não seja igual
        }
    }
}
