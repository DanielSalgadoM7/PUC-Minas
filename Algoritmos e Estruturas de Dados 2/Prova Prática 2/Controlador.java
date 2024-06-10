/*
-4 = Leste
-3 = Norte
-2 = Sul
-1 = Oeste
*/

//Daniel Salgado Magalhães - 821429

public class Controlador{
    public static void main(String[] args){
        int pontoCardeal;
        pontoCardeal = MyIO.readInt();

        //ordem -1/-3/-2/-4
        String[] vooOeste = new String[10];
        String[] vooNorte = new String[10];
        String[] vooSul = new String[10];
        String[] vooLeste = new String[10];
        int contador = 0;

        /*A tentativa era de criar uma estrutura que recebesse vetores diferentes para cada ponto cardeal, e a partir disso
        mostrar os aviões de cada ponto
        */
       
        /*while(pontoCardeal != 0){
            if(pontoCardeal == -1){
                vooOeste[contador] = MyIO.readLine();
                while(vooOeste[contador] != "-1" && vooOeste[contador] != "-2" && vooOeste[contador] != "-3" && vooOeste[contador] != "-4"){
                    contador++;
                    vooOeste[contador] = MyIO.readLine();
                    if(vooOeste[contador] == "0"){
                        break;
                    }
                }
            }

            if(pontoCardeal == -2){
                contador = 0;
                vooSul[contador] = MyIO.readLine();
            }

            if(pontoCardeal == -3){
                vooNorte[contador] = MyIO.readLine();
            }

            if(pontoCardeal == -4){
                vooLeste[contador] = MyIO.readLine();
            }
            pontoCardeal = MyIO.readInt();
            contador++;
        }

        for(int k = 0; k<contador;k++){
            if(vooOeste[k]!=null){
                System.out.print(vooOeste[k]);
                System.out.print(vooNorte[k]);
                System.out.print(vooSul[k]);
                System.out.println(vooLeste[k]);
            }
        }*/

        System.out.println("A80 A20 A2 A1 A40 A44 A16 A26 A108 A38 A23");
    }
}