# Programa 12
#Considere a seguinte situação:
#int ***x;
#onde x contem um ponteiro para um ponteiro para um ponteiro para um inteiro.
#Nessa situação, considere que a posição inicial de memória contenha o inteiro em questão.
#Coloque todos os outros valores em registradores, use os endereços de memória que quiser dentro
#do espaço de endereçamento do Mips.
#Resumo do problema:
#k = MEM [ MEM [MEM [ x ] ] ].
#Crie um programa que implemente a estrutura de dados acima, leia o valor de K, o multiplique por
#2 e o reescreva no local correto conhecendo-se apenas o valor de x.

# x->mem->mem->mem

.text

lui $t0, 0x1001
lw $t1, 0($t0) # x
add $t0,$t0,$t1 # ponteiro 1
lw $t2, 0($t0) 
add $t0,$t0,$t2 # ponteiro 2
lw $s0, 0($t0) 
sll $s0, $s0, 1 # k = k * 2
sw $s0, 0($t0) # 

.data
x: .word 0x0004
p1: .word 0x0008
p2: .word 0x000c
num: .word 10