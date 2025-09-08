//Daniel Salgado Magalhães - 821429
//Conforme informado na mensagem enviada no canvas, não consegui acessar a máquina da PUC, então fiz na minha, que possui 12 threads.
//O processador é um AMD Ryzen 5 5600X 6-Core Processor, ou seja, 12 threads e 6 núcleos.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <omp.h> 

int sieveOfEratosthenes(int n)
{
    int primes = 0; 
    bool *prime = (bool*) malloc((n+1)*sizeof(bool));
    int sqrt_n = sqrt(n);

    memset(prime, true, (n+1)*sizeof(bool));

    for (int p=2; p <= sqrt_n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (int p=2; p<=n; p++)
        if (prime[p])
            primes++;

    free(prime);
    return(primes);
}

int sieveOfEratosthenesSchedule(int n, int tam_chunk, char tipoSchedule)
{
    int primes = 0; 
    bool *prime = (bool*) malloc((n+1) * sizeof(bool));
    int sqrt_n = sqrt(n);

    memset(prime, true, (n+1) * sizeof(bool));

//schedyle static
    if(tipoSchedule == 's'){
        for (int p = 2; p <= sqrt_n; p++){
            if (prime[p] == true)
            {
                //paraleliza a contagem dos numeros primos
                #pragma omp parallel for schedule(static, tam_chunk)
                for (int i = p * 2; i <= n; i += p)
                    prime[i] = false;
            }
        }

        //paraleliza a contagem usando redução
        #pragma omp parallel for reduction(+:primes) schedule(static, tam_chunk)
        for (int p = 2; p <= n; p++)
            if (prime[p])
                primes++;
//schedyle dynamic
    }else if(tipoSchedule == 'd'){
        for (int p = 2; p <= sqrt_n; p++){
            if (prime[p] == true)
            {
                //paraleliza a contagem dos numeros primos
                #pragma omp parallel for schedule(dynamic, tam_chunk)
                for (int i = p * 2; i <= n; i += p)
                    prime[i] = false;
            }
        }

        //paraleliza a contagem usando redução
        #pragma omp parallel for reduction(+:primes) schedule(dynamic, tam_chunk)
        for (int p = 2; p <= n; p++)
            if (prime[p])
                primes++;

//schedyle guided
    }else if(tipoSchedule == 'g'){
        for (int p = 2; p <= sqrt_n; p++){
            if (prime[p] == true)
            {
                //paraleliza a contagem dos numeros primos
                #pragma omp parallel for schedule(guided, tam_chunk)
                for (int i = p * 2; i <= n; i += p)
                    prime[i] = false;
            }
        }

        //paraleliza a contagem usando redução
        #pragma omp parallel for reduction(+:primes) schedule(guided, tam_chunk)
        for (int p = 2; p <= n; p++)
            if (prime[p])
                primes++;
    }

    free(prime);
    return primes;
}

int main()
{
    int n = 100000000;
    double melhor_Speedup = 0.0;
    int melhor_tam_chunk = 0;

    //versão Sequencial
    double inicio = omp_get_wtime();
    int qtd = sieveOfEratosthenes(n);
    double fim = omp_get_wtime();
    double tempo = fim - inicio;

    printf("Resultado Sequencial:\n");
    printf("Primos: %d\n", qtd);
    printf("Tempo: %.3f segundos\n\n", tempo);

    //versão Paralela
    int num_threads = 12;
    int tam_chunk = 10;
    omp_set_num_threads(num_threads);
    for(int i = 0; i < 4; i++) {
        double inicioStatic = omp_get_wtime();
        int qtdStatic = sieveOfEratosthenesSchedule(n, tam_chunk,'s');
        double fimStatic = omp_get_wtime();
        double tempoStatic= fimStatic - inicioStatic;

        printf("Resultado Paralelo com schedule static:\n");
        printf("Primos: %d\n", qtdStatic);
        printf("Tempo: %.3f segundos\n", tempoStatic);

        //calculo do Speedup static
        double speedupStatic = tempo / tempoStatic;
        printf("Speedup com tam_chunk = %d: %.2f\n\n", tam_chunk, speedupStatic);

        if(speedupStatic > melhor_Speedup){
            melhor_Speedup = speedupStatic;
            melhor_tam_chunk = tam_chunk;
        }

        double inicioDynamic = omp_get_wtime();
        int qtdDynamic = sieveOfEratosthenesSchedule(n, tam_chunk,'d');
        double fimDynamic = omp_get_wtime();
        double tempoDynamic = fimDynamic - inicioDynamic;

        printf("Resultado Paralelo com schedule dynamic:\n");
        printf("Primos: %d\n", qtdDynamic);
        printf("Tempo: %.3f segundos\n", tempoDynamic);

        //calculo do Speedup dynamic
        double speedupDynamic = tempo / tempoDynamic;
        printf("Speedup com tam_chunk = %d: %.2f\n\n", tam_chunk, speedupDynamic);

        if(speedupDynamic > melhor_Speedup){
            melhor_Speedup = speedupDynamic;
            melhor_tam_chunk = tam_chunk;
        }

        double inicioGuided = omp_get_wtime();
        int qtdGuided = sieveOfEratosthenesSchedule(n, tam_chunk,'g');
        double fimGuided = omp_get_wtime();
        double tempoGuided = fimGuided - inicioGuided;

        printf("Resultado Paralelo com schedule guided:\n");
        printf("Primos: %d\n", qtdGuided);
        printf("Tempo: %.3f segundos\n", tempoGuided);

        //calculo do Speedup guided
        double speedupGuided = tempo / tempoGuided;
        printf("Speedup com tam_chunk = %d: %.2f\n\n", tam_chunk, speedupGuided);

        if(speedupGuided > melhor_Speedup){
            melhor_Speedup = speedupGuided;
            melhor_tam_chunk = tam_chunk;
        }

        tam_chunk *= 10;
    }

    printf("Melhor Speedup obtido: %.2f com tamanho de chunk: %d\n", melhor_Speedup, melhor_tam_chunk);

    return 0;
}
