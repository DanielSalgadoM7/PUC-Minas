# TAREFA

Implementar um código paralelo OpenMP em C (Linux utilizando o compilador GCC) usando também o padrão REDUCE e políticas de escalonamento para encontrar a quantidade de números primos entre 2 e n, onde n é um número inteiro <= 1000000000, usando o Crivo de Eratóstenes sequencial (sieve.c). Um exemplo de entrada e saída abaixo:

Entrada: 100000000
Saída: 5761455

Explicação do algoritmo: Crivo de Eratóstenes.

Obs: Para compilar o código use a seguinte linha de comando:

$ gcc sieve.c -o sieve -fopenmp -lm

Para executar o programa, utilize a seguinte linha de comando:

$ time ./sieve

IMPORTANTE: O código .c deve ser submetido e conter um comentário com os tempos sequencial e paralelo, utilizando diferentes políticas de escalonamento (i.e., schedule: static, dynamic e guided). Faça variações de chunks também. Os resultados de tempo devem ser os obtidos com execuções no servidor Parcode. Caso opte por executar em outra máquina, comentar no código e acrescentar detalhes da arquitetura.