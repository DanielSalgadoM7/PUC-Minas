# Programa 15
#Escrever um programa que crie um vetor de 100 elementos na memória onde vetor[i] = 2*i +
#1. Após a última posição do vetor criado, escrever a soma de todos os valores armazenados
#do vetor.
#Use o MARS para verificar a quantidade de instruções conforme o tipo (ULA, Desvios, Mem ou
#Outras)

.text 
# t0 -> endereço
# t1 -> posição do vetor(i)
# t2 -> resultado de 2*i + 1
# t3 -> tamanho do vetor
lui $t0,0x1001
ori $t1,$zero, 0
ori $t3,$zero, 100
loop1:
sll $t2, $t1, 1
addi $t2, $t2, 1
sw $t2, 0($t0)
addi $t1, $t1, 1
addi $t0, $t0, 4
bne $t1, $t3, loop1

# t0 -> endereço
# t1 -> numero lido na memoria
# t2 -> soma dos numeros lidos
# t3 -> contador do loop(começa em 100 termina em zero)
addi $t0, $t0, -4
ori $t2,$zero, 0
loop2:
lw $t1, 0($t0)
add $t2, $t2, $t1
addi $t0, $t0, -4
addi $t3, $t3, -1
bne $t3, $zero, loop2
