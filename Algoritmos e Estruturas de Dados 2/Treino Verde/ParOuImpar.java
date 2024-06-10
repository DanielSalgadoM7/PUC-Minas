// Ler números até encontrar 0.

// Daniel Salgado Magalhães - 821429

import java.util.Scanner;

public class ParOuImpar {

    public static void main(String[] args) {
        int num;

        Scanner sc;
        sc = new Scanner (System.in);

        do{
            num = sc.nextInt();

            if(num == 0){
                break;
            }else if(num%2 == 0){
                System.out.println("P");
            }else{
                System.out.println("I");
            }
        }while(num != 0);

        sc.close();
    }
    
}
