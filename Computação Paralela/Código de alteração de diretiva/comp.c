//Daniel Salgado Magalhães - 821429

#include <stdio.h>
#include <omp.h>

int main()
{
    int i;

    #pragma omp parallel num_threads(2) // seta o número de threads em 2 
    {
        int tid = omp_get_thread_num(); // lê o identificador da thread 

        #pragma omp for schedule(static,2) //tid 0 vai fazer as iterações 1 e 2 e tid 1 vai fazer a iteração 3, pq dividiu entre 2 threads
        for(i = 1; i <= 3; i++) {
           printf("[PRINT1] T%d = %d \n",tid,i);
           printf("[PRINT2] T%d = %d \n",tid,i);
        }
    }
}
